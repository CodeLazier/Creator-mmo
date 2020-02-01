#pragma once
#include "PlayMonster.h"
#include "leudgrid/MemoryPool.h"

#define HATE_LIST_MAX_PRIORITY 12
#define LOCK_TARGET_TIME 10

namespace OGSLib
{
	enum SlaveType
	{
		Slave_type_dog = 0,
		Slave_type_huwei = 1,
		Slave_type_other = 2,
	};

	class DomainPlay;
	class PlaySlave :
		public PlayAIBase
	{
		friend class ManagerMap;
		friend class DomainPlay;
	public:
		DomainPlay* mOwner;
		bool    mLiving;
		int		mSkill;
		int     mAiType;///ʹ�õ�AI����
		int		mFkAttPlus;
		bool    mAutoFindNext;//�Զ�����
		double  mDelayTick;
		double  mDelayTime;
		double  mGongshaTick;
		double  mLiehuoTick;
		double  mWalkTick;
		int     mLocktarget;
		int		mStartPosX;
		int		mStartPosY;
		int		mMoveRange;
		bool	mNewTarget;

		bool mNameShowOwner;
		// ����
		LEUD_INT64	mExp;
	private:
		// ����AI�߼����
		int				 m_nHateIDList[HATE_LIST_MAX_PRIORITY];	// ������ȼ��б�
		double			 m_dLockTargetTime;						// ������ǰĿ��ʱ��
	public:
		PlaySlave(void);
		virtual ~PlaySlave(void);
		DomainPlay* Owner(){return mOwner;}
		virtual bool IsSlave(){return true;}
		void FindNextTarget(PlayActiveObject* t);
		virtual void FindHateListTarget();
		void Relive(PlayMap* map,int x,int y,int dir);
		virtual int AiIdle();
		int AiIdleZS(double time);//սʿAI
		int AiIdleFS(double time);//��ʦAI
		int AiIdleDS(double time);//��ʿAI
		//int AiIdleHW(double time);//�»���AI
		int AiIdleSZFS(double time);//����ʦ
		int AiType() {return mAiType;}

		// virtual const char * Name();
		virtual int Attacked(PlayActiveObject* src,SkillDef * sd,int pawer,int flags,int delay);
		virtual void AiOther(double time);
		virtual int Update(double time);
		virtual void OnDead(PlayActiveObject* src,int delay);
		virtual bool IsProperAttackDes(PlayActiveObject* des, SkillDef *sd);
		virtual int evaluateWalkDirection(int fromX,int fromY,int dir,int toX,int toY);
		virtual void NotifyBye(PlayMap* map,PlayMapObject* src);
		virtual LEUD_INT64 AddExperience(int ex,int src);
		int CheckLevelUp();
		void SetHateObj(PlayActiveObject * src, bool act, int damage);

		// �����ȼ�,���ó�޸߶���ID
		void SetHateObjID(int priority, int id);
		// �������˱������
		void ChangeAttrByOwnerAttr(MonDef * md);

		int GetSlaveType();

		virtual void NotifyHPMPChange(PlayActiveObject* src,int hp_change,int mp_change);
	};

	class PlayDart2 : public PlaySlave
	{
	public:
		// std::string mDartType;
		int mDartTaskStartTick;
		int mDestroyed;
		int mAlertOut;
		int mCurPathIndex;
		bool mReached;
		int m_nStopX;
		int m_nStopY;
		int m_nLifeTime;
	public:
		PlayDart2(void);
		virtual ~PlayDart2(void);
		virtual int AiIdle();
		// virtual int Update(double time);
		virtual bool DamageHP(PlayActiveObject* src,int damage,int delay, bool safeAreaEnable = false);
		void Destroyed();
		bool IsOwnerCloseMe();
		bool StopPosReached();
		void DropItem();
	};

	class PlaySalveFashi : public PlaySlave
	{
	private:
		bool m_bNoMove;
		bool m_bNoFire;
	public:
		PlaySalveFashi(void);
		virtual ~PlaySalveFashi(void);
		virtual int AiIdle();
		virtual bool IsProperAttackDes(PlayActiveObject* des, SkillDef* sd);
		void SetNoMove(bool nomove) {m_bNoMove = nomove;}
		bool IsNoMove() {return m_bNoMove;}

		void SetNoFire (bool noFire) {m_bNoFire = noFire;}
		bool IsNoFire() {return m_bNoFire;}
	};
	class PlaySlaveStatue : public PlaySlave
	{
	public:
		PlaySlaveStatue(void);
		virtual ~PlaySlaveStatue(void);
		virtual int AiIdle();
		virtual bool IsProperAttackDes(PlayActiveObject* des, SkillDef* sd);
	};
}