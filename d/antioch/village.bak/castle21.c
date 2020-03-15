#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void init() {
  ::init();
  do_random_encounters(({
    MON+"thorn"
  }),70,10);
  add_action("north", "north");
}
void create() {
  ::create();
  set_light(1);
  set_indoors(1);
  set_short("Hall of Thorns");
  set_long(
     "\n"
"%^BOLD%^You are in the Castle of Antioch.%^RESET%^\n"
"%^RED%^You are in the hall of Thorns%^RESET%^.\n"
"The storm has increased by ten.  Sand from rooms below blows in your face, "
"making it very hard to see.  Because of the light weight of the skeletons "
"they just fly by, falling into small little pieces.\n"
);
  set_smell("default", "You can smell dry sand.\n");
  set_listen("default", "You hear wind.\n");
  set_exits(([
    "north": CASTLE+"castle22",
    "portal": CASTLE+"castle18"
  ]));
  set_items(([
    "water":"That's not water, it's %^RED%^BLOOD%^RESET%^!"
  ]));
}

int north(string str) {
  write("20 thorns spring into your back.\n");
  write("OUCH");
  TP->move_player(CASTLE+"castle22");
  TP->add_hp(-(random(30)));
  return 1;
}

