#include <std.h>

inherit WEAPON;

void create(){
    ::create();
   set_id(({"bec de corbin","pole arm","polearm","corbin",}));
   set_name("bec de corbin");
   set_short("Bec de corbin");
    set_long(
   "This long pole arm has a spear tip with a spike in the shape of a crows beak jutting out from the base of the point."
  "  On the reverse side of the beak a clawed hammer gives extra weight to the weapon for the crushing blows it would need to drive it through plate armor."
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
  set_damage_type("piercing");
  set_property("repairtype",({"weaponsmith"}));
}
