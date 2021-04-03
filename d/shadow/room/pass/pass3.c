#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + desc_road_slow + "%^ORANGE%^. " + desc_plain_fade + desc_trees);

    set_exits(([
	"south" : PASSDIR+"passn11",
	"northwest" : PASSDIR+"passn10"
   	]));
}
