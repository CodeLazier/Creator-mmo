#pragma once
#include "PlayMapObject.h"
#include "leudgrid/MemoryPool.h"
namespace OGSLib
{
	enum EnumTrapTypeId
	{
		eTrapIdMapConn =0,
		eTrapIdHuoQiang,
		eTrapIdEnd,
		eTrapIdUserEefBegin = 10000,
	};

	struct TrapDef;

	// ������(��ǽ...�ͷ��ڵ���������˺�)
	class PlayMapTrap :
		public PlayMapObject,
		public LEUD::PoolMemoryBase< PlayMapTrap >
	{
		std::string mName;

		PlayActiveObject * mCaller;
		int mPickLimitLv;
		// ����ʱ��s
		int mLifeTime;
		// ��������ms
		int mDamageGap;
		// �����˺�ֵ
		int mDamage;
		// �˺�����
		int mSkillType;
		// ������Чid
		int mEffect;
		// ��������id
		int mTrapTypeID;

		bool mCallerLeaveRemove;
	private:
		// 0 ����
		int mTriggerTimes;
		bool mLifeTimeRemove;
	public:
		PlayMapTrap(int x,int y, TrapDef * def, PlayActiveObject * caller);
		virtual ~PlayMapTrap(void);
	public:
		void ClearCaller();
		int GetTrapTypeId();
		void ClothID(int id){mCloth = id;}
		bool GetCallerLeaveRemove();
		void RemoveFromMap();
		void OnTrapGap();
		virtual const char* Name();
		virtual int Hp(){return 0;}
		virtual int MaxHp(){return 0;}
		virtual int Power(){return 0;}
		virtual int DefId(){return mTrapTypeID;}
	public:
		virtual void OnSecondTimer(int param);
	public:
		virtual void NotifyMapEnter(PlayMap* map);
		virtual void NotifyMeet(PlayMap* map,PlayMapObject* src){};
		virtual void NotifyMapLeave(PlayMap* map);
		virtual void NotifyBye(PlayMap* map,PlayMapObject* src){}
		virtual void NotifyAvatarChange(PlayMapObject* src){}

		virtual void NotifyWalkOut(PlayActiveObject* src);
		virtual void NotifyWalkIn(PlayActiveObject* src);
	};
}