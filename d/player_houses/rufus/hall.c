// A Hall
// Thorn@ShadowGate
// 001205
// Rufus' Player House
// hall.c

#include <std.h>

inherit VAULT;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no sticks", 1);
  set_short("%^BOLD%^Hall%^RESET%^");
  set_long("%^YELLOW%^You are in a brilliantly %^RESET%^%^ORANGE%^illuminated "+
  "%^BOLD%^room with a very high vaulted ceiling cut out of solid stone. "+ 
  "From the light you see streaming down from a %^WHITE%^i%^RESET%^r%^BOLD%^on "+ 
  "c%^RESET%^ha%^BOLD%^ndel%^BLACK%^i%^RESET%^e%^BOLD%^r%^ORANGE%^, you "+ 
  "can make out that the room is decorated sparsely with what appears to "+ 
  "be strange and %^MAGENTA%^wonderful machines %^ORANGE%^of some form. "+ 
  "In the center, a large %^RESET%^%^ORANGE%^round table %^BOLD%^sits with "+ 
  "chairs of all sizes. To the south is a %^RESET%^%^ORANGE%^great brass "+ 
  "door%^BOLD%^, and to the north is a even heavier %^RESET%^iron door "+ 
  "%^YELLOW%^which hangs on very large iron hinges. Although this room "+ 
  "is made for a giant, there is a tall, narrow and well -used chair that "+ 
  "actually has a few steps built into it. From the elaborate carved crest "+ 
  "of the %^WHITE%^b%^RESET%^o%^BOLD%^ne ha%^RESET%^n%^BOLD%^d %^ORANGE%^and "+ 
  "%^WHITE%^s%^RESET%^c%^BOLD%^al%^RESET%^e%^BOLD%^s %^ORANGE%^in it, you "+ 
  "gather that it belongs to the master of this place.\n\nTo the east, you "+ 
  "see an open archway that leads into a %^BLACK%^dark space %^ORANGE%^that "+ 
  "is lit by more conventional torchlight.\n %^RESET%^");
  set_smell("default", "The smell of parchment and leather pervades the room.");
  set_listen("default", "There is the sound of a fire crackling.");
  set_items(([
    "table" : "It has been made large enough for a giant or two "
	          "to sit at, and there are chairs of all sizes in the room.",
    "machines" : "You have no idea what kind of contraptions that these "
	             "things might be, but you have the sense that they were "
			     "crafted by an experienced gnomish mechanic.",
    "chandelier" : "This is a simple circle of iron that supports a number "
	               "of bright magical light sources.  Its hangs from the "
				   "top of the very high ceiling by an iron chain."
  ]));
  set_exits(([
      "north" : "/d/player_houses/rufus/entry",
      "south" : "/d/player_houses/rufus/library",
      "east" : "/d/player_houses/rufus/chapel",
  ]));
  set_door("brass door","/d/player_houses/rufus/library","south","rufus house key");
  set_door("iron door","/d/player_houses/rufus/entry","north");
  set_open("brass door",1);
  set_open("iron door",0);
  set_locked("iron door",1);
  "/d/player_houses/rufus/entry"->set_open("iron door",0);
  "/d/player_houses/rufus/library"->set_open("brass door",1);
  
}

void reset(){
  ::reset();  
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
  other = find_object_or_load("/d/player_houses/rufus/entry");
  if(!query_locked("iron door")) {
    tell_room(TO,
      TP->query_cap_name()+" snaps "+TP->query_possessive()+
	  " fingers twice and you hear a bolt crash home!",
      ({ TP }));
    tell_room(other,
      "You hear a bolt crash home on the iron door!",
      ({ TP }));
    write("You snap your fingers twice and the iron door locks itself with a crash!");
    TO->set_open("iron door",0);
    TO->set_locked("iron door",1);
    other->set_locked("iron door",1,"lock");
    other->set_locked("iron door",1,"sigil lock");
    other->set_locked("iron door",1,"vault lock");
    other->set_open("iron door",0);
	return 1;
  } 
  tell_room(TO,
    TP->query_cap_name()+" snaps "+TP->query_possessive()+
	" fingers twice and you hear a bolt creak as the iron door unlocks itself!",
    ({ TP }));
    tell_room(other,
      "You hear a mechanism creak as the iron door unlocks!",
      ({ TP }));
  write("You snap your fingers twice and the iron door unlocks itself!");
  TO->set_locked("iron door",0);
    other->set_locked("iron door",0,"lock");
    other->set_locked("iron door",0,"sigil lock");
    other->set_locked("iron door",0,"vault lock");
  return 1;
}
