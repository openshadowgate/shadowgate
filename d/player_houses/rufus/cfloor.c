// A canyon floor
// Thorn@ShadowGate
// 010110
// Rufus' Player House
// cfloor.c

#include <std.h>

inherit ROOM;

void create() {
  ::create();
   set_terrain(BARREN);
   set_travel(GAME_TRACK);
  set_property("light", 2);
  set_short("%^BOLD%^A canyon floor%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This is the floor of a narrow canyon surrounded "+ 
  "by high mountains. Sheer rock walls rise very high on three sides of you. "+ 
  "There appears to be only one way out to the world: to the north, up a narrow "+ 
  "path into the mountains above.\n\nTo the south, you see what appears to be "+ 
  "an %^WHITE%^ornately columned facade %^ORANGE%^that has been carved out of "+ 
  "the cliffside itself. It is completely out of place for this whole area and "+ 
  "reminds you very distinctly of a %^BOLD%^%^BLACK%^tomb %^RESET%^%^ORANGE%^or "+ 
  "%^BOLD%^%^BLACK%^funerary temple%^RESET%^%^ORANGE%^. "+ 
  "%^BOLD%^%^WHITE%^Sk%^RESET%^u%^BOLD%^lls %^RESET%^%^ORANGE%^and "+ 
  "%^BOLD%^%^WHITE%^bon%^RESET%^e%^BOLD%^s %^RESET%^%^ORANGE%^make up the carved "+ 
  "decorations. At the top of the facade, a newer-looking symbol of "+ 
  "a %^BOLD%^%^WHITE%^b%^RESET%^o%^BOLD%^ny a%^RESET%^r%^BOLD%^m "+ 
  "%^RESET%^%^ORANGE%^holding %^BOLD%^scales %^RESET%^%^ORANGE%^is carved in "+ 
  "a place where an %^BOLD%^ancient symbol %^RESET%^%^ORANGE%^has been "+ 
  "obliterated.\n%^WHITE%^");
  set_smell("default", "The smell of stale air and dust.");
  set_listen("default", "You hear the wind whisper and howl through the canyon.");
  set_items(([
    "facade" : "Clearly an ancient work, the facade looks vaguely evil and certainly "
               "foreboding.  Columns are hewn out of the rock in a marvel of the "
               "stone carver's art."
  ]));
  set_exits(([
    "north" : "/d/shadow/room/mountain/road7",
      "south" : "/d/player_houses/rufus/entry",
  ]));
  set_pre_exit_functions( ({ "south" }), ({ "south" }) );
}

int south() {
	write("%^CYAN%^You feel a momentary, but distinct, chill as you make your "
		"way into the wall of the cliff though the facade.");
	return 1;
}
void reset(){
  ::reset();  
}


