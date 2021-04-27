// Laboratory
// Thorn@ShadowGate
// 001027
// Rufus' Player House
// labratory.c

#include <std.h>

inherit "/std/lab";

void create() {
  object ob;
  
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Laboratory%^RESET%^");
  set_long("%^BOLD%^A normal person would have no problem standing up in here, "+
  "as the ceiling is quite high. A long chain holds a lamp which appears to "+ 
  "be powered by magic that gives off a %^RESET%^bright white light%^BOLD%^. "+ 
  "The bright lighting illuminates a room in a state of very precise order. "+ 
  "Component bottles are neatly stowed and precisely labelled. Large "+ 
  "%^BLACK%^leather "+ 
  "%^WHITE%^and %^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^on-bou%^RESET%^n%^BOLD%^%^BLACK%^d "+ 
  "tom%^RESET%^e%^BOLD%^%^BLACK%^s %^WHITE%^are put away and actually connected "+ 
  "with %^BLACK%^metal chains %^WHITE%^to the bookcases. In another corner "+ 
  "of the room, it looks like a %^RESET%^workbench %^BOLD%^has been set up "+ 
  "and some %^RESET%^mechanical gadgets %^BOLD%^are in various states of repair. "+ 
  "In the center, a %^RESET%^table %^BOLD%^holds the requisite "+ 
  "%^RESET%^beakers%^BOLD%^, %^RESET%^burners %^BOLD%^and various "+ 
  "%^RESET%^magical paraphernalia %^BOLD%^that you might expect.\n\nThere "+ 
  "is a trap door in the floor by the north wall that gives access to the "+ 
  "room below.\n\nThere is a large sign on the wall which is written in "+ 
  "%^MAGENTA%^strange %^RESET%^%^MAGENTA%^mystic %^BOLD%^characters%^WHITE%^.%^RESET%^");
  set_items(([
    "sign" : "You can try and read the sign.",
  ]));
  set_exits(([
      "down" : "/d/player_houses/rufus/library",
  ]));
  setOwner("rufus");
  setLabId("rufus");
  setAllowedStorage(100);
  set_door("trap door","/d/player_houses/rufus/library","down");
  set_open("trap door",0);
  set_locked("trap door",0);
  "/d/player_houses/rufus/library"->set_open("trap door",0);
  ob=new("/d/magic/obj/mirror");
  ob->move(TO);
}

void reset(){
  ::reset();  
  if(!present("idol"))
new("/d/player_houses/obj/idol.c")->move(TO);
}

void init() {
  ::init();
  add_action("read", "read");
  add_action("snap", "snap");
}

int read(string str) {
  if(!str) return 0;
  if((string)TP->query_name() != "rufus" && !avatarp(TP)) {
    write("You try and read the sign, but the characters appear to be magically encoded.");
	return 1;
  }
  write("You can see how to operate this laboratory by typing <help laboratory>.");
  return 1;
}  

int snap(string str) {
  object ob;
  object other;
  
  if(str != "twice") return 0;
  if( (string)TP->query_name() != "rufus" && 
      (string)TP->query_name() != "stefano" && !avatarp(TP) )
    return 0;
  other = find_object_or_load("/d/player_houses/rufus/library");
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
