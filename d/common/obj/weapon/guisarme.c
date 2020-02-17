//updated base damage - Circe 4/29/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({"guisarme","pole arm","polearm"}));
    set_name("guisarme");
    set_short("A gruesome looking guisarme");
    set_long("This weapon looks like a pruning hook that's been "+
       "pressed into service as a moderately effective polearm.  "+
       "It doesn't have a spear point however, just the inside of "+
       "the sharpened curved hook to inflict damage.");
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
