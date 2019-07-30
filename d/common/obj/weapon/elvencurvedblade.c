//Coded by Odin
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "curved blade", "elven curved blade", "blade" }));
   set_name("elven curved blade");
   set_short("An elven curved blade");
   set_long("Essentially a longer version of a scimitar, but with a thinner blade, the elven curve blade is exceptionally rare.");
   set_weight(7);
   set_size(3);
   set_value(80);
   set_wc(2,6); //putting this higher than TT values since we lack the tech to make it useable with weapon finesse.  Also 2h sword was strictly better by the numbers - Odin
   set_large_wc(2,6); //see above
   set_type("thiefslashing");
   set_weapon_speed(10);
   set_weapon_prof("exotic");
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
}
