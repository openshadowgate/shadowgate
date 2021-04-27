//Coded by Diego//

#include <std.h>
#include "../isaiah.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create()
{
    ::create();
    set_terrain(BRANCHES);
    set_travel(FRESH_BLAZE);
    set_short("maple tree");
    set_long(
        "%^RESET%^%^ORANGE%^" +
        "Large branches jut out from the trunk of the tree here.  Several small " +
        "limbs come out from the tree forming a set of steps leading up to a " +
        "%^BOLD%^%^BLACK%^wooden door.  %^RESET%^%^ORANGE%^The door is angled " +
        "upward and the only way to go from here is the climb down the tree or " +
        "walk up the limbs to the door of the treehouse.\n" +
        "%^RESET%^"
        );
    set_property("indoors", 0);
    set_property("light", 2);
    set_smell("default", "You can smell crisp clean air and traces of %^BOLD%^%^YELLOW%^f%^RED%^l%^BLUE%^o%^YELLOW%^w%^RED%^e%^BLUE%^r%^YELLOW%^s%^RESET%^ %^ORANGE%^from the valley below.");
    set_listen("default", "The rustle of leaves and the faint sounds of crashing " +
               "water can be heard far below.");
    set_items(([
                   ({ "trunk", "tree" }) : "Though the tree is very large in girth there " +
                   "seems to be enough handholds to descend if you have the skill or " +
                   "the tools to climb.\n"
               ]));

    set_door("door", IROOMS + "iscom", "enter", "wood key");
    set_locked("door", 1, "lock");
    (IROOMS + "iscom")->set_locked("door", 1, "lock");
    set_door_description("door", "This door looks to be made of a single piece of " +
                         "wood, but you can discern no marks to show that the wood has been cut.  " +
                         "It is, almost, as if the door has grown to fit the opening exactly.");
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    set_string("door", "open", "You open the door into the common room of a tree house.\n");

    set_exits(([
                   "enter" : IROOMS + "iscom"
               ]));

    set_climb_exits((["descend" : ({ IROOMS + "istreed", 20, 6, 100 })]));
    set_fall_desc("%^BOLD%^%^GREEN%^You loose your grip and fall to the partially down " +
                  "the trunk of the tree bouncing from branch to branch all the way " +
                  "down!%^RESET%^\n");
}
