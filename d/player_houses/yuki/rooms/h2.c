#include <std.h>
#include "../yuki.h"

inherit STORAGE"hallway.c";

void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The hallway continues to the "+
   "west to a dark room, and east to the foyer. A door blocks your way "+
   "north. On the south wall a large painting hangs.\n");
   set_exits(([
      "west" : ROOMS"kill",
      "east" : ROOMS"h1",
	  "north" : ROOMS"meet",
		  
   ]));
       add_item(({"painting","south painting"}),"%^ORANGE%^Rising out "+
	   "of the deepest of %^YELLOW%^cypress swamps %^RESET%^%^ORANGE%^ is a "+
	   "beautifully detailed adult %^BOLD%^%^BLACK%^black dragon. %^YELLOW%^Firefli"+
	   "es %^RESET%^%^ORANGE%^dance in the background giving a effortless display "+
	   "of the shining %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^a%^WHITE%^c%^BLACK%^k "+
	   "scales %^RESET%^%^ORANGE%^on the creature. %^RESET%^%^ORANGE%^Her lon"+
	   "g %^WHITE%^serpentine%^ORANGE%^ neck curls %^RED%^protectively %^ORANGE%^ar"+
	   "ound a strange bundle of %^CYAN%^energy. %^ORANGE%^Not many would dare tr"+
	   "y to take this %^GREEN%^treasure %^ORANGE%^she seems to care for so much. "+
	   "And it is almost as if the %^YELLOW%^swamp %^RESET%^%^ORANGE%^itself seeks "+
	   "to hide them both from prying eyes. At the bottom of the painting "+
	   "are the initials A. K.%^RESET%^");
	   
	set_door("wooden door",ROOMS"meet","north",0);
    set_door_description("wooden door","%^ORANGE%^This heavy oak door looks very sturdy.%^RESET%^");
    set_string("wooden door", "open", "%^ORANGE%^The heavy door opens quietly.%^RESET%^");
    set_string("wooden door", "close", "%^ORANGE%^The heavy door closes without a sound.%^RESET%^");

}
