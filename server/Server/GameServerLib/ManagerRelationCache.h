#pragma once
#include "leudgrid/MemoryPool.h"
#include <string>
#include <map>

namespace OGSLib
{
	class GameServerLib;
	class DomainPlay;
	// ������Ʒ��Ϣ
	class RelationShipOper : public LEUD::PoolMemoryBase< RelationShipOper >
	{
	public:
		// ����������
		std::string name_oper;
		// �������seed_name
		std::string name;
		// ��������
		int title;
		// ʱ��
		time_t time;
	public:
		RelationShipOper();
	};

	class ManagerRelationCache
	{
	public:
		// first ������
		typedef std::map<std::string, RelationShipOper *> RelationShipOperMap;
		// first ��������
		typedef std::map<std::string, RelationShipOperMap> ChrRelationShipOpersMap;
	public:
		ManagerRelationCache(GameServerLib* gslib);
		virtual ~ManagerRelationCache(void);

		void PushCache(std::string name, std::string name_oper, int title);
		bool PopCache(std::string ame, RelationShipOper & oper);
		RelationShipOper * FindOperCache(std::string name, std::string name_oper);
		void init();
		void update();
		void dest(bool save=true);
		void LoadRelationCache();
		void SaveRelationCache();
		void OnLoadRelationCache(std::vector<RelationShipOper *> vec);
		void CopyRelationOperData(std::vector<RelationShipOper *> &vec);
	private:
		GameServerLib* mGameServerLib;
		ChrRelationShipOpersMap mOperateMap;
		time_t mSaveTick;
	};
}