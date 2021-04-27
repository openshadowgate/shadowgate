#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(PAVED_ROAD);
   set_name("Rocky mountain path");
   set_short("%^BLACK%^%^BOLD%^Rocky mountain path%^RESET%^");
   set_smell("default","The salty sea air is still carried upon the breeze.");
   set_listen("default","You can barely hear the distant roar of the ocean.");
   set_items(([
     ({"rocks","path","trail","pathway"}) : (:TO,"path_desc":),
     ({"mountains","walls","stone walls","mountainside"}) : (:TO,"mountain_desc":)
   ]));
}

string path_desc() {
   return("%^ORANGE%^The rocks part here in a seemingly natural formation, leaving a trail of sorts that "
"leads upward into the mountains on a slight incline.%^RESET%^");
}

string mountain_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The %^WHITE%^snowcapped%^ORANGE%^ peaks of the %^BLUE%^mountains%^ORANGE%^ loom "
"above you to the south.");
   }
   return("%^ORANGE%^The tall peaks of the %^BLUE%^mountains%^ORANGE%^ loom above you to the "
"south.%^RESET%^");
}
