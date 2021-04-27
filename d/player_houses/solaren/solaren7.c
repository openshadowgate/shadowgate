// The kitchen of the tower
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren7.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>

inherit ROOM;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^The kitchen of the tower%^RESET%^");
  set_long(
@THORN
%^BOLD%^The kitchen of the tower%^RESET%^
This room is a large work space with a fireplace ready to be lit.  There
are small cupboards throughout, storing various foodstuffs and cooking
implements.  You can see cooking herbs and spices that have been hung
from the rafters to dry.  Off to one side, a doorway leads to what you
suppose to be a pantry.  You can pass though a smaller door into a
hallway to the southwest.
THORN
  );
  set_smell("default", "You can smell pungent herbs hanging in here and the scent of wood smoke.");
  set_exits(([
      "west" : "/d/player_houses/solaren/solaren5",
      "southwest" : "/d/player_houses/solaren/solaren6",
  ]));
}

void reset(){
  ::reset();  
}
