//platform.c - steps to Shrydelhi's house from the meadow.  Coded by Circe 9/12/03
#include <std.h>
#include "shry.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(STAIRWAY);
   set_name("A platform outside of a treehouse");
   set_short("A platform outside of a treehouse");
   set_long("%^RESET%^%^ORANGE%^A large branch here has grown to make a "+
      "perfectly flat surface to stand on.  Whats more, the edges of the branch "+
      "have curved up slightly, providing a natural barrier to keep anyone from "+
      "falling off.  The bark is smooth to the touch, and the canopy of "+
      "%^GREEN%^leaves %^RESET%^%^ORANGE%^above provide ample shade. A large door "+
      "can be seen that leads into the tree itself.%^RESET%^"+
      "\n");
   set_smell("default","You smell the crisp scent of treebark.");
   set_listen("default","You hear the quiet rustle of the leaves blown by the breeze.");
   set_items(([
      ({"canopy","leaves"}) : "%^GREEN%^A canopy of %^BOLD%^%^GREEN%^assorted colored green "+
         "%^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e%^GREEN%^a%^ORANGE%^v%^GREEN%^e%^ORANGE%^s "+
         "%^GREEN%^can be seen above you.%^RESET%^",
      ({"trunk","bark"}) : "The bark of the tree seems to have formed naturally into a "+
         "doorway of sorts, complete with a small knot for a handle."
   ]));
   set_exits(([
      "steps" : SHRY"meadow",
      "enter" : SHRY"living_room"
   ]));
   set_door("door",SHRY"living_room","enter","twig_key");
   set_door_description("door","The gnarled bark of the tree has grown into this door, which seems naturally formed.");
   set_locked("door",1);
}
