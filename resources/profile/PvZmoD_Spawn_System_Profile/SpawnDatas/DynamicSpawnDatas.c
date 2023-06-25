///  									NUMCONFIG	TIMEmini     TIMEmaxi	NBRmini		NBRmaxi		DISTANCE	AREA RADIUS 	Lateral SHIFT 	numChooseZombiesCategorie  
ref autoptr TIntArray data_Suspended =		{ 0,		100,		100,		0,			30 ,		2,			30,				0,					1 };			// 0 Suspended (don't modify this line)   

ref autoptr TIntArray data_CountrySide =	{ 0,		300,		600,		15,			25,			400,		10,				50,					0 };			// 1 DEFAULT (Countryside)

ref autoptr TIntArray data_SmallTwon =		{ 0,		10,			15,			2,			5,			100,		3,				30,					0 };			// 10 SmallTwon
ref autoptr TIntArray data_AverageTown =	{ 0,		10,			15,			3,			7,			100,		5,				30,					0 };			// 20 AverageTown
ref autoptr TIntArray data_BigTown =		{ 0,		10,			15,			5,			9,			100,		10,				30,					0 };			// 30 BigTown
ref autoptr TIntArray data_Building =		{ 0,		20,			20,			5,			7,			100,		10,				30,					0 };			// 40 Building
ref autoptr TIntArray data_Industial =		{ 0,		10,			15,			3,			4,			100,		5,				30,					0 };			// 50 Industial
ref autoptr TIntArray data_Military =		{ 0,		10,			15,			3,			6,			80,			5,				30,					0 };			// 60 Military 	(always focus)
ref autoptr TIntArray data_Fog =			{ 0,		0,			0,			0,			0,			0,			0,				0,					0 };			// 70
ref autoptr TIntArray data_Prison =			{ 0,		5,			7,			3,			7,			60,			3,				30,					0 };			// 71 Prison 	(always focus)
ref autoptr TIntArray data_Marines =		{ 0,		0,			0,			0,			0,			0,			0,				0,					0 };			// 72
ref autoptr TIntArray data_Bridge =			{ 0,		0,			0,			0,			0,			0,			0,				0,					0 };			// 73
ref autoptr TIntArray data_Config90 =		{ 0,		10,			10,			1,			1,			600,		200,			200,				0 };			// 90 Hunters aroud castles (very long distance)

/// Here you can configure your personnal dynamic spawn types
ref autoptr TIntArray data_Config91 =		{ 91,		120,		600,		2,			5,			70,			10,				50,					050 };			// Dog
ref autoptr TIntArray data_Config92 =		{ 92,		120,		600,		2,			5,			70,			10,				50,					030 };			// Cat
ref autoptr TIntArray data_Config93 =		{ 93,		120,		600,		2,			5,			70,			10,				50,					020 };			// Boar
ref autoptr TIntArray data_Config94 =		{ 94,		120,		600,		2,			5,			70,			10,				50,					040 };			// Fresh
ref autoptr TIntArray data_Config95 =		{ 95,		120,		600,		2,			5,			70,			10,				50,					060 };			// PseDog
ref autoptr TIntArray data_Config96 =		{ 96,		120,		600,		2,			5,			70,			10,				50,					105 };			// RatWolf
ref autoptr TIntArray data_Config97 =		{ 97,		120,		600,		3,			6,			70,			10,				50,					103 };			// Snork
ref autoptr TIntArray data_Config98 =		{ 98,		240,		600,		1,			2,			80,			20,				50,					101 };			// 98

ref autoptr TIntArray data_Config99 =		{ 99,		7,			10,			2,			3,			80,			10,				40,					99 };			// 99 Toxic zones (always focus)

///  									NUMCONFIG	TIMEmini     TIMEmaxi	NBRmini		NBRmaxi		DISTANCE	AREA RADIUS 	Lateral SHIFT 	numChooseZombiesCategorie  

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// look at ZombiesChooseCategories.c to choose numChooseZombiesCategorie number (use the number who is instead XXX of data_Horde_XXX_ZombiesCategories variable name)

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// NUMCONFIG 	: !! don't modify !! it is used in ZombiesDynamicSpawnZones.c file

/// TIMEmini 		: Minumun Time (in seconds) between each dynamic spawn.    
/// TIMEmaxi 		: Maximum Time (in seconds) between each dynamic spawn.    
/// !!! if value "6" (coast factor) of RealTimeTweaks.json file is not set to 0, remember than the time here correspond to the extreme north west of the map  
/// For example if value "6" is set to 10 and you set time here to 20 seconds the real time on the coast will be around 32 seconds (10 correspond to +12 seconds on the coast)

/// NBRmini		: Minimum number of Z to spawn (!! this number will be multiply by the ratio "3" of the RealTimeTweaks.json file (if "3" = 50 => quantity spawned will be 50%, so you need double the quantities)
/// NBRmaxi		: Maximum number of Z to spawn (!! this number will be multiply by the ratio "3" of the RealTimeTweaks.json file (if "3" = 50 => quantity spawned will be 50%, so you need double the quantities)

/// DISTANCE	  : Distance to which the group spawn (!! must not be lower than 60 !!)
/// AREA RADIUS	  : The size of the zone in which the zeds will spawn
/// Lateral SHIFT : 0 => The group will spawn in front of the player, 10 => The group will spawn with a random lateral shift between 0 and 10 meters

/// numChooseZombiesCategorie : Choose the type of zombie to spawn (see ZombiesChooseCategories.c file and look for the number in variable name. For exemple variable name data_Horde_102_CastelCategories, 102 is the number to spawn Castle zeds categorie)
