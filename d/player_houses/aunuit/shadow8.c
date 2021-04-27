//Ryzan and Aunuit's House
//Coded by ~Circe~ 10/4/13

#include <std.h>
#include "aunuit.h"

inherit ROOMS"storage/shadow_maze";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"shadow7",
      "northeast" : ROOMS"shadow9",
      "south" : ROOMS"shadow2",
      "southeast" : ROOMS"shadow8" //Yes, it returns you to this room.
   ]));
   set_post_exit_functions(({"northeast"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through the "
      "darkness, you notice a %^CYAN%^faint light%^BLACK%^ deep within "
      "the shadows to the %^WHITE%^south%^BLACK%^.%^RESET%^");
   return ::GoThroughDoor();
}

void reset(){
   ::reset();
   if(!present("dead_thief",TO)){
      new(OBJ"thief_obj")->move(TO);
   }
}