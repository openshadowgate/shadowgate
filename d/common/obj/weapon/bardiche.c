//updated code to current - Circe 4/29/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({"bardiche","polearm","pole axe","axe"}));
    set_name("bardiche");
    set_short("A nasty looking bardiche");
    set_long("The massive blade on this axe makes you shudder, "+
       "as its only purpose could be war.  Just over two feet of "+
       "razor sharpened steel are connected to a five foot handle "+
       "with two steel rings.");
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
       set_property("repairtype",({"weaponsmith"}));
}
