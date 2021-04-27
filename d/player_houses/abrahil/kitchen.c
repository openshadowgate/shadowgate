//Coded by Styx for Abrahil
#include <std.h>

inherit ROOM;
int drinks, fruit;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("Kitchen");
    set_short("Kitchen of the hut");
    set_long("This chamber is used as a kitchen of sorts.  %^ORANGE%^Small "
"earthenware bowls %^RESET%^are set up on a rickety table along the eastern "
"wall.  Indications are that the food stored and prepared in this small room "
"frequently feeds many people.  You see small surpluses of food stacked in "
"the corners.  There is a %^ORANGE%^small oven %^RESET%^on the eastern wall "
"of the room.  A water basin is imbedded in the eastern wall.");
   set_items(([
     "table" : "This is an old wooden table.  It is well used but still stands.",
     "bowls" : "Small bowls made from clay.  They are neatly set around the "
        "table.  One of them has portions of dried fruit and nuts in it.",
     "food" : "A large stash of food, this includes dried meats and fruits, "
        "cheeses, wheat, grain, and spices.  There is a bowl out that you "
        "could grab a handful of dried fruit from if you're hungry.",
     "fruit" : "%^ORANGE%^Bits of dried fruit with some nuts mixed in.",
     "oven" : "%^ORANGE%^A small, well used oven made from earthen clay bricks.",
     ({"basin", "water basin" }) : "It seems to be filled from a spring and "
        "the water looks clear enough you're tempted to drink from it.",
    ] ));
    set_exits(([
       "northwest" : "/d/player_houses/abrahil/bedroom",
       "northeast" : "/d/player_houses/abrahil/meeting",
       "south" : "/d/player_houses/abrahil/main",
    ] ));
   set_smell("default","You smell the aroma of salted meats, dried fruits, and the various herbs.");
   set_listen("default","All sound seems to be muted by the earthen walls.");
}

void init(){
  ::init();
  add_action("drink_it","drink");
  add_action("get_food", "grab");
}

void reset() {
  ::reset();
  if(!random(2)) {
    if(drinks > 1)    drinks = 0;
    tell_room(TO,"%^BOLD%^You hear a soft gurgling as the basin slowly refills.");
  }
}

int drink_it(string str) {
  if(str != "water" && str != "from basin")  return 0;
  if(!str) return 0;
  if(!TP->add_quenched(50)){
    write("You are so full of water already that you don't really want more.");
    return 1;
  }
  if(drinks > 3) {
    write("The basin is too empty to get a drink right now.");
    return 1;
  }
  write("You take a large drink of the cool spring water.");
  tell_room(ETP,TPQCN+" takes a drink from the basin and seems refreshed.",TP);
  drinks++;
  return 1;
}

int get_food(string str) {
  if(!str)  notify_fail("Maybe you meant to grab fruit?");
  if(fruit > 3) {
    write("There's not enough left to grab right now.");
    return 1;
  }
  if(str != "food" && str != "fruit" && str != "handful") {
     write("Maybe you meant to grab fruit?");
     return 1;
  }
  write("You grab a nice handful of the fruit and nuts from the bowl.");
  tell_room(ETP,TPQCN+" grabs a small handful of fruit and nuts from a bowl",TP);
  new("/d/player_houses/obj/abrahil_food")->move(TP);
  fruit++;
  return 1;
}