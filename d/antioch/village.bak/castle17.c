#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/room";

void init() {
  ::init();
  do_random_encounters(({
    MON+"skeleton",
    MON+"zombie"
  }),50, 3);
  add_action("go_north","north");
}
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Top of Stairs");
  set_long(
@ANTIOCH
%^BOLD%^You are in the Castle of Antioch.
%^GREEN%^You have finally reached the top of the staircase.  But it seems
that now you have bigger things to worry about.  The weather outside 
looks as if it is getting worse, and the rain is beginning to leak
through the walls.
ANTIOCH
  );
  set_smell("default", "You can smell great amounts of blood.");
  set_listen("default", "You hear water leaking through the walls.");
  set_exits(([
    "north": CASTLE+"castle18",
    "down":CASTLE+"castle16"
  ]));
  set_items(([
     ({"water"}):"Thats not water it's %^RED%^BLOOD%^RESET%^"
  ]));
}

int go_north(string str){
  if(present("skeleton")){
    write("The skeleton will not let you go that way.");
    return 1;
  }
  if(present("zombie")){
    write("The zombie will not let you pass.");
    return 1;
  }
}
