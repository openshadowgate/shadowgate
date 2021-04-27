//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;
int ROD_IN, FLAG;

void create()
{
    ::create();
    set_name("hall");
    set_short("hall");
    set_long(
        "%^BOLD%^%^BLACK%^" +
        "This is a secret hallway leading to the west and an iron door in the west.  " +
        "The walls have grooves in them and this is similar " +
        "to the first hallway in craftmanship." +
        "%^RESET%^"
        );
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 1);
    set_smell("default", "The air is oppressive in this small hallway.");
    set_listen("default", "You can hear the very faint clinking of chains to the west.");
    set_items(([
                   "floor" : "The floor is clean and made of finely cut stone that has " +
                   "been expertly fitted together.\n",
                   "ceiling" : "The ceiling is about ten feet above and lost in the shadows.\n"
               ]));
    set_exits(([
                   "west" : SROOMS + "torture",
                   "east" : SROOMS + "hall"
               ]));

    set_door("iron door", SROOMS + "torture", "west", "black skeleton key");
    set_locked("iron door", 1, "lock");
    (SROOMS + "torture")->set_locked("iron door", 1, "lock");
    set_door_description("iron door", "The door is made of iron " +
                         "and looks massive and tough.\n");
    lock_difficulty("iron door",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    set_string("iron door", "open", "The iron door was balanced perfectly " +
               "because it opened with little effort into the torture chamber.\n");

    ROD_IN = 0;
    FLAG = 0;
}

void init()
{
    ::init();
    add_action("insert_em", "insert");
    add_action("lift_em", "lift");
}

int lift_em(string str)
{
    if (!str) {
        tell_object(TP, "%^BOLD%^Lift what where?");
        return 1;
    }
    if (ROD_IN == 0) {
        tell_object(TP, "%^BOLD%^You need to insert the rod first!");
        return 1;
    }
    if (str == "rod upward") {
        tell_room(TO, "%^BOLD%^" + TPQCN + " lifts up on the rod.\n");
        call_out("draining", 0, TP, 0);
        tell_room(TO, "You a click and feel a slight shudder in the floor!\n");
        tell_room(TO, "The rod crumbles.\n");
        return 1;
    }
}

int insert_em(string str)
{
    object obj;
    if (!str) {
        tell_object(TP, "Insert what into where?");
        return 1;
    }
    if (FLAG == 1) {
        tell_object(TP, "%^BOLD%^You can't do that, something is already jamming the hole!\n");
        return 1;
    }
    if (str == "rod into hole" || str == "rod into the hole" || str == "rod into center hole"
        || str == "rod into the center hole" || str == "rod in hole"
        || str == "rod in the hole" || str == "rod in center hole"
        || str == "rod in the center hole") {
        if (obj = present("rod", TP)) {
            ROD_IN = 1;
            tell_room(TO, "%^BOLD%^" + TPQCN + " inserts the rod into the center hole.\n");
            obj->remove();
            FLAG = 1;
            return 1;
        }else {
            tell_object(TP, "%^BOLD%^You don't have a rod!\n");
            return 1;
        }
    }
}

void draining(object tp, int num)
{
    switch (num) {
    case (0):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^You hear a distant click and then " +
                  "a grinding sound.\n");
        break;

    case (1):
        break;

    case (2):
        break;

    case (3):
        break;

    case (4):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^You hear the sounds of metal " +
                  "screeching as it protests against movement then silence.\n");
        tell_room(TO, "%^BOLD%^%^CYAN%^You hear the sounds of metal " +
                  "screeching as it protests against movement then silence.\n");
        tell_room((SROOMS + "hall0"), "%^BOLD%^%^CYAN%^You hear the sounds of metal " +
                  "screeching as it protests against movement then silence.\n");
        break;

    case (5):
        break;

    case (6):
        break;

    case (7):
        break;

    case (8):
        break;

    case (9):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^Stone grinds against stone from " +
                  "the bottom of the north and south wall.\n");
        tell_room(TO, "%^BOLD%^%^CYAN%^The grinding of stone against stone " +
                  "can be heard through the southwest wall.\n");
        tell_room((SROOMS + "hall0"), "%^BOLD%^%^CYAN%^The grinding of stone " +
                  "against stone can be head through the east wall.\n");
        break;

    case (10):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^The water level " +
                  "starts to rapidly drop.\n");
        break;

    case (11):
        break;

    case (12):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^The last of the water drains " +
                  "out through slots at the base of the walls.\n");
        break;

    case (13):
        break;

    case (14):
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^The walls blocking the passages " +
                  "to the northeast and the west slides slowly back up into the ceiling.\n");
        tell_room((SROOMS + "hall0"), "%^BOLD%^%^CYAN%^The wall blocking the passage " +
                  "to the southwest slides slowly back up into the ceiling.\n");
        tell_room(TO, "%^BOLD%^%^CYAN%^The wall blocking the passage " +
                  "to the east slides slowly back up into the ceiling.\n");
        tell_room((SROOMS + "hall"), "%^BOLD%^%^CYAN%^Another harrowing escape?!?!\n");
        (SROOMS + "hall")->set_surface(1);
        (SROOMS + "hall")->remove_property("underwater");
        (SROOMS + "hall")->set_smell("default", "The air is damp and " +
                                     "oppressive in this small hallway.");
        (SROOMS + "hall")->set_listen("default", "You can hear the faint " +
                                      "dripping of water and " +
                                      "the clinking of chains to the west.");
        (SROOMS + "hall0")->set_long("%^BOLD%^%^BLACK%^" +
                                     "This is a secret hallway leads to the southwest.  " +
                                     "The walls have grooves in them and this is similar " +
                                     "to the first hallway in craftmanship." +
                                     "%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^" +
                 "This is a secret hallway leads to the east and to an iron door in the west.  " +
                 "The walls have grooves in them and this is similar " +
                 "to the first hallway in craftmanship." +
                 "%^RESET%^");
        (SROOMS + "hall")->add_exit(SROOMS + "hall0", "northeast");
        (SROOMS + "hall")->add_exit(SROOMS + "hall1", "west");
        (SROOMS + "hall0")->add_exit(SROOMS + "hall", "southwest");
        add_exit(SROOMS + "hall", "east");
        return;
    }
    num++;
    call_out("draining", 0, tp, num);
    return;
}

void reset()
{
    ::reset();
    ROD_IN = 0;
    FLAG = 0;
}
