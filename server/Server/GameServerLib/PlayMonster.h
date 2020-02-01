#pragma once
#include "PlayAIObject.h"
#include "TimerFix.h"
#include <set>

namespace OGSLib
{
	enum TALKTYPE{
		TALK_NORMAL=0,
		TALK_ATTACK,
		TALK_ATTACKED,
		TALK_HALF_HP,
		TALK_DIE,
	};
	class ScriptLua;
	class SubItem;
	class ManagerMonster;
	class DomainPlay;
	class PlayMonsterCaller;

	class GameServerLib;

	class PlayMonster : public PlayAIBase
	{
		friend class ManagerMap;
	public:
		//typedef std::map<int,int>	HurtRecordMap;
		struct ExpHitter
		{
			int id;
			time_t tick;
			std::string name;
		};
	protected:
		std::string mReliveMap;
		int mReliveDir;
		int mReliveRange;
		double m_ReliveGap;
		double m_ReliveGap2;////����ˢ��ʱ��
		double mTalkTick;
		int mTalkGap;
		int mMonType;
		///////////////////////////////�µĹ���ai  Begin
		int mMabiGap;///������
		int mMabiProb;
		int mPoisonProb;//ʩ�����
		int mPoisonTime;
		int mPoisonDefense;
		int mPoisonDamage;
		int mAoeRange;//��Χ�������
		int mFenshenNum;//�������
		int mFenshenHp;
		int mFenshenMonName;
		bool mFenshenFlag;
		int mRageHp;//�����
		int mRagePowerMul;
		int mRageAttackSpeedMul;
		int mRageRunSpeedMul;
		bool mRageFlag;
		bool mLandification;//ʯ�����
		int mDirFixed;
		bool mDirectDie;
		bool mNoShowHitter;
		
		// �����ٻ����		
		int mCallMonCountOnce;			// �����ٻ�����
		int mCallMonMaxCount;			// ����ٻ�����
		int mCallMonName;				// �ٻ���������
		PlayMonster * mCaller;			// �ٻ�this�Ĺ���
		std::vector<PlayMonster *> mMonstersCalled; // this�ٻ��Ĺ���

		int mSwitchTargetType;			// �л�Ŀ������(2:ʱ��,1:���ֵ)
		int mSwitchTargetInteval;		// �л�Ŀ��ʱ��(����ڷǳ��ѡ��Ŀ��Ĺ�),0���л�Ŀ��
		int mHatredDamageRatio;			// �˺�ϵ��
		int mHatredDistanceRatio;		// �������ϵ��
		double mLastSwitchTargetTick;	// ����л�Ŀ��ʱ��
		int mFollowRange;				// ׷����Χ
		int mNoTargetTick;				// ��¼û��Ŀ���ʱ��
		///////////////////////////////�µĹ���ai  End
		TimerFix   m_ReliveTimer;
		int mNoRilive;

		int mDeathExp;
		int mDropNoOwner;
		int mTeamID;
		int mlimitlv;
		//�������
		int m_nMonGroup;

		int mHurtRecord[10];
		int mHurtRecordID[10];
		int mHurtRecordSeed[10];
		time_t mHurtRecordTick[10];
		ExpHitter m_expHiter;
		int mHurtRecordTime;
		bool mHalfHp;
		double mLastSlowTimer;
		std::vector<MonDropDef>* mDropList;
		std::vector<MonTalkDef>* mTalkList;
		std::vector<NewMonDropDef2>* mDropList2;
		std::map<int,int> mDropGroupRecord;
		int mDeadNum;
		int mDisapearTime;
		int mPowerExp;

		int m_nTombId;

		bool m_bLockTarget;
		/*int m_nDestX;
		int m_nDestY;*/

	public:
		PlayMonster();
		virtual ~PlayMonster(void);
	public:
		int TeamID(){return mTeamID;}
		int GetMonGroup(){return m_nMonGroup;}
		const char* FirstName();
		virtual int DefId(){return mDefId;}
		virtual int  Attacked(PlayActiveObject* src,SkillDef * sd,int pawer,int flags,int delay);
		// virtual bool IsProperAttackDes(PlayActiveObject* des,int param);
		virtual bool IsProperAttackDes(PlayActiveObject* des, SkillDef * sd);
		virtual int Update(double time);
		virtual int State();
		virtual int CollectTime(){return 0;}
		virtual int IsBoss(){ return mMonType == 4002; }
		virtual int IsElite(){ return mMonType == 4003; }
		virtual int getlimitlv(){ return mlimitlv; }
		virtual int DisaperTime();
		virtual int getShowState();
		virtual int GetMabiGap() { return mMabiGap; }
		virtual int GetPoisonTime() { return mPoisonTime; }
		virtual int GetPoisonDefense() { return mPoisonDefense; }
		virtual int GetPoisonDamage() { return mPoisonDamage; }
		virtual void SetPosioner(PlayActiveObject * src);
		virtual bool AddBuff(int id, double param = -1);
		virtual bool AddStatus(int status,int duration,int param,double gap=1.0,int flags=0,int level[]=NULL);
		GameServerLib* gsl(){ return mGSL; }

		bool IsDirFixed();
		bool IsNoShowHitter(){return mNoShowHitter;}
		//�������
		void clearExpHiter();
	protected:
		virtual int AiIdle();
		virtual void AiOther(double time);
		virtual void AiRelive();
		virtual void AiWalk();
		virtual void OnDead(PlayActiveObject* src,int delay);
		virtual int OnSkillAttack(PlayActiveObject* target,SkillDef* sd,SubSkill* ss);
	public:
		virtual void NotifyMeet(PlayMap* map,PlayMapObject* src);
		virtual void NotifyBye(PlayMap* map,PlayMapObject* src);
		virtual void NotifyWalk(PlayMapObject* src,int dir,int newx,int newy);
		virtual void NotifyRun(PlayMapObject* src,int dir,int newx,int newy);
		void ClearDie();
		int PlayMonster::GetDeathExp();
		int PlayMonster::GetPowerExp(){return mPowerExp;}
		void IncCallMon(PlayMonster * monCalled);
		void DecCallMon(PlayMonster * monCalled);
		int GetCallMonCountOnce() {return mCallMonCountOnce;};
		int GetCallMonMaxCount() {return mCallMonMaxCount;}
		int GetCallMonCurCount() {return mMonstersCalled.size();}
		int GetCallMonName() {return mCallMonName;}
		//֪ͨ����src����
		void NotifyClearYingShen(PlayMapObject* src);
		// ��ȡ��������
		void GetExpHitter(int& id, std::string& name);

		int GetExpHitterId();

		//����Ĺ��
		void GenTombStone();
		//���Ĺ��
		void CleanTombStone();

		//��ȡʣ��ˢ��ʱ��
		//double GetRefreshRemain(){return m_ReliveGap - m_ReliveTimer.Elapsed();}

		//����Ŀ�����
		void SetLockTarget(bool lock);
		bool IsLockTarget();
		void LockTarget(int targetId);

		//void SetDestination(int x, int y) {m_nDestX = x; m_nDestY = y;};
	protected:
		void Relive();
		void ClearHurtRecord();
		void RecordExpHitter(PlayActiveObject* src);
		void RecordHurtRecord(int src_id, int pawer, int seed);
		bool IsDesYinShen(PlayActiveObject* src);
		virtual void CheckTarget(PlayMapObject* src,int newx,int newy);
		void DropItem(DomainPlay* play);
		//void DropItem2(DomainPlay* play);
		//void DropItem2(DomainPlay* play,NewMonDropDef* pos);
		void DropItem3(DomainPlay* play);
		void DropItem3(std::set<DomainPlay *>& players);
		bool check_drop_group(int group_id,int select,int randmax);
		void RandTalk(int flags);
		void GiveExperience(DomainPlay* player);
		DomainPlay* FindDeadOwner();
		unsigned int FindMaxHurt();
		void SwitchTarget();
		void SwitchTarget(PlayActiveObject * target);

		std::set<DomainPlay *> GetHurtPlayers();

		// ����ս��״̬
		void EnterFightState();
		// �뿪ս��״̬
		void LeaveFightState();
	};
}