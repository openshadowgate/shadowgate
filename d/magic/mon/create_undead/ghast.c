//Met many times in the world
// http://www.d20srd.org/srd/monsters/ghoul.htm
#include <std.h>
#include <daemons.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
	::create();
	set_name("ghast");
	set_id(({"ghast","undead","monster"}));
	set_short("%^BOLD%^%^CYAN%^A %^CYAN%^n%^BLACK%^i%^CYAN%^m%^BLACK%^b%^CYAN%^l%^CYAN%^e%^CYAN%^ ghast%^RESET%^");
	set_long(
	"%^RESET%^%^RED%^This disfigured creature seems to have once been humanoid in appearance, but its race is not recognizable in the form it has after transformation into fell abomination. It's flesh is mummified, yet the undead monster stenches horribly. It has a long tongue that falls out of the maw full of sharp teeth, its nails are sharp and polished.%^RESET%^"
	);
    //Str 17, Dex 17, Con Ø, Int 13, Wis 14, Cha 16
    set_stats("strenght",18);
    set_stats("dexterity",18);
    set_stats("constitution",18);
    set_stats("intelligence",12);
    set_stats("wisdom",14);
    set_stats("charisma",16);

	set_property("undead",1);
	set_level(15);    
	set_hd(15,3);
	set_max_hp(random(30)+205);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-14);
	set_alignment(9);
	set_size(2);

	set_race("ghoul");
	set_class("fighter");
	set_mlevel("fighter",17);
    
	set_new_exp(17,"normal");
	set_gender("neuter");
	set_attack_limbs(({"right hand","left hand","mouth"}));
	set_attacks_num(3);
	set_nat_weapon_type("thiefslashing");
	set_damage(1,12);
	set_func_chance(15);
	set_hit_funcs((["mouth":(:TO,"bite":)]));
    set_resistance("negative energy",60);
    set_resistance("positive energy",-60);
}

int bite(object targ)
{
	targ->do_damage("torso",roll_dice(2,6));
    POISON_D->ApplyPoison(targ,"wyvern_poison",TO,"injury");
	if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death"))
    {
		tell_object(targ,"%^ORANGE%^The cold touch of the ghoul causes you to become paralyzed!");
		tell_room(ETO,"%^ORANGE%^The ghoul reaches out and touches "+targ->query_cap_name()+".",targ);
		targ->set_paralyzed(roll_dice(1,2),"%^BOLD%^%^BLACK%^You are sickened by the %^MAGENTA%^gho%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^l's %^MAGENTA%^t%^RESET%^%^MAGENTA%^o%^MAGENTA%^u%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^h%^MAGENTA%^!");
	}
	else
    {
		tell_object(targ,"%^BOLD%^You grit your teeth and manage to withstand the cold touch of the ghoul.");
		tell_room(ETO,"%^ORANGE%^The ghoul reaches out and touches "+targ->query_cap_name()+".",targ);
	}    
	return 1;
}

