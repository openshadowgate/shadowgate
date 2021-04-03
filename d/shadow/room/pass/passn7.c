//New rooms added by Circe 12/29/03 to fix mapping problems
#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + desc_road_slow + " " + desc_and_cumbersome 
    + desc_road_high + desc_road_narrow + desc_cliff);


    set_exits(([
      "northwest" : PASSDIR+"passn6",
      "east" : PASSDIR+"passn8"
      ]));
}
