#pragma once

namespace OGSLib
{
	struct MonDef
	{
		int id; //��ʶid
		int res_id; //ģ��
		int weapon;
		int wing;
		char name[64];
		char nodigital_name[64];
		char script[64]; //ˢ�´����ű�
		std::string ai;
		int atk_ai;		 // ����ai
		int effect_type; //��������
		int effect_res; //������Դ
		int appr; //Ŀ����Ч
		int lvl;
		int zslevel;
		int cooleye; //��Ұ��Χ
		int exp;
		int power_exp;

		int hp;
		int mp;
		int ac;
		int acMax;
		int mac;
		int macMax;
		int dc;
		int dcMax;
		int mc;
		int mcMax;
		int dodge; //����
		int accuracy; //����
		int walk_gap; //��С�ȴ�ʱ��
		int walk_gap2; //���ȴ�ʱ��
		int walk_step; //ÿ��walk�Ĳ������Է�Ҫ��ÿ������ʱ��

		int attack_spd; // �������
		int head_icon; //ͷ����Դ
		int talk_gap; //˵�����
		int mon_type; //��������
		int drop_group; //������id
		int patrol_range; //Ѳ�߷�Χ
		int fllow_range; //׷����Χ
		int no_hit; //�Ƿ����Ұ��
		// �л�Ŀ������
		int switch_target_type;
		// �л�Ŀ��ʱ��,ֵΪ0���л�Ŀ��
		int switch_target_inteval;
		// ����˺�ϵ��,Ĭ��1
		int hatred_damage_ratio;
		// ������ϵ��,Ĭ��0
		int hatred_distance_ratio;
		// ׷����Χ

		// �̶�����
		int dirFixed;

		std::string mapName; //��ͼ
		int mType; //��λ����

		//�������
		int monGroup;

		//���͵�id
		int teleportID;
		//Ѳ���ٶ�
		int patrolTime;
		//ʬ����ʧʱ��
		int deadTime;
		//ˢ��ʱ��
		int refreshTime;
		//������
		int CRIRate;
		//������
		int DUCrate;
		//����������
		int ADTR;
		//ħ������
		int MR;
		//��Ѫ�ٶ�
		int HPup;
		//�Ƿ���ʾˢ�¹���
		int isShowRefresh;
		//�Ƿ���ʾ���乫��
		int isShowDrop;
		// boss����
		int BossPt;
		int title;
		int colltime;
		int no_show_hitter;
		// bossͷ��
		std::string BossHead;
		//����ID	
		std::string funcid;
		//���ܲ���
		std::string funcparams;
		//Ĭ�϶Ի�	
		std::string dialog;
		//�Ƿ�Ằ��	
		int canSpeak;
		//�������	
		std::string randomDialog;
		//�򵥵���ID
		int simpleDropID;	
		//�����Ƿ���ʾĹ��
		int isShowTomb;
	};
	struct MonDropDef
	{
		int selNum;
		int maxNum;
		int item_id;
		int count;
		int bind;
		int use_bind;
		int start_drop_day;
	};
	struct NewMonDropDef
	{
		int item_id;
		int count;
		int bind;
		int use_bind;
		NewMonDropDef()
		{
			item_id=0;
			count=0;
			bind=0;
			use_bind=0;
		}
	};
	struct MonDropGroup
	{
		int group_id;
		int select;
		int randmax;
		int randed;
		int passed;
		std::vector<NewMonDropDef> drop;
	};
	struct MonTalkDef
	{
		int prob;
		std::string msg;
	};
	struct NewMonDropDef2
	{
		int group_id;
		int gold_min;
		int gold_max;
		int item_id;
		std::vector<int> drop_plus;
		int drop_prob;
		int bind;
		int owned_duration;
		int start_drop_day;
	};
	struct MonAtkAI
	{
		int id;
		std::string strDesc;
		// Ĭ�ϼ���
		int default_skill;
		// ���뼼��
		int dis_skill_min;
		// ���뼼��id
		int dis_skill;
		// ���ʼ���
		int rate_skill;
		// ���ʼ��ܸ���(��ֱ�)
		int rate_skill_rate;
		// ʱ�似��id
		int time_skill;
		// ����ս��ʱ��(ms)
		int time_skill_need;
		// ��Ѫʱ�似��
		int life_time_skill;
		// ��Ѫʱ�似��ʱ��
		int life_time_skill_time;
		// ��Ѫʱ�似��Ѫ������
		int life_time_skill_life_rate;
		// ��Ѫ����
		int life_skill;
		// ��Ѫ����Ѫ������
		double life_left_rate;
		int max_life_skill_cout;

		std::string around_kind;
		std::string first_attack_kind;
		// �л�Ŀ������
		int switch_target_type;
		// ����˺�ϵ�� / �л�Ŀ��ʱ��,ֵΪ0���л�Ŀ��
		int switch_target_param;
		// ������ϵ��
		int hatred_distance_ratio;

		MonAtkAI()
		{
			id = 0;
			default_skill = 0;
			dis_skill_min = 0;
			dis_skill = 0;
			rate_skill = 0;
			rate_skill_rate = 0;
			time_skill = 0;
			time_skill_need = 0;
			life_skill = 0;
			life_left_rate = 0;
			max_life_skill_cout = 0;
			switch_target_type = 0;		// 1 ���ֵ���� 2 ʱ�����
			switch_target_param = 0;
			hatred_distance_ratio = 0;
			life_time_skill = 0;
			life_time_skill_life_rate = 0;
			life_time_skill_time = 0;
		}
	};

	class GameServerLib;
	class ManagerMonDef
	{
		typedef std::map<int,MonDef> MondefMap;
		typedef std::map<int,std::vector<MonDropDef> > MonDropDefMap;
		typedef std::map<int,std::vector<MonDropGroup> > MonDropGroupDefMap;
		typedef std::map<int,std::vector<MonTalkDef> > MonTalkDefMap;

		typedef std::map<int,std::vector<NewMonDropDef2>> NewMonDropGroupMap;
		typedef std::map<int,std::vector<NewMonDropDef2>> NewMonDropGroupMap2;

		typedef std::vector<int> DropPlus;
		typedef std::map<int,DropPlus> MonDropPlusMap;

		typedef std::map<int,MonAtkAI> MonAIMap;

		MondefMap mMondefs;
		MonAIMap m_monAIs;
		//MonDropDefMap mMonDropDefs;
		//MonDropGroupDefMap mMonDropGroups;
		//MonTalkDefMap mMonTalkDefs;
		
		MonDropPlusMap mMonDropPlusMap;
		NewMonDropGroupMap mNewMonDropGroups;
		NewMonDropGroupMap2 mNewMonDropGroupItem;

		GameServerLib* mGameServerLib;
	public:
		ManagerMonDef(GameServerLib* gslib);
		virtual ~ManagerMonDef(void);
		
		bool init();
		void dest();
		bool ReloadMonAIDef();
		void ReloadMonDropDef();
		bool ReloadMonDropDef(std::string name);

		bool LoadDropPlusCsv();
		bool LoadMonDropCsv();
		bool LoadMonAICsv();

		MonDef* FindMonDef(int id);
		std::vector<MonDropDef>* FindMonDropDef(int mon_id);
		std::vector<MonDropGroup>* FindMonDropGroupDef(int mon_id);
		std::vector<NewMonDropDef2>* FindNewMonDropGroupDef2(int mon_id);
		std::vector<MonTalkDef>* FindMonTalkDef(int mon_id);

		MonAtkAI * FindAtkAI(int ai_id);
	private:
		void LoadMonDropDef(int mon_id);
		void LoadMonTalkDef(int mon_id);
		void LoadNewMonDropDef(int mon_id);

	};
}