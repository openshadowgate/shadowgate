#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + desc_road_easy + desc_road_fade + desc_trees);

    set_exits(([
	"south" : PASSDIR+"pass2",
	"north" : PASSDIR+"pass3"
   	]));
}
