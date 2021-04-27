#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("feather key");
   set_id(({"key","feather key","yuki_key"}));
   set_short("%^BLACK%^%^BOLD%^feather key%^RESET%^");
   set_long("This small key is made from darkened silver, "+
   "and is shaped in the form of a feather. It is "+
   "obviously for a specific door.\n");
   set_weight(1);
   set_value(0);
}
