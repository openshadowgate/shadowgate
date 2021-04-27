// Stairwell in the tower
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren8.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>

inherit ROOM;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Stairwell in the tower%^RESET%^");
  set_long(
@THORN
%^BOLD%^Stairwell in the tower%^RESET%^
You are at the foot of a great staircase heading up into the Tower.  The
smooth stairs are carved from single pieces of stone and curve along the
exterior wall of the place, with several windows piercing its exterior
to provide additional light during the day.  The stairs will allow you
to go up from here.
THORN
  );
  set_exits(([
      "south" : "/d/player_houses/solaren/solaren5",
      "up" : "/d/player_houses/solaren/solaren9",
  ]));
}

void reset(){
  ::reset();  
}
