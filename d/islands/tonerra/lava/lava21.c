#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "southwest":LAVA+"lava20",
    "east":LAVA+"lava34",
    "northeast":LAVA+"lava22",
  ]));
}