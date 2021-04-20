#include <std.h>
#include "../defs.h"
inherit VAULT;

string nurvalentrance = "/d/dagger/nurval/room/necro1";

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",0);
    set_travel(FOOT_PATH);
    set_terrain(ROCKY);
    set_name("A earthen basement");
    set_short("A earthen basement");
    set_long("%^BOLD%^%^BLACK%^You find yourself in a dusty tunnel "
"dug out of the earth. The walls are dusty with dry, grey soil, and pebbles "
"loosen and trickle to the ground as you walk past. There are no support "
"beams in this area, hopefully the tunnel will not cave in around you.\n"
"The tunnel stops abruptly here."
"%^RESET%^\n");
    set_smell("default","Dust fills the air, clogging your sense of smell.");
    set_listen("default","You can hear the faint sound of someone moving above you.");

    set_items(([
      ({"tunnel"}) : "%^RESET%^%^ORANGE%^The tunnel is more a hole through the ground "
"than a proper tunnel. It is narrow and dusty, making it hard for living creatures "
"to breathe in here. %^RESET%^",
      ({"stone", "dirt", "soil"}) : "%^RESET%^%^ORANGE%^There is very little "
"stone here as most of the walls are made up of packed yet crumbling earth. "
"%^RESET%^",
      ({"walls", "wall", "floor", "ceiling"}) : "%^RESET%^%^ORANGE%^The occasional shifting of "
"loose soil can be seen falling from the ceiling or floors. "
"The lack of supporting beams makes you realize this is indeed "
"not safe, except for those who do not mind being buried on occasion.%^RESET%^",
    ]));

    set_exits(([
      "southwest" : TUNNEL"tonovi04",
      "up" : nurvalentrance,      
    ]));
    set_invis_exits(({"up"}));
    set_search("default", "A hole leads upwards. You catch a glimpse of light above.");

}
