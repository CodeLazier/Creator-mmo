#include "StdAfx.h"
#include "PlayMonster.h"
#include "PlayMap.h"
#include "ManagerMap.h"
#include "GameServerlib.h"
#include "PlayMapItem.h"
#include "PlayNeutral.h"
#include "SubSkill.h"
#include "SubAction.h"
#include "ScriptLua.h"
#include "DomainPlay.h"
#include "ManagerMonDef.h"
#include "ManagerItemDef.h"
#include "ManagerSkillDef.h"
#include "ManagerMonster.h"
#include "PlaySlave.h"
#include "PlayMonsterCaller.h"

namespace OGSLib
{

	PlayMonster::PlayMonster()
	{
		mType=MAP_OBJECT_TYPE_MONSTER;
		mReliveRange = 0;
		mNoRilive = 0;
		mDeadNum = 0;

		mTargetEffectResID = 0;
		mOwnerEffectType = 0;
		mOwnerEffectResID = 0;
		mLastSlowTimer = 0;
		m_ReliveGap = 30.0;
		m_ReliveGap2 = 0;
		mDropList = 0;
		mDropList2 = 0;
		mTalkList = 0;
		//mDropGroup = 0;
		mDropNoOwner = 0;
		mlimitlv = 0;
		mDisapearTime = 5;
		ClearHurtRecord();
		mTeamID = -1;
		mTalkTick = 0;
		mTalkGap = 30;
		mMonType = 0;
		m_expHiter.id = 0;
		m_expHiter.tick = 0;
		mHurtRecordTime = 0;
		mHalfHp = false;
		mNoShowHitter = false;
		/////////////////////�µĹ���ai
		mMabiGap = 0;
		mMabiProb = 0;
		mPoisonProb = 0;
		mPoisonTime = 0;
		mPoisonDefense = 0;
		mPoisonDamage = 0;
		mAoeRange = 0;
		mFenshenNum = 0;
		mFenshenHp = 0;
		mFenshenFlag = false;
	    mRageHp=0;
		mRagePowerMul=0;
		mRageAttackSpeedMul=0;
		mRageRunSpeedMul=0;
		mRageFlag=false;
		mLandification = false;
		mCaller = 0;
		mCallMonCountOnce = 0;
		mCallMonMaxCount = 0;

		mSwitchTargetType = 2;
		mSwitchTargetInteval = 0;
		mHatredDamageRatio = 0;			// �˺�ϵ��
		mHatredDistanceRatio = 0;		// �������ϵ��
		mLastSwitchTargetTick = 0;		// ����л�Ŀ��ʱ��
		mFollowRange = 0;
		mDirFixed = -1;
		mDirectDie = false;
		mNoTargetTick = 0;

		m_bLockTarget = false;
		/*m_nDestX = -1;
		m_nDestY = -1;*/
	}

	PlayMonster::~PlayMonster(void)
	{
	}
	void PlayMonster::ClearHurtRecord()
	{
		for(int i = 0;i < 10;i ++)
		{
			mHurtRecordID[i] = 0;
			mHurtRecordTick[i] = 0;
			mHurtRecord[i] = 0;
			mHurtRecordSeed[i] = 0;
		}
	}
	void PlayMonster::RecordHurtRecord(int src_id, int pawer,int seed)
	{
		time_t t = time(0);

		int min_index = -1;
		int min_hurt = 0xFFFFFF;
		int empty_index = -1;
		for (int i = 0; i < 10; i++)
		{
			if (mHurtRecordTick[i]>0 && mHurtRecordTick[i] + mGSL->mMonClearRecordTime<t)
			{
				mHurtRecordTick[i] = 0;
				mHurtRecord[i] = 0;
				mHurtRecordID[i] = 0;
				mHurtRecordSeed[i] = 0;
			}

			if (mHurtRecordID[i] > 0)
			{
				if (mHurtRecordID[i] == src_id)
				{
					if (mHurtRecordSeed[i] == seed){
						mHurtRecord[i] += pawer;
						mHurtRecordTick[i] = t;
						mHurtRecordSeed[i] = seed;
					}
					else
					{
						mHurtRecordTick[i] = t;
						mHurtRecord[i] = pawer;
						mHurtRecordSeed[i] = seed;
					}
					return;
				}
				if (mHurtRecord[i] < min_hurt)
				{
					min_hurt = mHurtRecord[i];
					min_index = i;
				}
			}
			else
			{
				if (empty_index < 0)
				{
					empty_index = i;
				}
			}
		}
		if (empty_index >= 0)
		{
			mHurtRecordID[empty_index] = src_id;
			mHurtRecord[empty_index] = pawer;
			mHurtRecordTick[empty_index] = t;
			mHurtRecordSeed[empty_index] = seed;
		}
		else
		{
			if (min_index >= 0)
			{
				mHurtRecordID[min_index] = src_id;
				mHurtRecord[min_index] = pawer;
				mHurtRecordTick[min_index] = t;
				mHurtRecordSeed[min_index] = seed;
			}
		}
	}

	unsigned int PlayMonster::FindMaxHurt()
	{
		unsigned int owner_id=0;
		int max_hurt=0;
		for( int i = 0;i< 10;i++)
		{
			if( mHurtRecordID[i] > 0 )
			{
				int nHurtVal = mHurtRecord[i];
				int nRatio = 1;
				// ���ֵϵ���������ֵ
				PlayActiveObject* fa = FindActiveInView(mHurtRecordID[i]);
				if( fa )
				{
					if (fa->TypeIsSlave() && ((PlaySlave*)fa)->AiType() == 4)
						nRatio = 2;
					int dis = std::abs(fa->X() - X()) + std::abs(fa->Y() - Y());
					nHurtVal = (nHurtVal * mHatredDamageRatio + dis * mHatredDistanceRatio) * nRatio;

					if (nHurtVal > max_hurt)
					{
						max_hurt = nHurtVal;
						owner_id = mHurtRecordID[i];
					}
				}
				else
					continue;
			}
		}
		return owner_id;
	}

	DomainPlay* PlayMonster::FindDeadOwner()
	{
		if (mGSL->mMonClearOwnerTime>0)
		{
			if (m_expHiter.id >0 && m_expHiter.tick + mGSL->mMonClearOwnerTime >= time(0))
			{
				PlayActiveObject* fa = FindActiveInView(m_expHiter.id);
				if (fa && fa->TypeIsPlayer())
				{
					DomainPlay* player = (DomainPlay*)fa;
					return player;
				}
				else if (fa && fa->TypeIsSlave())
				{
					PlaySlave* slave = dynamic_cast<PlaySlave*>(fa);
					if (slave)
					{
						DomainPlay* player = slave->Owner();
						return player;
					}
				/*	PlayTowerHelper* tower = dynamic_cast<PlayTowerHelper*>(fa);/////û�м����ħ�빦��
					if (tower)
					{
						DomainPlay* player = tower->Owner();
						return player;
					}*/
				}
			}
		}
		unsigned int owner_id = 0;
		//int count=0;
		int max_hurt = 0;
		int max_index = -1;
		int repeat = 0;
		for (;;)
		{
			repeat++;
			owner_id = 0;
			max_index = -1;
			for (int i = 0; i< 10; i++)
			{
				if (mHurtRecordID[i] > 0)
				{
					if (mHurtRecord[i] > max_hurt)
					{
						owner_id = mHurtRecordID[i];
						max_hurt = mHurtRecord[i];
						max_index = i;
					}
				}
			}
			if (owner_id > 0 && max_index >= 0 && max_index < 10)
			{
				// mHurtRecordID[max_index] = 0;
				PlayActiveObject* fa = FindActiveInView(owner_id);
				if (fa && fa->TypeIsPlayer())
				{
					DomainPlay* player = (DomainPlay*)fa;
					return player;
				}
				else if (fa && fa->TypeIsSlave())
				{
					PlaySlave* slave = dynamic_cast<PlaySlave*>(fa);
					if (slave)
					{
						DomainPlay* player = slave->Owner();
						return player;
					}
					/*PlayTowerHelper* tower = dynamic_cast<PlayTowerHelper*>(fa);/////û�м����ħ�빦��
					if (tower)
					{
						DomainPlay* player = tower->Owner();
						return player;
					}*/
				}
			}
			else
			{
				break;
			}
			if (repeat > 10){ printf("finddeadowner break \n."); break; }
		}
		return 0;
	}
	void PlayMonster::ClearDie()
	{
		ClearBuffOnDead();
		ClearStatusOnDead();
		mDirectDie = true;
		SetState(PlayMapObject::MAP_OBJECT_STATE_DEAD);
		ClearHurtRecord();
		mAIState = AI_STATE_RELIVE;
		m_ReliveTimer.Restart();
		PlayAIObject::OnDead(0,0);
		ResetUpdate(1);
	}
	void PlayMonster::OnDead(PlayActiveObject* src,int delay)
	{
		PlayActiveObject::OnDead(src, delay);

		// ����ù����Ǳ��ٻ�������
		if (mCaller)
			mCaller->DecCallMon(this);
		
		// ����ù�����"�ٻ�ʦ",�����ٻ������Ĺ���caller���ó�NULL(�ٻ������Ĺ����û����������ϵ)
		if (mMonstersCalled.size() > 0)
		{
			for (size_t i = 0; i < mMonstersCalled.size(); ++ i)
			{
				mMonstersCalled[i]->mCaller = NULL;
			}
			// ���,������������ٻ�
			mMonstersCalled.clear();
		}

		mDeadNum ++;
		ClearBuffOnDead();
		ClearStatusOnDead();
		SetState(PlayMapObject::MAP_OBJECT_STATE_DEAD);

		PlayMap * pMap = this->GetMap();
		if (pMap && pMap->TaskShare())
		{
			// ������,���乲��,���鲻����
			DomainPlay* player = FindDeadOwner();
			std::set<DomainPlay *> setPlayers = GetHurtPlayers();
			std::set<DomainPlay *>::iterator it = setPlayers.begin();
			while (it != setPlayers.end())
			{
				if (player == *it)
				{
					// ��ȡ����
					GiveExperience(player);
				}
				(*it)->OnKillMonster(this);
				++ it;
			}
			if (setPlayers.size() > 0)
			{
				DropItem3(setPlayers);
			}
		}
		else
		{
			DomainPlay* player = FindDeadOwner();
			DomainPlay* player2 = 0;
			if( player )
			{
				GiveExperience(player);
				player->OnKillMonster(this);
			}
			else
			{
				if( src && src->TypeIsPlayer() )
				{
					player2 = static_cast<DomainPlay*>(src);
					if( player2 )
					{
						player2->OnKillMonster(this);
					}
				}
			}
			if( player2 )
			{
				//DropItem(player2);
				DropItem3(player2);
				//��������ҵ����⴦��(ids)��¼�����Ա��id
				/*if (player2->GroupID() > 0)
				{
					int ids[5] = {};
					player2->GetGroupMemberId(ids);
				}*/
				
			}
			else
			{
				//DropItem(player);
				DropItem3(player);
			}
		}
		RandTalk(TALK_DIE);
		//if( ! mScriptPackage.empty() )
		//{
		//	std::stringstream ss;ss<<mScriptPackage<<".onDead";
		//	mScript->OnlyMonster(this,ss.str());
		//}

		ClearHurtRecord();
		m_expHiter.id = 0;
		m_expHiter.tick = 0;
		m_expHiter.name = "";
		mAIState = AI_STATE_RELIVE;
		m_ReliveTimer.Restart();
		ResetUpdate(1);
		
		PlayAIObject::OnDead(src,delay);

		//ˢĹ��
		MonDef* md = mGSL->GetMonDefManager()->FindMonDef(mDefId);
		if (IsBoss() && md->isShowTomb)
		{
			GenTombStone();
		}
	}

	const char* PlayMonster::FirstName()
	{
		//std::string monname = Name();
		MonDef* md = mGSL->GetMonDefManager()->FindMonDef(mDefId);
		if ( md )
		{
			return md->nodigital_name;
		}
		else
		{
			return Name();
		}
	}
	int PlayMonster::State()
	{
		//std::string monname = Name();
		MonDef* md = mGSL->GetMonDefManager()->FindMonDef(mDefId);
		if (md)
		{
			return md->title;
		}
		return 0;

	}
	int PlayMonster::GetDeathExp()
	{
		int exp = 0;
		//if( mGSL->mSystemEngineType == SYSTEM_ENGINE_WUZUN )
		//{
			exp = mDeathExp;
			return exp;
		//}
		//exp = mDeathExp*GetMap()->GetManager()->GetGSLib()->mExpMul;
		//if( GetMap() && GetMap()->ExpMul() > 0 )
		//{
		//	exp = int(exp * GetMap()->ExpMul() / 100.0f);
		//}
		//return exp;
	}
	void PlayMonster::GiveExperience(DomainPlay* player)
	{
		int exp = GetDeathExp();
// 		int temp = exp;
// 		int cha = (player->level()-level());
// 		if( cha > 10 )
// 		{
// 			exp -= (exp/2) * (cha-10) / 10;
// 		}
// 		if( exp <= temp/2 ) exp = temp/2;
		player->WinExpByMonster(exp);
	}

	bool PlayMonster::IsProperAttackDes(PlayActiveObject* des,SkillDef * sd)
	{
		if( ! PlayActiveObject::IsProperAttackDes(des,sd) )
		{
			return false;
		}

		if( des->TypeIsMonster() )
		{
			return false;
		}

		if (des->IsYingShen())
		{
			return false;
		}

		if( mTeamID > 0 && des->TypeIsPlayer() )
		{
			DomainPlay* play = (DomainPlay*)des;
			if( play->TeamID() == mTeamID )
			{
				return false;
			}
		}
		return true;
	}

	int  PlayMonster::Attacked(PlayActiveObject* src,SkillDef * sd,int pawer,int flags,int delay)
	{
		if (mLandification)
		{
			return 0;////ʯ��״̬���޵е�
		}
		if( src->TypeIsPlayer() )
		{
			pawer = GetMap()->GetManager()->GetGSLib()->mPawMul * pawer;
		}
		if( ! Target() )
		{
			Target(src);
		}
		//if(mGSL->mSystemEngineType == SYSTEM_ENGINE_WUZUN)
		//{
		//	if( rand() % 6 == 1 && src->TypeIsPlayer() )
		//	{
		//		Target(src);
		//	}
		//}
		int src_id = src->ID();
		if( src->TypeIsSlave() )
		{
			PlaySlave* slave = static_cast<PlaySlave*>(src);
			/*if( slave )
			{
				DomainPlay* play = slave->Owner();
				if( play )
				{
					src_id = play->ID();
				}
			}*/
		}
		if( src->TypeIsPlayer() )
		{
			DomainPlay* play = (DomainPlay*)src;
			if (Hp()<MaxHp()/2 && !mHalfHp)
			{
				RandTalk(TALK_HALF_HP);
				mHalfHp = true;
			}
			else if (mHurtRecordTime%10 == 0 && mHurtRecordTime > 0)
			{
				RandTalk(TALK_ATTACKED);
			}
		}
		if (Hp()<MaxHp()*mFenshenHp/100 && !mFenshenFlag)///������
		{
			mFenshenFlag = true;
			if (mFenshenMonName)
			{
				mGSL->GetMapManager()->GenMon(GetMap(), mFenshenMonName, X(), Y(), mFenshenNum, 10, 1, 1, "update");
			}
		}
		if (Hp()<MaxHp()*mRageHp / 100 && !mRageFlag)///��״̬
		{
			mRageFlag = true;
			Attributes()->mDC = int(Attributes()->mDC*mRagePowerMul);
			Attributes()->mDCMax = int(Attributes()->mDCMax*mRagePowerMul);
			mAttackGap = int(mAttackGap*mRageAttackSpeedMul);
			mWalkStep = int(mWalkStep*mRageRunSpeedMul);
			mWalkGap = int(mWalkGap*mRageRunSpeedMul);
		}
		RecordExpHitter(src);

		RecordHurtRecord(src_id, pawer, src->hurtSeed());

		if( Target())
		{
			if (mSwitchTargetType == 1)
			{
				unsigned int max_hurt_id = FindMaxHurt();
				if(max_hurt_id > 0 && max_hurt_id != Target()->ID() )
				{
					PlayActiveObject* fa = FindActiveInView(max_hurt_id);
					if( fa )
					{
						Target(fa);
					}
				}
			}
			else
			{
				// ����ʱ���л�
				double t = mGSL->GetTimerFix()->Elapsed();
				if ( mSwitchTargetInteval != 0 && t - mLastSwitchTargetTick >= mSwitchTargetInteval)
				{
					if ((!IsDesYinShen(src)) && std::abs(src->X() - X()) + std::abs(src->Y() - Y())  < mCoolEye)
					{
						Target((PlayActiveObject*)src);
						if (src->TypeIsPlayer())
						{
							if (rand()%100 > 50)
							{
								RandTalk(TALK_ATTACK);
							}
						}
						mLastSwitchTargetTick = mGSL->GetTimerFix()->Elapsed();
					}
				}
			}
		}
		return PlayActiveObject::Attacked(src,sd,pawer,flags,delay);
	}
	void PlayMonster::RandTalk(int flags)
	{
		if( !IsState(PlayMapObject::MAP_OBJECT_STATE_DEAD) )
		{
			if( mTalkList )
			{
				int msg_index = 0;
				if (flags > TALK_NORMAL)
				{
					msg_index = flags*10000;
				}
				std::vector<MonTalkDef> tempTalk;
				for (int i = 0;i < mTalkList->size();i++)
				{
					MonTalkDef& mtd = mTalkList->at(i);
					if (mtd.prob == msg_index )
					{
						tempTalk.push_back(mtd);
					}
				}
				if (tempTalk.size() > 0)
				{
					size_t p = rand() % tempTalk.size();
					MonTalkDef& talk = tempTalk.at(p);
					if (talk.msg != "")
					{
						for( InteractiveObjectVector::iterator pos = mVisibleInteractiveObjectList.begin();
							pos != mVisibleInteractiveObjectList.end();
							++ pos )
						{
							if ((*pos))
							{
								if ((*pos)->TypeIsPlayer())
								{
									DomainPlay* play = (DomainPlay*)(*pos);
									if (play)
									{
										play->NotifyMonsterChat(this, talk.msg.c_str());
									}
								}
							}
						}
					}
				}
			}
		}
	}

	bool PlayMonster::check_drop_group(int group_id,int select,int randmax)
	{
		if( mDropGroupRecord.find(group_id) == mDropGroupRecord.end() )
		{
			mDropGroupRecord[group_id] = 0;
		}
		int can_drop_num = static_cast<int>(mDeadNum * 1.0f / randmax * select);
		if( mDropGroupRecord[group_id] <= can_drop_num )
		{
			mDropGroupRecord[group_id] = mDropGroupRecord[group_id] + 1;
			return true;
		}
		return false;
	}
	
	void PlayMonster::DropItem(DomainPlay* play)
	{
		
	}

	void PlayMonster::DropItem3(std::set<DomainPlay *>& players)
	{

		std::vector<NewMonDropDef2>* pmddv = mDropList2;
		std::string item_str = "";
		int itemId;
		if( pmddv )
		{
			{
				int mul = 10;
				for (std::vector<NewMonDropDef2>::iterator pos = pmddv->begin();
					pos != pmddv->end();
					++pos)
				{
					itemId = 0;
					if (pos->gold_min && pos->gold_max)
					{
						itemId = ITEM_GOLD_ID;
					}
					else if (pos->item_id)
					{
						itemId = pos->item_id;
					}
					else if (pos->drop_plus.size() > 0)
					{
						int index = (rand() % pos->drop_plus.size());
						itemId = pos->drop_plus[index];
					}
					if (itemId)
					{
						ItemDef* id = mGSL->GetItemDefineManager()->GetItemDefine(itemId);

						if ((rand() % (10000 * 10)) < pos->drop_prob * mul /*&& (day_start >= pos->start_drop_day)*/)
						{
							ItemDef* id = mGSL->GetItemDefineManager()->GetItemDefine(itemId);
							if (id)
							{
								SubItem ii;
								bool rand_add = false;

								int flags = 0;
								if (mGSL->mMonDropBind == 1 || pos->bind == 1)
								{
									flags = ITEM_FLAG_BIND;
								}
								else if (mGSL->mMonDropUseBind == 1 /*|| pos->bind == 2*/)
								{
									flags = ITEM_FLAG_USE_BIND;
								}
								ii.BuildItemInstance(id, flags, rand_add, mGSL->mItemAddType);
								int count = 1;
								if (itemId == ITEM_GOLD_ID)
								{
									count = (rand() % (pos->gold_max - pos->gold_min + 1)) + pos->gold_min;
								}
								
							
// 								if ((m_ReliveGap2 > 0 && day_start <= 1) || mDropNoOwner)////����BOSS����������һ��ȫ�� �ɼ�ȡ
// 								{
// 									owner_id = 0;
// 								}
							
								int pick_limit_lv = 0;
								if (this->getlimitlv())
								{								
									pick_limit_lv = this->getlimitlv();
								}
								ItemDef* drop_id = mGSL->GetItemDefineManager()->GetItemDefine(ii.mTypeID);
								if (mParentMap  && drop_id)
								{
									if (drop_id->mNeedZsLevel >= 1 || ((drop_id->IsCloth(drop_id->mEquipType) || drop_id->IsWeapon(drop_id->mEquipType)) && drop_id->mNeedParam >= 70))
									{
										item_str += drop_id->mName + "_";
									}
								}

								if (mDropNoOwner)
								{
									DropTheItem(&ii, count, 0, pick_limit_lv, pos->owned_duration);
								}
								else
								{
									std::vector<int> ids;
									std::set<DomainPlay*>::iterator it = players.begin();
									while (it != players.end())
									{
										ids.push_back((*it)->ID());
										++ it;
									}
									DropTheItem(&ii, count, ids, pick_limit_lv, pos->owned_duration);
								}
							}
						}
					}					
				}
				if (item_str != "")
				{
					for (std::set<DomainPlay *>::iterator it = players.begin(); it != players.end(); ++ it)
						mGSL->GetScriptEngine()->PlayerLuaFunction(*it, "player.onDropAlert", Name(), item_str.c_str());
				}
			}
			
		}
	}

	void PlayMonster::DropItem3(DomainPlay* play)
	{
		std::vector<NewMonDropDef2>* pmddv = mDropList2;
		std::string item_str = "";
		int itemId;
		if( pmddv )
		{
			{
				int mul = 10;
				int day_start = gsl()->GetServerStartDays();///��ȡ��������

				for (std::vector<NewMonDropDef2>::iterator pos = pmddv->begin();
					pos != pmddv->end();
					++pos)
				{
					itemId = 0;
					if (pos->gold_min && pos->gold_max)
					{
						itemId = ITEM_GOLD_ID;
					}
					else if (pos->item_id)
					{
						itemId = pos->item_id;
					}
					else if (pos->drop_plus.size() > 0)
					{
						int index = (rand() % pos->drop_plus.size());
						itemId = pos->drop_plus[index];
					}
					if (itemId)
					{
						ItemDef* id = mGSL->GetItemDefineManager()->GetItemDefine(itemId);
						if (id)
						{
							if (ItemDef::IsEquipment(id->SubType))
							{
								if (play)
								{
									mul = play->checkStatusmulpro();	
								}
							}
						}
						if ((rand() % (10000 * 10)) < pos->drop_prob * mul /*&& (day_start >= pos->start_drop_day)*/)
						{
							ItemDef* id = mGSL->GetItemDefineManager()->GetItemDefine(itemId);
							if (id)
							{
								SubItem ii;
								bool rand_add = false;
								/*if (ItemDef::IsEquipment(id->mTypeID))
								{
									int add_prob = pos->count;
									if (play)
									{
										add_prob += play->checkStatusMonDropItemAddProb();
									}
									if (add_prob > 0)
									{
										if (rand() % 10000 < add_prob)
										{
											rand_add = true;
										}
									}
								}*/
								int flags = 0;
								if (mGSL->mMonDropBind == 1 || pos->bind == 1)
								{
									flags = ITEM_FLAG_BIND;
								}
								else if (mGSL->mMonDropUseBind == 1 /*|| pos->bind == 2*/)
								{
									flags = ITEM_FLAG_USE_BIND;
								}
								ii.BuildItemInstance(id, flags, rand_add, mGSL->mItemAddType);
								int count = 1;
								if (itemId == ITEM_GOLD_ID)
								{
									count = (rand() % (pos->gold_max - pos->gold_min + 1)) + pos->gold_min;
								}
								int owner_id = play ? play->ID() : 0;
							
// 								if ((m_ReliveGap2 > 0 && day_start <= 1) || mDropNoOwner)////����BOSS����������һ��ȫ�� �ɼ�ȡ
// 								{
// 									owner_id = 0;
// 								}
 							
								int pick_limit_lv = 0;
								if (this->getlimitlv())
								{								
									pick_limit_lv = this->getlimitlv();
								}
								ItemDef* drop_id = mGSL->GetItemDefineManager()->GetItemDefine(ii.mTypeID);
								if (mParentMap && play && drop_id)
								{
									if (drop_id->mNeedParam >= 80 || (day_start<=3 && drop_id->mNeedParam >= 70))
									{
										char ss[256];
										itoa(drop_id->mTypeID, ss,10);
										std::string value(ss);
										item_str += value + "_";
									}
								}
								DropTheItem(&ii, count, owner_id, pick_limit_lv);
							}
						}
					}					
				}
				if (item_str != "")
				{
					mGSL->GetScriptEngine()->PlayerLuaFunction(play, "player.onDropAlert", Name(), item_str.c_str());
				}
			}
			
		}
	}
	void PlayMonster::NotifyClearYingShen(PlayMapObject* src) 
	{
		if(! Target())
		{
			CheckTarget(src,src->X(),src->Y());
		}
	}
	void PlayMonster::NotifyMeet(PlayMap* map,PlayMapObject* src)
	{
		PlayAIObject::NotifyMeet(map,src);
		CheckTarget(src,src->X(),src->Y());
	}

	void PlayMonster::NotifyBye(PlayMap* map,PlayMapObject* src)
	{
		PlayAIObject::NotifyBye(map,src);
	}
	void PlayMonster::NotifyWalk(PlayMapObject* src,int dir,int newx,int newy)
	{
		int dis = std::abs(newx - X()) + std::abs(newy - Y());
		if (Target() && Target()->ID() == src->ID() && dis > mFollowRange)
		{
			ClearTarget();
			return;
		}
		CheckTarget(src,newx,newy);
	}
	void PlayMonster::NotifyRun(PlayMapObject* src,int dir,int newx,int newy)
	{
		int dis = std::abs(newx - X()) + std::abs(newy - Y());
		if (Target() && Target()->ID() == src->ID() && dis > mFollowRange)
		{
			ClearTarget();
			return;
		}
		CheckTarget(src,newx,newy);
	}
	bool PlayMonster::IsDesYinShen(PlayActiveObject* src)
	{
		if( mCoolEye >= 50 )
		{
			return false;
		}
		return src->IsYingShen();
	}

	void PlayMonster::CheckTarget(PlayMapObject* src,int newx,int newy)
	{
		if( ! src->IsInteractive() ) return;
		PlayActiveObject* act = (PlayActiveObject*)src;
		
		if (!src->TypeIsPlayer() && !src->TypeIsSlave())
		{
			return;
		}

		if (!Target())
		{
			// ��ǰû��Ŀ������,�����Ƿ�����,ֻҪ������Ұ��Χ��,����ΪĿ��
			if (!IsProperAttackDes(static_cast<PlayActiveObject*>(src), NULL))
			{
				return;
			}

			int dis = std::abs(newx - X()) + std::abs(newy - Y());
			if (dis < mCoolEye)
			{
				Target((PlayActiveObject*)src);
				if (src->TypeIsPlayer())
				{
					if (rand()%100 > 50)
					{
						RandTalk(TALK_ATTACK);
					}
				}
				mLastSwitchTargetTick = mGSL->GetTimerFix()->Elapsed();
			}
		}
		else
		{
			// ��ǰ��Ŀ������,����Ŀ��ѡ��ʽ,�л�Ŀ��
			if (mSwitchTargetType == 2)
			{
				// ����ʱ���л�
				if (mSwitchTargetInteval == 0)
					return;

				double t = mGSL->GetTimerFix()->Elapsed();
				if (t - mLastSwitchTargetTick < mSwitchTargetInteval)
					return;

				if ((!IsDesYinShen(act)) && std::abs(newx - X()) + std::abs(newy - Y())  < mCoolEye)
				{
					Target((PlayActiveObject*)src);
					if (src->TypeIsPlayer())
					{
						if (rand()%100 > 50)
						{
							RandTalk(TALK_ATTACK);
						}
					}
					mLastSwitchTargetTick = mGSL->GetTimerFix()->Elapsed();
				}
			}
			// ���ݳ��ֵѡ��Ŀ������ �ڱ�����ʱ����
		}
	}

	void PlayMonster::Relive()
	{
		if( mNoRilive )
		{
			//if( mParentMap )
			//{
			//	mParentMap->RemoveObject(this);
			//}
			//mDieClear = 1;
			return ;
		}
		SetState(PlayMapObject::MAP_OBJECT_STATE_IDLE);
		if( mParentMap )
		{
			mParentMap->RemoveObject(this);
		}
		ResetAttribute();
		PlayMap* map = mGSL->GetMapManager()->FindRealMap(mReliveMap);
		if( map )
		{
			int ox=mReliveX;
			int oy=mReliveY;
			if( mReliveRange > 0 )
			{
				map->GenValidateRandomPosition(mReliveX,mReliveY,mReliveRange,&ox,&oy, 1);
				//if( ! map->GenValidatePosition(mReliveX + rand()%(mReliveRange*2) - mReliveRange,mReliveY + rand()%(mReliveRange*2) - mReliveRange,&ox,&oy) )
				//{
				//	ox = mReliveX;
				//	oy = mReliveY;
				//}
			}
			ForceMove(ox,oy,mDir);
			map->AddObject(this);
		}
		if( ! mScriptPackage.empty() )
		{
			char strbuf[512];
			_snprintf_s(strbuf,512,"%s.onRelive",mScriptPackage.c_str());
			mScript->OnlyMonster(this,strbuf);
		}
		MonDef* md = mGSL->GetMonDefManager()->FindMonDef(mDefId);
		if (md->isShowRefresh)
		{
			mScript->OnlyMonster(this,"mon.bossRefresh.onRelive");
		}
		CleanTombStone();
	}
	int PlayMonster::AiIdle()
	{
		if( mPlayerList.size() > 0 || Target())
		{
			if( Target() )
			{
				PlayActiveObject* ao=Target();
				if( ao->IsDead()  || (!IsProperAttackDes(ao, NULL)) )
				{
					ClearTarget();
					mAIState = AI_STATE_IDLE;
				}
				else 
				{
					EnterFightState();

					// ѡ����
					int skill = ChooseSkill(ao);
					SkillDef * skill_def = mGSL->GetSkillDefineManager()->GetSkillDefineById(skill);
					int disX = std::abs(ao->X()-X());
					int disY = std::abs(ao->Y()-Y());
					int dis = disX > disY ? disX : disY;
					int moveDisEnd = 2;

					if (skill_def != NULL)
						moveDisEnd = skill_def->CastDistanceMax + 1;

					bool bCanUseSkill = false;
					if (skill_def != NULL 
						&& dis >= skill_def->CastDistanceMin && dis <= skill_def->CastDistanceMax)
					{
						if (skill_def->Shape == 2 || skill_def->Shape == 3)
						{
							if (disX == 0 || disY == 0 || disX == disY)
								bCanUseSkill = true;
						}
						else
						{
							bCanUseSkill = true;
						}
					}

					if (bCanUseSkill)
					{
						if (mLandification)
							mLandification = false;
						// ʹ�ü���
						onAiAttack(ao, skill_def);
					}
					else
					{
						// ����Ŀ���ƶ�
						if (mLandification)
						{
							return AI_STATE_NULL;
						}
						if (mFollowRange >= dis && mFollowRange != 0)
						{
							if (disX == 0 && disY == 0)
							{
								//�����һ��
								RandGo();
							}
							else if (!Walk(ao->X(),ao->Y(),moveDisEnd) && moveDisEnd > 1)
								Walk(ao->X(),ao->Y(),moveDisEnd - 1);
							mAIState = AI_STATE_WALK;
						}
						else
							mAIState = AI_STATE_IDLE;
						
						return mAIState;
					}
				}
			} // if( Target() )
			else
			{
				RandGo();
				mAIState = AI_STATE_IDLE;
				LeaveFightState();
			}
		} // if( mPlayerList.size() > 0 )
		else
		{
			if (mLandification)
			{
				return AI_STATE_NULL;
			}
			RandGo();
			mAIState = AI_STATE_NULL;
			LeaveFightState();
		}
		return mAIState;
	}

	void PlayMonster::AiOther(double time)
	{
		if( mAIState == AI_STATE_RELIVE )
		{
			return ;
		}
		if( mPlayerList.size() > 0 )
		{
			mAIState = AI_STATE_IDLE;
			return;
		}
		else
		{
			if( time - mLastSlowTimer > (20.0+rand()%10) )
			{
				mLastSlowTimer = time;
				RandGo();
			}
			return;
		}
	}
	void PlayMonster::AiWalk()
	{
		if( Target() )
		{
			if( m_WalkTimer.Elapsed() > mWalkGap )
			{
				mAIState = AI_STATE_IDLE;
			}
		}
		else
		{
			if( m_WalkTimer.Elapsed() > mWalkGap*3 )
			{
				mAIState = AI_STATE_IDLE;
			}
		}
	}
	void PlayMonster::AiRelive()
	{
		if( mDirectDie )
		{
			if (mParentMap)
			{
				mParentMap->RemoveObject(this);
			}
			mDieClear = 1;
			mDirectDie = false;
		}
		else if (m_ReliveTimer.Elapsed() > mDisapearTime)
		{
			if ( mNoRilive )
			{
				if (mParentMap)
				{
					mParentMap->RemoveObject(this);
				}
				mDieClear = 1;
			}
			else if (m_ReliveGap > mDisapearTime)
			{
				if (mParentMap)
				{
					mParentMap->RemoveObject(this);
				}
			}
		}
		int server_days = gsl()->GetServerStartDays();
		if (m_ReliveGap2 > 0 && server_days <= 1)
		{
			if (m_ReliveTimer.Elapsed() > m_ReliveGap2)
			{
				Relive();
				mAIState = AI_STATE_NULL;
			}
			return;
		}
		if( m_ReliveTimer.Elapsed() > m_ReliveGap + mDisapearTime)
		{
			Relive();
			if (this->IsBoss() == 1 && mParentMap)///��������֮��������������
			{
				mParentMap->ExeNotifyMonDie();
			}
			mAIState = AI_STATE_NULL;
		}
	}
	int PlayMonster::DisaperTime()
	{
		if( IsState(PlayMapObject::MAP_OBJECT_STATE_DEAD) )
		{
			return m_ReliveGap - m_ReliveTimer.Elapsed();
		}
		if( mAIState != AI_STATE_RELIVE )
		{
			return mDisapearTime;
		}
		if (m_ReliveTimer.Elapsed() > m_ReliveGap)
		{
			return 0;
		}
		return m_ReliveGap - m_ReliveTimer.Elapsed();
	}
	int PlayMonster::getShowState()
	{
		if (mDisapearTime > 5)
		{
			return 1;
		}
		return 0;
	}

	int PlayMonster::Update(double time)
	{
		if( IsState(PlayMapObject::MAP_OBJECT_STATE_DEAD) )
		{
			//if (getShowState())
			//{
			//	ForceMove(mReliveX,mReliveY,mDir);
			//}
			mAIState = AI_STATE_RELIVE;
		}
		if( mAIState == AI_STATE_RELIVE )
		{
			AiRelive();
			//���⴦���и�������boss
			if(TypeIsMonster())
			{
				PlayMonster * mon = static_cast<PlayMonster *>(this);
				if (mon->IsBoss())
				{
					return 10;
				}
			}
			return 0;
		}
		if (mTalkTick + RandRange2(mTalkGap-60,mTalkGap+60) < time)
		{
			mTalkTick = time;
			RandTalk(TALK_NORMAL);
		}

		return PlayAIObject::Update(time);
	}

	int PlayMonster::OnSkillAttack(PlayActiveObject* target,SkillDef* sd,SubSkill* ss)
	{
		if( sd->TypeID == SkillDef::Skill_Type_Monster_ClearHurt )
		{
			ClearHurtRecord();
		}
		if( sd->TypeID == SkillDef::Skill_Type_Monster_NextTarget )
		{
			SwitchTarget();
		}
		if( sd->TypeID == SkillDef::Skill_Type_Monster_PubTarget )
		{
			if( Target() && mParentMap )
			{
				mParentMap->PublicTarget(Target());
			}
		}
		return 0;
	}
	void PlayMonster::SwitchTarget()
	{
		if( Target() )
		{
			PlayActiveObject* t = Target();
			int tid = Target()->ID();
			ClearTarget();
			for(InteractiveObjectVector::iterator pos = this->mVisibleInteractiveObjectList.begin();
				pos != this->mVisibleInteractiveObjectList.end();
				++ pos)
			{
				if ((*pos))
				{
					if ((*pos)->ID() != tid)
					{
						CheckTarget(*pos, (*pos)->X(), (*pos)->Y());
						if (Target() && Target()->ID() != tid)
						{
							break;
						}
					}
				}
			}
			if( ! Target() )
			{
				Target(t);
			}
		}
	}

	void PlayMonster::SwitchTarget(PlayActiveObject * target)
	{
		PlayActiveObject* t = Target();
		if (t && target)
		{
			if (t->ID() == target->ID())
				return;

			for(InteractiveObjectVector::iterator pos = this->mVisibleInteractiveObjectList.begin();
				pos != this->mVisibleInteractiveObjectList.end();
				++ pos)
			{
				if ((*pos))
				{
					if ((*pos)->ID() == target->ID())
					{
						CheckTarget(*pos, (*pos)->X(), (*pos)->Y());
						break;
					}
				}
			}

			if(!Target())
			{
				Target(t);
			}
		}
	}

	void PlayMonster::IncCallMon(PlayMonster * monCalled)
	{
		mMonstersCalled.push_back(monCalled);
	}	

	void PlayMonster::DecCallMon(PlayMonster * monCalled)
	{
		std::vector<PlayMonster *>::iterator it = std::find(mMonstersCalled.begin(), mMonstersCalled.end(), monCalled);
		if (it != mMonstersCalled.end())
		{
			mMonstersCalled.erase(it);
		}
	}

	std::set<DomainPlay *> PlayMonster::GetHurtPlayers()
	{
		std::set<DomainPlay *> setPlayers;
		for (size_t i = 0; i < 10; ++ i)
		{
			if (mHurtRecordID[i] == 0)
				continue;

			if (!mParentMap)
				return setPlayers;

			PlayActiveObject* fa = mParentMap->FindPlayerOrSlave(mHurtRecordID[i]);
			if (fa && fa->TypeIsPlayer())
			{
				DomainPlay* player = static_cast<DomainPlay*>(fa);
				if (!player->IsDead())
					setPlayers.insert(player);
			}
			else if (fa && fa->TypeIsSlave())
			{
				PlaySlave* slave = dynamic_cast<PlaySlave*>(fa);
				if (slave)
				{
					DomainPlay* player = slave->Owner();
					if (!player->IsDead())
						setPlayers.insert(player);
				}
			}
		}

		return setPlayers;
	}

	bool PlayMonster::IsDirFixed()
	{
		return mDirFixed >= 0? true: false;
	}

	void PlayMonster::RecordExpHitter(PlayActiveObject* src)
	{
		if (!src)
			return;

		DomainPlay * player = 0;
		if (src->TypeIsPlayer())
		{
			player = static_cast<DomainPlay*>(src);
		}
		else if (src->TypeIsSlave())
		{
			player = dynamic_cast<PlaySlave *>(src)->Owner();
		}

		if (player == 0)
		{
			return;
		}

		time_t t = time(0);
		if (mGSL->mMonClearOwnerTime>0)
		{
			if (m_expHiter.tick + mGSL->mMonClearOwnerTime<t)
			{
				bool bNotify = false;
				if (m_expHiter.id != player->ID())
					bNotify = true;
				m_expHiter.id = player->ID();
				m_expHiter.name = player->Name();
				m_expHiter.tick = t;
				player->AddBelongMonster(ID());
				// ��¼��������
				if (bNotify && !IsNoShowHitter())
				{
					for( DomainPlayVector::iterator pos = mPlayerList.begin();
						pos != mPlayerList.end();)
					{
						if ((*pos))
						{
							(*pos)->NotifyMonExpHiterChange(this, player);
							++pos;
						}
						else
						{
							printf("PlayMonster RecordExpHitter *pos=0\n");
							pos = mPlayerList.erase(pos);
							continue;
						}
					}
				}
			}
			else
			{
				if (m_expHiter.id == player->ID())
				{
					m_expHiter.tick = t;
				}
			}
		}
	}

	void PlayMonster::SetPosioner(PlayActiveObject * src)
	{
		PlayActiveObject::SetPosioner(src);
		RecordExpHitter(src);
	}

	bool PlayMonster::AddBuff(int id, double param)
	{
		if (mLandification)
		{
			return false;////ʯ��״̬���޵е�
		}
		return PlayActiveObject::AddBuff(id, param);
	}

	bool PlayMonster::AddStatus(int status,int duration,int param,double gap,int flags,int level[])
	{
		if (mLandification)
		{
			return false;////ʯ��״̬���޵е�
		}
		return PlayActiveObject::AddStatus(status,duration,param,gap,flags,level);
	}

	void PlayMonster::GetExpHitter(int& id, std::string& name)
	{
		if (m_expHiter.id >0 && m_expHiter.tick + mGSL->mMonClearOwnerTime >= time(0))
		{
			id = m_expHiter.id;
			name = m_expHiter.name;
		}
		else
		{
			id = 0;
			name = "";
		}
	}

	int PlayMonster::GetExpHitterId()
	{
		if (m_expHiter.id >0 && m_expHiter.tick + mGSL->mMonClearOwnerTime >= time(0))
		{
			return m_expHiter.id;
		}
		return 0;
	}

	void PlayMonster::EnterFightState()
	{
		mNoTargetTick = 0;
		if (m_AIAtkParam.in_fight_tick < m_AIAtkParam.out_fight_tick)
		{
			// ����ս��ʱ��С������ս��ʱ��,��ʼ�������ý���ս��ʱ��
			m_AIAtkParam.in_fight_tick = mGSL->GetTimerFix()->Elapsed();
			// ����ʱ������
			m_AIAtkParam.life_time_skill_tick = m_AIAtkParam.in_fight_tick;
			m_AIAtkParam.time_skill_tick = m_AIAtkParam.in_fight_tick;
		}
	}

	void PlayMonster::LeaveFightState()
	{
		if (mNoTargetTick == 0)
			mNoTargetTick = mGSL->GetTimerFix()->Elapsed();
		if (mGSL->GetTimerFix()->Elapsed() - mNoTargetTick > 5)
		{
			// ����û��Ŀ��,��Ϊ����ս��
			m_AIAtkParam.out_fight_tick = mGSL->GetTimerFix()->Elapsed();
		}
	}

	void PlayMonster::clearExpHiter()
	{
		bool bNotify = false;
		if (m_expHiter.id > 0)
		{
			bNotify = true;
		}
		m_expHiter.id = 0;
		m_expHiter.tick = 0;
		m_expHiter.name = "";

		// ��¼��������
		if (bNotify && !IsNoShowHitter())
		{
			for( DomainPlayVector::iterator pos = mPlayerList.begin();
				pos != mPlayerList.end();)
			{
				if ((*pos))
				{
					(*pos)->NotifyMonExpHiterChange(this, 0, "");
					++pos;
				}
				else
				{
					printf("PlayMonster RecordExpHitter *pos=0\n");
					pos = mPlayerList.erase(pos);
					continue;
				}
			}
		}
	}

	//����Ĺ��
	void PlayMonster::GenTombStone()
	{
		if (m_nTombId == 0)
		{
			MapMonGen* mapMonGen = mGSL->GetMapManager()->GetMapMonGen(mParentMap->GetID(), DefId());
			if (mapMonGen)
			{
				m_nTombId = mGSL->GetMapManager()->GenMon(GetMap(), 11006003, mapMonGen->map_x, mapMonGen->map_y, 1, 1, 1, 1, "landification,dirfixed(4)",1,0,0,0,0,0,Name(),ID());
			}
		}
	}

	//���Ĺ��
	void PlayMonster::CleanTombStone()
	{
		if (m_nTombId > 0)
		{
			mParentMap->ClearNeutralBySeedID(m_nTombId);
			m_nTombId = 0;
		}
	}

	void PlayMonster::SetLockTarget(bool lock)
	{
		m_bLockTarget = lock;
	}

	bool PlayMonster::IsLockTarget()
	{
		return m_bLockTarget;
	}
	//��������Ŀ��
	void PlayMonster::LockTarget(int targetId)
	{
		if (!mParentMap) return;
		PlayActiveObject* activeObj = mParentMap->FindMonsterOrNeutral(targetId);
		if (activeObj)
		{
			Target(activeObj);
			SetLockTarget(true);
		}
	}
}