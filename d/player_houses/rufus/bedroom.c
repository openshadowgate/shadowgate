// Bedroom
// Thorn@ShadowGate
// 001130
// Rufus' Player House
// bedroom.c

#include <std.h>

inherit ROOM;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Bedroom%^RESET%^");
  set_long("%^RESET%^%^CYAN%^The room you are "+
  "in is fairly austere with minimal furniture "+ 
  "and embellishment. Up against the wall facing "+ 
  "the door is a %^ORANGE%^small bed%^CYAN%^, "+ 
  "obviously made for a small person. To the right "+ 
  "of the bed is a dresser. A lamp sits on the "+ 
  "dresser along with a %^ORANGE%^picture frame "+ 
  "%^CYAN%^with a small painting. To the left "+ 
  "of the bed is a small %^ORANGE%^armoire "+ 
  "%^CYAN%^which is plain and functional, but "+ 
  "obviously well made.\n\nAbove the bed, you see "+ 
  "a carving into the rock itself which depicts "+ 
  "the sign of a %^BOLD%^%^WHITE%^s%^RESET%^k%^BOLD%^elet%^RESET%^a%^BOLD%^l "+ 
  "ha%^RESET%^n%^BOLD%^d %^RESET%^%^CYAN%^and arm "+ 
  "holding a set of "+ 
  "%^BOLD%^%^WHITE%^s%^RESET%^c%^BOLD%^al%^RESET%^e%^BOLD%^s%^RESET%^%^CYAN%^. "+ 
  "Other than that, the walls are bare, giving the room a cold feeling.\n\nThere "+ 
  "is an open portal to the north leading into the library.%^WHITE%^");
  set_smell("default", "The smell of parchment and leather pervades the room.");
  set_listen("default", "There is the sound of a fire crackling.");
  set_items(([
    "painting" : "It is a rendering of a young female gnome, it looks to be quite old.",
    "picture frame" : "There is a painting in the frame you can look at.",
    "frame" : "There is a painting in the frame you can look at.",
    "carving" : "The carving reminds you of something you may have seen in a temple or graveyard.",
    "lamp" : "The small lamp gives off a constant magical light and seems to require no oil to burn.",
  ]));
  set_exits(([
      "north" : "/d/player_houses/rufus/library",
  ]));
}

void reset(){
  ::reset();  
}


