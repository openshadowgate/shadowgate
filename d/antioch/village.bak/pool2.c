// Village of Antioch
// Pit Area

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

int pulled =0;
int found =0;

void create() {
  ::create();
  set_light(-2);
  set_indoors(1);
  set_property("no castle",1);
  set("short",
"Inside a sewer"
  );
  set_long(
@ANTIOCH
You are below the surface of the village of Antioch.
You seem to have reached the end of the sewers... at least this
is as far as you are able to travel.  There is a slimy chain 
hanging from the ceiling of the tunnel.  The water is about 12 
inches deep at this point, and you are worried that there may be a
sudden drop if you try to go any farther into the tunnels.
ANTIOCH
);
  set_listen("default","You hear a chain clinking against one of the walls.");
  set_exits(([
    "south":PIT+"pool1"
]));
  set_items(([
    "chain":"It is very slimy.  You wonder what it is attached to...",
    "water":"It is dark and you decide you do not really want to look too closely!"
]));
}

void init(){
  ::init();
  add_action("pull_chain","pull");
  add_action("search_water","search");
}

void reset(){
  ::reset();
  pulled =0;
  found = 0;
}

int pull_chain(string str){
  if(!str){
    notify_fail("Pull what?\n");
    return 0;
  }
  if(str!="chain"){
    notify_fail("You can't pull that!\n");
    return 0;
  }
  if(!pulled){
    tell_room(environment(this_player()),this_player()->query_cap_name()+" pulls on the slimy chain.",this_player());
    tell_player(this_player(),"As you pull on the slimy chain...\n");
    tell_room(environment(this_player()),"%^BOLD%^%^BLUE%^Water comes rushing out of a hole above your head!\n%^RESET%^");
    tell_room(environment(this_player()),"%^BOLD%^You hear something splash into the water at your feet.\n");
    pulled =1;
    return 1;
  }
  else {
      tell_player(this_player(),"You are already being drenched with water and other things!\n");
    return 1;
  }
}

int search_water(string str){
  if((!str)||(str!="water")){
    notify_fail("You find nothing odd.\n");
    return 0;
  }
    tell_room(environment(this_player()),this_player()->query_cap_name()+" searches the dirty water.\n",this_player());
  tell_player(this_player(),"You reach down into the murky water and feel around.\n");
  if(!found){
    tell_player(this_player(),"You jar a stone loose and it floats to the top.\n");
      new("/d/antioch/obj/diamond.c")->move(this_object());
    found =1;
  return 1;
  }
}
