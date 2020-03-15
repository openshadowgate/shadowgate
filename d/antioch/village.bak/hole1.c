#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

int flag;

void create() {
  ::create();
  set_light(0);
  set_indoors(1);
  set_no_steal(1);
  set_short("Antioch Castle");
  set_long(
@ANTIOCH
The room is pretty barren, as far as you can see.  The edges of 
the room are cloaked in shadows and you are not sure if you see
something moving or not.  There is a chair - more of a throne,
really - on a raised platform in the center of the room.  Two 
torches in tall stands behind the throne give off the only light
in the room.  You begin to wonder if you should just leave before
anyone, or anything, finds you here.
ANTIOCH
  );
    set_listen("default","You hear nothing but silence.\n");
  set_exits(([
      "out":CASTLE+"castle2"
  ]));
  set_items(([
    "torches":"They look dangerously close to going out.",
    "shadows":"The flickering torchlight makes it look like something is there.",
    "throne":"From the size of the throne, you are glad its occupant is not here!"
  ]));
}

void init(){
  ::init();
  add_action("search_room","search");
}

int search_room(string str){
  if(flag) return notify_fail("You find nothing odd.\n");
  if(!str){
    notify_fail("Search what?\n");
    return 0;
  }
  if(str!="shadows"){
    notify_fail("You can't search that!\n");
    return 0;
  }
  if(!present("undead lord")){
      tell_room(environment(this_player()),this_player()->query_cap_name()+" peers into the shadows.\n", this_player());
       tell_object(this_player(),"You peer into the shadows... right into the eyes of the Undead Lord!\n");
      new(MON+"ulord")->move(this_object());
      flag = 1;
      return 1;
  }
  else{
    tell_object(this_player(),"You find nothing more in the shadows.\n");
    return 1;
  }
}

void reset(){
   ::reset();
   flag = 0;
}
