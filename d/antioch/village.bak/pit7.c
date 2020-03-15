// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_light(-1);
  set_indoors(1);
  set_property("no castle",1);
  set("short",
"Inside a sewer"
  );
  set_long(
@ANTIOCH
You are below the surface of the village of Antioch.
The tunnel is almost dry here.  There is a large pipe emptying into
this part of the sewers and you can hear and see its contents 
pouring onto the ground.  There appears to be a hole of some sort in
the wall of the tunnel.  It is very dark here, but you see some
light coming from the north.
ANTIOCH
  );
   set_listen("default","You hear the contents of the drain pipe hitting the floor.");
  set_exits(([
    "north":PIT+"pit8"
  ]));
  set_items(([
    "pipe":"It is emptying waste into the sewers.",
    "hole":"It looks just large enough for someone to crawl through."
  ]));
}

void init(){
  ::init();
  add_action("look_hole","look");
}

void reset(){
  ::reset();
  remove_exit("hole");
}

int look_hole(string str){
  if((!str)||(str!="hole"))
    return 0;
  else{
    add_exit(PIT+"tunnel1","hole");
    return 0;
  }
}
