class CfgPatches {
    class StalkerMainMenu {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[]={
            "DZ_Data",
            "DZ_Gear_Consumables",
            "DZ_Vehicles_Wheeled",
            "DZ_Structures_Residential",
            "DZ_Sounds_Effects",
            "DZ_Sounds_Weapons"
        };
    };
};

class CfgMods {
    class StalkerMainMenu {
        dir = "StalkerMainMenu";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "StalkerMainMenu";
        logoSmall = "";
        logo = "";
        logoOver = "StalkerMainMenu";
        tooltip = "StalkerMainMenu";
        overview = "StalkerMainMenu";
        credits = "Crevan";
        author = "Crevan";
        authorID =;
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = { "Mission", "Game" };

        class defs {
            class gameScriptModule {
                value = "";
                files[]= { "StalkerMainMenu/scripts/3_Game" };
            };

            class missionScriptModule {
                value = "";
                files[]={ "StalkerMainMenu/scripts/5_Mission" };
            };
        };
    };
};

class CfgSoundSets {
    class FMusic_Menu_SoundSet {
        soundShaders[] = { "FMusic_Menu_SoundShader" };
        volumeFactor = 1;
        frequencyFactor = 1;
        spatial = 0;
    };
};

class CfgSoundShaders {
    class FMusic_Menu_SoundShader {
        samples[] = {{ "StalkerMainMenu/mainmenu", 1 }};
        volume = 0.5;
    };
};
