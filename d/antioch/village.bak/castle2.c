#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";
void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(
     " \n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"This room is filled with strange noises.  A clock, on the west wall, echos "
"a continues song.  A huge statue is also standing in the corner of the "   
"room.  The noises seem to increase to the east.\n"  
);
     set("night long",
     "\n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"%^CYAN%^It is very cold.\n"
"The castle now is very cold.  Dust is here on the ground, making it hard to breath.  There is also "
"footprints in the dust but they do not extend very far.  A broken "
"grandfather clock is here.\n" 
);
     set_smell("default", "You smell dust from the statue.\n");
     set_listen("default", "You hear the Grandfather clock.\n");
     set_exits(([
    "east":CASTLE+"castle3",
    "south": CASTLE+"castle1"
]));     
     set_items(([
({"clock"}):
"It seems to be a grandfather clock.\n"
"Is that a crack you see behind it?",
({"statue"}):
"This is a huge statue of a zombie.",
({"footprints"}):
"They seem to lead toward the clock.",
({"crack"}):
"You can't quite see it... maybe if you %^BOLD%^push %^RESET%^the clock out of the way?"
]));
}
void init() {
     ::init();
do_random_encounters(({"/d/antioch/mon/zombie.c"}),50, 1);
    add_action("go_east","east");
    add_action("move_clock","push");
}

int move_clock(string str){
  if((!str) || (str!="clock"))
    return(0);
  else {
    tell_room(environment(this_player()),this_player()->query_cap_name()+"moves the clock out of the way, revealing a hole in the wall.",this_player());
    tell_object(this_player(),"You find a hole in the wall!");
    TO->add_exit(CASTLE+"hole1","hole");
  return(1);
  }
}

int go_east(string str){
  if(present("zombie")){
    write("The zombie blocks your way east.\n");
    return 1;
  }
}
void reset(){
  ::reset();
  remove_exit("hole");
}
