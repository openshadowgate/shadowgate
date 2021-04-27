#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("wolf key");
   set_id(({"key","iron key","small key","small iron key"}));
   set_short("%^BLACK%^%^BOLD%^small iron key%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^Forged from black iron, this is a simple key. "
"It has been forged into the shape of the profile of a wolf's head. It must "
"be to a very specific door.%^RESET%^\n");
   set_weight(1);
   set_value(0);
}
