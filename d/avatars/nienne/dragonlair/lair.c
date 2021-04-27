#include "std.h"
inherit ROOM;

void create(){
   ::create();
   set_name("A cavern shrouded in shadows");
   set_property("light",-2);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BLUE%^A cavern shrouded in shadows%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The dank smell of %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^"
"and the underground fills the air.%^RESET%^");
   set_listen("default","%^GREEN%^The silence here is like a weight on your shoulders.%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A cavern shrouded in shadows%^RESET%^\n"
"%^BLUE%^This cavern might be of small or large size, as it becomes impossible to make out within the %^BOLD%^%^BLACK%^"
"shad%^RESET%^ow%^BOLD%^%^BLACK%^y gloom%^RESET%^%^BLUE%^ that enshrouds it.  The nearest sections of wall and floor show "
"it to be naturally formed, with %^ORANGE%^rug%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^ed%^BLUE%^ stone walls and a "
"scattering of stalagmites around the floor's edges.   The roof lies somewhere far above your head, lost to sight in the "
"darkness.\n%^RESET%^");
   set_items( ([ 
     ({"walls","cavern","floor","roof","stalagmites"}):"%^BLUE%^This cavern is seemingly naturally-formed, with %^ORANGE%^"
"rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h %^BLUE%^stone walls and stalagmites that dot the perimiter of the area.  The "
"roof is high above your head somewhere, lost to the %^BOLD%^%^BLACK%^sha%^RESET%^do%^BOLD%^%^BLACK%^ws %^RESET%^%^BLUE%^"
"of the cavern.%^RESET%^",
   ]) );
   set_exits(([
     "tunnel":"/d/avatars/nienne/dragonlair/tunnel1",
   ]));
   set_no_clean(1);
   set_property("no pocket space",1);
}

int quit_func(string str) {
   TP->move("/d/islands/pirates/caves/canyons6");
   tell_object(TP,"%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
"carefully make your way back out of the tunnel before taking a rest.%^RESET%^");
   TP->force_me("quit");
}