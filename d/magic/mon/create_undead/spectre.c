#include <std.h>
#include <daemons.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
	::create();
	set_name("spectre");
	set_id(({"spectre","undead","monster"}));
	set_short("A @translucent @spectre");
	set_long("This creature is almost @see-through in appearance, and is hovering jus above the ground. A long robe of shadows covers all but its head and hands. Its hands are more like claws than anything else, with long sharp fingernails on them. Its face is twisted by a mask of hatred, rage and pain. @(bwhite,white)Flowing @(bwhite,white)white wair trails down its back, ever blowing in a non-existand wind.");
    //Str Ø, Dex 16, Con Ø, Int 14, Wis 14, Cha 15
    set_stats("strenght",10);
    set_stats("dexterity",16);
    set_stats("constitution",18);
    set_stats("intelligence",14);
    set_stats("wisdom",14);
    set_stats("charisma",16);

	set_property("undead",1);
	set_level(15);    
	set_hd(7,12);
	set_max_hp(random(35)+345);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-28);
	set_alignment(3);
	set_size(2);

	set_race("shadow");
	set_class("fighter");
	set_mlevel("fighter",20);
    
	set_new_exp(20,"normal");
	set_gender("neuter");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(7);
	set_nat_weapon_type("thiefslashing");
	set_damage(1,6);
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
    
