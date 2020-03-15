#include <std.h>
#include "../tecqumin.h"

inherit RIVER;

void create (){
  set_exits( ([ "left" : ROOMS + "leftbank1" , "right" : ROOMS + "rightbank1" ]) );
}