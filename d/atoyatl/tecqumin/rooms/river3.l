#include <std.h>
#include "../tecqumin.h"

inherit RIVER;

void create (){
  set_exits( ([ "left" : ROOMS + "leftbank3" , "right" : ROOMS + "rightbank3" ]) );
}