#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("light",-2);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_name("The entry to a shadowy tunnel");
   set_short("%^BOLD%^%^BLACK%^The entry to a shadowy tunnel%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The dank smell of %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^"
"and the underground fills the air.%^RESET%^");
   set_listen("default","%^GREEN%^The faint whistle of the %^RESET%^wi%^CYAN%^n%^RESET%^d %^GREEN%^outside is all that "
"can be heard here.%^RESET%^");

   set_long("%^BOLD%^%^BLACK%^The entry to a shadowy tunnel%^RESET%^\n"
"%^BLUE%^The small crack in the cliffs reveals this little cavern, which leads back further into the mountains by way of "
"a twisting corridor.  The cavern itself, and the tunnel further in, seem naturally formed of %^BOLD%^%^BLACK%^rough bl"
"%^RESET%^ac%^BOLD%^%^BLACK%^k stone%^RESET%^%^BLUE%^, with jagged outcroppings that snag at nearby skin and clothing.  "
"The walls and floor are %^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h"
"%^BLUE%^, with an occasional outcropping that forces you to duck or walk sideways for a few paces.  It is difficult to "
"see more than a few feet down the corridor, where it seems the %^MAGENTA%^shadows %^BLUE%^are almost alive, shifting "
"even as you look at them and giving you a seriously unsettled feeling.  A faint glimmer of %^YELLOW%^lig%^WHITE%^h"
"%^YELLOW%^t %^RESET%^%^BLUE%^is all that shows the opening to daylight.\n%^RESET%^");
   set_items( ([ 
     ({"walls","tunnel","floor","roof","shadows"}):"%^BLUE%^This cavern is seemingly naturally-formed, with jagged "
"outcroppings that snag at skin and clothing.  Shadows chase their way down the corridor ahead, so that it feels like "
"something is constantly lurking just at the edge of your vision.%^RESET%^",
   ]) );
   set_exits(([
     "north":"/d/avatars/nienne/dragonlair/tunnel4",
     "out":"/d/islands/pirates/caves/canyons6",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^BOLD%^%^BLACK%^The shadows flicker and move at the edges of your vision, and you can't help "
"jerking around to try and follow their movement with your eyes.%^RESET%^");
   return 1;
}

int quit_func(string str) {
   TP->move("/d/islands/pirates/caves/canyons6");
   tell_object(TP,"%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
"carefully make your way back out of the tunnel before taking a rest.%^RESET%^");
   TP->force_me("quit");
}