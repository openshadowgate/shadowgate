#include <std.h>
inherit FIREARM;

create() {
   ::create();
   set_id(({ "pistol", "gun"}));
   set_name("pistol");
   set_short("A pistol");
   set_long("This is primitive single-barrel firearm with flintlock mechanism that fires paper cartriges.");
   set_weight(5);
   set_size(1);
   set_value(1000);

   set_wc(1,6);

   set_critical_hit_multiplier(4);
   set_type("bludgeon");
   set_lr_prof_type("gun");

   set_weapon_prof("exotic");

   set_rate_of_fire(4);
   set_range(2,4,6);
   set_ammo("cartrige");

   set_decay_rate(100);
   set_weapon_speed(1);
   set_damage_type("piercing");
}
