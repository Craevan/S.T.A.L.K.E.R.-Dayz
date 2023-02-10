/*
	Описание: Скрипт выдачи индивидуального стартового лута, скина игрока и точек спавна
	Автор: 123new
	Установка:
	1. По пути: {папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\
		создать папку 'CustomSpawnPlayerConfig'
		и поместить в нее 3 файла скрипта: Script.c Sets.c init_mod.c
	2. В файле: {папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\init.c
		в самом верху файла добавить:
			#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\CustomSpawnPlayerConfig\init_mod.c"
	3.  В папке, обозначенной параметром запуска сервера '-profile=', поместить файл с именем CustomSpawnPlayerConfig.txt
		и заполнить его данными по следующему формату:
		UID|Skin_player|sets_numbers|points_spawns
		где UID - это steam64id от профиля игрока в steam
		Skin_player - точный id скина игрока (можно указать 0 для отключения опции)
		sets_numbers - номер сета со стартовым лутом (можно указать несколько через ';', указать один всего, либо указать 0 для отключения опции)
		points_spawns - координаты спавна игрока на карте в формате 'x y z' (можно указать несколько через ';', указать всего одну точку, либо указать 0 для отключения опции)
		Пример:
		76561198141889254|SurvivorM_Oliver|1|12955.091797 16.115206 7993.588379
		76561198141889256|SurvivorM_Oliver|1;2|14791.965820 76.481781 14041.661133;12029.079102 196.356125 7274.689941
		76561198141889253|SurvivorM_Oliver|0|0
	4. В файле Sets.c в папке: {папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\CustomSpawnPlayerConfig\
		настроить стартовый лут для ваших игроков и написать собственные сеты
		ВАЖНО: количество сетов можно делать любое, номера сетов брать от 1 и выше (не должно быть -1, либо 0, только от 1 и выше)
		Все что укажете в блоке default будет применено для всех игроков при респавне в случае, если им не выдан никакой сет!
	P.S. Прикрепить к соспавненному оружию магазин не получится, рабочего кода я не смог найти!!

	Если у вас папка активной миссии сервера отличается от dayzOffline.chernarusplus то переименуйте ее в строке, вписываемой в:
		{папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\init.c
		{папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\CustomSpawnPlayerConfig\init_mod.c

*/

class CustomSpawnPlayerConfig
{
	private string Location_Directory_config = "$profile:"; // Расположение папки с конфигом скрипта
	private string Location_filename_config = "CustomSpawnPlayerConfig.txt"; // имя файла с конфигом скрипта
	private string default_log_block_name = "[CustomSpawnPlayerConfig] "; // Стандартный блок скрипта для идентификации с script.log
	private string disable_read_parameter = "0";	// Стандартное значение (без кавычек) для обозначения в файле конфига скрипта неиспользование параметра
	private string block_split_parameters_config = "|";	// Символ, обозначающий разделение параметров при чтении файла конфига
	private string block_split_multi_parameters_config = ";";	// Символ, обозначающий перечисление в одной ячейке параметра нескольких параметров при чтении файла конфига

	private bool enabled_loading_custom_spawnpoints = true; // Параметр, включающий и отключающий возможность использования приватной точки спавна для каждого игрока. В случае отключения кастомная точка спавна будет отключена для всех поумолчанию, вне зависимости от данных в конфиге!
	private bool enabled_loading_custom_sets = true; // Параметр, включающий и отключающий возможность использования приватного сета для каждого игроков. В случае отключения выдача сетов будет отключена для всех поумолчанию, вне зависимости от данных в конфиге, будет выдаваться только сет для всех игроков!
	private bool enabled_loading_custom_skins = true; // Параметр, включающий и отключающий возможность использования индивидуального стартового скина игрока для каждого игрока. В случае отключения эта возможность будет отключена для всех поумолчанию, вне зависимости от данных в конфиге!

	// ------------------------------------------------------------
	// ----------------    NEXT CODE DON'T EDIT   -----------------
	// ------------------------------------------------------------
	ref map<string, ref array<vector>> players_spawnpoints = new map<string, ref array<vector> >;
	ref map<string, ref array<int>> players_sets = new map<string, ref array<int> >;
	ref map<string, string> players_skins = new map<string, string>;
	private bool enabled_loaded_successfull_config = false;
	string Log_CustomSpawnPlayerConfig_GetDateTime()
	{
		private int year, month, day, hour, minute, second;
		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);
		string returned_message = "[" + day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(2) + " - " + hour.ToStringLen(2) + "." + minute.ToStringLen(2) + "." + second.ToStringLen(2) + "] ";
		return returned_message;
	}
	bool Check_coords_disable(vector coord)
	{
		private bool ret_zn = false;
		private float pos_x = coord[0];
		private float pos_y = coord[1];
		private float pos_z = coord[2];
		if ((pos_x == 0.0) & (pos_y == 0.0) & (pos_z == 0.0))
		{
			ret_zn = true;
		}
		return ret_zn;
	}
	vector Set_Read_coords_disable()
	{
		return Vector(0.0, 0.0, 0.0);
	}
	void CustomSpawnPlayerConfig()
	{
		Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + "CustomSpawnPlayerConfig initialize start!");
		Read_Update_Config();
	}

	void ~CustomSpawnPlayerConfig()
	{
		Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + "CustomSpawnPlayerConfig work end, class closed!");
	}

	void Read_Update_Config()
	{
		private string name_block_work = "[ReadAndUpdateSettings] ";
		Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + " Started Reading config!");
		private array<string> readed_lines_config = ReadFileConfig();
		private bool check_normal_read = AnaliseFileConfig(readed_lines_config);
		if (check_normal_read)
		{
			LoadFileConfig(readed_lines_config);
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "config readed successfull!");
			enabled_loaded_successfull_config = true;
		} else
		{
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "config read failed, work script disabled for players!");
			enabled_loaded_successfull_config = false;
		}
	}

	array<string> ReadFileConfig()
	{
		private string name_block_work = "[ReadFileConfig] ";
		private array<string> readed_lines_config = new array<string>;
		readed_lines_config.Clear();
		if (FileExist ( (Location_Directory_config + Location_filename_config) ) )
		{
			private string line_content;
			FileHandle file = OpenFile((Location_Directory_config + Location_filename_config), FileMode.READ);
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Open file config: " + (Location_Directory_config + Location_filename_config));
			if (file != 0)
			{
				while ( FGets( file,  line_content ) > 0 )
				{
					readed_lines_config.Insert( line_content);
				}
				CloseFile(file);
			} else
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! CAN'T OPEN FILE CONFIG : " + (Location_Directory_config + Location_filename_config));
			}
			//readed_lines_config.Debug();
		} else
		{
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! CAN'T FOUND FILE CONFIG OR DIRECTORY: " + (Location_Directory_config + Location_filename_config));
		}
		return readed_lines_config;
	}

	bool AnaliseFileConfig(array<string> readed_lines_config)
	{
		private bool return_zn = true;
		private string name_block_work = "[AnaliseFileConfig] ";
		if (readed_lines_config.Count() > 0)
		{
			foreach (string line : readed_lines_config)
			{
				if (line.Contains(block_split_parameters_config))
				{
					private array<string> splited_line = new array<string>;
					line.Split( block_split_parameters_config, splited_line );
					if (splited_line.Count() == 4)
					{
						private string UID_player = splited_line.Get(0);
						private string default_skin_player = splited_line.Get(1);
						private string sets_numbers_player = splited_line.Get(2);
						private string points_spawn_player = splited_line.Get(3);
						if ((UID_player == "") || (default_skin_player == "") || (sets_numbers_player == "") || (points_spawn_player == ""))
						{
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! Lines in Readed file is not correct, please, fix your config script!");
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Line checking: " + line);
							return_zn = false;
							break;
						}
					} else
					{
						Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! Readed file is have incorrect count parameters with a tag '" + block_split_parameters_config + "', please, fix your config script!");
						Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Line checking: " + line);
						return_zn = false;
						break;
					}
				} else
				{
					Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! Readed file can't have a tag '" + block_split_parameters_config + "', please, fix your config script!");
					Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Line checking: " + line);
					return_zn = false;
					break;
				}
			}
		} else
		{
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "ERROR!!! Config file is empty, fix your config script!");
			return_zn = false;
		}
		return return_zn;
	}

	void LoadFileConfig(array<string> readed_lines_config)
	{
		private string name_block_work = "[LoadFileConfig] ";
		players_spawnpoints.Clear();
		players_sets.Clear();
		players_skins.Clear();
		foreach (string line : readed_lines_config)
		{
			private array<string> splited_line = new array<string>; splited_line.Clear();
			line.Split( block_split_parameters_config, splited_line );
			private string UID_player = splited_line.Get(0);
			private string default_skin_player = splited_line.Get(1);
			private string sets_numbers_player = splited_line.Get(2);
			private string points_spawn_player = splited_line.Get(3);
			private array<vector> temp_players_spawnpoints = new array<vector>; temp_players_spawnpoints.Clear();
			array<int> temp_players_sets = new array<int>; temp_players_sets.Clear();
			array<string> temp_players_spawnpoints_string = new array<string>; temp_players_spawnpoints_string.Clear();
			array<string> temp_players_sets_string = new array<string>; temp_players_sets_string.Clear();
			if (points_spawn_player.Contains(block_split_multi_parameters_config))
			{
				points_spawn_player.Split( block_split_multi_parameters_config, temp_players_spawnpoints_string );
			} else
			{
				temp_players_spawnpoints_string.Insert(points_spawn_player);
			}
			foreach (string line_spawnpoint : temp_players_spawnpoints_string)
			{
				if (line_spawnpoint == disable_read_parameter)
				{
					temp_players_spawnpoints.Insert(Set_Read_coords_disable());
				} else
				{
					temp_players_spawnpoints.Insert(line_spawnpoint.ToVector());
				}
			}
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Generated massive for " + UID_player + " with " + temp_players_spawnpoints.Count().ToString() + " spawnpoints.");
			if (sets_numbers_player.Contains(block_split_multi_parameters_config))
			{
				sets_numbers_player.Split( block_split_multi_parameters_config, temp_players_sets_string );
			} else
			{
				temp_players_sets_string.Insert(sets_numbers_player);
			}
			foreach (string line_set : temp_players_sets_string)
			{
				if (line_set == disable_read_parameter)
				{
					temp_players_sets.Insert(0);
				} else
				{
					temp_players_sets.Insert(line_set.ToInt());
				}
			}
			if (default_skin_player == disable_read_parameter)
			{
				default_skin_player = "0";
			}
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Generated massive for " + UID_player + " with " + temp_players_sets.Count().ToString() + " sets.");
			Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Detected for " + UID_player + " skin " + default_skin_player);
			players_spawnpoints.Insert(UID_player,temp_players_spawnpoints);
			players_sets.Insert(UID_player,temp_players_sets);
			players_skins.Insert(UID_player,default_skin_player);
		}
	}

	vector Load_And_Check_Spawnpoints(PlayerIdentity identity, vector pos_default)
	{
		private string name_block_work = "[Load_And_Check_Spawnpoints] ";
		private vector retun_pos = pos_default;
		if(identity)
		{
			private string Name_P = identity.GetName();
			private string UID_P = identity.GetPlainId();
			private string Game_UID_P = identity.GetId();
			private string Game_ID_P = identity.GetPlayerId().ToString();
			if (enabled_loading_custom_spawnpoints)
			{
				if ((players_spawnpoints.Count() > 0) && (enabled_loaded_successfull_config))
				{
					if (players_spawnpoints.Contains(UID_P))
					{
						private array<vector> readed_lines_config = new array<vector>;
						readed_lines_config = players_spawnpoints.Get(UID_P);
						private vector retun_pos_check = readed_lines_config.GetRandomElement();
						if (Check_coords_disable(retun_pos_check))
						{
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") disabled loading private spawn point. Will be used default spawn point!");
						} else
						{
							retun_pos = retun_pos_check;
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") setuped private spawn point: " + retun_pos.ToString());
						}
					} else
					{
						Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Can't founded private spawnpoint for player " + Name_P + "(steam64id=" + UID_P + ")");
					}
				} else
				{
					Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Config script is incorrect, checking private spawnpoints is disabled! Player: " + Name_P + "(steam64id=" + UID_P + ")");
				}
			} else
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "disabled loading personal spawnpoints from config file script!");
			}
		}
		Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") will be used spawn point: " + retun_pos.ToString());
		return retun_pos;
	}
	string Load_And_Check_SpawnSkin_Player(PlayerIdentity identity, string characterName)
	{
		private string name_block_work = "[SelectStartSkinPlayer] ";
		private string retun_skin = characterName;
		if(identity)
		{
			private string Name_P = identity.GetName();
			private string UID_P = identity.GetPlainId();
			private string Game_UID_P = identity.GetId();
			private string Game_ID_P = identity.GetPlayerId().ToString();
			if (enabled_loading_custom_skins)
			{
				if (players_skins.Count() > 0)
				{
					if (players_skins.Contains(UID_P))
					{
						private string readed_skin = players_skins.Get(UID_P);
						if (readed_skin == "0")
						{
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") disabled loading private skin setting, will be used default setting game!");
						} else
						{
							retun_skin = readed_skin;
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") setuped private skin setting: " + retun_skin);
						}
					}  else
					{
						Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Can't founded private skin setting for player " + Name_P + "(steam64id=" + UID_P + ")");
					}
				} else
				{
					Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Config script is incorrect, checking private skin setting is disabled! Player: " + Name_P + "(steam64id=" + UID_P + ")");
				}
			} else
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "disabled loading personal skin player settings from config file script!");
			}
		}
		Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") will be used skin: " + retun_skin);
		return retun_skin;
	}
	void Load_And_Check_StartLoadout(PlayerBase player)
	{
		private string name_block_work = "[SelectStartSetPlayer] ";
		private int use_set_id = -1;
		private PlayerIdentity identity = player.GetIdentity();
		if(identity)
		{
			private string Name_P = identity.GetName();
			private string UID_P = identity.GetPlainId();
			private string Game_UID_P = identity.GetId();
			private string Game_ID_P = identity.GetPlayerId().ToString();
			if (enabled_loading_custom_sets)
			{
				if ((players_sets.Count() > 0) && (enabled_loaded_successfull_config))
				{
					if (players_sets.Contains(UID_P))
					{
						private array<int> readed_lines_config = new array<int>; readed_lines_config.Clear();
						readed_lines_config = players_sets.Get(UID_P);
						private int chek_use_set_id = readed_lines_config.GetRandomElement();
						if (chek_use_set_id == 0)
						{
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") disabled loading private set numbers. Will be used default set player! ");
						} else
						{
							use_set_id = chek_use_set_id;
							Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") setuped private set number is: " + use_set_id.ToString());
						}
					} else
					{
						Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Can't founded private sets for player " + Name_P + "(steam64id=" + UID_P + ")");
					}
				} else
				{
					Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "Config script is incorrect, checking private sets is disabled! Player: " + Name_P + "(steam64id=" + UID_P + ")");
				}
			} else
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "disabled loading personal loadout sets player settings from config file script! Will be used default loadout!");
			}
			if (use_set_id >= 0)
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") will be used spawn set with number is: " + use_set_id.ToString());
			} else
			{
				Print(Log_CustomSpawnPlayerConfig_GetDateTime() + default_log_block_name + name_block_work + "For player " + Name_P + "(steam64id=" + UID_P + ") will be used spawn default start set without number. ");
			}
			StartSetsPlayers.StartSetsPlayer(player, use_set_id);
		}
	}

	private array<EntityAI> GetItemListinobject(PlayerBase player,EntityAI item, bool check_player)
	{
		array<EntityAI> EntityAI_list_items = new array<EntityAI>; EntityAI_list_items.Clear();
		int	attIdx = 0; int attCount = 0; EntityAI		item_in_object;
		if ((player) && (check_player))
		{
			attCount	=	player.GetInventory().AttachmentCount();
			for (attIdx	=	0; attIdx < attCount; attIdx++)
			{
				item_in_object	=	player.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( item_in_object.IsItemBase() )
				{
					EntityAI_list_items.Insert(item_in_object);
				}
			}
		}
		if ((item) && !check_player)
		{
			attCount	=	item.GetInventory().AttachmentCount();
			for (attIdx	=	0; attIdx < attCount; attIdx++)
			{
				item_in_object	=	item.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( item_in_object.IsItemBase() )
				{
					EntityAI_list_items.Insert(item_in_object);
				}
			}
		}
		return EntityAI_list_items;
	}
	void RemoveAllItems (PlayerBase player)
	{
		private array<EntityAI> ItemListPlayer = new array<EntityAI>;
		private array<EntityAI> ItemsForDelete = new array<EntityAI>;
		private EntityAI itemInHands_player = player.GetHumanInventory().GetEntityInHands();
		if (itemInHands_player != NULL)
		{
			if (player.CanDropEntity(itemInHands_player) && player.GetHumanInventory().CanRemoveEntityInHands())
			{
			//	Print("ItemForDelete: " + itemInHands_player.ToString());
				ItemsForDelete.Insert(itemInHands_player);
			}
		}
		ItemListPlayer = GetItemListinobject(player,NULL,true);
		if (ItemListPlayer.Count() > 0)
		{
			foreach(EntityAI ItemPlayer: ItemListPlayer)
			{
				private array<EntityAI> ItemInItemInInventory = GetItemListinobject(NULL,ItemPlayer,false);
				private CargoBase cargo = ItemPlayer.GetInventory().GetCargo();
				if(cargo)
				{
					if (cargo.GetItemCount() > 0)
					{
						for (int f = 0; f < cargo.GetItemCount(); f++)
						{
							if(cargo.GetItem(f))
							{
								ItemsForDelete.Insert(cargo.GetItem(f));
							}
						}
					}
				}
				if (ItemInItemInInventory.Count() > 0)
				{
					foreach(EntityAI items_temp: ItemInItemInInventory)
					{
						if(items_temp)
						{
							ItemsForDelete.Insert(items_temp);
						}
					}
				}
				if(ItemPlayer)
				{
					ItemsForDelete.Insert(ItemPlayer);
				}
			}
		}
		if (ItemsForDelete.Count() > 0)
		{
			foreach(EntityAI item_temp: ItemsForDelete)
			{
				if(item_temp)
				{
					GetGame().ObjectDelete(item_temp);
				}
			}
		}
	}
};
