#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A dark chamber");
  set_short("%^BOLD%^%^BLACK%^A dark chamber%^RESET%^");
  set_long( "%^BOLD%^%^BLACK%^You are in a dark %^RESET%^stone chamber"
     +"%^BOLD%^%^BLACK%^, hidden within the %^RESET%^%^GREEN%^j%^BOLD%^"
     +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
     +"%^GREEN%^e%^BOLD%^%^BLACK%^. There are no windows, the little"
     +" l%^RESET%^i%^BOLD%^%^BLACK%^ght that slants in through low"
     +" doorways to the north and south seems to be swallowed by the"
     +" surrounding gloom." );
  set_items(([ ({"walls", "north wall", "south wall", "east wall", "west wall"}) :
     "The stones of the wall are not as plain and blank as might be assumed at"
    +" first glance. Closer inspection reveals that they bear carved decoration,"
    +" though much of it has been worn smooth by the passage of years.",
    ({"decoration", "decorations"}) : "Not all of the decoration can be made out"
    +" now, but there appears to be writing in some strange script, as well as"
    +" images of jungle scenes and an apparent civilisation, unlike any that you"
    +" know of existing today. The south wall bears an image of a stepped pyramid,"
    +" with a stylised sun appearing at its peak, and a feathered serpent coiling"
    +" through the air beside it." ]));
  set_smell("default","The air is musty and dusty, with a smell of damp."
             +" earth");
  set_listen("default","The room itself is very quiet, with the sounds"
             +" of the jungle filtering in from outside.");
  set_exits( ([      "north" : ROOMS + "stone_pillar" , "south": ROOMS + "hillside"])  );
 set_pre_exit_functions(({"north", "south"}), ({"GoNorth", "GoSouth"}));
}

void GoNorth(){
  object pillar;
  int cleared;
  pillar = find_object_or_load(ROOMS + "stone_pillar");
  if (!objectp(pillar)){
    return;
  }
  cleared = pillar->query_cleared();
  switch (cleared){
  case 2:
    return;
    break;
  case 0..1:
    tell_object(TP, "To get through the doorway, you have to force your way through a mass of overgrown creepers and vines that were blocking the other side of the doorway");
    tell_room(TO, TPQCN + "forces " + TP->QP + " way through a mass of overgrown creepers and vines to go through the low doorway to the north.", TP);
    tell_room(pillar, "The wall of foliage to the south heaves and shifts as "+ TPQCN + " forces " + TP->QP + " way through it, to emerge from some kind of doorway in a wall that was hidden underneath the mas of vines and creepers", TP);
    pillar->set_cleared(0);
    pillar->add_exit(ROOMS + "entry_chamber", "south");
    break;
  }
  return 1;
}

void GoSouth(){
  tell_object(TP, "You duck through the low doorway and emerge onto the top of a"
                 +" relatively clear, lush %^BOLD%^%^GREEN%^green hillside%^RESET%^.");
  tell_room(TO, TPQCN + "ducks through the low doorway to the south.", TP);
  return 1;
}
