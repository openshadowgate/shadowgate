#include "/d/antioch/areadefs.h"
inherit "/std/room";

void create() {
     ::create();
     set_light(3);
     set_indoors(3);
     set_short("dirt hills");
     set_long(
     "\n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"There is a strange clearing here, filled with sand and dirt.  Some "
"people are here, shoveling their way down into the ground.  They must be looking "
"for something important.  As they dig, you notice bones being turned up.\n"
);
set_smell("default","You smell dry bones.\n");
set_listen("default", "You hear the shovels shovelling.\n");
     set_exits(([
       "east": CASTLE+"castle13",
       "south": CASTLE+"castle11"
]));
set_items(([
(({"people"})):
"They look like they could use some help digging"
]));
}
void init() {
     ::init();
add_action("dig", "dig");
add_action("lift", "lift");
}

int dig(string str) {
write(
"\n"
"As you dig through the dirt and bones your hand hits something hard.  As "
"you continue to brush the sand from the hard object you see a grate.  You "
"should lift the grate.\n"
);
return 1;
}
int lift(string str) {
  this_player()->move_player(CASTLE+"dig");
write("As you remove the grate you loose your footing and fall into a hole.");
write("A huge spike drives through your torso.\n");
write("Better get someone to heal you!\n");
return 1;
}

