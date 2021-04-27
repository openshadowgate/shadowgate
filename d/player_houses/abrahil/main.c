//Coded by Styx for Abrahil
#include <std.h>

inherit VAULT;
#define OWNERS ({"abrahil", "styx"})

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("earthen hut");
    set_short("An earthen-walled hut");
    set_long("This room is dimly lit and you notice it is furnished with simple wooden furniture.  Three small cots dot the room as well as an %^ORANGE%^oaken desk%^RESET%^.  A lovely %^GREEN%^forest green rug %^RESET%^made out of wool lines the floor.  Obviously the one who owns this dwelling is simple in nature.");
   set_items(([
    "desk" : "The medium sized oak desk has various papers spread out upon it.",
    "papers" : "The papers seem to hold many documents pertaining to land "
       "titles and forestry cutting.  There are also cartography maps showing "
       "streams and other natural landmarks.",
    "cots" : "It looks as though these are well used.  Either this place has "
       "more than one occupant or people rest here often.",
    "rug" : "%^GREEN%^A lovely forest green woolen rug, woven with a design "
       "of the holy symbol of Eldath.",
    ] ));
    set_exits(([
       "out" : "/d/player_houses/abrahil/yard",
       "north" : "/d/player_houses/abrahil/kitchen",
    ] ));
   set_door("door","/d/player_houses/abrahil/yard","out",0);
   set_door_description("door","This is a strong oak door that is hinged "
     "well.  It has a knob that lets you unlock the door from inside "
     "without a key.");
   set_smell("default","The earthen smell is unmistakable but not unpleasant.");
   set_listen("default","All sound seems to be muted by the earthen walls, "
      "further enhancing the tranquility you sense.");
}

void init() {
   ::init();
}
