#include "$CurrentDir:mpmissions\Dayz.ExclusionZone\CustomSpawnPlayerConfig\Script.c"
#include "$CurrentDir:mpmissions\Dayz.ExclusionZone\CustomSpawnPlayerConfig\Sets.c"

ref CustomSpawnPlayerConfig  My_Custom_Spawn_Parameters = new CustomSpawnPlayerConfig();
ref StartSetsPlayersConfig StartSetsPlayers = new StartSetsPlayersConfig();

modded class CustomMission
{

	override void OnInit ()
    {
		super.OnInit();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(My_Custom_Spawn_Parameters.Read_Update_Config, 120000, true); // Обновление настроек скрипта кастомных спавнов, 1 минута = 60000

    }

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		pos = My_Custom_Spawn_Parameters.Load_And_Check_Spawnpoints(identity, pos);
		characterName = My_Custom_Spawn_Parameters.Load_And_Check_SpawnSkin_Player(identity, characterName);
		super.CreateCharacter(identity, pos, ctx, characterName);
		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		super.StartingEquipSetup(player, clothesChosen);
		My_Custom_Spawn_Parameters.Load_And_Check_StartLoadout(player);
	}
}
