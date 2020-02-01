#pragma once

namespace OGSLib
{
	struct TrapDef
	{
		// id
		int id;
		// ���
		int cloth;
		// ������Чid
		int effect_id;
		// ����ʱ��s
		int life_time;
		// ��������ms
		int damage_gap;
		// �����˺�ֵ
		int damage;
		// �˺�����(����)
		int skill_type;
		// �����ٻ����뿪ɾ��
		bool caller_leave_remove;

		std::string name;
	};

	class GameServerLib;
	class ManagerTrapDef
	{
		typedef std::map<int,TrapDef> TrapMap;

		GameServerLib* mGameServerLib;
	public:
		ManagerTrapDef(GameServerLib* gslib);
		virtual ~ManagerTrapDef(void);
		
		bool init();
		void dest();

	private:
		TrapMap mTraps;
	};
}