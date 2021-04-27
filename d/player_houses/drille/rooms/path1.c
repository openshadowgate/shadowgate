#include <std.h>
#include "../drille.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("A neat little path");    
    set_short("%^GREEN%^A neat little path%^RESET%^");
    set_long("This is a small path travels between the large forest trees. It "
"looks as though it is not well travelled, but clearly someone is using it at "
"present. The center of the path is free from grass and weeds. Animals can be "
"heard scurrying about in the trees and beneath the brush. In the distance a "
"few birds are singing.");
    set_smell("default","The smells of the forest surround you.");
    set_listen("default","Animals can be heard scurrying about through the woods.");
    set_exits(([
      "west" : "/d/guilds/kindred/rooms/bees",
      "east" : ROOMS"path2",
    ]));
}
