//updated base damage - Circe 4/29/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({"partisan","pole arm","polearm","spear"}));
    set_name("partisan");
    set_short("A partisan");
    set_long("This form of pole arm consists of a long ox-tongue "+
       "spear blade, with two small axe blades added to the base "+
       "of the spearhead.");
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type("thiefslashing");
    set_prof_type("polearm");
    set_weapon_speed(8);
//    set_wc(1,6);
//    set_large_wc(1,6);
    set_wc(1,8);
    set_large_wc(2,5);
    set_weapon_prof("martial");
   
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
}
