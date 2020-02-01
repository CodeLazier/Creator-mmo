#pragma once
#include "SubItem.h"
#include "leudgrid/MemoryPool.h"
#include <set>

namespace OGSLib
{
	class GameServerLib;
	class DomainPlay;
	// ������Ʒ��Ϣ
	class ConsignableItemInfo : public LEUD::PoolMemoryBase< ConsignableItemInfo >
	{
	public:
		int seed_id;
		SubItem item;
		std::string seller_seed_name;
		std::string seller_name;
		// ���۽���ʱ��
		time_t end_time;
		// ��Ʒ���
		int price;

		// �����ȼ�Ȩֵ,����ʹ��
		int dress_weight;
		// ����λ��Ȩֵ
		int equiptype_weight;

		//���ַ�����,����ʹ��
		std::wstring ws_item_name;
	public:
		ConsignableItemInfo();

		bool operator >=(const ConsignableItemInfo val) const;
	};

	class ManagerConsignment
	{
	public:
		typedef std::vector<ConsignableItemInfo *> ConsignableItemList;
		typedef std::map<std::string, int> UserVCoinMap;
	public:
		ManagerConsignment(GameServerLib* gslib);
		virtual ~ManagerConsignment(void);

		int ConsignItem(DomainPlay * src, SubItem * item, int count, int price, int duration_hour);
		int BuyConsignableItem(DomainPlay * src, int seed_id);
		int TakeBackConsignableItem(DomainPlay * src, int seed_id);
		int TakeBackVCoin(DomainPlay * src);
		int GetVCoin(DomainPlay * src);
		void GetConsignableItems(DomainPlay * src, int type, int begin_index, int job, int condition, std::string filter, std::vector<ConsignableItemInfo *>& vec, std::vector<int>& index_list);
		
		void init();
		void update();
		void dest(bool save=true);
		void LoadConsignment();
		bool OnLoadConsignment(const std::vector<ConsignableItemInfo *>& consignmentVector, UserVCoinMap& user_vcoin_map);
		void SaveConsignment();
		ConsignableItemList & GetConsignableItemInfoList() {return mItemAllInfos;};
		ConsignableItemList & GetOverTimeItemInfoList() {return mItemOverTime;};
		UserVCoinMap& GetVCoinMap() {return mVcoinMap;};
	private:
		void AddConsignableItem(ConsignableItemInfo * pItem);
		// ������Ʒ,ֻ�ڼ����б������
		ConsignableItemInfo * FindConsignableItem(int seed_id);
		// ֻɾ��,���ͷ�
		void DelConsignableItem(ConsignableItemInfo * pItem);

		size_t GetInsertPos(ConsignableItemList & v, ConsignableItemInfo * key);

		void UpdateItemsOverTime();
	private:
		GameServerLib* mGameServerLib;
		// ������������Ʒ
		ConsignableItemList mItemAllInfos;
		// װ��
		ConsignableItemList mItemsEquip;
		// ҩƷ
		ConsignableItemList mItemsEatable;
		// ����
		ConsignableItemList mItemsMaterial;
		// ����
		ConsignableItemList mItemsOther;
		// �����Ʒ
		std::map<std::string, ConsignableItemList> mUserItemMap;
		// ������Ʒ
		ConsignableItemList mItemOverTime;
		
		// ������Ʒ����
		UserVCoinMap mVcoinMap;

		time_t mSaveTick;
		time_t mUpdateTick;
	/*������־������:*/
	/*
		0:��������̵�
		1:����
		2:ȡ��
	*/
		static int m_seed_id;
	};
}