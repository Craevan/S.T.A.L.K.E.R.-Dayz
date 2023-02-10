class CfgPatches {
    class CustomBulletStacks {
        units[]={};
        weapons[]={};
        requiredVersion = 0.1;
        requiredAddons[]=
        {
            "DZ_Weapons_Ammunition",
            "DZ_Weapons_Magazines"
        };
    };
};

class CfgMagazines {
    class Magazine_Base;

    class Ammunition_Base : Magazine_Base {
    };

    class Ammo_45ACP : Ammunition_Base {
        count = 100;
    };

    class Ammo_308Win : Ammunition_Base {
        count = 80;
    };

    class Ammo_308WinTracer : Ammunition_Base {
        count = 80;
    };

    class Ammo_9x19 : Ammunition_Base {
        count = 100;
    };

    class Ammo_380 : Ammunition_Base {
        count = 140;
    };

    class Ammo_556x45 : Ammunition_Base {
        count = 80;
    };

    class Ammo_556x45Tracer : Ammunition_Base {
        count = 80;
    };

    class Ammo_762x54 : Ammunition_Base {
        count = 80;
    };

    class Ammo_762x54Tracer : Ammunition_Base {
        count = 80;
    };

    class Ammo_762x39 : Ammunition_Base {
        count = 80;
    };

    class Ammo_762x39Tracer : Ammunition_Base {
        count = 80;
    };

    class Ammo_9x39 : Ammunition_Base {
        count = 80;
    };

    class Ammo_9x39AP : Ammunition_Base {
        count = 80;
    };

    class Ammo_22 : Ammunition_Base {
        count = 200;
    };

    class Ammo_12gaPellets : Ammunition_Base {
        count = 60;
    };

    class Ammo_12gaSlug : Ammunition_Base {
        count = 60;
    };

    class Ammo_12gaRubberSlug : Ammunition_Base {
        count = 60;
    };

    class Ammo_357 : Ammunition_Base {
        count = 80;
    };

    class Ammo_545x39 : Ammunition_Base {
        count = 80;
    };

    class Ammo_545x39Tracer : Ammunition_Base {
        count = 80;
    };

    class air_Ammo_792x33 : Ammunition_Base {
        count = 100;
    };

    class air_Ammo_762x25 : Ammunition_Base {
        count = 100;
    };

    class air_Ammo_792x57 : Ammunition_Base {
        count = 100;
    };

    class air_Ammo_9x18 : Ammunition_Base {
        count = 100;
    };

    class air_Ammo_9x18_Rubber : Ammunition_Base {
        count = 100;
    };
};
