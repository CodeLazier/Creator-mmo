#include "StdAfx.h"
#include "ConstsString.h"
#include "leudgrid/ToolsMemFile.h"
#include "GameServerLib.h"

namespace OGSLib
{
	bool ConstsString::Load(GameServerLib* gslib)
	{
		char temp[1024];
		size_t size= 0;
		const char* data = gslib->GetListener()->LoadFile("infostring.txt",size);
		if( data && size > 0 )
		{
			LEUD::ToolsMemFile f(data,size);
			char line[1204];
			char key[1024];
			char value[1024];
			while( f.read_line(line,1024) )
			{
				if( line[0]!=0 )
				{
					if( line[0] == '#' || line[0] == ';' )
					{
						continue;
					}
					if( 2 == sscanf_s(line,"%[^=]=%[^\"]",key,_countof(key),value,_countof(value)) )
					{
						UtilString::act_2_utf8(value,strlen(value),temp,1024);
						strcpy_s(value,temp);
						mStringMap[key]=value;
					}
				}
			}
		}
		reload_key(NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP,"NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP");
		reload_key(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY,"NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY");
		reload_key(NOTIFY_BING_ITEM_LIMIT,"NOTIFY_BING_ITEM_LIMIT");
		reload_key(NOTIFY_BEYOND_ONSALE_LIMIT,"NOTIFY_BEYOND_ONSALE_LIMIT");
		reload_key(NOTIFY_ONSALE_TIME_ERROR,"NOTIFY_ONSALE_TIME_ERROR");
		reload_key(NOTIFY_ONSALE_ITEM_MISS,"NOTIFY_ONSALE_ITEM_MISS");
		reload_key(NOTIFY_ONSALE_MAX_LIMIT,"NOTIFY_ONSALE_MAX_LIMIT");
		reload_key(NOTIFY_ONSALE_PUT_SUC,"NOTIFY_ONSALE_PUT_SUC");
		reload_key(NOTIFY_ONSALE_OWNER_OFFLINE,"NOTIFY_ONSALE_OWNER_OFFLINE");
		reload_key(NOTIFY_ONSALE_MIN_LEVEL_LIMIT,"NOTIFY_ONSALE_MIN_LEVEL_LIMIT");
		reload_key(NOTIFY_ONSALE_ITEM_SUC,"NOTIFY_ONSALE_ITEM_SUC");
		reload_key(NOTIFY_ONSALE_ITEM_CANNOT,"NOTIFY_ONSALE_ITEM_CANNOT");
		reload_key(NOTIFY_ONSALE_FREE_LIMIT,"NOTIFY_ONSALE_FREE_LIMIT");
		reload_key(NOTIFY_ONSALE_MONEY_LIMIT,"NOTIFY_ONSALE_MONEY_LIMIT");
		reload_key(NOTIFY_MERGE_FASHION_CONDITION_FAIL,"NOTIFY_MERGE_FASHION_CONDITION_FAIL");
		reload_key(NOTIFY_MERGE_XYFASHION_CONDITION_FAIL,"NOTIFY_MERGE_XYFASHION_CONDITION_FAIL");
		reload_key(NOTIFY_ITEM_DESTORY_LIMIT_FAIL,"NOTIFY_ITEM_DESTORY_LIMIT_FAIL");
		reload_key(NOTIFY_SPLIT_BAG_FULL_FAIL,"NOTIFY_SPLIT_BAG_FULL_FAIL");
		reload_key(NOTIFY_MAIL_RECEIVE_SUC,"NOTIFY_MAIL_RECEIVE_SUC");
		reload_key(NOTIFY_MAIL_HAVE_RECEIVED,"NOTIFY_MAIL_HAVE_RECEIVED");
		reload_key(NOTIFY_MAIL_DELETE_SUC,"NOTIFY_MAIL_DELETE_SUC");
		reload_key(NOTIFY_MAIL_EXCEED_MAX_LENGTH,"NOTIFY_MAIL_EXCEED_MAX_LENGTH");
		reload_key(NOTIFY_MAIL_DELETE_UNRECEIVED,"NOTIFY_MAIL_DELETE_UNRECEIVED");
		reload_key(NOTIFY_MAIL_NOT_EXIST,"NOTIFY_MAIL_NOT_EXIST");
		reload_key(NOTIFY_BAG_BLANK_NOT_ENOUGH,"NOTIFY_BAG_BLANK_NOT_ENOUGH");
		reload_key(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND,"NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND");
		reload_key(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN,"NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN");
		reload_key(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND,"NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND");
		reload_key(NOTIFY_USE_TIEM_LIMIT_ERROR,"NOTIFY_USE_TIEM_LIMIT_ERROR");
		reload_key(NOTIFY_ZHUANSHENG_LEVEL_LIMIT,"NOTIFY_ZHUANSHENG_LEVEL_LIMIT");
		//reload_key(NOTIFY_USE_ITEM_LIMIT_MAXLOAD,"NOTIFY_USE_ITEM_LIMIT_MAXLOAD");
		//reload_key(NOTIFY_USE_ITEM_LIMIT_MAXBRAWN,"NOTIFY_USE_ITEM_LIMIT_MAXBRAWN");
		reload_key(NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR,"NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR");
		reload_key(NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY,"NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY");
		reload_key(NOTIFY_NOT_ENOUPH_MP,"NOTIFY_NOT_ENOUPH_MP");
		reload_key(NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP,"NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP");
		reload_key(NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN,"NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN");
		reload_key(NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP,"NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP");
		reload_key(NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE,"NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE");
		reload_key(NOTIFY_DROP_ITEM_CAN_NOT_BIND,"NOTIFY_DROP_ITEM_CAN_NOT_BIND");
		reload_key(NOTIFY_TRADE_ITEM_CAN_NOT_BIND,"NOTIFY_TRADE_ITEM_CAN_NOT_BIND");
		reload_key(NOTIFY_CHAT_TOO_QUICK,"NOTIFY_CHAT_TOO_QUICK");
		reload_key(NOTIFY_SKILL_YEMAN_FALIED,"NOTIFY_SKILL_YEMAN_FALIED");
		reload_key(NOTIFY_SKILL_CISHAJIANSHU_OPEN,"NOTIFY_SKILL_CISHAJIANSHU_OPEN");
		reload_key(NOTIFY_SKILL_CISHAJIANSHU_CLOSE,"NOTIFY_SKILL_CISHAJIANSHU_CLOSE");
		reload_key(NOTIFY_SKILL_BANYUEWANDAO_OPEN,"NOTIFY_SKILL_BANYUEWANDAO_OPEN");
		reload_key(NOTIFY_SKILL_BANYUEWANDAO_CLOSE,"NOTIFY_SKILL_BANYUEWANDAO_CLOSE");
		reload_key(NOTIFY_SKILL_LIEHUOJIANFA_OK,"NOTIFY_SKILL_LIEHUOJIANFA_OK");
		reload_key(NOTIFY_SKILL_COLDING,"NOTIFY_SKILL_COLDING");
		reload_key(NOTIFY_SKILL_SHUNJIANYIDONG_FAILED,"NOTIFY_SKILL_SHUNJIANYIDONG_FAILED");
		reload_key(NOTIFY_MERDER,"NOTIFY_MERDER");
		reload_key(NOTIFY_PK_KILLED,"NOTIFY_PK_KILLED");
		reload_key(NOTIFY_PK_MAP_NOT_MERDER,"NOTIFY_PK_MAP_NOT_MERDER");
		reload_key(NOTIFY_MAP_PK_PROHIBIT,"NOTIFY_MAP_PK_PROHIBIT");
		reload_key(NOTIFY_MAPTIME_PK_PROHIBIT, "NOTIFY_MAPTIME_PK_PROHIBIT");
		reload_key(NOTIFY_TRADE_TOO_FAR,"NOTIFY_TRADE_TOO_FAR");
		reload_key(NOTIFY_TRADE_CAN_NOT_AUTH_TYPE,"NOTIFY_TRADE_CAN_NOT_AUTH_TYPE");
		reload_key(NOTIFY_TRADE_CAN_NOT_LEVEL,"NOTIFY_TRADE_CAN_NOT_LEVEL");
		reload_key(NOTIFY_ITEM_USE_TIME_TOO_SHORT,"NOTIFY_ITEM_USE_TIME_TOO_SHORT");
		reload_key(NOTIFY_BAG_USE_ITEM_MAP_DISABLED,"NOTIFY_BAG_USE_ITEM_MAP_DISABLED");
		reload_key(NOTIFY_SKILL_MAP_DISABLED,"NOTIFY_SKILL_MAP_DISABLED");
		reload_key(NOTIFY_MERGESTEEL_SUC,"NOTIFY_MERGESTEEL_SUC");
		reload_key(NOTIFY_MERGESTEEL_FAL,"NOTIFY_MERGESTEEL_FAL");
		reload_key(NOTIFY_UPGRADEEQUIP_SUC,"NOTIFY_UPGRADEEQUIP_SUC");
		reload_key(NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT,"NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT");
		reload_key(NOTIFY_QILING_SUC,"NOTIFY_QILING_SUC");
		reload_key(NOTIFY_QILING_FULL,"NOTIFY_QILING_FULL");
		reload_key(NOTIFY_UPGRADEEQUIP_FAL,"NOTIFY_UPGRADEEQUIP_FAL");
		reload_key(NOTIFY_NOENOUGHMONEY_FAL,"NOTIFY_NOENOUGHMONEY_FAL");
		reload_key(NOTIFY_UPGRADE_MATCHSTONE_FAL,"NOTIFY_UPGRADE_MATCHSTONE_FAL");
		reload_key(NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT,"NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT");
		reload_key(NOTIFY_BUY_ITEM_NOT_YOUKE,"NOTIFY_BUY_ITEM_NOT_YOUKE");
		reload_key(NOTIFY_SKILL_YOULINGDUN,"NOTIFY_SKILL_YOULINGDUN");
		reload_key(NOTIFY_SKILL_SHENGZHANJIASHU,"NOTIFY_SKILL_SHENGZHANJIASHU");
		reload_key(NOTIFY_WORLD_CHAT_LEVEL_LIMIT,"NOTIFY_WORLD_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_GROUP_CHAT_LEVEL_LIMIT,"NOTIFY_GROUP_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_GUILD_CHAT_LEVEL_LIMIT,"NOTIFY_GUILD_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_MAP_CHAT_LEVEL_LIMIT,"NOTIFY_MAP_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT,"NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_HORN_CHAT_LEVEL_LIMIT,"NOTIFY_HORN_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_NORMAL_CHAT_LEVEL_LIMIT,"NOTIFY_NORMAL_CHAT_LEVEL_LIMIT");
		reload_key(NOTIFY_LOGIN_ANOTHER_PLACE,"NOTIFY_LOGIN_ANOTHER_PLACE");
		reload_key(NOTIFY_FRESH_VCOIN_WAIT,"NOTIFY_FRESH_VCOIN_WAIT");
		reload_key(NOTIFY_KICK_BUY_GM,"NOTIFY_KICK_BUY_GM");
		reload_key(NOTIFY_TALK_PROHIBITED,"NOTIFY_TALK_PROHIBITED");
		reload_key(NOTIFY_TALK_ALLOWED,"NOTIFY_TALK_ALLOWED");
		reload_key(NOTIFY_PK_KILL,"NOTIFY_PK_KILL");
		reload_key(NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD,"NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD");
		reload_key(NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD,"NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD");
		reload_key(NOTIFY_CONGZI_INFO,"NOTIFY_CONGZI_INFO");
		reload_key(NOTIFY_ADD_FRIEND_NO_EXIST,"NOTIFY_ADD_FRIEND_NO_EXIST");
		reload_key(NOTIFY_CHECK_EQUIP_NO_EXIST,"NOTIFY_CHECK_EQUIP_NO_EXIST");
		reload_key(NOTIFY_BUY_ITEM_BAG_FULL,"NOTIFY_BUY_ITEM_BAG_FULL");
		reload_key(NOTIFY_ITEM_BAG_FULL,"NOTIFY_ITEM_BAG_FULL");
		reload_key(NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN,"NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN");
		reload_key(NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE,"NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE");
		reload_key(NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE,"NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE");
		reload_key(NOTIFY_GROUP_MEMBER_ADD,"NOTIFY_GROUP_MEMBER_ADD");
		reload_key(NOTIFY_JOIN_GROUP,"NOTIFY_JOIN_GROUP");
		reload_key(NOTIFY_GROUP_MEMBER_REM,"NOTIFY_GROUP_MEMBER_REM");
		reload_key(NOTIFY_LEAVE_GROUP,"NOTIFY_LEAVE_GROUP");
		reload_key(NOTIFY_TRADE_FAIL,"NOTIFY_TRADE_FAIL");
		reload_key(NOTIFY_TRADE_SUC,"NOTIFY_TRADE_SUC");
		reload_key(NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR,"NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR");
		reload_key(NOTIFY_TRADE_PLAYER_OFFLINE,"NOTIFY_TRADE_PLAYER_OFFLINE");
		reload_key(NOTIFY_CHATTRADE_MYSELF,"NOTIFY_CHATTRADE_MYSELF");
		reload_key(NOTIFY_CHATTRADE_FAIL,"NOTIFY_CHATTRADE_FAIL");
		reload_key(NOTIFY_CHANGE_ATTACK_MODE_FAIL,"NOTIFY_CHANGE_ATTACK_MODE_FAIL");
		reload_key(NOTIFY_MAP_NOGOD, "NOTIFY_MAP_NOGOD");
		reload_key(NOTIFY_CHATTRADE_BAGFULL, "NOTIFY_CHATTRADE_BAGFULL");
		reload_key(NOTIFY_CHATTRADE_ADDITEM_SUC,"NOTIFY_CHATTRADE_ADDITEM_SUC");
		reload_key(NOTIFY_NO_FRIEND_ONLINE, "NOTIFY_NO_FRIEND_ONLINE");
		reload_key(NOTIFY_CHATTRADE_ADDITEM_FAIL,"NOTIFY_CHATTRADE_ADDITEM_FAIL");
		reload_key(NOTIFY_CHATTRADE_SUBITEM_SUC,"NOTIFY_CHATTRADE_SUBITEM_SUC");
		reload_key(NOTIFY_CHATTRADE_SUBITEM_NOITEM,"NOTIFY_CHATTRADE_SUBITEM_NOITEM");
		reload_key(NOTIFY_CHATTRADE_SUBITEM_FAIL,"NOTIFY_CHATTRADE_SUBITEM_FAIL");
		reload_key(NOTIFY_CHATTRADE_MONEY_NOTENOUGH,"NOTIFY_CHATTRADE_MONEY_NOTENOUGH");
		reload_key(NOTIFY_HUICHENGSHI_CISHU, "NOTIFY_HUICHENGSHI_CISHU");
		reload_key(NOTIFY_SLAVE_AI_OPEN,"NOTIFY_SLAVE_AI_OPEN");
		reload_key(NOTIFY_SLAVE_AI_CLOSE,"NOTIFY_SLAVE_AI_CLOSE");
		reload_key(NOTIFY_GUILD_CREATE_EMPTY_NAME,"NOTIFY_GUILD_CREATE_EMPTY_NAME");
		reload_key(NOTIFY_GUILD_CREATE_TOO_LONG_NAME,"NOTIFY_GUILD_CREATE_TOO_LONG_NAME");
		reload_key(NOTIFY_GUILD_CREATE_NAME_PROHIBITED,"NOTIFY_GUILD_CREATE_NAME_PROHIBITED");
		reload_key(NOTIFY_GUILD_CREATE_EXIST_NAME,"NOTIFY_GUILD_CREATE_EXIST_NAME");
		reload_key(NOTIFY_GUILD_CREATE_CONDITION_FAIL,"NOTIFY_GUILD_CREATE_CONDITION_FAIL");
		reload_key(NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR,"NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR");
		reload_key(NOTIFY_GUILD_CREATE_HAVE_GUILD,"NOTIFY_GUILD_CREATE_HAVE_GUILD");
		reload_key(NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR,"NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR");
		reload_key(NOTIFY_GUILD_JOIN_HAVED,"NOTIFY_GUILD_JOIN_HAVED");
		reload_key(NOTIFY_GUILD_JOIN_NOT_EXIST,"NOTIFY_GUILD_JOIN_NOT_EXIST");
		reload_key(NOTIFY_GROUP_MEMBER_ONLINE,"NOTIFY_GROUP_MEMBER_ONLINE");
		reload_key(NOTIFY_GROUP_MEMBER_OFFLINE,"NOTIFY_GROUP_MEMBER_OFFLINE");
		reload_key(NOTIFY_GUILD_MEMBER_ENTERING,"NOTIFY_GUILD_MEMBER_ENTERING");
		reload_key(NOTIFY_GUILD_ADD_PRESIDENT, "NOTIFY_GUILD_ADD_PRESIDENT");
		reload_key(NOTIFY_GUILD_SUB_PRESIDENT, "NOTIFY_GUILD_SUB_PRESIDENT");
		reload_key(NOTIFY_GUILD_BECOME_ADMIN, "NOTIFY_GUILD_BECOME_ADMIN");
		reload_key(GUILD_RED_PACKET_MAIL_TITLE, "GUILD_RED_PACKET_MAIL_TITLE");
		reload_key(GUILD_RED_PACKET_MAIL_CONTENT, "GUILD_RED_PACKET_MAIL_CONTENT");
		reload_key(NOTIFY_UPGRADEEQUIP_BREAK,"NOTIFY_UPGRADEEQUIP_BREAK");
		reload_key(NOTIFY_SAFEAREA_ENTER,"NOTIFY_SAFEAREA_ENTER");
		reload_key(NOTIFY_SAFEAREA_LEAVE,"NOTIFY_SAFEAREA_LEAVE");
		reload_key(NOTIFY_STATUS_NO_DAMAGE,"NOTIFY_STATUS_NO_DAMAGE");
		reload_key(NOTIFY_STATUS_NO_DROP_ON_DIE,"NOTIFY_STATUS_NO_DROP_ON_DIE");
		reload_key(NOTIFY_PK_LEVEL_LIMIT,"NOTIFY_PK_LEVEL_LIMIT");
		reload_key(NOTIFY_IN_CHINA_LIMIT,"NOTIFY_IN_CHINA_LIMIT");
		reload_key(NOTIFY_GUILD_FULL,"NOTIFY_GUILD_FULL");
		reload_key(NOTIFY_GUILD_WAR_START,"NOTIFY_GUILD_WAR_START");
		reload_key(NOTIFY_RELIVE_STAND_NOT_ALLOW,"NOTIFY_RELIVE_STAND_NOT_ALLOW");
		reload_key(NOTIFY_GUILD_CREATE_LEVEL_LIMIT,"NOTIFY_GUILD_CREATE_LEVEL_LIMIT");
		reload_key(NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP,"NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP");
		reload_key(NOTIFY_GUILD_JOIN_LEVEL_LIMIT,"NOTIFY_GUILD_JOIN_LEVEL_LIMIT");
		reload_key(NOTIFY_SERVER_FULL,"NOTIFY_SERVER_FULL");
		reload_key(NOTIFY_STEEL_EQUIP_NO_MONEY,"NOTIFY_STEEL_EQUIP_NO_MONEY");
		reload_key(NOTIFY_STEEL_EQUIP_NO_BAG_ROOM,"NOTIFY_STEEL_EQUIP_NO_BAG_ROOM");
		reload_key(NOTIFY_STEEL_EQUIP_NO_LEVEL,"NOTIFY_STEEL_EQUIP_NO_LEVEL");
		reload_key(NOTIFY_STEEL_EQUIP_SUC,"NOTIFY_STEEL_EQUIP_SUC");
		reload_key(NOTIFY_ITEM_USE_BROKE,"NOTIFY_ITEM_USE_BROKE");
		reload_key(NOTIFY_ITEM_USE_GENDER_ERROR,"NOTIFY_ITEM_USE_GENDER_ERROR");
		reload_key(NOTIFY_ITEM_USE_JOB_ERROR,"NOTIFY_ITEM_USE_JOB_ERROR");
		reload_key(NOTIFY_ITEM_EXCHANGE_LV_LIMIT,"NOTIFY_ITEM_EXCHANGE_LV_LIMIT");

		reload_key(NOTIFY_HORN_HAVE_NO,"NOTIFY_HORN_HAVE_NO");
		reload_key(NOTIFY_WAR_KILL,"NOTIFY_WAR_KILL");
		reload_key(NOTIFY_WAR_KILL_RAM,"NOTIFY_WAR_KILL_RAM");
		reload_key(NOTIFY_NPC_SELL_DENY,"NOTIFY_NPC_SELL_DENY");
		reload_key(NOTIFY_GIFT,"NOTIFY_GIFT");
		reload_key(NOTIFY_ITEM_TIME_LIMIT_FULL,"NOTIFY_ITEM_TIME_LIMIT_FULL");
		reload_key(NOTIFY_CHATTRADE_SUC,"NOTIFY_CHATTRADE_SUC");
		reload_key(NOTIFY_MOXUESHI_EMPTY,"NOTIFY_MOXUESHI_EMPTY");
		reload_key(NOTIFY_MOXUESHI_UPGRADE_NO,"NOTIFY_MOXUESHI_UPGRADE_NO");

		reload_key(NOTIFY_FRIEND_AUTHTYPE_ERROR,"NOTIFY_FRIEND_AUTHTYPE_ERROR");
		reload_key(NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR,"NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR");
		reload_key(NOTIFY_FRIEND_OPERATER_ERROR,"NOTIFY_FRIEND_OPERATER_ERROR");
		reload_key(NOTIFY_FRIEND_TOO_MUCH,"NOTIFY_FRIEND_TOO_MUCH");
		reload_key(NOTIFY_ENEMY_TOO_MUCH,"NOTIFY_ENEMY_TOO_MUCH");
		reload_key(NOTIFY_BLACK_TOO_MUCH,"NOTIFY_BLACK_TOO_MUCH");
		reload_key(NOTIFY_FRIEND_DELETE,"NOTIFY_FRIEND_DELETE");
		reload_key(NOTIFY_FRIEND_ADD,"NOTIFY_FRIEND_ADD");
		reload_key(NOTIFY_FRIEND_ADD_NOTIFY,"NOTIFY_FRIEND_ADD_NOTIFY");
		reload_key(NOTIFY_CANCEL_BY_TRADING,"NOTIFY_CANCEL_BY_TRADING");
		reload_key(NOTIFY_EXCUPD_FROM_NO_LEVEL,"NOTIFY_EXCUPD_FROM_NO_LEVEL");
		reload_key(NOTIFY_EXCUPD_TO_HAVE_LEVEL,"NOTIFY_EXCUPD_TO_HAVE_LEVEL");
		reload_key(NOTIFY_EXCUPD_BIND_TO_NOBIND,"NOTIFY_EXCUPD_BIND_TO_NOBIND");
		reload_key(NOTIFY_EXCUPD_EQUIP_TYPE_DIFF,"NOTIFY_EXCUPD_EQUIP_TYPE_DIFF");
		reload_key(NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW,"NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW");
		reload_key(NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH,"NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH");
		reload_key(NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH,"NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH");
		reload_key(NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN,"NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN");
		reload_key(NOTIFY_PK_KILL_SUB_LUCK,"NOTIFY_PK_KILL_SUB_LUCK");
		//reload_key(NOTIFY_UPGRADEEQUIP_PUBLISH_SUC,"NOTIFY_UPGRADEEQUIP_PUBLISH_SUC");
		//reload_key(NOTIFY_UPGRADEEQUIP_PUBLISH_FAIL,"NOTIFY_UPGRADEEQUIP_PUBLISH_FAIL");
		reload_key(NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN,"NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN");

		reload_key(NOTIFY_GAMEMONEY_ENOUGH, "NOTIFY_GAMEMONEY_ENOUGH");
		reload_key(NOTIFY_GAMEMONEYBIND_ENOUGH, "NOTIFY_GAMEMONEYBIND_ENOUGH");
		reload_key(NOTIFY_VCOIN_ENOUGH, "NOTIFY_VCOIN_ENOUGH");
		reload_key(NOTIFY_VCOINBIND_ENOUGH, "NOTIFY_VCOINBIND_ENOUGH");

		//reload_key(NOTIFY_MONSTER_DROP_ITEM,"NOTIFY_MONSTER_DROP_ITEM");
		//reload_key(NOTIFY_MONSTER_DROP_ITEM_NONAME,"NOTIFY_MONSTER_DROP_ITEM_NONAME");
		reload_key(NOTIFY_ADD_SLOT_MAX_LIMIT,"NOTIFY_ADD_SLOT_MAX_LIMIT");
		reload_key(NOTIFY_DART_OUT_TIME,"NOTIFY_DART_OUT_TIME");
		reload_key(NOTIFY_DART_OUT_RANGE_REMAIND,"NOTIFY_DART_OUT_RANGE_REMAIND");
		reload_key(NOTIFY_IS_DARTING,"NOTIFY_IS_DARTING");
		reload_key(NOTIFY_ACCEPT_DART_TASK,"NOTIFY_ACCEPT_DART_TASK");
		reload_key(NOTIFY_ROB_DART_NO_REWARD,"NOTIFY_ROB_DART_NO_REWARD");
		reload_key(NOTIFY_ROB_DART_REWARD,"NOTIFY_ROB_DART_REWARD");
		reload_key(NOTIFY_ROB_DART_NUMBER_FULL,"NOTIFY_ROB_DART_NUMBER_FULL");
		reload_key(NOTIFY_DART_DESTROYED,"NOTIFY_DART_DESTROYED");
		reload_key(NOTIFY_DART_DESTROYED_SUCCEED,"NOTIFY_DART_DESTROYED_SUCCEED");
		reload_key(NOTIFY_DART_SUCCEED,"NOTIFY_DART_SUCCEED");
		reload_key(NOTIFY_DIRECTFLY_FORBID_DARTING,"NOTIFY_DIRECTFLY_FORBID_DARTING");
		reload_key(NOTIFY_ACCEPT_DART_NUMBER_FULL,"NOTIFY_ACCEPT_DART_NUMBER_FULL");
		reload_key(NOTIFY_SKILL_FORBID_ROB_DART,"NOTIFY_SKILL_FORBID_ROB_DART");
		reload_key(NOTIFY_DIRECT_FLY_MAP_FORBID,"NOTIFY_DIRECT_FLY_MAP_FORBID");
		reload_key(NOTIFY_DIRECT_FLY_PKVALUE_FORBID,"NOTIFY_DIRECT_FLY_PKVALUE_FORBID");
		reload_key(NOTIFY_DIRECT_FLY_DEAD_FORBID,"NOTIFY_DIRECT_FLY_DEAD_FORBID");
		reload_key(NOTIFY_CDUPDITEM_VCOIN_FAIL,"NOTIFY_CDUPDITEM_VCOIN_FAIL");
		reload_key(NOTIFY_CANNOT_USE_LOTTERYDEPOT,"NOTIFY_CANNOT_USE_LOTTERYDEPOT");
		reload_key(NOTIFY_BAG_AND_DEPOT_FULL,"NOTIFY_BAG_AND_DEPOT_FULL");
		reload_key(NOTIFY_MAP_NO_INFO_PLAYER,"NOTIFY_MAP_NO_INFO_PLAYER");
		reload_key(NOTIFY_MAP_NO_INFO_CHAT,"NOTIFY_MAP_NO_INFO_CHAT");
		reload_key(NOTIFY_CAN_NOT_DEPOT, "NOTIFY_CAN_NOT_DEPOT");
		reload_key(NOTIFY_CAN_NOT_DESTORY, "NOTIFY_CAN_NOT_DESTORY");
		reload_key(NOTIFY_SAFEAREA_NO_DROP, "NOTIFY_SAFEAREA_NO_DROP");
		reload_key(NOTIFY_PK_VALUE_DESP, "NOTIFY_PK_VALUE_DESP");
		reload_key(NOTIFY_MAIL_TITLE, "NOTIFY_MAIL_TITLE");
		reload_key(NOTIFY_PLAYER_NOT_ONLINE_CHAT, "NOTIFY_PLAYER_NOT_ONLINE_CHAT");
		reload_key(NOTIFY_MAIL_CONTENT, "NOTIFY_MAIL_CONTENT");
		reload_key(NOTIFY_ANONYM_NAME, "NOTIFY_ANONYM_NAME");		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ONSALE_ITEM_SUC,"eee");//�����۵�%s�Ѿ������%s����.
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ONSALE_MIN_LEVEL_LIMIT,20);//"%d.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ITEM_TIME_LIMIT_FULL,"ss");//"%s��Ʒʹ��ʱ������.");,1
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_CHATTRADE_SUC,"ss","ss","ss");//"��� %s �� %s �Ѿ������ %s ����  
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_WORLD_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ROB_DART_REWARD,20);//"���ڳɹ�,������� %d ����ֵ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_DART_DESTROYED_SUCCEED,20);//"Ѻ�����,���������ڳ����𻵣�ֻ�ܻ��ʣ��� %d ����ֵ");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_DART_SUCCEED,20);//"Ѻ�ڳɹ�,�������ȫ���� %d ����ֵ");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GROUP_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GUILD_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_NORMAL_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_MAP_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_HORN_CHAT_LEVEL_LIMIT,20);//"%d����ſ��Է���������Ϣ.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_PK_KILLED,"eefe");//"�㱻 %s ɱ����");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_PK_KILL,"trest");//"��ɱ���� %s");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_CONGZI_INFO,"eee",100);//"��� %s ͨ�����̵�Ԫ����ֵ���ܻ�� %d Ԫ��");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN,100);//"Ԫ������,��������Ʒդ����Ҫ���� %d Ԫ��");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GROUP_MEMBER_ADD,"eee");//"��� %s �������");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_JOIN_GROUP,"eee");//"������� %s �Ķ���.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GROUP_MEMBER_REM,"eee");//"��� %s �뿪����");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GROUP_MEMBER_ONLINE,"eee");//"��Ա %s ������.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GROUP_MEMBER_OFFLINE,"eee");//"��Ա %s ������.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GUILD_MEMBER_ENTERING,"eee");//"��� %s ��������л�.");
		_snprintf_s(temp, _countof(temp),1023,NOTIFY_GUILD_ADD_PRESIDENT,"eee");//"��� %s ��Ϊ���л᳤��.");
		_snprintf_s(temp, _countof(temp),1023,NOTIFY_GUILD_SUB_PRESIDENT, "eee");//"��� %s ��ȡ���˳����ʸ�."); 
		_snprintf_s(temp, _countof(temp),1023,NOTIFY_GUILD_BECOME_ADMIN, "eee");//"��� %s ��Ϊ�˻᳤.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_CHATTRADE_SUBITEM_NOITEM,"eee");//"����Ʒ�ѱ���� %s ����.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_PK_LEVEL_LIMIT,1000);//"�ȼ����� %d ��,������PK.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GUILD_CREATE_LEVEL_LIMIT,10);//"%d�����²��������л�.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_CHATTRADE_MONEY_NOTENOUGH,10);//"����ʧ��,Ԫ������:%d"); 
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_HUICHENGSHI_CISHU,10);//"�س�ʯʣ%d��ʹ�û���");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GUILD_JOIN_LEVEL_LIMIT,100);//"%d�����²���������л�.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ITEM_EXCHANGE_LV_LIMIT,100);//"%d ���²�����ʹ��װ���һ�����.");

		_snprintf_s(temp,_countof(temp),1023,NOTIFY_WAR_KILL,"eee","eee","ee","ee");//"%s �л�� %s �ڹ���ս�л�ɱ�� %s �л�� %s.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_WAR_KILL_RAM,"ee","eee","eeee");//"%s �л�� %s �ڹ���ս�м����� %s �л�Ĺ��ǳ�.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_GIFT,"ee","ee");//"ͨ��<font color='#FF0000'> %s </font>���<font color='#FF0000'> %s </font>.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_FRIEND_DELETE,"ee");//"ɾ����ϵ�� %s.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_FRIEND_ADD,"ee");//"�����ϵ�� %s.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_FRIEND_ADD_NOTIFY,"ee");//"%s ����Ϊ����.");
		_snprintf_s(temp,_countof(temp),1023,NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN,10);//"װ��Ʒ���½� %d.");

		

		return true;
	}
	void ConstsString::reload_key(char* dest,std::string key)
	{
		size_t slot_num=0;
		for(size_t i = 0;i < strlen(dest);i++)
		{
			if( dest[i] == '%' )
			{
				slot_num ++;
			}
		}
		StringMap::iterator pos = mStringMap.find(key);
		if( mStringMap.end() != pos )
		{
			size_t o=0;
			const char* p = pos->second.c_str();
			for(size_t i = 0;i < pos->second.length();i++)
			{
				if( p[i] == '%' )
				{
					o ++;
				}
			}
			if( o <= slot_num )
			{
				if( 0 != strcmp(dest,pos->second.c_str()) )
				{
					strcpy_s(dest,512,pos->second.c_str());
				}
			}
		}
		dest[511]=0;
	}
	bool ConstsString::ReLoad(GameServerLib* gslib)
	{
		LoadDefault();
		Load(gslib);
		return true;
	}
	bool ConstsString::LoadDefault()
	{
		char temp[1024];

		strcpy_s(NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP,"60��֮ǰ���ܼ�ȡ");
		UtilString::act_2_utf8(NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP, strlen(NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP), temp, 1024);
		strcpy_s(NOTIFY_ITEM_LEVEL_LIMINT_CAN_NOT_PICK_UP, temp);

		strcpy_s(NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP,"һ��ʱ���ڲ���ʰȡ");
		UtilString::act_2_utf8(NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP,strlen(NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP),temp,1024);
		strcpy_s(NOTIFY_ITEM_LOCK_CAN_NOT_PICK_UP,temp);

		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY,"��Ҳ���,����ʧ��");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY,strlen(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEY,temp);

		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND,"���Ҳ���,����ʧ��");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND,strlen(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_GAMEMONEYBIND,temp);

		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN,"Ԫ������,����ʧ��");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN,strlen(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOIN,temp);

		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND,"��Ҳ���,����ʧ��");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND,strlen(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_NOT_ENOPHY_VCOINBIND,temp);

		strcpy_s(NOTIFY_BING_ITEM_LIMIT,"����Ʒ�����Լ���.");
		UtilString::act_2_utf8(NOTIFY_BING_ITEM_LIMIT,strlen(NOTIFY_BING_ITEM_LIMIT),temp,1024);
		strcpy_s(NOTIFY_BING_ITEM_LIMIT,temp);

		strcpy_s(NOTIFY_BEYOND_ONSALE_LIMIT,"����ǰ�Ѵﵽ������������.");
		UtilString::act_2_utf8(NOTIFY_BEYOND_ONSALE_LIMIT,strlen(NOTIFY_BEYOND_ONSALE_LIMIT),temp,1024);
		strcpy_s(NOTIFY_BEYOND_ONSALE_LIMIT,temp);

		strcpy_s(NOTIFY_ONSALE_MAX_LIMIT,"ϵͳ��ǰ�����б��ѳ����ټ�������ѡ�����������Ʒ.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_MAX_LIMIT,strlen(NOTIFY_ONSALE_MAX_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ONSALE_MAX_LIMIT,temp);

		strcpy_s(NOTIFY_ONSALE_PUT_SUC,"���۳ɹ������ɹ��۳�����ȡ��5%�������ѣ��Լ�ȡ�ز���������.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_PUT_SUC,strlen(NOTIFY_ONSALE_PUT_SUC),temp,1024);
		strcpy_s(NOTIFY_ONSALE_PUT_SUC,temp);

		strcpy_s(NOTIFY_ONSALE_TIME_ERROR,"�������ڲ�������Ʒ�����Ժ�.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_TIME_ERROR,strlen(NOTIFY_ONSALE_TIME_ERROR),temp,1024);
		strcpy_s(NOTIFY_ONSALE_TIME_ERROR,temp);

		strcpy_s(NOTIFY_ONSALE_ITEM_MISS,"����Ʒ���۳�����Ϊ��ˢ���б�������ѡ��.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_ITEM_MISS,strlen(NOTIFY_ONSALE_ITEM_MISS),temp,1024);
		strcpy_s(NOTIFY_ONSALE_ITEM_MISS,temp);

		strcpy_s(NOTIFY_ONSALE_OWNER_OFFLINE,"�������Ѿ����ߣ��Ѿ�Ϊ��ˢ���б�������ѡ��.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_OWNER_OFFLINE,strlen(NOTIFY_ONSALE_OWNER_OFFLINE),temp,1024);
		strcpy_s(NOTIFY_ONSALE_OWNER_OFFLINE,temp);

		strcpy_s(NOTIFY_ONSALE_MIN_LEVEL_LIMIT,"������Ʒ��ȼ��ﵽ%d��.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_MIN_LEVEL_LIMIT,strlen(NOTIFY_ONSALE_MIN_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ONSALE_MIN_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_ONSALE_ITEM_SUC,"�����۵�%s�Ѿ��ɹ��۳�.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_ITEM_SUC,strlen(NOTIFY_ONSALE_ITEM_SUC),temp,1024);
		strcpy_s(NOTIFY_ONSALE_ITEM_SUC,temp);

		strcpy_s(NOTIFY_ONSALE_ITEM_CANNOT,"����Ʒ���������.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_ITEM_CANNOT,strlen(NOTIFY_ONSALE_ITEM_CANNOT),temp,1024);
		strcpy_s(NOTIFY_ONSALE_ITEM_CANNOT,temp);

		strcpy_s(NOTIFY_ONSALE_FREE_LIMIT,"�������Ƚ���%5��������.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_FREE_LIMIT,strlen(NOTIFY_ONSALE_FREE_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ONSALE_FREE_LIMIT,temp);

		strcpy_s(NOTIFY_ONSALE_MONEY_LIMIT,"���۵Ľ������1000-99999999֮��,Ԫ������10-999999֮��.");
		UtilString::act_2_utf8(NOTIFY_ONSALE_MONEY_LIMIT,strlen(NOTIFY_ONSALE_MONEY_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ONSALE_MONEY_LIMIT,temp);

		strcpy_s(NOTIFY_USE_TIEM_LIMIT_ERROR,"������װ������,װ��ʧ��");
		UtilString::act_2_utf8(NOTIFY_USE_TIEM_LIMIT_ERROR,strlen(NOTIFY_USE_TIEM_LIMIT_ERROR),temp,1024);
		strcpy_s(NOTIFY_USE_TIEM_LIMIT_ERROR,temp);

		strcpy_s(NOTIFY_ZHUANSHENG_LEVEL_LIMIT,"������ת���ȼ�Ҫ��,װ��ʧ��");
		UtilString::act_2_utf8(NOTIFY_ZHUANSHENG_LEVEL_LIMIT,strlen(NOTIFY_ZHUANSHENG_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ZHUANSHENG_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR,"װ������Ҫ����");
		UtilString::act_2_utf8(NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR,strlen(NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR),temp,1024);
		strcpy_s(NOTIFY_REPAIR_ITEM_NONEEDTOREPAIR,temp);

		strcpy_s(NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY,"��Ҳ���,����ʧ��");
		UtilString::act_2_utf8(NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY,strlen(NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY),temp,1024);
		strcpy_s(NOTIFY_REPAIR_ITEM_NOT_ENOPHY_GAMEMONEY,temp);

		strcpy_s(NOTIFY_ITEM_TIME_LIMIT_FULL,"��ӵ�е� %s ��ʹ��ʱ���ѵ����ѱ�ϵͳ�Զ��ջ�.");//��ӵ�е� %s �� %d ���ӵ�ʹ��ʱ���ѵ����ѱ�ϵͳ�Զ��ջ�.
		UtilString::act_2_utf8(NOTIFY_ITEM_TIME_LIMIT_FULL,strlen(NOTIFY_ITEM_TIME_LIMIT_FULL),temp,1024);
		strcpy_s(NOTIFY_ITEM_TIME_LIMIT_FULL,temp);

		strcpy_s(NOTIFY_MOXUESHI_EMPTY,"����ħѪʯ�����꣬��ϵͳ����.");
		UtilString::act_2_utf8(NOTIFY_MOXUESHI_EMPTY,strlen(NOTIFY_MOXUESHI_EMPTY),temp,1024);
		strcpy_s(NOTIFY_MOXUESHI_EMPTY,temp);

		strcpy_s(NOTIFY_MOXUESHI_UPGRADE_NO,"����Ʒ������ǿ��.");
		UtilString::act_2_utf8(NOTIFY_MOXUESHI_UPGRADE_NO,strlen(NOTIFY_MOXUESHI_UPGRADE_NO),temp,1024);
		strcpy_s(NOTIFY_MOXUESHI_UPGRADE_NO,temp);

		strcpy_s(NOTIFY_NOENOUGHMONEY_FAL,"��Ҳ���.");
		UtilString::act_2_utf8(NOTIFY_NOENOUGHMONEY_FAL,strlen(NOTIFY_NOENOUGHMONEY_FAL),temp,1024);
		strcpy_s(NOTIFY_NOENOUGHMONEY_FAL,temp);

		strcpy_s(NOTIFY_UPGRADE_MATCHSTONE_FAL,"װ��ǿ����Ҫƥ�䵱ǰ�ȼ��ı�ʯ.");
		UtilString::act_2_utf8(NOTIFY_UPGRADE_MATCHSTONE_FAL,strlen(NOTIFY_UPGRADE_MATCHSTONE_FAL),temp,1024);
		strcpy_s(NOTIFY_UPGRADE_MATCHSTONE_FAL,temp);

		strcpy_s(NOTIFY_NOT_ENOUPH_MP,"ħ��ֵ����");
		UtilString::act_2_utf8(NOTIFY_NOT_ENOUPH_MP,strlen(NOTIFY_NOT_ENOUPH_MP),temp,1024);
		strcpy_s(NOTIFY_NOT_ENOUPH_MP,temp);
		
		strcpy_s(NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP,"��������,����ʰȡ");
		UtilString::act_2_utf8(NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP,strlen(NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP),temp,1024);
		strcpy_s(NOTIFY_ITEM_SLOB_FULL_CAN_NOT_PICK_UP,temp);

		strcpy_s(NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN,"Ԫ������,���ܸ���");
		UtilString::act_2_utf8(NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN,strlen(NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN),temp,1024);
		strcpy_s(NOTIFY_RELIVE_STAND_NOT_ENOUPH_VCOIN,temp);

		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP,"�õ�ͼ���ɶ�����Ʒ");
		UtilString::act_2_utf8(NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP,strlen(NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP),temp,1024);
		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_ON_MAP,temp);

		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE,"�ο���Ҳ��ɶ�����Ʒ");
		UtilString::act_2_utf8(NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE,strlen(NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE),temp,1024);
		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_AUTH_TYPE,temp);

		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_BIND,"��Ʒ�Ѱ󶨲��ɶ���");
		UtilString::act_2_utf8(NOTIFY_DROP_ITEM_CAN_NOT_BIND,strlen(NOTIFY_DROP_ITEM_CAN_NOT_BIND),temp,1024);
		strcpy_s(NOTIFY_DROP_ITEM_CAN_NOT_BIND,temp);

		strcpy_s(NOTIFY_TRADE_ITEM_CAN_NOT_BIND,"��Ʒ�Ѱ󶨲��ɽ���");
		UtilString::act_2_utf8(NOTIFY_TRADE_ITEM_CAN_NOT_BIND,strlen(NOTIFY_TRADE_ITEM_CAN_NOT_BIND),temp,1024);
		strcpy_s(NOTIFY_TRADE_ITEM_CAN_NOT_BIND,temp);

		strcpy_s(NOTIFY_CHAT_TOO_QUICK,"���Թ���Ƶ��,���Ժ��ٷ�");
		UtilString::act_2_utf8(NOTIFY_CHAT_TOO_QUICK,strlen(NOTIFY_CHAT_TOO_QUICK),temp,1024);
		strcpy_s(NOTIFY_CHAT_TOO_QUICK,temp);

		strcpy_s(NOTIFY_SKILL_YEMAN_FALIED,"��ײ������");
		UtilString::act_2_utf8(NOTIFY_SKILL_YEMAN_FALIED,strlen(NOTIFY_SKILL_YEMAN_FALIED),temp,1024);
		strcpy_s(NOTIFY_SKILL_YEMAN_FALIED,temp);

		strcpy_s(NOTIFY_SKILL_CISHAJIANSHU_OPEN,"��ɱ��������");
		UtilString::act_2_utf8(NOTIFY_SKILL_CISHAJIANSHU_OPEN,strlen(NOTIFY_SKILL_CISHAJIANSHU_OPEN),temp,1024);
		strcpy_s(NOTIFY_SKILL_CISHAJIANSHU_OPEN,temp);

		strcpy_s(NOTIFY_SKILL_CISHAJIANSHU_CLOSE,"��ɱ�����ر�");
		UtilString::act_2_utf8(NOTIFY_SKILL_CISHAJIANSHU_CLOSE,strlen(NOTIFY_SKILL_CISHAJIANSHU_CLOSE),temp,1024);
		strcpy_s(NOTIFY_SKILL_CISHAJIANSHU_CLOSE,temp);

		strcpy_s(NOTIFY_SKILL_BANYUEWANDAO_OPEN,"�����䵶����");
		UtilString::act_2_utf8(NOTIFY_SKILL_BANYUEWANDAO_OPEN,strlen(NOTIFY_SKILL_BANYUEWANDAO_OPEN),temp,1024);
		strcpy_s(NOTIFY_SKILL_BANYUEWANDAO_OPEN,temp);

		strcpy_s(NOTIFY_SKILL_BANYUEWANDAO_CLOSE,"�����䵶�ر�");
		UtilString::act_2_utf8(NOTIFY_SKILL_BANYUEWANDAO_CLOSE,strlen(NOTIFY_SKILL_BANYUEWANDAO_CLOSE),temp,1024);
		strcpy_s(NOTIFY_SKILL_BANYUEWANDAO_CLOSE,temp);

		strcpy_s(NOTIFY_SKILL_LIEHUOJIANFA_OK,"%s �ٻ��ɹ�");
		UtilString::act_2_utf8(NOTIFY_SKILL_LIEHUOJIANFA_OK,strlen(NOTIFY_SKILL_LIEHUOJIANFA_OK),temp,1024);
		strcpy_s(NOTIFY_SKILL_LIEHUOJIANFA_OK,temp);

		strcpy_s(NOTIFY_SKILL_COLDING,"ħ����ȴ��");
		UtilString::act_2_utf8(NOTIFY_SKILL_COLDING,strlen(NOTIFY_SKILL_COLDING),temp,1024);
		strcpy_s(NOTIFY_SKILL_COLDING,temp);

		strcpy_s(NOTIFY_SKILL_SHUNJIANYIDONG_FAILED,"�ƶ�ʧ��");
		UtilString::act_2_utf8(NOTIFY_SKILL_SHUNJIANYIDONG_FAILED,strlen(NOTIFY_SKILL_SHUNJIANYIDONG_FAILED),temp,1024);
		strcpy_s(NOTIFY_SKILL_SHUNJIANYIDONG_FAILED,temp);

		strcpy_s(NOTIFY_MERDER,"������ıɱ��,��������100��PKֵ");
		UtilString::act_2_utf8(NOTIFY_MERDER,strlen(NOTIFY_MERDER),temp,1024);
		strcpy_s(NOTIFY_MERDER,temp);

		strcpy_s(NOTIFY_TRADE_TOO_FAR,"����̫Զ,�����Խ���");
		UtilString::act_2_utf8(NOTIFY_TRADE_TOO_FAR,strlen(NOTIFY_TRADE_TOO_FAR),temp,1024);
		strcpy_s(NOTIFY_TRADE_TOO_FAR,temp);

		strcpy_s(NOTIFY_TRADE_CAN_NOT_AUTH_TYPE,"�ο���Ҳ����Խ���");
		UtilString::act_2_utf8(NOTIFY_TRADE_CAN_NOT_AUTH_TYPE,strlen(NOTIFY_TRADE_CAN_NOT_AUTH_TYPE),temp,1024);
		strcpy_s(NOTIFY_TRADE_CAN_NOT_AUTH_TYPE,temp);

		strcpy_s(NOTIFY_TRADE_CAN_NOT_LEVEL,"��������Ҳſ��Խ��н���");
		UtilString::act_2_utf8(NOTIFY_TRADE_CAN_NOT_LEVEL,strlen(NOTIFY_TRADE_CAN_NOT_LEVEL),temp,1024);
		strcpy_s(NOTIFY_TRADE_CAN_NOT_LEVEL,temp);

		strcpy_s(NOTIFY_ITEM_USE_TIME_TOO_SHORT,"��Ʒʹ�ù���");
		UtilString::act_2_utf8(NOTIFY_ITEM_USE_TIME_TOO_SHORT,strlen(NOTIFY_ITEM_USE_TIME_TOO_SHORT),temp,1024);
		strcpy_s(NOTIFY_ITEM_USE_TIME_TOO_SHORT,temp);

		strcpy_s(NOTIFY_BAG_USE_ITEM_MAP_DISABLED,"�˵�ͼ��ֹʹ�ø���Ʒ");
		UtilString::act_2_utf8(NOTIFY_BAG_USE_ITEM_MAP_DISABLED,strlen(NOTIFY_BAG_USE_ITEM_MAP_DISABLED),temp,1024);
		strcpy_s(NOTIFY_BAG_USE_ITEM_MAP_DISABLED,temp);

		strcpy_s(NOTIFY_SKILL_MAP_DISABLED,"�˵�ͼ��ֹʹ�øü���");
		UtilString::act_2_utf8(NOTIFY_SKILL_MAP_DISABLED,strlen(NOTIFY_SKILL_MAP_DISABLED),temp,1024);
		strcpy_s(NOTIFY_SKILL_MAP_DISABLED,temp);

		strcpy_s(NOTIFY_MERGESTEEL_SUC,"���������ɹ�");
		UtilString::act_2_utf8(NOTIFY_MERGESTEEL_SUC,strlen(NOTIFY_MERGESTEEL_SUC),temp,1024);
		strcpy_s(NOTIFY_MERGESTEEL_SUC,temp);

		strcpy_s(NOTIFY_MERGESTEEL_FAL,"��������ʧ��");
		UtilString::act_2_utf8(NOTIFY_MERGESTEEL_FAL,strlen(NOTIFY_MERGESTEEL_FAL),temp,1024);
		strcpy_s(NOTIFY_MERGESTEEL_FAL,temp);

		strcpy_s(NOTIFY_UPGRADEEQUIP_SUC,"װ��ǿ���ɹ�");
		UtilString::act_2_utf8(NOTIFY_UPGRADEEQUIP_SUC,strlen(NOTIFY_UPGRADEEQUIP_SUC),temp,1024);
		strcpy_s(NOTIFY_UPGRADEEQUIP_SUC,temp);

		strcpy_s(NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT,"��ʱװ�������Խ���ǿ��.");
		UtilString::act_2_utf8(NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT,strlen(NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT),temp,1024);
		strcpy_s(NOTIFY_UPGRADEEQUIP_LASTTIME_LIMIT,temp);

		strcpy_s(NOTIFY_QILING_SUC,"װ������ɹ�.");
		UtilString::act_2_utf8(NOTIFY_QILING_SUC,strlen(NOTIFY_QILING_SUC),temp,1024);
		strcpy_s(NOTIFY_QILING_SUC,temp);

		strcpy_s(NOTIFY_QILING_FULL,"�ɼ�����������,����Ҫ��������.");
		UtilString::act_2_utf8(NOTIFY_QILING_FULL,strlen(NOTIFY_QILING_FULL),temp,1024);
		strcpy_s(NOTIFY_QILING_FULL,temp);

		strcpy_s(NOTIFY_UPGRADEEQUIP_FAL,"װ��ǿ��ʧ��");
		UtilString::act_2_utf8(NOTIFY_UPGRADEEQUIP_FAL,strlen(NOTIFY_UPGRADEEQUIP_FAL),temp,1024);
		strcpy_s(NOTIFY_UPGRADEEQUIP_FAL,temp);

		strcpy_s(NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT,"������װ��ʹ������,װ��ǿ��ʧ��");
		UtilString::act_2_utf8(NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT,strlen(NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT),temp,1024);
		strcpy_s(NOTIFY_UPGRADEEQUIP_FAL_NEED_LIMIT,temp);

		strcpy_s(NOTIFY_BUY_ITEM_NOT_YOUKE,"�ο�ģʽ�����Թ������Ʒ");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_NOT_YOUKE,strlen(NOTIFY_BUY_ITEM_NOT_YOUKE),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_NOT_YOUKE,temp);

		strcpy_s(NOTIFY_SKILL_YOULINGDUN,"ħ����������");
		UtilString::act_2_utf8(NOTIFY_SKILL_YOULINGDUN,strlen(NOTIFY_SKILL_YOULINGDUN),temp,1024);
		strcpy_s(NOTIFY_SKILL_YOULINGDUN,temp);

		strcpy_s(NOTIFY_SKILL_SHENGZHANJIASHU,"�����������");
		UtilString::act_2_utf8(NOTIFY_SKILL_SHENGZHANJIASHU,strlen(NOTIFY_SKILL_SHENGZHANJIASHU),temp,1024);
		strcpy_s(NOTIFY_SKILL_SHENGZHANJIASHU,temp);

		strcpy_s(NOTIFY_PK_MAP_NOT_MERDER,"PK��ͼ������");
		UtilString::act_2_utf8(NOTIFY_PK_MAP_NOT_MERDER,strlen(NOTIFY_PK_MAP_NOT_MERDER),temp,1024);
		strcpy_s(NOTIFY_PK_MAP_NOT_MERDER,temp);

		strcpy_s(NOTIFY_MAP_PK_PROHIBIT,"�õ�ͼ������PK");
		UtilString::act_2_utf8(NOTIFY_MAP_PK_PROHIBIT,strlen(NOTIFY_MAP_PK_PROHIBIT),temp,1024);
		strcpy_s(NOTIFY_MAP_PK_PROHIBIT,temp);

		strcpy_s(NOTIFY_MAPTIME_PK_PROHIBIT, "׼���׶β�����PK");
		UtilString::act_2_utf8(NOTIFY_MAPTIME_PK_PROHIBIT, strlen(NOTIFY_MAPTIME_PK_PROHIBIT), temp, 1024);
		strcpy_s(NOTIFY_MAPTIME_PK_PROHIBIT, temp);

		strcpy_s(NOTIFY_WORLD_CHAT_LEVEL_LIMIT,"%d����ſ��Է���������Ϣ.");
		UtilString::act_2_utf8(NOTIFY_WORLD_CHAT_LEVEL_LIMIT,strlen(NOTIFY_WORLD_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_WORLD_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_ROB_DART_REWARD,"���ڳɹ�,������� %d ����ֵ.");
		UtilString::act_2_utf8(NOTIFY_ROB_DART_REWARD,strlen(NOTIFY_ROB_DART_REWARD),temp,1024);
		strcpy_s(NOTIFY_ROB_DART_REWARD,temp);

		strcpy_s(NOTIFY_DART_DESTROYED_SUCCEED,"���Ѿ����Ѻ�������ʣ�ཱ������� %d ����ֵ.");
		UtilString::act_2_utf8(NOTIFY_DART_DESTROYED_SUCCEED,strlen(NOTIFY_DART_DESTROYED_SUCCEED),temp,1024);
		strcpy_s(NOTIFY_DART_DESTROYED_SUCCEED,temp);

		strcpy_s(NOTIFY_DART_SUCCEED,"Ѻ�ڳɹ�,�������ȫ���� %d ����ֵ.");
		UtilString::act_2_utf8(NOTIFY_DART_SUCCEED,strlen(NOTIFY_DART_SUCCEED),temp,1024);
		strcpy_s(NOTIFY_DART_SUCCEED,temp);

		strcpy_s(NOTIFY_GROUP_CHAT_LEVEL_LIMIT,"%d����ſ��Է��������Ϣ.");
		UtilString::act_2_utf8(NOTIFY_GROUP_CHAT_LEVEL_LIMIT,strlen(NOTIFY_GROUP_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_GROUP_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_GUILD_CHAT_LEVEL_LIMIT,"%d����ſ��Է����л���Ϣ.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CHAT_LEVEL_LIMIT,strlen(NOTIFY_GUILD_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_GUILD_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_NORMAL_CHAT_LEVEL_LIMIT,"%d����ſ��Է�����ͨ��Ϣ.");
		UtilString::act_2_utf8(NOTIFY_NORMAL_CHAT_LEVEL_LIMIT,strlen(NOTIFY_NORMAL_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_NORMAL_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_MAP_CHAT_LEVEL_LIMIT,"%d����ſ��Է��ͺ�����Ϣ.");
		UtilString::act_2_utf8(NOTIFY_MAP_CHAT_LEVEL_LIMIT,strlen(NOTIFY_MAP_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_MAP_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT,"%d����ſ��Է���˽����Ϣ.");
		UtilString::act_2_utf8(NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT,strlen(NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_PRIVATE_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_HORN_CHAT_LEVEL_LIMIT,"%d����ſ��Է���������Ϣ.");
		UtilString::act_2_utf8(NOTIFY_HORN_CHAT_LEVEL_LIMIT,strlen(NOTIFY_HORN_CHAT_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_HORN_CHAT_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_PK_KILLED,"�㱻 %s ɱ����");
		UtilString::act_2_utf8(NOTIFY_PK_KILLED,strlen(NOTIFY_PK_KILLED),temp,1024);
		strcpy_s(NOTIFY_PK_KILLED,temp);

		strcpy_s(NOTIFY_LOGIN_ANOTHER_PLACE,"�˽�ɫ�������ն˵�¼,���Ự�ر�");
		UtilString::act_2_utf8(NOTIFY_LOGIN_ANOTHER_PLACE,strlen(NOTIFY_LOGIN_ANOTHER_PLACE),temp,1024);
		strcpy_s(NOTIFY_LOGIN_ANOTHER_PLACE,temp);

		strcpy_s(NOTIFY_FRESH_VCOIN_WAIT,"ˢ�¹���,���Ժ�����");
		UtilString::act_2_utf8(NOTIFY_FRESH_VCOIN_WAIT,strlen(NOTIFY_FRESH_VCOIN_WAIT),temp,1024);
		strcpy_s(NOTIFY_FRESH_VCOIN_WAIT,temp);

		strcpy_s(NOTIFY_KICK_BUY_GM,"�㱻ǿ������");
		UtilString::act_2_utf8(NOTIFY_KICK_BUY_GM,strlen(NOTIFY_KICK_BUY_GM),temp,1024);
		strcpy_s(NOTIFY_KICK_BUY_GM,temp);

		strcpy_s(NOTIFY_TALK_PROHIBITED,"���Ѿ�������");
		UtilString::act_2_utf8(NOTIFY_TALK_PROHIBITED,strlen(NOTIFY_TALK_PROHIBITED),temp,1024);
		strcpy_s(NOTIFY_TALK_PROHIBITED,temp);

		strcpy_s(NOTIFY_TALK_ALLOWED,"��Ľ����ѽ��");
		UtilString::act_2_utf8(NOTIFY_TALK_ALLOWED,strlen(NOTIFY_TALK_ALLOWED),temp,1024);
		strcpy_s(NOTIFY_TALK_ALLOWED,temp);

		strcpy_s(NOTIFY_PK_KILL,"��ɱ���� %s");
		UtilString::act_2_utf8(NOTIFY_PK_KILL,strlen(NOTIFY_PK_KILL),temp,1024);
		strcpy_s(NOTIFY_PK_KILL,temp);

		strcpy_s(NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD,"�οͲ����Դ����л�");
		UtilString::act_2_utf8(NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD,strlen(NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD),temp,1024);
		strcpy_s(NOTIFY_YOUKE_CAN_NOT_CREATE_GUILD,temp);

		strcpy_s(NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD,"�οͲ����Լ����л�");
		UtilString::act_2_utf8(NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD,strlen(NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD),temp,1024);
		strcpy_s(NOTIFY_YOUKE_CAN_NOT_JOIN_GUILD,temp);

		strcpy_s(NOTIFY_CONGZI_INFO,"��� %s ͨ�����̵�Ԫ����ֵ���ܻ�� %d Ԫ��");
		UtilString::act_2_utf8(NOTIFY_CONGZI_INFO,strlen(NOTIFY_CONGZI_INFO),temp,1024);
		strcpy_s(NOTIFY_CONGZI_INFO,temp);

		strcpy_s(NOTIFY_BUY_ITEM_BAG_FULL,"��������,�����Թ���");
		UtilString::act_2_utf8(NOTIFY_BUY_ITEM_BAG_FULL,strlen(NOTIFY_BUY_ITEM_BAG_FULL),temp,1024);
		strcpy_s(NOTIFY_BUY_ITEM_BAG_FULL,temp);

		strcpy_s(NOTIFY_ITEM_BAG_FULL,"��������.");
		UtilString::act_2_utf8(NOTIFY_ITEM_BAG_FULL,strlen(NOTIFY_ITEM_BAG_FULL),temp,1024);
		strcpy_s(NOTIFY_ITEM_BAG_FULL,temp);

		strcpy_s(NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN,"Ԫ������,��������Ʒդ����Ҫ���� %d Ԫ��");
		UtilString::act_2_utf8(NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN,strlen(NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN),temp,1024);
		strcpy_s(NOTIFY_ADD_SLOT_NOT_ENOUPH_VCOIN,temp);

		strcpy_s(NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE,"�ο�ģʽ�����Դ�������");
		UtilString::act_2_utf8(NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE,strlen(NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE),temp,1024);
		strcpy_s(NOTIFY_GROUP_CREATE_FAIL_ERROR_AUTH_TYPE,temp);

		strcpy_s(NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE,"�ο�ģʽ�����Լ������");
		UtilString::act_2_utf8(NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE,strlen(NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE),temp,1024);
		strcpy_s(NOTIFY_GROUP_JOIN_FAIL_ERROR_AUTH_TYPE,temp);

		strcpy_s(NOTIFY_GROUP_MEMBER_ADD,"��� %s �������");
		UtilString::act_2_utf8(NOTIFY_GROUP_MEMBER_ADD,strlen(NOTIFY_GROUP_MEMBER_ADD),temp,1024);
		strcpy_s(NOTIFY_GROUP_MEMBER_ADD,temp);

		strcpy_s(NOTIFY_JOIN_GROUP,"������� %s �Ķ���.");
		UtilString::act_2_utf8(NOTIFY_JOIN_GROUP,strlen(NOTIFY_JOIN_GROUP),temp,1024);
		strcpy_s(NOTIFY_JOIN_GROUP,temp);

		strcpy_s(NOTIFY_GROUP_MEMBER_REM,"��� %s �뿪����");
		UtilString::act_2_utf8(NOTIFY_GROUP_MEMBER_REM,strlen(NOTIFY_GROUP_MEMBER_REM),temp,1024);
		strcpy_s(NOTIFY_GROUP_MEMBER_REM,temp);

		strcpy_s(NOTIFY_LEAVE_GROUP,"�����뿪����");
		UtilString::act_2_utf8(NOTIFY_LEAVE_GROUP,strlen(NOTIFY_LEAVE_GROUP),temp,1024);
		strcpy_s(NOTIFY_LEAVE_GROUP,temp);

		strcpy_s(NOTIFY_TRADE_FAIL,"����ȡ��");
		UtilString::act_2_utf8(NOTIFY_TRADE_FAIL,strlen(NOTIFY_TRADE_FAIL),temp,1024);
		strcpy_s(NOTIFY_TRADE_FAIL,temp);

		strcpy_s(NOTIFY_TRADE_SUC,"���׳ɹ�");
		UtilString::act_2_utf8(NOTIFY_TRADE_SUC,strlen(NOTIFY_TRADE_SUC),temp,1024);
		strcpy_s(NOTIFY_TRADE_SUC,temp); 

		strcpy_s(NOTIFY_CHATTRADE_SUC,"��� %s �� %s �Ѿ������ %s ����");//"��� &s �� %s �Ѿ������ %s ����
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_SUC,strlen(NOTIFY_CHATTRADE_SUC),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_SUC,temp);

		strcpy_s(NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR,"������Ʒ�������޸�,�޷��鿴");
		UtilString::act_2_utf8(NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR,strlen(NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR),temp,1024);
		strcpy_s(NOTIFY_TRADE_PLAYER_ITEM_DATA_ERROR,temp); 

		strcpy_s(NOTIFY_TRADE_PLAYER_OFFLINE,"����������,��ͣ����");
		UtilString::act_2_utf8(NOTIFY_TRADE_PLAYER_OFFLINE,strlen(NOTIFY_TRADE_PLAYER_OFFLINE),temp,1024);
		strcpy_s(NOTIFY_TRADE_PLAYER_OFFLINE,temp);  

		strcpy_s(NOTIFY_CHATTRADE_ADDITEM_SUC,"��Ʒ�ϼܳɹ�");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_ADDITEM_SUC,strlen(NOTIFY_CHATTRADE_ADDITEM_SUC),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_ADDITEM_SUC, temp); 

		strcpy_s(NOTIFY_NO_FRIEND_ONLINE, "�����޺�������");
		UtilString::act_2_utf8(NOTIFY_NO_FRIEND_ONLINE, strlen(NOTIFY_NO_FRIEND_ONLINE), temp, 1024);
		strcpy_s(NOTIFY_NO_FRIEND_ONLINE, temp);

		strcpy_s(NOTIFY_CHATTRADE_ADDITEM_FAIL,"��Ʒ�ϼ�ʧ��");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_ADDITEM_FAIL,strlen(NOTIFY_CHATTRADE_ADDITEM_FAIL),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_ADDITEM_FAIL,temp);

		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_SUC,"��Ʒ�¼ܳɹ�,�Զ����뱳��");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_SUBITEM_SUC,strlen(NOTIFY_CHATTRADE_SUBITEM_SUC),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_SUC,temp);

		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_FAIL,"��Ʒ�¼�ʧ��,����Ʒ�Ѳ�����");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_SUBITEM_FAIL,strlen(NOTIFY_CHATTRADE_SUBITEM_FAIL),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_FAIL,temp);

		strcpy_s(NOTIFY_CHATTRADE_MYSELF,"���������ҽ���");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_MYSELF,strlen(NOTIFY_CHATTRADE_MYSELF),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_MYSELF,temp);

		strcpy_s(NOTIFY_CHATTRADE_FAIL,"����ʧ��,����Ʒ���¼�");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_FAIL,strlen(NOTIFY_CHATTRADE_FAIL),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_FAIL, temp); 

		strcpy_s(NOTIFY_CHANGE_ATTACK_MODE_FAIL,"����ģʽ������,�л�ʧ��");
		UtilString::act_2_utf8(NOTIFY_CHANGE_ATTACK_MODE_FAIL,strlen(NOTIFY_CHANGE_ATTACK_MODE_FAIL),temp,1024);
		strcpy_s(NOTIFY_CHANGE_ATTACK_MODE_FAIL, temp); 

		strcpy_s(NOTIFY_MAP_NOGOD, "�˵�ͼ��ֹս�����");
		UtilString::act_2_utf8(NOTIFY_MAP_NOGOD, strlen(NOTIFY_MAP_NOGOD), temp, 1024);
		strcpy_s(NOTIFY_MAP_NOGOD, temp);
		
		strcpy_s(NOTIFY_CHATTRADE_BAGFULL, "���������������������������");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_BAGFULL, strlen(NOTIFY_CHATTRADE_BAGFULL), temp, 1024);
		strcpy_s(NOTIFY_CHATTRADE_BAGFULL, temp);

		strcpy_s(NOTIFY_CHATTRADE_MONEY_NOTENOUGH,"����ʧ��,Ԫ������:%d");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_MONEY_NOTENOUGH,strlen(NOTIFY_CHATTRADE_MONEY_NOTENOUGH),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_MONEY_NOTENOUGH, temp);  

		strcpy_s(NOTIFY_HUICHENGSHI_CISHU, "����ʯʣ��ʹ�ô���:%d");
		UtilString::act_2_utf8(NOTIFY_HUICHENGSHI_CISHU, strlen(NOTIFY_HUICHENGSHI_CISHU), temp, 1024);
		strcpy_s(NOTIFY_HUICHENGSHI_CISHU, temp);

		strcpy_s(NOTIFY_SLAVE_AI_OPEN,"�����Զ������Ѵ�,����ͨ����������ر�");
		UtilString::act_2_utf8(NOTIFY_SLAVE_AI_OPEN,strlen(NOTIFY_SLAVE_AI_OPEN),temp,1024);
		strcpy_s(NOTIFY_SLAVE_AI_OPEN,temp);

		strcpy_s(NOTIFY_SLAVE_AI_CLOSE,"�����Զ������ѹر�,����ͨ�����������");
		UtilString::act_2_utf8(NOTIFY_SLAVE_AI_CLOSE,strlen(NOTIFY_SLAVE_AI_CLOSE),temp,1024);
		strcpy_s(NOTIFY_SLAVE_AI_CLOSE,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_EMPTY_NAME,"����ʧ��,�л���Ϊ��.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_EMPTY_NAME,strlen(NOTIFY_GUILD_CREATE_EMPTY_NAME),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_EMPTY_NAME,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_TOO_LONG_NAME,"����ʧ��,�л����ƹ���.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_TOO_LONG_NAME,strlen(NOTIFY_GUILD_CREATE_TOO_LONG_NAME),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_TOO_LONG_NAME,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_NAME_PROHIBITED,"����ʧ��,�л������а����Ƿ��ַ�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_NAME_PROHIBITED,strlen(NOTIFY_GUILD_CREATE_NAME_PROHIBITED),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_NAME_PROHIBITED,temp);
		
		strcpy_s(NOTIFY_GUILD_CREATE_EXIST_NAME,"����ʧ��,�����ֵ��л��Ѵ���.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_EXIST_NAME,strlen(NOTIFY_GUILD_CREATE_EXIST_NAME),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_EXIST_NAME,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_CONDITION_FAIL,"����ʧ��,�����㴴���л��Ҫ��.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_CONDITION_FAIL,strlen(NOTIFY_GUILD_CREATE_CONDITION_FAIL),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_CONDITION_FAIL,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR,"����ʧ��,�ο�ģʽ�����Դ����л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR,strlen(NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_AUTH_TYPE_ERROR,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_HAVE_GUILD,"����ʧ��,�Ѿ�ӵ���л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_HAVE_GUILD,strlen(NOTIFY_GUILD_CREATE_HAVE_GUILD),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_HAVE_GUILD,temp);

		strcpy_s(NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR,"�����л�ʧ��,�ο�ģʽ�����Լ����л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR,strlen(NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR),temp,1024);
		strcpy_s(NOTIFY_GUILD_JOIN_AUTH_TYPE_ERROR,temp);

		strcpy_s(NOTIFY_GUILD_JOIN_HAVED,"�����л�ʧ��,�Ѿ����л�����.");
		UtilString::act_2_utf8(NOTIFY_GUILD_JOIN_HAVED,strlen(NOTIFY_GUILD_JOIN_HAVED),temp,1024);
		strcpy_s(NOTIFY_GUILD_JOIN_HAVED,temp);
		
		strcpy_s(NOTIFY_GUILD_JOIN_NOT_EXIST,"�����л�ʧ��,�л᲻����.");
		UtilString::act_2_utf8(NOTIFY_GUILD_JOIN_NOT_EXIST,strlen(NOTIFY_GUILD_JOIN_NOT_EXIST),temp,1024);
		strcpy_s(NOTIFY_GUILD_JOIN_NOT_EXIST,temp);

		strcpy_s(NOTIFY_GUILD_ADV_FULL,"ֻ�ܴ�����λ���᳤!");
		UtilString::act_2_utf8(NOTIFY_GUILD_ADV_FULL,strlen(NOTIFY_GUILD_ADV_FULL),temp,1024);
		strcpy_s(NOTIFY_GUILD_ADV_FULL,temp);

		strcpy_s(NOTIFY_MAIL_FULL, "�ʼ��Ѵ������Ŀ30,����ɾ�������ʼ�����������ʼ�!");
		UtilString::act_2_utf8(NOTIFY_MAIL_FULL, strlen(NOTIFY_MAIL_FULL), temp, 1024);
		strcpy_s(NOTIFY_MAIL_FULL, temp);

		strcpy_s(NOTIFY_GROUP_MEMBER_ONLINE,"��Ա %s ������.");
		UtilString::act_2_utf8(NOTIFY_GROUP_MEMBER_ONLINE,strlen(NOTIFY_GROUP_MEMBER_ONLINE),temp,1024);
		strcpy_s(NOTIFY_GROUP_MEMBER_ONLINE,temp);

		strcpy_s(NOTIFY_GROUP_MEMBER_OFFLINE,"��Ա %s ������.");
		UtilString::act_2_utf8(NOTIFY_GROUP_MEMBER_OFFLINE,strlen(NOTIFY_GROUP_MEMBER_OFFLINE),temp,1024);
		strcpy_s(NOTIFY_GROUP_MEMBER_OFFLINE,temp);

		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_NOITEM,"����Ʒ�ѱ���� %s ����");
		UtilString::act_2_utf8(NOTIFY_CHATTRADE_SUBITEM_NOITEM,strlen(NOTIFY_CHATTRADE_SUBITEM_NOITEM),temp,1024);
		strcpy_s(NOTIFY_CHATTRADE_SUBITEM_NOITEM,temp);

		strcpy_s(NOTIFY_GUILD_MEMBER_ENTERING,"��� %s ��������л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_MEMBER_ENTERING,strlen(NOTIFY_GUILD_MEMBER_ENTERING),temp,1024);
		strcpy_s(NOTIFY_GUILD_MEMBER_ENTERING,temp);

		strcpy_s(NOTIFY_GUILD_ADD_PRESIDENT, "��� %s ��Ϊ���лḱ�᳤.");
		UtilString::act_2_utf8(NOTIFY_GUILD_ADD_PRESIDENT, strlen(NOTIFY_GUILD_ADD_PRESIDENT), temp, 1024);
		strcpy_s(NOTIFY_GUILD_ADD_PRESIDENT, temp); 

		strcpy_s(NOTIFY_GUILD_SUB_PRESIDENT, " ��� %s ��ȡ���˸��᳤�ʸ�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_SUB_PRESIDENT, strlen(NOTIFY_GUILD_SUB_PRESIDENT), temp, 1024);
		strcpy_s(NOTIFY_GUILD_SUB_PRESIDENT, temp); 

		strcpy_s(NOTIFY_GUILD_BECOME_ADMIN, " ��� %s ��Ϊ�˻᳤.");
		UtilString::act_2_utf8(NOTIFY_GUILD_BECOME_ADMIN, strlen(NOTIFY_GUILD_BECOME_ADMIN), temp, 1024);
		strcpy_s(NOTIFY_GUILD_BECOME_ADMIN, temp);

		strcpy_s(GUILD_RED_PACKET_MAIL_TITLE, "������˻�");
		UtilString::act_2_utf8(GUILD_RED_PACKET_MAIL_TITLE, strlen(GUILD_RED_PACKET_MAIL_TITLE), temp, 1024);
		strcpy_s(GUILD_RED_PACKET_MAIL_TITLE, temp);

		strcpy_s(GUILD_RED_PACKET_MAIL_CONTENT, "�˻غ��");
		UtilString::act_2_utf8(GUILD_RED_PACKET_MAIL_CONTENT, strlen(GUILD_RED_PACKET_MAIL_CONTENT), temp, 1024);
		strcpy_s(GUILD_RED_PACKET_MAIL_CONTENT, temp);

		strcpy_s(NOTIFY_UPGRADEEQUIP_BREAK,"����ʧ��,װ��������.");
		UtilString::act_2_utf8(NOTIFY_UPGRADEEQUIP_BREAK,strlen(NOTIFY_UPGRADEEQUIP_BREAK),temp,1024);
		strcpy_s(NOTIFY_UPGRADEEQUIP_BREAK,temp);

		strcpy_s(NOTIFY_SAFEAREA_ENTER,"���밲ȫ��.");
		UtilString::act_2_utf8(NOTIFY_SAFEAREA_ENTER,strlen(NOTIFY_SAFEAREA_ENTER),temp,1024);
		strcpy_s(NOTIFY_SAFEAREA_ENTER,temp);

		strcpy_s(NOTIFY_SAFEAREA_LEAVE,"�뿪��ȫ��.");
		UtilString::act_2_utf8(NOTIFY_SAFEAREA_LEAVE,strlen(NOTIFY_SAFEAREA_LEAVE),temp,1024);
		strcpy_s(NOTIFY_SAFEAREA_LEAVE,temp);

		strcpy_s(NOTIFY_STATUS_NO_DAMAGE,"Ŀ�����޵�״̬��,�˺�������.");
		UtilString::act_2_utf8(NOTIFY_STATUS_NO_DAMAGE,strlen(NOTIFY_STATUS_NO_DAMAGE),temp,1024);
		strcpy_s(NOTIFY_STATUS_NO_DAMAGE,temp);

		strcpy_s(NOTIFY_STATUS_NO_DROP_ON_DIE,"������Ʒ����״̬��,û�е�����Ʒ.");
		UtilString::act_2_utf8(NOTIFY_STATUS_NO_DROP_ON_DIE,strlen(NOTIFY_STATUS_NO_DROP_ON_DIE),temp,1024);
		strcpy_s(NOTIFY_STATUS_NO_DROP_ON_DIE,temp);

		strcpy_s(NOTIFY_PK_LEVEL_LIMIT,"�ȼ����� %d ��,������PK.");
		UtilString::act_2_utf8(NOTIFY_PK_LEVEL_LIMIT,strlen(NOTIFY_PK_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_PK_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_IN_CHINA_LIMIT,"���ѱ����������ϵͳ");
		UtilString::act_2_utf8(NOTIFY_IN_CHINA_LIMIT,strlen(NOTIFY_IN_CHINA_LIMIT),temp,1024);
		strcpy_s(NOTIFY_IN_CHINA_LIMIT,temp);

		strcpy_s(NOTIFY_GUILD_FULL,"�л�������������,�������ټ����л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_FULL,strlen(NOTIFY_GUILD_FULL),temp,1024);
		strcpy_s(NOTIFY_GUILD_FULL,temp);

		strcpy_s(NOTIFY_GUILD_WAR_START,"��������%s������ս.");
		UtilString::act_2_utf8(NOTIFY_GUILD_WAR_START,strlen(NOTIFY_GUILD_WAR_START),temp,1024);
		strcpy_s(NOTIFY_GUILD_WAR_START,temp);

		strcpy_s(NOTIFY_RELIVE_STAND_NOT_ALLOW,"�˵�ͼ��ֹԭ�ظ���.");
		UtilString::act_2_utf8(NOTIFY_RELIVE_STAND_NOT_ALLOW,strlen(NOTIFY_RELIVE_STAND_NOT_ALLOW),temp,1024);
		strcpy_s(NOTIFY_RELIVE_STAND_NOT_ALLOW,temp);

		strcpy_s(NOTIFY_GUILD_CREATE_LEVEL_LIMIT,"%d�����²��������л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_CREATE_LEVEL_LIMIT,strlen(NOTIFY_GUILD_CREATE_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_GUILD_CREATE_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_GUILD_JOIN_LEVEL_LIMIT,"%d�����²���������л�.");
		UtilString::act_2_utf8(NOTIFY_GUILD_JOIN_LEVEL_LIMIT,strlen(NOTIFY_GUILD_JOIN_LEVEL_LIMIT),temp,1024);
		strcpy_s(NOTIFY_GUILD_JOIN_LEVEL_LIMIT,temp);

		strcpy_s(NOTIFY_SERVER_FULL,"���������ѱ���,Ϊ��������������Ϸ,��ѡ������������Ϸ.");
		UtilString::act_2_utf8(NOTIFY_SERVER_FULL,strlen(NOTIFY_SERVER_FULL),temp,1024);
		strcpy_s(NOTIFY_SERVER_FULL,temp);

		strcpy_s(NOTIFY_STEEL_EQUIP_NO_MONEY,"��Ҳ���,�����Բ��װ��.");
		UtilString::act_2_utf8(NOTIFY_STEEL_EQUIP_NO_MONEY,strlen(NOTIFY_STEEL_EQUIP_NO_MONEY),temp,1024);
		strcpy_s(NOTIFY_STEEL_EQUIP_NO_MONEY,temp);

		strcpy_s(NOTIFY_STEEL_EQUIP_NO_BAG_ROOM,"�����ռ䲻��,�����Բ��װ��.");
		UtilString::act_2_utf8(NOTIFY_STEEL_EQUIP_NO_BAG_ROOM,strlen(NOTIFY_STEEL_EQUIP_NO_BAG_ROOM),temp,1024);
		strcpy_s(NOTIFY_STEEL_EQUIP_NO_BAG_ROOM,temp);

		strcpy_s(NOTIFY_STEEL_EQUIP_NO_LEVEL,"װ��δ����,�����Բ��װ��.");
		UtilString::act_2_utf8(NOTIFY_STEEL_EQUIP_NO_LEVEL,strlen(NOTIFY_STEEL_EQUIP_NO_LEVEL),temp,1024);
		strcpy_s(NOTIFY_STEEL_EQUIP_NO_LEVEL,temp);

		strcpy_s(NOTIFY_STEEL_EQUIP_SUC,"��ʯ��ֳɹ�.");
		UtilString::act_2_utf8(NOTIFY_STEEL_EQUIP_SUC,strlen(NOTIFY_STEEL_EQUIP_SUC),temp,1024);
		strcpy_s(NOTIFY_STEEL_EQUIP_SUC,temp);

		strcpy_s(NOTIFY_ITEM_USE_BROKE,"��Ʒ����,���������װ��.");
		UtilString::act_2_utf8(NOTIFY_ITEM_USE_BROKE,strlen(NOTIFY_ITEM_USE_BROKE),temp,1024);
		strcpy_s(NOTIFY_ITEM_USE_BROKE,temp);

		strcpy_s(NOTIFY_MERGE_FASHION_CONDITION_FAIL,"ֻ��������������ʱװ�����������·�ʱװ�ſ��Ժϳ�ϡ��ʱװ.");
		UtilString::act_2_utf8(NOTIFY_MERGE_FASHION_CONDITION_FAIL,strlen(NOTIFY_MERGE_FASHION_CONDITION_FAIL),temp,1024);
		strcpy_s(NOTIFY_MERGE_FASHION_CONDITION_FAIL,temp);

		strcpy_s(NOTIFY_MERGE_XYFASHION_CONDITION_FAIL,"ϡ��ʱװ�����ٲ���ϳ�.");
		UtilString::act_2_utf8(NOTIFY_MERGE_XYFASHION_CONDITION_FAIL,strlen(NOTIFY_MERGE_XYFASHION_CONDITION_FAIL),temp,1024);
		strcpy_s(NOTIFY_MERGE_XYFASHION_CONDITION_FAIL,temp);

		strcpy_s(NOTIFY_ITEM_DESTORY_LIMIT_FAIL,"����Ʒ���ܱ���������.");
		UtilString::act_2_utf8(NOTIFY_ITEM_DESTORY_LIMIT_FAIL,strlen(NOTIFY_ITEM_DESTORY_LIMIT_FAIL),temp,1024);
		strcpy_s(NOTIFY_ITEM_DESTORY_LIMIT_FAIL,temp);

		strcpy_s(NOTIFY_ITEM_USE_GENDER_ERROR,"�Ա�ƥ��,װ��ʧ��.");
		UtilString::act_2_utf8(NOTIFY_ITEM_USE_GENDER_ERROR,strlen(NOTIFY_ITEM_USE_GENDER_ERROR),temp,1024);
		strcpy_s(NOTIFY_ITEM_USE_GENDER_ERROR,temp);

		strcpy_s(NOTIFY_ITEM_USE_JOB_ERROR,"ְҵ��ƥ��,װ��ʧ��.");
		UtilString::act_2_utf8(NOTIFY_ITEM_USE_JOB_ERROR,strlen(NOTIFY_ITEM_USE_JOB_ERROR),temp,1024);
		strcpy_s(NOTIFY_ITEM_USE_JOB_ERROR,temp);

		strcpy_s(NOTIFY_ITEM_EXCHANGE_LV_LIMIT,"%d ���²�����ʹ��װ���һ�����.");
		UtilString::act_2_utf8(NOTIFY_ITEM_EXCHANGE_LV_LIMIT,strlen(NOTIFY_ITEM_EXCHANGE_LV_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ITEM_EXCHANGE_LV_LIMIT,temp);

		strcpy_s(NOTIFY_ADD_FRIEND_NO_EXIST,"����Ҳ����߻򲻴��ڣ��������.");
		UtilString::act_2_utf8(NOTIFY_ADD_FRIEND_NO_EXIST,strlen(NOTIFY_ADD_FRIEND_NO_EXIST),temp,1024);
		strcpy_s(NOTIFY_ADD_FRIEND_NO_EXIST,temp);

		strcpy_s(NOTIFY_CHECK_EQUIP_NO_EXIST,"����Ҳ����ߣ����ܲ鿴װ��.");
		UtilString::act_2_utf8(NOTIFY_CHECK_EQUIP_NO_EXIST,strlen(NOTIFY_CHECK_EQUIP_NO_EXIST),temp,1024);
		strcpy_s(NOTIFY_CHECK_EQUIP_NO_EXIST,temp);

		//strcpy_s(NOTIFY_CHINA_LIMIT_OK,"��������Ϣ���ύ�ɹ�.");
		//UtilString::act_2_utf8(NOTIFY_CHINA_LIMIT_OK,strlen(NOTIFY_CHINA_LIMIT_OK),temp,1024);
		//strcpy_s(NOTIFY_CHINA_LIMIT_OK,temp);

		//strcpy_s(NOTIFY_CHINA_LIMIT_GAMEMONEY_NOTIFY,"���ԭʼ���� %d,�����Ժ����� %d.");
		//UtilString::act_2_utf8(NOTIFY_CHINA_LIMIT_GAMEMONEY_NOTIFY,strlen(NOTIFY_CHINA_LIMIT_GAMEMONEY_NOTIFY),temp,1024);
		//strcpy_s(NOTIFY_CHINA_LIMIT_GAMEMONEY_NOTIFY,temp);

		//strcpy_s(NOTIFY_CHINA_LIMIT_GAMEMONEYBIND_NOTIFY,"����ԭʼ���� %d,�����Ժ����� %d.");
		//UtilString::act_2_utf8(NOTIFY_CHINA_LIMIT_GAMEMONEYBIND_NOTIFY,strlen(NOTIFY_CHINA_LIMIT_GAMEMONEYBIND_NOTIFY),temp,1024);
		//strcpy_s(NOTIFY_CHINA_LIMIT_GAMEMONEYBIND_NOTIFY,temp);

		//strcpy_s(NOTIFY_CHINA_LIMIT_VCOINBIND_NOTIFY,"��Ԫ��ԭʼ���� %d,�����Ժ����� %d.");
		//UtilString::act_2_utf8(NOTIFY_CHINA_LIMIT_VCOINBIND_NOTIFY,strlen(NOTIFY_CHINA_LIMIT_VCOINBIND_NOTIFY),temp,1024);
		//strcpy_s(NOTIFY_CHINA_LIMIT_VCOINBIND_NOTIFY,temp);

		//strcpy_s(NOTIFY_CHINA_LIMIT_EXP_NOTIFY,"����ԭʼ���� %d,�����Ժ����� %d.");
		//UtilString::act_2_utf8(NOTIFY_CHINA_LIMIT_EXP_NOTIFY,strlen(NOTIFY_CHINA_LIMIT_EXP_NOTIFY),temp,1024);
		//strcpy_s(NOTIFY_CHINA_LIMIT_EXP_NOTIFY,temp);

		strcpy_s(NOTIFY_HORN_HAVE_NO,"���İ�����û�����ȵ���,������̳ǹ���.");
		UtilString::act_2_utf8(NOTIFY_HORN_HAVE_NO,strlen(NOTIFY_HORN_HAVE_NO),temp,1024);
		strcpy_s(NOTIFY_HORN_HAVE_NO,temp);

		strcpy_s(NOTIFY_WAR_KILL,"%s �л�� %s �ڹ���ս�л�ɱ�� %s �л�� %s.");
		UtilString::act_2_utf8(NOTIFY_WAR_KILL,strlen(NOTIFY_WAR_KILL),temp,1024);
		strcpy_s(NOTIFY_WAR_KILL,temp);

		strcpy_s(NOTIFY_WAR_KILL_RAM,"%s �л�� %s �ڹ���ս�м����� %s �л�Ĺ��ǳ�.");
		UtilString::act_2_utf8(NOTIFY_WAR_KILL_RAM,strlen(NOTIFY_WAR_KILL_RAM),temp,1024);
		strcpy_s(NOTIFY_WAR_KILL_RAM,temp);

		strcpy_s(NOTIFY_NPC_SELL_DENY,"����Ʒ�����Ի���.");
		UtilString::act_2_utf8(NOTIFY_NPC_SELL_DENY,strlen(NOTIFY_NPC_SELL_DENY),temp,1024);
		strcpy_s(NOTIFY_NPC_SELL_DENY,temp);

		strcpy_s(NOTIFY_GIFT,"ͨ��<font color='#FF0000'> %s </font>���<font color='#FF0000'> %s </font>.");
		UtilString::act_2_utf8(NOTIFY_GIFT,strlen(NOTIFY_GIFT),temp,1024);
		strcpy_s(NOTIFY_GIFT,temp);

		strcpy_s(NOTIFY_FRIEND_AUTHTYPE_ERROR,"�ο�ģʽ�����ź���ϵͳ.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_AUTHTYPE_ERROR,strlen(NOTIFY_FRIEND_AUTHTYPE_ERROR),temp,1024);
		strcpy_s(NOTIFY_FRIEND_AUTHTYPE_ERROR,temp);

		strcpy_s(NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR,"���������ѹ���.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR,strlen(NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR),temp,1024);
		strcpy_s(NOTIFY_FRIEND_AGREE_TIMEOUT_ERROR,temp);

		strcpy_s(NOTIFY_FRIEND_OPERATER_ERROR,"��ϵ�˲���̫��Ƶ��,���Ժ�����.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_OPERATER_ERROR,strlen(NOTIFY_FRIEND_OPERATER_ERROR),temp,1024);
		strcpy_s(NOTIFY_FRIEND_OPERATER_ERROR,temp);

		strcpy_s(NOTIFY_FRIEND_TOO_MUCH,"���������ﵽ����,�����������ó���99.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_TOO_MUCH,strlen(NOTIFY_FRIEND_TOO_MUCH),temp,1024);
		strcpy_s(NOTIFY_FRIEND_TOO_MUCH,temp);

		strcpy_s(NOTIFY_ENEMY_TOO_MUCH,"���������ﵽ����,�����������ó���99.");
		UtilString::act_2_utf8(NOTIFY_ENEMY_TOO_MUCH,strlen(NOTIFY_ENEMY_TOO_MUCH),temp,1024);
		strcpy_s(NOTIFY_ENEMY_TOO_MUCH,temp);

		strcpy_s(NOTIFY_BLACK_TOO_MUCH,"���ĺ������Ѵ�����,�뼰ʱ����");
		UtilString::act_2_utf8(NOTIFY_BLACK_TOO_MUCH,strlen(NOTIFY_BLACK_TOO_MUCH),temp,1024);
		strcpy_s(NOTIFY_BLACK_TOO_MUCH,temp);

		strcpy_s(NOTIFY_FRIEND_DELETE,"ɾ����ϵ�� %s.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_DELETE,strlen(NOTIFY_FRIEND_DELETE),temp,1024);
		strcpy_s(NOTIFY_FRIEND_DELETE,temp);

		strcpy_s(NOTIFY_FRIEND_ADD,"�����ϵ�� %s.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_ADD,strlen(NOTIFY_FRIEND_ADD),temp,1024);
		strcpy_s(NOTIFY_FRIEND_ADD,temp);

		strcpy_s(NOTIFY_FRIEND_ADD_NOTIFY,"%s ����Ϊ����.");
		UtilString::act_2_utf8(NOTIFY_FRIEND_ADD_NOTIFY,strlen(NOTIFY_FRIEND_ADD_NOTIFY),temp,1024);
		strcpy_s(NOTIFY_FRIEND_ADD_NOTIFY,temp);

		strcpy_s(NOTIFY_CANCEL_BY_TRADING,"�����У�����ȡ��.");
		UtilString::act_2_utf8(NOTIFY_CANCEL_BY_TRADING,strlen(NOTIFY_CANCEL_BY_TRADING),temp,1024);
		strcpy_s(NOTIFY_CANCEL_BY_TRADING,temp);

		strcpy_s(NOTIFY_EXCUPD_FROM_NO_LEVEL,"Դװ��û��ǿ��,�������ۺ�.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_FROM_NO_LEVEL,strlen(NOTIFY_EXCUPD_FROM_NO_LEVEL),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_FROM_NO_LEVEL,temp);

		strcpy_s(NOTIFY_EXCUPD_TO_HAVE_LEVEL,"Ŀ��װ����ǿ��,�������ۺ�.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_TO_HAVE_LEVEL,strlen(NOTIFY_EXCUPD_TO_HAVE_LEVEL),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_TO_HAVE_LEVEL,temp);

		strcpy_s(NOTIFY_EXCUPD_BIND_TO_NOBIND,"��װ����������ǰ�װ���ۺ�.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_BIND_TO_NOBIND,strlen(NOTIFY_EXCUPD_BIND_TO_NOBIND),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_BIND_TO_NOBIND,temp);

		strcpy_s(NOTIFY_EXCUPD_EQUIP_TYPE_DIFF,"װ�����Ͳ�ͬ�������ۺ�.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_EQUIP_TYPE_DIFF,strlen(NOTIFY_EXCUPD_EQUIP_TYPE_DIFF),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_EQUIP_TYPE_DIFF,temp);

		strcpy_s(NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW,"�������ߵȼ�̫��,�ۺ�ȡ��.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW,strlen(NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_PROTECTITEM_LEVEL_TOO_LOW,temp);

		strcpy_s(NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH,"��Ҳ���,�ۺ�ȡ��.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH,strlen(NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_EQUIP_GM_NOT_ENOUPH,temp);

		strcpy_s(NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH,"��Ԫ������,�ۺ�ȡ��.");
		UtilString::act_2_utf8(NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH,strlen(NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH),temp,1024);
		strcpy_s(NOTIFY_EXCUPD_EQUIP_BV_NOT_ENOUPH,temp);

		strcpy_s(NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN,"װ��Ʒ���½� %d.");
		UtilString::act_2_utf8(NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN,strlen(NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN),temp,1024);
		strcpy_s(NOTIFY_ITEM_EXCHANGE_UPD_LEVEL_DOWN,temp);

		strcpy_s(NOTIFY_PK_KILL_SUB_LUCK,"���������������.");
		UtilString::act_2_utf8(NOTIFY_PK_KILL_SUB_LUCK,strlen(NOTIFY_PK_KILL_SUB_LUCK),temp,1024);
		strcpy_s(NOTIFY_PK_KILL_SUB_LUCK,temp);

		strcpy_s(NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN,"Ԫ������,����������");
		UtilString::act_2_utf8(NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN,strlen(NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN),temp,1024);
		strcpy_s(NOTIFY_PROTECT_ITEM_NOT_ENOUPH_VCOIN,temp);

		strcpy_s(NOTIFY_GAMEMONEY_ENOUGH, "���Ľ���Ѵﵽ���洢����");
		UtilString::act_2_utf8(NOTIFY_GAMEMONEY_ENOUGH, strlen(NOTIFY_GAMEMONEY_ENOUGH), temp, 1024);
		strcpy_s(NOTIFY_GAMEMONEY_ENOUGH, temp);

		strcpy_s(NOTIFY_GAMEMONEYBIND_ENOUGH, "���İ󶨽���Ѵﵽ���洢��");
		UtilString::act_2_utf8(NOTIFY_GAMEMONEYBIND_ENOUGH, strlen(NOTIFY_GAMEMONEYBIND_ENOUGH), temp, 1024);
		strcpy_s(NOTIFY_GAMEMONEYBIND_ENOUGH, temp);

		strcpy_s(NOTIFY_VCOIN_ENOUGH, "����Ԫ���Ѵﵽ���洢��");
		UtilString::act_2_utf8(NOTIFY_VCOIN_ENOUGH, strlen(NOTIFY_VCOIN_ENOUGH), temp, 1024);
		strcpy_s(NOTIFY_VCOIN_ENOUGH, temp);

		strcpy_s(NOTIFY_VCOINBIND_ENOUGH, "���İ�Ԫ���Ѵﵽ���洢��");
		UtilString::act_2_utf8(NOTIFY_VCOINBIND_ENOUGH, strlen(NOTIFY_VCOINBIND_ENOUGH), temp, 1024);
		strcpy_s(NOTIFY_VCOINBIND_ENOUGH, temp);

		strcpy_s(NOTIFY_MAIL_TITLE,"ϵͳ�ʼ�");
		UtilString::act_2_utf8(NOTIFY_MAIL_TITLE,strlen(NOTIFY_MAIL_TITLE),temp,1024);
		strcpy_s(NOTIFY_MAIL_TITLE,temp);

		strcpy_s(NOTIFY_MAIL_CONTENT,"��л��֧�����ǵ���Ϸ,���ǻ���õ������Ϸ����.");
		UtilString::act_2_utf8(NOTIFY_MAIL_CONTENT,strlen(NOTIFY_MAIL_CONTENT),temp,1024);
		strcpy_s(NOTIFY_MAIL_CONTENT,temp);

		strcpy_s(NOTIFY_ANONYM_NAME,"������");
		UtilString::act_2_utf8(NOTIFY_ANONYM_NAME,strlen(NOTIFY_ANONYM_NAME),temp,1024);
		strcpy_s(NOTIFY_ANONYM_NAME,temp);

		strcpy_s(NOTIFY_PK_VALUE_DESP,"���PKֵ������.PKֵ��һ�ֳͷ�����,��PKֵ����200ʱ,��������䱳���е�����װ��,�ڳ����ڻᱻ���������ֹ���.");
		UtilString::act_2_utf8(NOTIFY_PK_VALUE_DESP,strlen(NOTIFY_PK_VALUE_DESP),temp,1024);
		strcpy_s(NOTIFY_PK_VALUE_DESP,temp);

		strcpy_s(NOTIFY_ADD_SLOT_MAX_LIMIT,"����ǰ��󿪰���������");
		UtilString::act_2_utf8(NOTIFY_ADD_SLOT_MAX_LIMIT,strlen(NOTIFY_ADD_SLOT_MAX_LIMIT),temp,1024);
		strcpy_s(NOTIFY_ADD_SLOT_MAX_LIMIT,temp);

		strcpy_s(NOTIFY_DART_OUT_TIME,"����ȡ��Ѻ�������ѳ�ʱ������ʧ��.");
		UtilString::act_2_utf8(NOTIFY_DART_OUT_TIME,strlen(NOTIFY_DART_OUT_TIME),temp,1024);
		strcpy_s(NOTIFY_DART_OUT_TIME,temp);

		strcpy_s(NOTIFY_DART_OUT_RANGE_REMAIND,"���Ѿ��뿪�ڳ����뾡���ȥ�������ڳ��������ƶ���");
		UtilString::act_2_utf8(NOTIFY_DART_OUT_RANGE_REMAIND,strlen(NOTIFY_DART_OUT_RANGE_REMAIND),temp,1024);
		strcpy_s(NOTIFY_DART_OUT_RANGE_REMAIND,temp);

		strcpy_s(NOTIFY_IS_DARTING,"�㵱ǰ����Ѻ������");
		UtilString::act_2_utf8(NOTIFY_IS_DARTING,strlen(NOTIFY_IS_DARTING),temp,1024);
		strcpy_s(NOTIFY_IS_DARTING,temp);

		strcpy_s(NOTIFY_ACCEPT_DART_TASK,"���Ѿ���ȡѺ������.");
		UtilString::act_2_utf8(NOTIFY_ACCEPT_DART_TASK,strlen(NOTIFY_ACCEPT_DART_TASK),temp,1024);
		strcpy_s(NOTIFY_ACCEPT_DART_TASK,temp);

		strcpy_s(NOTIFY_ROB_DART_NO_REWARD,"�ڳ��ѻٻ���but���������ĵȼ�������11�������ܻ�ý���.");
		UtilString::act_2_utf8(NOTIFY_ROB_DART_NO_REWARD,strlen(NOTIFY_ROB_DART_NO_REWARD),temp,1024);
		strcpy_s(NOTIFY_ROB_DART_NO_REWARD,temp);

		strcpy_s(NOTIFY_ROB_DART_NUMBER_FULL,"������ڴ�������.");
		UtilString::act_2_utf8(NOTIFY_ROB_DART_NUMBER_FULL,strlen(NOTIFY_ROB_DART_NUMBER_FULL),temp,1024);
		strcpy_s(NOTIFY_ROB_DART_NUMBER_FULL,temp);

		strcpy_s(NOTIFY_DART_DESTROYED,"����ڳ��Ѿ���,���Լ���ǰ��Ѻ��Ŀ�ĵ���ȡʣ�ཱ��.");
		UtilString::act_2_utf8(NOTIFY_DART_DESTROYED,strlen(NOTIFY_DART_DESTROYED),temp,1024);
		strcpy_s(NOTIFY_DART_DESTROYED,temp);

		strcpy_s(NOTIFY_DIRECTFLY_FORBID_DARTING,"Ѻ�ڹ����н�ֹ���ͣ�");
		UtilString::act_2_utf8(NOTIFY_DIRECTFLY_FORBID_DARTING,strlen(NOTIFY_DIRECTFLY_FORBID_DARTING),temp,1024);
		strcpy_s(NOTIFY_DIRECTFLY_FORBID_DARTING,temp);

		strcpy_s(NOTIFY_ACCEPT_DART_NUMBER_FULL,"�㵱�����ȡѺ������Ĵ���������");
		UtilString::act_2_utf8(NOTIFY_ACCEPT_DART_NUMBER_FULL,strlen(NOTIFY_ACCEPT_DART_NUMBER_FULL),temp,1024);
		strcpy_s(NOTIFY_ACCEPT_DART_NUMBER_FULL,temp);

		strcpy_s(NOTIFY_SKILL_FORBID_ROB_DART,"����ʱ��ֹʹ�øü��ܣ�");
		UtilString::act_2_utf8(NOTIFY_SKILL_FORBID_ROB_DART,strlen(NOTIFY_SKILL_FORBID_ROB_DART),temp,1024);
		strcpy_s(NOTIFY_SKILL_FORBID_ROB_DART,temp);

		strcpy_s(NOTIFY_DIRECT_FLY_MAP_FORBID,"�õ�ͼ�����Դ���.");
		UtilString::act_2_utf8(NOTIFY_DIRECT_FLY_MAP_FORBID,strlen(NOTIFY_DIRECT_FLY_MAP_FORBID),temp,1024);
		strcpy_s(NOTIFY_DIRECT_FLY_MAP_FORBID,temp);

		strcpy_s(NOTIFY_DIRECT_FLY_PKVALUE_FORBID,"����ʱ�����Դ���.");
		UtilString::act_2_utf8(NOTIFY_DIRECT_FLY_PKVALUE_FORBID,strlen(NOTIFY_DIRECT_FLY_PKVALUE_FORBID),temp,1024);
		strcpy_s(NOTIFY_DIRECT_FLY_PKVALUE_FORBID,temp);

		strcpy_s(NOTIFY_DIRECT_FLY_DEAD_FORBID,"����״̬ʱ��ֹ����.");
		UtilString::act_2_utf8(NOTIFY_DIRECT_FLY_DEAD_FORBID,strlen(NOTIFY_DIRECT_FLY_DEAD_FORBID),temp,1024);
		strcpy_s(NOTIFY_DIRECT_FLY_DEAD_FORBID,temp);

		strcpy_s(NOTIFY_CDUPDITEM_VCOIN_FAIL,"Ԫ������.");
		UtilString::act_2_utf8(NOTIFY_CDUPDITEM_VCOIN_FAIL,strlen(NOTIFY_CDUPDITEM_VCOIN_FAIL),temp,1024);
		strcpy_s(NOTIFY_CDUPDITEM_VCOIN_FAIL,temp);

		strcpy_s(NOTIFY_CANNOT_USE_LOTTERYDEPOT,"�òֿⲻ�ɴ����Ʒ");
		UtilString::act_2_utf8(NOTIFY_CANNOT_USE_LOTTERYDEPOT,strlen(NOTIFY_CANNOT_USE_LOTTERYDEPOT),temp,1024);
		strcpy_s(NOTIFY_CANNOT_USE_LOTTERYDEPOT,temp);

		strcpy_s(NOTIFY_BAG_AND_DEPOT_FULL,"�����Ͳֿ������");
		UtilString::act_2_utf8(NOTIFY_BAG_AND_DEPOT_FULL,strlen(NOTIFY_BAG_AND_DEPOT_FULL),temp,1024);
		strcpy_s(NOTIFY_BAG_AND_DEPOT_FULL,temp);

		strcpy_s(NOTIFY_MAP_NO_INFO_PLAYER,"�û��ͼ��ֹ�鿴�Է�װ��.");
		UtilString::act_2_utf8(NOTIFY_MAP_NO_INFO_PLAYER,strlen(NOTIFY_MAP_NO_INFO_PLAYER),temp,1024);
		strcpy_s(NOTIFY_MAP_NO_INFO_PLAYER,temp);

		strcpy_s(NOTIFY_MAP_NO_INFO_CHAT,"�û��ͼ��ֹ����.");
		UtilString::act_2_utf8(NOTIFY_MAP_NO_INFO_CHAT,strlen(NOTIFY_MAP_NO_INFO_CHAT),temp,1024);
		strcpy_s(NOTIFY_MAP_NO_INFO_CHAT,temp);

		strcpy_s(NOTIFY_SPLIT_BAG_FULL_FAIL,"��������,������������ٽ��в��.");
		UtilString::act_2_utf8(NOTIFY_SPLIT_BAG_FULL_FAIL,strlen(NOTIFY_SPLIT_BAG_FULL_FAIL),temp,1024);
		strcpy_s(NOTIFY_SPLIT_BAG_FULL_FAIL,temp);

		strcpy_s(NOTIFY_MAIL_RECEIVE_SUC,"�ɹ���ȡ�ʼ�����.");
		UtilString::act_2_utf8(NOTIFY_MAIL_RECEIVE_SUC,strlen(NOTIFY_MAIL_RECEIVE_SUC),temp,1024);
		strcpy_s(NOTIFY_MAIL_RECEIVE_SUC,temp);

		strcpy_s(NOTIFY_MAIL_HAVE_RECEIVED,"������ȡ�����ʼ�����.");
		UtilString::act_2_utf8(NOTIFY_MAIL_HAVE_RECEIVED,strlen(NOTIFY_MAIL_HAVE_RECEIVED),temp,1024);
		strcpy_s(NOTIFY_MAIL_HAVE_RECEIVED,temp);

		strcpy_s(NOTIFY_MAIL_DELETE_SUC,"�ɹ�ɾ���ʼ�.");
		UtilString::act_2_utf8(NOTIFY_MAIL_DELETE_SUC,strlen(NOTIFY_MAIL_DELETE_SUC),temp,1024);
		strcpy_s(NOTIFY_MAIL_DELETE_SUC,temp);

		strcpy_s(NOTIFY_MAIL_EXCEED_MAX_LENGTH,"�ʼ���������ʼ����ݳ�������󳤶�.");
		UtilString::act_2_utf8(NOTIFY_MAIL_EXCEED_MAX_LENGTH,strlen(NOTIFY_MAIL_EXCEED_MAX_LENGTH),temp,1024);
		strcpy_s(NOTIFY_MAIL_EXCEED_MAX_LENGTH,temp);

		strcpy_s(NOTIFY_MAIL_DELETE_UNRECEIVED,"�ʼ�����δ��ȡ,����ɾ��.");
		UtilString::act_2_utf8(NOTIFY_MAIL_DELETE_UNRECEIVED,strlen(NOTIFY_MAIL_DELETE_UNRECEIVED),temp,1024);
		strcpy_s(NOTIFY_MAIL_DELETE_UNRECEIVED,temp);

		strcpy_s(NOTIFY_MAIL_NOT_EXIST,"�ʼ�������.");
		UtilString::act_2_utf8(NOTIFY_MAIL_NOT_EXIST,strlen(NOTIFY_MAIL_NOT_EXIST),temp,1024);
		strcpy_s(NOTIFY_MAIL_NOT_EXIST,temp);

		strcpy_s(NOTIFY_BAG_BLANK_NOT_ENOUGH,"�����ո��� %d ��,�޷������Ʒ,������");
		UtilString::act_2_utf8(NOTIFY_BAG_BLANK_NOT_ENOUGH,strlen(NOTIFY_BAG_BLANK_NOT_ENOUGH),temp,1024);
		strcpy_s(NOTIFY_BAG_BLANK_NOT_ENOUGH,temp);
		
		strcpy_s(NOTIFY_STALL_STOP,"��ֹ̯ͣ");
		UtilString::act_2_utf8(NOTIFY_STALL_STOP,strlen(NOTIFY_STALL_STOP),temp,1024);
		strcpy_s(NOTIFY_STALL_STOP,temp);

		strcpy_s(NOTIFY_STALL_ITEM_FULL,"̯λ����,�޷������Ʒ");
		UtilString::act_2_utf8(NOTIFY_STALL_ITEM_FULL,strlen(NOTIFY_STALL_ITEM_FULL),temp,1024);
		strcpy_s(NOTIFY_STALL_ITEM_FULL,temp);

		strcpy_s(NOTIFY_STALL_NO_ACTION,"��̯���޷����в���");
		UtilString::act_2_utf8(NOTIFY_STALL_NO_ACTION,strlen(NOTIFY_STALL_NO_ACTION),temp,1024);
		strcpy_s(NOTIFY_STALL_NO_ACTION,temp);

		strcpy_s(NOTIFY_STALL_NAME_ERROR,"�����̯λ��");
		UtilString::act_2_utf8(NOTIFY_STALL_NAME_ERROR,strlen(NOTIFY_STALL_NAME_ERROR),temp,1024);
		strcpy_s(NOTIFY_STALL_NAME_ERROR,temp);

		strcpy_s(NOTIFY_CAN_NOT_DEPOT,"����Ʒ���ɷ���ֿ�.");
		UtilString::act_2_utf8(NOTIFY_CAN_NOT_DEPOT,strlen(NOTIFY_CAN_NOT_DEPOT),temp,1024);
		strcpy_s(NOTIFY_CAN_NOT_DEPOT,temp);

		strcpy_s(NOTIFY_CAN_NOT_DESTORY,"����Ʒ���ɴݻ�.");
		UtilString::act_2_utf8(NOTIFY_CAN_NOT_DESTORY,strlen(NOTIFY_CAN_NOT_DESTORY),temp,1024);
		strcpy_s(NOTIFY_CAN_NOT_DESTORY,temp);

		strcpy_s(NOTIFY_SAFEAREA_NO_DROP,"��ȫ�����ɶ�����Ʒ.");
		UtilString::act_2_utf8(NOTIFY_SAFEAREA_NO_DROP,strlen(NOTIFY_SAFEAREA_NO_DROP),temp,1024);
		strcpy_s(NOTIFY_SAFEAREA_NO_DROP,temp);

		strcpy_s(NOTIFY_PLAYER_NOT_ONLINE_CHAT,"��Ҳ�����,�޷�˽��.");
		UtilString::act_2_utf8(NOTIFY_PLAYER_NOT_ONLINE_CHAT,strlen(NOTIFY_PLAYER_NOT_ONLINE_CHAT),temp,1024);
		strcpy_s(NOTIFY_PLAYER_NOT_ONLINE_CHAT,temp);
		
		return true;
	}
	void ConstsString::dest()
	{
	}
	ConstsString::ConstsString(void)
	{
		LoadDefault();
	}
	ConstsString::~ConstsString(void)
	{
	}
}