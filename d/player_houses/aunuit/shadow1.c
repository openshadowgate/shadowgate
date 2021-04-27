//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/29/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "west" : "/d/tharis/newtharis/rooms/tunnel8",
      "northwest" : ROOMS"shadow3",
      "southeast" : ROOMS"shadow2",
      "north" : ROOMS"shadow1" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"southeast"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^north%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}
