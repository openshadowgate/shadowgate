#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create() {
   ::create();
   set_long("%^ORANGE%^You have stumbled upon a small gap among the rocks, at the lowest regions of "
"the Barrier Mountains.  The %^YELLOW%^co%^WHITE%^a%^YELLOW%^rse "
"san%^WHITE%^d%^YELLOW%^s%^RESET%^%^ORANGE%^ have given way to dry, %^BLACK%^%^BOLD%^stony "
"gro%^RESET%^%^WHITE%^u%^BLACK%^%^BOLD%^nd%^RESET%^%^ORANGE%^ here, sloping upward on a gentle incline.  "
"You can see further westward along this makeshift pathway through the stones, which seems to continue "
"higher up into the mountains.%^RESET%^\n");
   set_exits(([
     "west" : ROOMS+"path3",
     "east" : "/d/barriermnts/bpeak/rooms/t2"
   ]));
}
