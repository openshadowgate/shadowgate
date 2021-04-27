#include <std.h>
#include "../yuki.h"

inherit STORAGE"hallway.c";

void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The foyer is dominated "+
   "by a large statue of a %^RESET%^crow%^BLACK%^%^BOLD%^ carved "+
   "from bl%^RESET%^a%^BLACK%^%^BOLD%^ck marb%^RESET%^l%^BLACK%^%^BOLD%^"+
   "e. The hallway continues to the east and to the west.\n");
   set_exits(([
      "east" : ROOMS"h3",
      "west" : ROOMS"h2",
           "south" : ROOMS"c1",
   ]));
       add_item(({"statue","crow statue","marble statue"}),"%^BLACK%^%^BOLD%^Ca"+
	"rved from black marble, this six foot statue is of a crow. The artist "+
	"has captured the bird leaping into flight and the realism is simply "+
	"amazing. As you walk around it you swear the eyes follow you, and the "+
	"breeze from the outside seems to disturb the feathers though you know "+
	"it to be impossible of solid stone. At the bottom of the statue is a "+
	"small plaque with the initials 'A. K' ");
}

