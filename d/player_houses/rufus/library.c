// Library
// Thorn@ShadowGate
// 001101
// Rufus' Player House
// library.c

#include <std.h>

inherit VAULT;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Library%^RESET%^");
  set_long("%^RESET%^%^MAGENTA%^You are in what looks to be a very cozy "+ 
  "library or study. %^BOLD%^Books %^RESET%^%^MAGENTA%^of all sorts seem "+ 
  "to be crammed into %^ORANGE%^bookcases %^MAGENTA%^that line most of the "+ 
  "available wall space. The rest of the space is taken up by %^CYAN%^rugs "+ 
  "%^MAGENTA%^that have been hung on the walls to add color and warmth. "+ 
  "Off to the side of the room appears to be a big %^BOLD%^%^BLACK%^cast "+ 
  "iron stove %^RESET%^%^MAGENTA%^of the sort that gnomes have developed "+ 
  "that contain %^BOLD%^%^RED%^fir%^RESET%^%^RED%^e%^BOLD%^s "+ 
  "%^RESET%^%^MAGENTA%^in enclosed spaces like this. A number of "+ 
  "lamps hang from the ceiling, providing ample, warm light for reading. "+ 
  "There are a few %^ORANGE%^leather armchairs %^MAGENTA%^both small and "+ 
  "normal-sized.\n\nThere is a small stairway that seem to allow access up "+ 
  "through a trap door. To the north, you see a large %^ORANGE%^brass "+ 
  "door%^MAGENTA%^, to the south, there is an opening that looks to lead "+ 
  "into private living quarters.\n%^WHITE%^");
  set_smell("default", "The smell of parchment and leather pervades the room.");
  set_listen("default", "There is the sound of a fire crackling.");
  set_items(([
    "armchairs" : "Large and small, they are very comfortable looking.",
    "stove" : "Squat and black, the iron stove has a little door in the front and a pipe that goes up into the ceiling.",
    "bookcases" : "They are crammed with books of all sorts, some mundane, some of common arcane lore.",
    "lamps" : "The lamps seem to give off a constant magical light.",
  ]));
  set_exits(([
      "north" : "/d/player_houses/rufus/hall",
      "south" : "/d/player_houses/rufus/bedroom",
      "up" : "/d/player_houses/rufus/labratory",
  ]));
  set_door("brass door","/d/player_houses/rufus/hall","north");
  set_door("trap door","/d/player_houses/rufus/labratory","up","rufus house key");
  set_open("brass door",1);
  set_open("trap door",0);
  set_locked("trap door",0);
  "/d/player_houses/rufus/labratory"->set_open("trap door",0);
  "/d/player_houses/rufus/hall"->set_open("brass door",1);
}


void init() {
  ::init();
  add_action("snap", "snap");
}

int snap(string str) {
  object ob;
  object other;
  
  if(str != "twice") return 0;
  if( (string)TP->query_name() != "rufus" && 
      (string)TP->query_name() != "stefano" && !avatarp(TP) )
    return 0;
  other = find_object_or_load("/d/player_houses/rufus/labratory");
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
