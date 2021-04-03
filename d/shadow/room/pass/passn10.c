#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + desc_road_slow + " " + desc_and_cumbersome 
    + desc_road_high + desc_cliff + desc_savannah_bush);


    set_exits(([
      "north" : PASSDIR+"passn9",
      "southeast" : PASSDIR+"pass3"
      ]));
}
