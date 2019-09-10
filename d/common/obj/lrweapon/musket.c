#include <std.h>
inherit FIREARM;

create() {
   ::create();
   set_id(({ "musket", "gun"}));
   set_name("musket");
   set_short("A musket");
   set_ammo("cartrige");

   set_long("This long-barreled firearm has a much greater range than a pistol. It shoots paper cartriges.");
   set_two_handed();
   set_weight(9);
   set_size(2);

   set_range(4,8,12);
   set_wc(1,10);
   set_large_wc(1,12);
   set_critical_hit_multiplier(4);

   set_value(1500);
   set_weapon_speed(1);
}
