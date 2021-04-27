#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("bag");
   set_id(({"bag","canvas bag","small bag","small canvas bag"}));
   set_short("%^RESET%^%^ORANGE%^small canvas bag%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^Simply woven canvas forms this bag, with a drawstring to hold it closed at the "
"top.  It is rather plain, but quite well crafted.%^RESET%^");
   set_weight(1);
}
