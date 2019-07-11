#include <std.h>
inherit FIREARM;

create() {
   ::create();
   set_id(({ "pistol", "gun"}));
   set_name("pistol");
   set_short("A pistol");
   set_long("This is primitive firearm with flintlock mechanism that fires bullets.");
   set_weight(5);
   set_size(1);
   set_value(100);
   set_critical_hit_multiplier(15);   
   set_type("bludgeon");
   set_lr_prof_type("gun");
   set_weapon_prof("simple");
   set_prof_type("club");
   set_rate_of_fire(4);
   set_range(2,4,6);
   set_ammo("bullet");
   set_decay_rate(100);
   set_weapon_speed(1);
   set_damage_type("piercing");   
}

