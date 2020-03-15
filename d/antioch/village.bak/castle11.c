//  Created by Demonforce, For shadowgate
//  Antioch castle
//  quest=Undead

#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void create() {
     ::create();
     set_light(3);
     set_indoors(3);
     set_short("You are in the castle of antioch.\n");
     set_long(
     "\n"
"%^BOLD%^You are in the castle of Antioch!%^RESET%^\n"
"You are in what seems to be a small hall.  This castle is known for large "
"numbers of hall ways.  Yet there is one more popular hall.  <%^CYAN%^The "
"Hall of the Undead%^RESET%^>, if by some chance you get through the hall "
"Tell someone!\n"
);
    set_listen("default","You hear only your own footsteps.");
     set_exits(([
       "west": CASTLE+"castle10",
       "north": CASTLE+"castle12"
]));
}
void init() {
     ::init();
  add_action("west","west");
}
int west(string str){
     write("Ohh no, You hear voices again.\n");
    TP->move_player(CASTLE+"castle10");
     return 1;
}
