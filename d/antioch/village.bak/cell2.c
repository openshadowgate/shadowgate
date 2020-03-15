//  Code created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Garrison Area
//  One of the Jail Cells

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/vault";

int found = 0;

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 0);
  set("short", "A jail cell");
  set("long",
      "  The room is about six feet on a side, and the ceiling is a low, "
      "dark affair.  You wonder how anyone could stay sane in this room, "
      "but feel strongly that you don't want to find out.\n"
      "There is a small pile of dirt in the corner of the cell.\n"
  );
  set_items( ([
    ({"walls", "rock"}):
      "The walls seem to be hewn from living rock, leading you to believe "
      "that you are underground.  Large metal spikes poke from the walls, "
      "making this room even smaller than it appears!",
    ({"straw", "dirty straw", "floor"}):
      "The floor is covered with loose straw.  It looks as though it hasn't "
      "been cleaned in ages.",
    "ceiling":
      "The ceiling, much like the walls, looks to have been hewn from the "
      "living rock.  It has been thoughtfully covered in crap.\n"
      "Large spikes poke down from above, forcing you to stoop.\n",
    "door":
      "This door is set into the north wall.  It is made of wood banded "
      "with heavy metal straps.  A small grate is visible in the door, "
      "but it is closed."
    ]) );
  set_exits( ([
    "north":GAR+"jailhall4"
   ]) );
  set_listen("default","You hear footsteps in the distance.");
  set_door("cell door",GAR+"jailhall4","north","jail key");
  set_string("cell door", "open",
             "With a loud squeal from the hinges, the door swings open.\n"
            );
}

void init(){
  ::init();
  add_action("find_gold","look");
}

int find_gold(string str){
  if((!str)||(found)||((str!="pile")&&(str!="dirt")))
    return 0;
  if(!found){
    tell_object(TP,"%^BOLD%^You find a pile of gold and take the coins.\n");
    tell_room(TO,TPQCN+" finds a pile of gold.\n",TP);
    tell_object(TP,"%^BLUE%^You find a strange looking piece of %^YELLOW%^gold %^BLUE%^here.\n");
    new(OBJT+"gold")->move(this_object());
      TP->add_money("gold",random(3000));
  found=1;
  return 1;
  }
}

void reset(){
  ::reset();
  found=0;
}
