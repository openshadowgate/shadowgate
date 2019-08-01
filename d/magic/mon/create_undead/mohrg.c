//Met many times in the world
#include <std.h>
#include <daemons.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
	::create();
	set_name("mohrg");
	set_id(({"mohrg","undead"}));
	set_short("%^MAGENTA%^An %^MAGENTA%^i%^MAGENTA%^n%^BOLD%^%^MAGENTA%^f%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^st%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^d %^WHITE%^mohrg%^RESET%^");
	set_long(
	"%^MAGENTA%^This being looks like a humanoid %^BOLD%^%^WHITE%^ske%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^eto%^RESET%^%^WHITE%^n%^MAGENTA%^ entwined in worms. They wither and swarm about it, consuming whatever flesh there is still yet. The being is expressionless, with only eyes glowing with %^BOLD%^%^RED%^red %^RED%^h%^RESET%^%^RED%^a%^BOLD%^%^RED%^tred%^RESET%^%^RED%^."
	);
    //Str 21, Dex 19, Con Ø, Int 11, Wis 10, Cha 10
    set_stats("strenght",21);
    set_stats("dexterity",20);
    set_stats("constitution",18);
    set_stats("intelligence",10);
    set_stats("wisdom",10);
    set_stats("charisma",10);

	set_property("undead",1);
	set_level(22);    
	set_hd(14,12);
	set_max_hp(random(30)+155);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-22);
	set_alignment(9);
	set_size(2);

	set_race("mohrg");
	set_class("fighter");
	set_mlevel("fighter",22);
    
	set_new_exp(22,"normal");
	set_gender("neuter");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(6);
	set_nat_weapon_type("thiefslashing");
	set_damage(1,8);
    set_funcs(({"grapple"}));
    set_func_chance(42);
    set_resistance("negative energy",60);
    set_resistance("positive energy",-60);
}

int grapple(object targ)
{
	if(!SAVING_D->saving_throw(targ,"reflex"))
    {
        targ->do_damage("torso",roll_dice(2,8));        
		tell_object(targ,"%^MAGENTA%^One of mohrg's worms entwines around you!");
		tell_room(ETO,"%^MAGENTA%^One of mohrg's worms entwines around "+targ->query_cap_name()+".",targ);
		targ->set_tripped(roll_dice(1,3),"%^MAGENTA%^You're struggling in the worm's grapple!");
	}
}

