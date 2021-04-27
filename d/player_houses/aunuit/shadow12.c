//Ryzan and Aunuit's House
//Coded by ~Circe~ 10/4/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"shadow13",
      "southeast" : ROOMS"shadow11",
      "west" : ROOMS"shadow3",
      "east" : ROOMS"shadow12" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"northeast"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^west%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}
