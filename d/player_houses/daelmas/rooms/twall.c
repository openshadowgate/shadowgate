//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

int FLAG;

void create()
{
    ::create();
    set_name("Tower wall");
    set_short("tower wall");
    set_long(
        "%^RESET%^" +
        "You stand before the tower's outer wall. The wall itself " +
        "reaches about ten feet up, and is made of the same marble " +
        "as the tower. The wall looks extraordinarily clean and well " +
        "taken care of. There is a single gate leading through the " +
        "wall, towards the tower. The gate itself is made of blackened " +
        "iron bars crossing over each other, allowing you to gaze " +
        "inside. An enormous garden lies behind the wall.\n"
        );
    set_terrain(SHORE);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_smell("default", "Numerous smells lifting from flowers floats " +
              "softly through the air.");
    set_listen("default", "There are no unordinary sounds here.");
    set_items(([
                   "wall" : "The wall is made up of marble stones of roughly the " +
                   "same size and coloration, but maybe a closer examination " +
                   "could tell you more.",
                   "stones" : "The stones appear to be made of marble and roughly " +
                   "the same size and coloration, but maybe a closer examination could tell you more."
               ]));

    set_door("iron gates", DROOMS + "garden", "northwest", "marble key");
    set_locked("iron gates", 1, "lock");
    lock_difficulty("iron gates",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    (DROOMS + "garden")->set_locked("iron gates", 1, "lock");
    set_door_description("iron gates", "The gate is made of blackened " +
                         "iron bars crossing over each other.");
    set_string("iron gates", "open", "The gates groan loudly as they " +
               "open into a beautiful garden.\n");

    set_search("wall", "The wall is made of large marble stones which " +
               "are roughly the same size and coloration, although one stone " +
               "near the gates appears to be darker than all the rest.");
    set_search("marble", "The marble is of good quality and durable.  " +
               "One stone of marble, about the size of a fist, seems darker than all the rest.");
    set_search("stones", "The are of marble and appear roughly the same " +
               "size and coloration except for one stone, about fist size, that " +
               "is darker than the rest.");
    set_search("stone", "This stone of marble is darker and smaller than " +
               "the rest for some reason.  Tapping it reveals a somewhat hollower " +
               "sound than tapping the rest of the wall.");


    set_exits(([
                   "northwest" : DROOMS + "garden",
                   "southwest" : DROOMS + "dp0"
               ]));

    set_trap_functions(({ "iron gates" }), ({ "alarm_me" }), ({ "open" }));

    FLAG = 0;
}

void init()
{
    ::init();
    add_action("tap_em", "tap");
}

int tap_em(string str)
{
    if (!str) {
        tell_object(TP, "%^BOLD%^Tap what?");
        return 1;
    }
    if (str == "stone twice") {
        if (FLAG == 1) {
            tell_room(TO, "%^BOLD%^" + TPQCN + " taps on a stone and it swings " +
                      "open.\n", TP);
            tell_object(TP, "%^BOLD%^You tap the stone twice and it swings open " +
                        "revealing an empty compartment.\n");
            return 1;
        }else {
            tell_object(TP, "%^BOLD%^You tap the stone twice and it swings open to " +
                        "reveal a small hidden compartment and your stashed key.\n");
            tell_room(TO, "%^BOLD%^" + TPQCN + " taps on a stone and it swings " +
                      "open.\n", TP);
            FLAG = 1;
            new(DOBJ + "marble_key")->move(TO);
            return 1;
        }
    }else if (str) {
        tell_room(TO, "%^BOLD%^" + TPQCN + " taps the " + str + " and nothing  " +
                  "happens.\n", TP);
        tell_object(TP, "%^BOLD%^You tap the " + str + " and nothing happens.\n");
        return 1;
    }
}

int alarm_me(string str)
{
    tell_room((DROOMS + "torture"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "balc"), "%^BOLD%^%^RED%^You hear a dragon's roar from below.\n");
    tell_room((DROOMS + "study"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "mast_room"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "land2"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the stairs.\n");
    tell_room((DROOMS + "land3"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the stairs.\n");
    tell_room((DROOMS + "land4"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the stairs.\n");
    tell_room((DROOMS + "land5"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the stairs.\n");
    tell_room((DROOMS + "land6"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the stairs.\n");
    tell_room((DROOMS + "gab_room"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "sitting"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "wash_room"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "kitchen"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    tell_room((DROOMS + "foyer"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "coming from the area of the garden.\n");
    tell_room((DROOMS + "hblood0"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the hallway.\n");
    tell_room((DROOMS + "hblood1"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the hallway.\n");
    tell_room((DROOMS + "hblood2"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the hallway.\n");
    tell_room((DROOMS + "hblood3"), "%^BOLD%^%^RED%^You hear a dragon's roar " +
              "echoing up and down the hallway.\n");
    tell_room((DROOMS + "rskulls"), "%^BOLD%^%^RED%^You hear a dragon's " +
              "roar in the distance.\n");
    return 0;
}
