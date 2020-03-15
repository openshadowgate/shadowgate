#include <std.h>
#include "../tecqumin.h"

inherit RIVER;

void create (){
  set_exits( ([ "left" : ROOMS + "leftbank2",  "right" : ROOMS + "rightbank2" ]) );
}