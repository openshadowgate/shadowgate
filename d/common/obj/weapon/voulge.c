#include <std.h>

inherit WEAPON;

void create(){
    ::create();
   set_id(({"voulge","pole arm","polearm"}));
   set_name("voulge");
   set_short("A stout voulge");
    set_long(
   "This looks like some deranged cook affixed a massive cleaver to a long, thick pole to make a weapon capable of cleaving through armor."
    );
    set_weight(10);
    set_size(3);
    set("value", 5);
    set_wc(3,4);
    set_large_wc(3,4);
    set_type("pierce");
    set_prof_type("polearm");
    set_weapon_prof("martial");
    set_weapon_speed(10);
    set_critical_threat_range(1);
    set_critical_hit_multiplier(3);
    set_damage_type("slashing");
}
