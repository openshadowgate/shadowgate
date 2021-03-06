// Governor Samir ibn Shiraz
// Thorn@ShadowGate
// 12/7/95
// Azha Garrison
// ibnshiraz.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Governor ibn Shiraz");
	set_id(({ "shiraz", "ibn shiraz", "governor" }));
	set_short("Samir ibn Shiraz, Governor of Azha");
	set_long(
@TSARVEN
	Governor ibn Shiraz is an elderly man of about 70 years.  This is
his final post in the service of the Empire before retiring to his
home in Tsarven.  He is a thin man, somewhat frail looking, with
white hair and a matching beard.  At first glance, he seems to be
very unthreatening and weak.  Another glance, though, will hint at
something that is a bit more formidable in this old man.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_overall_ac(2);
	set_class("mage");
	level = 35;
	set_hd(level,10);
	set_max_hp(150);
	set_hp(query_max_hp());
	set_guild_level("mage", level);
	set_stats("strength", 9);
	set_stats("constitution", 12);
	set_stats("wisdom", 15);
	set_stats("charisma", 12);
	set_stats("intelligence", 16);
	set_stats("dexterity", 13);
//new(AEQUIP+"gov_staff.c")->move(TO);
//force_me("wield staff in right hand");
//new(AEQUIP+"gov_robe.c")->move(TO);
//force_me("wear robe");
	set_spells(({ "magic missile", "finger of death", "monster summoning vi", "animate dead" }));
	set_spell_chance(75);
}

	
