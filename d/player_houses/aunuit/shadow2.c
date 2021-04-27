//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/29/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"shadow3",
      "northwest" : ROOMS"shadow1",
      "north" : ROOMS"shadow4",
      "east" : ROOMS"shadow2" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"south"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^west%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}
