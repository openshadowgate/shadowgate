#include <std.h>
#include "../tecqumin.h"

inherit RIVER;

void create (){
  set_exits( ([ "left" : ROOMS + "leftbank4", "right" : ROOMS + "rightbank4" ]) );
}