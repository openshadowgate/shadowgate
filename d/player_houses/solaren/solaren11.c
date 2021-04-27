// Observatory
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren11.c

#include <std.h>
#include "../defines.h"

inherit VAULT;

void create() {
    object ob;
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Observatory%^RESET%^");
  set_long(
@THORN
%^BOLD%^Observatory%^RESET%^
This is a relatively airy room with large windows facing each of the
cardinal compass points.  A telescope sits near the northwestern window
and charts of some sort lay near it on a small worktable.  There is a
comfortable seating area here and you imagine that this room provides an
excellent view of the surrounding area or provides a strategic vantage
point to view any encroaching threat to the tower.

There is a trapdoor that leads down into the tower.
THORN
  );
  set_items(([
    "sign" : "You can try and read the sign.",
  ]));
  set_exits(([
      "down" : "/d/player_houses/solaren/solaren10",
  ]));
// removed the key on this side so people can't get locked in *Styx*  4/18/03
  set_door("trap door","/d/player_houses/solaren/solaren10","down");
  set_open("trap door",0);
  set_locked("trap door",1);
  "/d/player_houses/solaren/solaren10"->set_open("trap door",0);
   ob = new("std/bboard");
// New board replacement to auto-log seen posters.
  ob->set_name("board");
     ob->set_short("A message board");
  ob->set_id( ({ "board", "bulletin board", "reality board" }) );
  ob->set_board_id("sherlock_board");
  ob->set("long","This is a message board where folk can leave messages.");
  ob->set_max_posts(50);
  ob->set_queue();
    ob->set_location("/d/player_houses/solaren/solaren11");
}

void reset(){
  ::reset();  
}

void init() {
  ::init();
//  add_action("snap", "snap");
}

/* not needed here now with no key on this side
int snap(string str) {
  object ob;
  object other;
  
  if(str != "twice") return 0;
  if(((string)TP->query_name() != "solaren") && !avatarp(TP))
    return 0;
  other = find_object_or_load("/d/player_houses/solaren/solaren10");
  if(!query_locked("trap door")) {
    tell_room(TO,
      TP->query_cap_name()+" snaps "+TP->query_possessive()+
	  " fingers twice and you hear a bolt slide home!",
      ({ TP }));
    tell_room(other,
      "You hear a bolt slide home on the trap door!",
      ({ TP }));
    write("You snap your fingers twice and the trap door locks itself!");
    TO->set_open("trap door",0);
    TO->set_locked("trap door",1);
    other->set_locked("trap door",1);
    other->set_open("trap door",0);
	return 1;
  } 
  tell_room(TO,
    TP->query_cap_name()+" snaps "+TP->query_possessive()+
	" fingers twice and you hear a bolt slide as the trap door unlocks itself!",
    ({ TP }));
    tell_room(other,
      "You hear a bolt slide as the trap door unlocks!",
      ({ TP }));
  write("You snap your fingers twice and the trap door unlocks itself!");
  TO->set_locked("trap door",0);
  other->set_locked("trap door",0);
  return 1;
}
*/
