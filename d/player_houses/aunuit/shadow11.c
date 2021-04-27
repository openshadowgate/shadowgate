//Ryzan and Aunuit's House
//Coded by ~Circe~ 10/4/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"shadow10",
      "northwest" : ROOMS"shadow12",
      "north" : ROOMS"shadow6",
      "south" : ROOMS"shadow11" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"northwest"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^southwest%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}
