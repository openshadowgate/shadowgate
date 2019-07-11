#include <std.h>
inherit FIREARM;

create() {
   ::create();
   set_id(({ "arquebus", "gun"}));
   set_name("arquebus");
   set_short("An arquebus");
   set_long("This is an arquebus, primitive firearm with flintlock mechanism that fires bullets.");
   set_two_handed();   
   set_weight(15);
   set_size(2);
   set_value(150);
   set_weapon_speed(1);
}

