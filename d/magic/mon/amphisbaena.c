#include "summoned_monster.h"

inherit WEAPONLESS;

void create(){
	::create();
	set_name("amphisbaena");
	set_id(({"amphisbaena","Amphisbaena","snake"}));
	set_short("snake");
	set_long(
"This odd snake has heads at both end of its body. Inside
each of the mouths you notice terrible fangs, you recognize that
the poison of this snake is terribly deadly.
"
	);
	set_hd(8,1);
	set_hp(40);
	set_body_type("snake");
	add_limb("tail's head","tail",0,0,0);
	add_limb("tail's mouth","tail's head",0,0,0);
	set_damage(1,3);
	set_attacks_num(2);
	set_attack_limbs(({"mouth","tail's mouth"}));
	set_base_damage_type("piercing");
	set_gender("male");
	set_race("snake");
        set_exp(100);
	set_alignment(5);
	set_overall_ac(3);
}
