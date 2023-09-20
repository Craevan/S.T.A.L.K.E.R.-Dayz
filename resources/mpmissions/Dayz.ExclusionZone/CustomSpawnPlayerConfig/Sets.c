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
				My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_BackPack"); 	// Выдаем рюкзак и записываем в переменную itemCreated
				if (itemCreated)															// Проверяем, создался ли рюкзак. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{
//					SetRandomHealthItem(itemCreated);												// Выдаем рюкзаку рандомное качество
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("TacticalBaconCan");			// Добавляем в инвентарь созданного рюкзака консервы и записываем в переменную itemCreated1
//					if (itemCreated1)																// Проверяем, создалось ли яблоко в рюкзаке, яблоко у нас с переменной itemCreated1
//					{
//						SetRandomHealthItem(itemCreated1);												// Выдаем яблоку рандомное качество
//					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней, чтобы следующая проверка прошла корректно
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("BandageDressing");				// Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("BandageDressing");				// Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
//					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке, они у нас с переменной itemCreated1
//					{
//						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией, поскольку в классе EntityAI нет нужной нам функции SetQuantity, а в подклассе ItemBase она есть. Предмет при этом так и остается один и тот же!
//						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
////						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество, функция работает с классом EntityAI (см. в конфе файла)
//					}
				}
				// переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Pants");		// Выдаем игроку штаны
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Jacket");	// Выдаем игроку куртку
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Vest");		// Выдаем игроку жилет
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Pouches");	// Выдаем игроку подсумки к жилету
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Belt");	// Выдаем игроку ремень
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Belt_Pouches");	// Выдаем игроку подсумки к ремню
                itemCreated = player.GetInventory().CreateInInventory("SGE_Stalker_Sunrise_Belt_Pouches");	// Выдаем игроку подсумки к ремню
                itemCreated = player.GetInventory().CreateInInventory("SGE_Loner_Hat_Green");	// Выдаем игроку шапку
                itemCreated = player.GetInventory().CreateInInventory("SGE_Loner_Mask");	// Выдаем игроку маску
                itemCreated = player.GetInventory().CreateInInventory("SGE_Sunrise_Patch");	// Выдаем игроку шеврон
                itemCreated = player.GetInventory().CreateInInventory("SGE_Sunrise_Patch");	// Выдаем игроку шеврон
                itemCreated = player.GetInventory().CreateInInventory("NylonKnifeSheath");	// Выдаем игроку ножны
                itemCreated = player.GetInventory().CreateInInventory("TacticalGloves_Black");	// Выдаем игроку перчатки
                itemCreated = player.GetInventory().CreateInInventory("MilitaryBoots_Brown");	// Выдаем игроку обувь
                //itemCasted = ItemBase.Cast(itemCreated);										// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
                itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Battery9V");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AoD_VSS_10Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AoD_VSS_10Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Ammo_9x39AP");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
                itemCreated = NULL;															// Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
                itemCreated = player.GetHumanInventory().CreateInHands("VSS_AOD");				// Выдаем игроку ВСС в руки
                if (itemCreated)															// Проверяем, создался ли АКМ
                {
                    itemCreated.GetInventory().CreateAttachment( "PSO11Optic" ); 				// Выдаем игроку на AKM оптику ПСО 11 и крепим
//					itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 			// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
//					itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );				// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
//					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );				// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
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

			default: //Default starting spawn set (Сет поумолчанию для всех игроков, если хотите назначить - добавляйте здесь!)
			{
				//My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
				DefaultSets(player); // Для выдачи своих сетов по рандому всем игрокам, не прописанным в скрипте, раскомментировать эту строку
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

		My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
		itemCreated = player.GetInventory().CreateInInventory("aod_pants_loner4_cargo");		// Выдаем игроку штаны
        itemCreated = player.GetInventory().CreateInInventory("aod_body_loner_sweater");	// Выдаем игроку куртку
        itemCreated = player.GetInventory().CreateInInventory("HikingBoots_Black");	// Выдаем игроку обувь
        itemCreated = player.GetInventory().CreateInInventory("HuntingKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("Ammo_12gaSlug");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("TunaCan");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("TunaCan");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("BandageDressing");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = player.GetInventory().CreateInInventory("BandageDressing");		// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
        itemCreated = NULL;															// Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
        itemCreated = player.GetHumanInventory().CreateInHands("Toz66Obrez_AoD");				// Выдаем игроку AKM в руки

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

//		private int random_set_number = Math.RandomIntInclusive(1,6); // генерируем рандом номер сета от 1 до 6 включительно (по значениям блоков case ниже)
//		switch( random_set_number ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
//		{
//			case 1: //Set with number 1 (Сет с номером 1)
//			{
//				break;
//			}
//
//			case 2: //Set with number 2  (Сет с номером 2)
//			{
//				break;
//			}
//
//			case 3: //Set with number 3   (Сет с номером 3)
//			{
//				break;
//			}
//
//			case 4: //Set with number 4   (Сет с номером 4)
//			{
//				break;
//			}
//
//			case 5: //Set with number 5   (Сет с номером 5)
//			{
//				break;
//			}
//
//			case 6: //Set with number 6   (Сет с номером 6)
//			{
//				break;
//			}
//
//			default: //Default starting spawn set (Сет поумолчанию для всех игроков, в случае если ни один из сетов выше не выпал.
//			{
//				//My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
//
//				break;
//			}
	}
}
