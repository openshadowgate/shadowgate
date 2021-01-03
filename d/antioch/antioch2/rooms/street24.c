#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    object ob;
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("Oak Street");
    set_long(
        "%^WHITE%^You are on Oak street.\n o the west is a large and cheerful looking %^ORANGE%^bar,%^WHITE%^ though it doesn't seem to have too many customers just yet. It is a new building, and while not the most extravagant, it probably suits its customers well. Across from the bar is the %^ORANGE%^inn.%^WHITE%^ It reaches two stories in height and seems to be fairly clean and well run. You can hear the clank and clatter of dishes coming from its kitchen, and all sorts of delicious smells spill out the entrance. This would be a good place to get a good meal from. Further north is a mighty %^BOLD%^%^WHITE%^palace.%^RESET%^%^WHITE%^ Back to the south Oak street continues, meeting with Apple and Cedar in a crossroads and then continuing south to join with Cherry street.
"
        );
    if (query_night() == 1) {
        set_listen("default", "Drunken laughter spills forth from the" +
                   " bar on the west.");
    }else {
        set_listen("default", "You can hear the clatter of dishes" +
                   " coming from the inn.");
    }
    set_smell("default", "Scents of delicious foods pour forth from" +
              " the inn.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is Oak street.",
                   "palace" : "At the northern part of this road is a large and" +
                   " impressive palace.",
                   "inn" : "The inn is the large two story building on the east," +
                   " the entrance is right here and it looks like a clean and upright" +
                   " establishment. There is a sign hanging outside of it with a picture" +
                   " of a white dragon on it.",
                   ({ "bar", "tavern" }) : "The entrance to the local tavern is on the" +
                   " west here. A sign hangs out in front of it, declaring it the Eagle's Roost.",
                   "fountain" : "You can barely make out what looks like a large" +
                   " fountain at the southern end of this street.",
                   ]));
    set_exits(([
                   "north" : ROOMS + "street25",
                   "south" : ROOMS + "street10",
                   "west" : ROOMS + "bar",
                   "east" : ROOMS + "inn1",
                   ]));
    set_door("door", ROOMS + "inn1", "east", 0);
    if (query_night() == 1) {
        set_open("door", 0);
        "/d/antioch/antioch2/rooms/inn1"->set_open("door", 0);
    }else if (query_night() != 1) {
        set_open("door", 1);
        "/d/antioch/antioch2/rooms/inn1"->set_open("door", 1);
    }
    find_object_or_load("/d/npc/nulipseas");
    find_object_or_load("/d/npc/whitson");
    find_object_or_load("/d/npc/swarmani");
}
