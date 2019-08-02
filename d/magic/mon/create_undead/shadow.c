#include <std.h>
#include <daemons.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
	::create();
	set_name("shadow");
	set_id(({"shadow","undead","monster"}));
	set_short("%^BOLD%^%^BLACK%^A shifting shadow%^RESET%^");
	set_long(
	"%^BOLD%^%^BLACK%^You can just barely see something moving. As you look towards the movement, you see a shadow of a being, loosely humanoid. It has blurry edges and it is indistinct, constantly moving so you can't quite focus on it. It blends in well with the surroundings.%^RESET%^"
	);
    //Str Ø, Dex 14, Con Ø, Int 6, Wis 12, Cha 13
    set_stats("strenght",10);
    set_stats("dexterity",14);
    set_stats("constitution",18);
    set_stats("intelligence",6);
    set_stats("wisdom",12);
    set_stats("charisma",14);

	set_property("undead",1);
	set_level(15);    
	set_hd(4,12);
	set_max_hp(random(35)+425);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-22);
	set_alignment(3);
	set_size(2);

	set_race("shadow");
	set_class("fighter");
	set_mlevel("fighter",20);
    
	set_new_exp(20,"normal");
	set_gender("neuter");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(6);
	set_nat_weapon_type("thiefslashing");
	set_damage(1,8);
    set_resistance("negative energy",60);
    set_resistance("positive energy",-60);

    set_property("magic",1);
}

void set_paralyzed(int time,string message)
{
    return 1;
}

