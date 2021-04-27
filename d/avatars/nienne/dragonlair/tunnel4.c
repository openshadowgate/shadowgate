#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("light",-2);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_name("A shadowy, winding tunnel");
   set_short("%^BLUE%^A shadowy, winding tunnel%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The dank smell of %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^"
"and the underground fills the air.%^RESET%^");
   set_listen("default","%^GREEN%^The faint whistle of the %^RESET%^wi%^CYAN%^n%^RESET%^d %^GREEN%^outside is all that "
"can be heard here.%^RESET%^");

   set_long("%^BOLD%^%^BLACK%^A shadowy, winding tunnel%^RESET%^\n"
"%^BLUE%^This tunnel seems naturally formed of %^BOLD%^%^BLACK%^rough bl%^RESET%^ac%^BOLD%^%^BLACK%^k stone%^RESET%^"
"%^BLUE%^, with jagged outcroppings that snag at nearby skin and clothing.  The tunnel itself is only narrow, at times "
"likely forcing a group to go single-file, but it broadens in other places to allow plenty of space to stretch your arms"
".  The walls and floor are %^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h"
"%^BLUE%^, with an occasional outcropping that forces you to duck or walk sideways for a few paces.  It is difficult to "
"see more than a few feet down the corridor, where it seems the %^MAGENTA%^shadows %^BLUE%^are almost alive, shifting "
"even as you look at them and giving you a seriously unsettled feeling.  A faint glimmer of %^YELLOW%^lig%^WHITE%^h"
"%^YELLOW%^t %^RESET%^%^BLUE%^back to the south is all that reveals an escape from here.\n%^RESET%^");
   set_items( ([ 
     ({"walls","tunnel","floor","roof","shadows"}):"%^BLUE%^This tunnel is seemingly naturally-formed, with jagged "
"outcroppings that snag at skin and clothing.  Shadows chase their way down the corridor, so that it feels like something "
"is constantly lurking just at the edge of your vision.  There are scratched markings and notches at some places upon the "
"stone, suggesting that someone or something has travelled along here before.%^RESET%^",
   ]) );
   set_exits(([
     "northeast":"/d/avatars/nienne/dragonlair/tunnel3",
     "south":"/d/avatars/nienne/dragonlair/tunnel5",
   ]));
}

int quit_func(string str) {
   TP->move("/d/islands/pirates/caves/canyons6");
   tell_object(TP,"%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
"carefully make your way back out of the tunnel before taking a rest.%^RESET%^");
   TP->force_me("quit");
}