//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Guard Room");
    set_long(
        "%^GREEN%^" +
        "This room is cut out of the mountain itself. It is cold and damp down here. The " +
        "stairs up are set in the east part of the room. There is a chair in the southwest " +
        "corner. Two torches light this room, one next to the stairs and one close to the " +
        "chair. A thick iron door leads north. This is not a place you would want to spend " +
        "alot of time in.\n" +
        "%^RESET%^"
        );
    set_property("indoors", 1);
    set_property("light", 2);
    set_smell("default", "The air is damp.");
    set_listen("default", "You hear squeaking noises.");
    set_items(([
                   "chair" : "The chair is most likely here for the comfort of a guard who watches the " +
                   "jail cell.  It is a normal wooden chair.",
                   ({ "torches", "torch" }) : "The torches are lit and set firmly in iron rings that stick " +
                   "out from the wall",
                   ({ "door", "iron door" }) : "The door is about 7 feet high, 5 feet wide and  made out of " +
                   "iron.  A large handle that can be gripped with both hands sticks out from the " +
                   "door.  A lock is set just under the handle."
               ]));

    set_door("iron door", MROOMS + "meldun", "north", "mithril key");
    set_locked("iron door", 1, "lock");
    (MROOMS + "meldun")->set_locked("iron door", 1, "lock");
    set_door_description("iron door", "The door is massive and made entirely of iron.");
    lock_difficulty("iron door",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "massive lock");
    set_string("iron door", "open", "The iron door creaks open revealing a dark,dingy, " +
               "smelly, and cramped jail cell.\n");

    set_exits(([
                   "north" : MROOMS + "meldun",
                   "up" : MROOMS + "meld1"
               ]));
}
