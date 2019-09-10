#include <std.h>
inherit FIREARM;

create() {
   ::create();
   set_id(({ "cannon", "gun"}));
   set_name("cannon");
   set_short("A cannon");
   set_long("This is an artillery cannon. Someone really big decided to use it as a handgun.");

   set_weight(30);
   set_size(4);
   set_value(150);
   set_two_handed();
   set_critical_hit_multiplier(30);
   set_type("bludgeon");
   set_two_handed();
   set_lr_prof_type("gun");
   set_weapon_prof("simple");
   set_prof_type("club");
   set_rate_of_fire(4);
   set_range(2,10,18);
   set_ammo("bullet");
   set_decay_rate(100);
   set_weapon_speed(1);
   set_damage_type("bludgeoning");
}
