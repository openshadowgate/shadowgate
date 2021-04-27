// A narrow hallway
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren6.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>

inherit ROOM;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^A narrow hallway%^RESET%^");
  set_long(
@THORN
%^BOLD%^A narrow hallway%^RESET%^
You find yourself in a narrow hallway, well lit and extending from north
to south.  There are several smaller rooms along this corridor, some
fitted with beds and small wardrobes.  You suppose these to be guest
rooms for those who may find themselves here after dark or for students
of the masters of the tower.  You can enter the kitchen though a door to
the northeast.
THORN
  );
  set_smell("default", "You can smell pungent herbs and the scent of wood smoke to the northeast.");
  set_exits(([
      "north" : "/d/player_houses/solaren/solaren5",
      "northeast" : "/d/player_houses/solaren/solaren7",
  ]));
}

void reset(){
  ::reset();  
}
