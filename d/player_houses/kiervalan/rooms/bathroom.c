#include <std.h>
#include "../kier.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A Bathroom");
   set_short("%^BOLD%^A Bathroom%^RESET%^");
   set_long("%^BOLD%^This small room is almost totally white, the floors "
"white marble. This room has no window and is lit by a single bright crystal "
"hanging from the ceiling. There is a fine marble toilet, and a large "
"bathtub. A mirror hangs on the wall near a wash basin. The room is "
"spotless.%^RESET%^");
   set_smell("default","There is no smell in this room.");
   set_listen("default","You can hear very little in this room.");

   set_items(([
     ({"mirror"}) : "%^BOLD%^Formed from glass with a high polish, you can "
"see your reflection clearly. The edges of the mirror are lined in "
"%^YELLOW%^gold%^RESET%^%^BOLD%^. Obviously this is an expensive item, and it "
"is securely hung on the wall.%^RESET%^",
     ({"basin","wash basin"}) : "%^BOLD%^A white marble wash basin filled "
"with %^BLUE%^clear blue water%^RESET%^%^BOLD%^. A bucket stands beside it "
"to refill it and several %^RESET%^%^ORANGE%^soft towels%^RESET%^%^BOLD%^ "
"hang on a %^BLACK%^%^BOLD%^wrought iron ring%^RESET%^%^BOLD%^ beside "
"it.%^RESET%^",
     ({"tub"}) : "%^BOLD%^Formed from white marble, this tub is immense, big "
"enough to fit more then one person easily. It rests on four legs, shaped "
"into lion's paws. Two %^YELLOW%^golden faucets%^RESET%^%^BOLD%^ are "
"connected to hot and cold water, though the pipes have been cleverly "
"hidden.%^RESET%^",
   ]));

   set_exits(([
     "north" : ROOMS+"bedroom",
   ]));
   set_door("door",ROOMS+"bedroom","north",0);
}
