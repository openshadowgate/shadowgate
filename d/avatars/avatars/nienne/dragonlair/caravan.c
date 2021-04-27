//interaction room!
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_name("Inside a caravan");
    set_short("%^RESET%^%^ORANGE%^Inside a caravan%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^You find yourself inside a caravan. It seems of "
"odd make, formed from strange %^RED%^dark wood %^ORANGE%^of a foreign texture. The wood has been "
"reinforced with strong %^BLUE%^metal bars%^ORANGE%^, including those that seal the only door, right at the back. Mere "
"slits exist to see out, revealing very little other than a splash of %^YELLOW%^daylight %^RESET%^%^ORANGE%^"
"that hints at the world beyond. A few elves sit about here, mostly inert or staring about with dull, empty gazes. Each is chained with "
"%^BOLD%^%^BLACK%^manacles %^RESET%^%^ORANGE%^to the wall of the wagon, and each far enough to be out of reach of "
"his or her nearest neighbour.\n");
    set_smell("default","You smell the odd aroma of the wood, and the dust of the road.");
    set_listen("default","The wagon creaks as it moves along the uneven roadway.");


}
