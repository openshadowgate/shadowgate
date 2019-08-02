#include <std.h>
#include <daemons.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
	::create();
	set_name("wraith");
	set_id(({"wraith","undead","monster"}));
	set_short("%^BOLD%^%^BLUE%^A %^BLACK%^h%^BLUE%^o%^BLUE%^r%^BLUE%^r%^BLACK%^i%^BLUE%^b%^BLACK%^l%^BLUE%^e%^BLUE%^ wraith%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^A %^BLACK%^s%^BLUE%^h%^BLUE%^a%^BLACK%^d%^BLUE%^o%^BLACK%^w%^BLUE%^y%^BLUE%^ humanoid shape which floats above the floor. It's cold %^CYAN%^b%^CYAN%^l%^BLUE%^ue%^BLUE%^ eyes gaze deep into your soul, as if searching for your inner being.%^RESET%^");
    //Str Ø, Dex 16, Con Ø, Int 14, Wis 14, Cha 15
    set_stats("strenght",10);
    set_stats("dexterity",16);
    set_stats("constitution",18);
    set_stats("intelligence",14);
    set_stats("wisdom",14);
    set_stats("charisma",16);

	set_property("undead",1);
	set_level(15);    
	set_hd(5,12);
	set_max_hp(random(35)+345);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-24);
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

    set_hit_funcs( (["right hand":(:TO,"drain":)]) );        
}

void drain(object targ)
{
    int damage;
    tell_object(targ,"%^BLUE%^You feel your life force drain away!");
    tell_room(ETO,"%^BLUE%^"+targ->query_cap_name()+" stumbles back @weakly from the touch of the Wraith!",targ);
    damage = roll_dice(TO->query_level(),2);
    targ->do_damage(targ->return_target_limb(),damage);
    TO->add_hp(-damage);
}

void set_paralyzed(int time,string message)
{
    return 1;
}
    
