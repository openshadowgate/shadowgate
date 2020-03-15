#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void init() {
  ::init();
  do_random_encounters(({
    MON+"demon",
    MON+"skeleton",
  }),50, 3);
  add_action("portal", "portal");
}
void create() {
  ::create();
  set_light(1);
  set_indoors(1);
  set_short("Hallway");
  set_long(
     "\n"
"%^BOLD%^You are in the Castle of Antioch.%^RESET%^\n"
"The storm has increased by ten.  Sand from rooms below blows in your face, "
"making it very hard to see.  Because of the light weight of the skeletons "
"they just fly by, falling into small little pieces.\n"
);
  set_smell("default", "You can smell dry sand.");
  set_listen("default", "You hear the wind howling.");
  set_exits(([
    "portal": CASTLE+"castle21",
    "south": CASTLE+"castle17"
  ]));
  set_items(([
    "water":"That's not water it's %^RED%^BLOOD%^RESET%^!"
  ]));
}

int portal(string str) {
  if(present("demon")){
    write("The demon will not let you pass.");
    return 1;
  }
  if(present("skeleton")){
    write("The skeleton will not let you pass.");
    return 1;
  }
  else{
    write("You travel through a small portal into another part of the castle.\n");
    TP->move_player(CASTLE+"castle21");
    return 1;
  }
}

