#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create() {
   ::create();
   set_long((:TO,"long_desc":));
   set_exits(([
     "northeast" : ROOMS+"path3",
     "south" : ROOMS+"path1"
   ]));
}

string path_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The rocks part here in a seemingly natural formation, leaving a trail of sorts "
"that leads upward into the mountains on a slight incline.  A light sprinkling of snow is beginning to "
"cover the trail here.%^RESET%^");
   }
   return("%^ORANGE%^The rocks part here in a seemingly natural formation, leaving a trail of sorts that "
"leads upward into the mountains on a slight incline.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The gap through the rocks here forms an almost well-defined path, winding up "
"into the mountain peaks at a moderate incline.  The stones are smooth beneath your feet, and uneven "
"%^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^ky walls%^RESET%^%^ORANGE%^ rise up on either "
"side, often becoming too tall to see anything beyond them.  A light sprinkling of %^WHITE%^snow "
"%^ORANGE%^coats the path at your feet.  Further south you can see that the trail continues still further "
"upward.%^RESET%^\n");
   }
   return("%^ORANGE%^The gap through the rocks here forms an almost well-defined path, winding up "
"into the mountain peaks at a moderate incline.  The stones are smooth beneath your feet, and uneven "
"%^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^ky walls%^RESET%^%^ORANGE%^ rise up on either "
"side, often becoming too tall to see anything beyond them.  Further south you can see that the trail "
"continues still further upward.%^RESET%^\n");
}
