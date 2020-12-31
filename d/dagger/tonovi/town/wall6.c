#include "/d/dagger/tonovi/town/short.h"

inherit "/d/dagger/tonovi/town/wall4";

void create(){
    ::create();
    set_exits( ([
	"east" : RPATH "wall5",
	"west" : RPATH "wall7",
        "down":"/d/shadow/ratpaths/rooms/rp_p031_p010",
      ]) );
    set_invis_exits(({"down"}));
    set_search("default", "You find a hatch with ladder leading down behind some rubble.");
}
