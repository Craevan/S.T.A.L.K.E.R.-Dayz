class StartSetsPlayersConfig
{
	void StartSetsPlayer(PlayerBase player,int use_set_id)
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;

		switch( use_set_id ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
		{
            case 1: //Set with number 1 (Сет с номером 1)
            {
                My_Custom_Spawn_Parameters.RemoveAllItems(player);                                              // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_BackPack_3"); 	    // Выдаем рюкзак и записываем в переменную itemCreated
                if (itemCreated)														                    	// Проверяем, создался ли рюкзак. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
                {
                    itemCreated.GetInventory().CreateAttachment( "Canteen" );
                    itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" );
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("TacticalBaconCan");			// Добавляем в инвентарь созданного рюкзака консервы и записываем в переменную itemCreated1
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("BandageDressing");				// Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("BandageDressing");
                }
                // переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Pants_3");		    // Выдаем игроку штаны
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Jacket_3");	        // Выдаем игроку куртку
                if (itemCreated)
                {
                    itemCreated.GetInventory().CreateAttachment( "SGE_Sunrise_Patch" );
                    itemCreated.GetInventory().CreateAttachment( "SGE_Sunrise_Patch" );
                }
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Vest_3");		    // Выдаем игроку жилет
                if (itemCreated)
                {
                    itemCreated.GetInventory().CreateAttachment( "SGE_Stalker_Sunrise_Pouches_3" );
                }
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Seva_Belt");     // Выдаем игроку ремень
                itemCreated = player.GetInventory().CreateInInventory("SGE_Loner_Hat_Green");       // Выдаем игроку шапку
                itemCreated = player.GetInventory().CreateInInventory("SGE_Loner_Mask");            // Выдаем игроку маску
                itemCreated = player.GetInventory().CreateInInventory("TacticalGloves_Black");      // Выдаем игроку перчатки
                itemCreated = player.GetInventory().CreateInInventory("MilitaryBoots_Brown");       // Выдаем игроку обувь
                //itemCasted = ItemBase.Cast(itemCreated);									        // Строка не нужна, закоментирована. Используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
                itemCreated = player.GetInventory().CreateInInventory("CombatKnife");               // Выдаем игроку ножик в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Battery9V");                 // Выдаем игроку батарейку в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AoD_VSS_10Rnd");	        // Выдаем игроку магазины к ВСС в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AoD_VSS_10Rnd");	        // Выдаем игроку магазины к ВСС в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");	            // Выдаем игроку патроны 9Х39 в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");	            // Выдаем игроку патроны 9Х39 в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");		        // Выдаем игроку патроны 9Х39 в любой свободный слот в инвентаре
                itemCreated = NULL;															        // Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
                itemCreated = player.GetHumanInventory().CreateInHands("VSS_AOD");			        // Выдаем игроку ВСС в руки
                if (itemCreated)															        // Проверяем, создался ли ВСС
                {
                    itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 				    // Выдаем игроку на ВСС оптику ПСО 11 и крепим
                    itemCreated.GetInventory().CreateAttachment( "Mag_AoD_VSS_10Rnd" ); 		    // Выдаем игроку на ВСС магазин и крепим
                }
                break;
            }
			case 2: //Set with number 2  (Сет с номером 2)
			{
				break;
			}

			case 3: //Set with number 3   (Сет с номером 3)
			{
				break;
			}

			case 4: //Set with number 4   (Сет с номером 4)
			{
				break;
			}

			case 5: //Set with number 5   (Сет с номером 5)
			{
				break;
			}

			case 6: //Set with number 6   (Сет с номером 6)
			{
				break;
			}

			default: //Default starting spawn set (Сет по-умолчанию для всех игроков)
			{
				DefaultSets(player); // Выдаем сет по-умолчанию
				break;
			}
		}
	}

/*
	void SetRandomHealthItem(EntityAI itemCreated) // Функция генерирует и применяет для предмета рандомное значение здоровья!
	{
		if ( itemCreated )
		{
			private int rndHlt = Math.RandomInt(55,6);
			itemCreated.SetHealth("","",rndHlt);
		}
	}

*/

	void DefaultSets(PlayerBase player) // Функция выдает сеты игрокам, не прописанным в конфигурации скрипта!!!
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;

		My_Custom_Spawn_Parameters.RemoveAllItems(player);                                  // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
		itemCreated = player.GetInventory().CreateInInventory("aod_pants_loner4_cargo");    // Выдаем игроку штаны
        itemCreated = player.GetInventory().CreateInInventory("aod_body_loner_sweater");    // Выдаем игроку куртку
        itemCreated = player.GetInventory().CreateInInventory("HikingBoots_Black");         // Выдаем игроку обувь
        itemCreated = player.GetInventory().CreateInInventory("HuntingKnife");		        // Выдаем игроку ножик в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");	            // Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");             // Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");	            // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("TunaCan");		            // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("TunaCan");	                // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("BandageDressing");	        // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("BandageDressing");		    // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = NULL;														            // Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
        itemCreated = player.GetHumanInventory().CreateInHands("Toz66Obrez_AoD");		    // Выдаем игроку AKM в руки

        private array <vector>  spawnpoints = {"4692 54.6 1068",
                                               "4689 54.6 1062"};
        private vector selected_spawnpoint = spawnpoints.GetRandomElement();
        player.SetPosition(selected_spawnpoint);


		// ниже пример, если вам нужно задать свои точки спавна для всех игроков. Этот код можно также использовать и для каждого сета индивидуально!
		// Код закомментирован, если это надо - раскомментируйте!
		// начало кода точек спавна игрока
		/*
		private array <vector>  spawnpoints = {"7500 0 7500",
			"7500 0 7500","7500 0 7500",
			"7500 0 7500"};
		private vector selected_spawnpoint = spawnpoints.GetRandomElement();
		player.SetPosition(selected_spawnpoint);
		*/
		// конец кода точек спавна игрока
	}
}
