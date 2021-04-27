//Ryzan and Aunuit's House
//Coded by ~Circe~ 10/4/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"shadow12",
      "east" : ROOMS"shadow14",
      "south" : ROOMS"shadow2",
      "northeast" : ROOMS"shadow13" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^north%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}
