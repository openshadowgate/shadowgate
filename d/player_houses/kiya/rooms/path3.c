#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create() {
   ::create();
   set_long("%^ORANGE%^The gap through the rocks here is much more clearly defined now, almost like "
"a makeshift path that ascends at a slight incline.  The stones are smooth beneath your feet, and uneven "
"%^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^ky walls%^RESET%^%^ORANGE%^ rise up on either "
"side, often becoming too tall to see anything beyond them.  Further to the southwest you can see that "
"the trail continues still further upward.%^RESET%^\n");
   set_exits(([
     "southwest" : ROOMS+"path2",
     "east" : ROOMS+"path4"
   ]));
}
