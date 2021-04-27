#include <std.h>

inherit OBJECT;


void create() {
   ::create();
   set_name("maestro's baton");
   set_id(({"baton","maestro","maestro's baton"}));
   set_obvious_short("%^RESET%^%^ORANGE%^odinary looking baton%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^T%^BOLD%^%^ORANGE%^h%^RESET%^%^ORANGE%^e M%^BOLD%^%^WHITE%^a%^RESET%^e%^RESET%^%^ORANGE%^stro%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is an ordinary looking baton."+
   " It is a little stout at the bottom and about fifteen inches long."+
   " The thickness of the finished oak, dwindles"+
   " down to to a point, making a fine, sturdy,"+
   " thin stick in the middle.");
