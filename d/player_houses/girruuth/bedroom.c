#include <std.h>
#define GHOUSE "/d/player_houses/girruuth/"
inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("A bedroom");
  set_short("A bedroom");
  set_long("This is a simple bedroom of fairly small size.  In the southeastern corner a %^BOLD%^%^BLUE%^king sized feather bed %^RESET%^dominates the room.  It sits on a sturdy %^ORANGE%^wooden frame %^RESET%^and has several %^BOLD%^fluffy feather pillows %^RESET%^upon it.  There is a dresser in the far north corner.  There is a window on the southern wall with %^GREEN%^heavy drapes%^RESET%^.  The floor is made of %^ORANGE%^thick wooden planks%^RESET%^."
  );
  set_smell("default", "There is a slight musky scent from somewhere.");
  set_listen("default", "Sounds from the city and shop are fairly well muffled.");
  set_exits(([
	"west" : GHOUSE+"shop",
  ]));
  set_door("bedroom door", GHOUSE+"shop", "west");
  set_items( ([
	"bed" : "The bed looks quite comfortable and would be quite spacious for two humans.",
	"pillows" : "The pillows look quite comfortable.  There are four of them in total.",
	"dresser" : "The dresser just contains clothes of various sorts.  There are some
of good quality and some lower quality or well worn.",
	"drapes" : "%^GREEN%^These are heavy drapes which can be drawn shut or opened.",
	"window" : "The window overlooks the city street outside.  The window does not allow
good visibility in or out as it appears re-enforced.  There are magic runes around the frame itself.",
	({"floor", "planks" }) : "%^ORANGE%^The floor is quite solid as the wood is made from treated oak."
  ]) );
}

void init() {
   ::init();
   add_action("pull_drapes", "pull");
   add_action("sit_bed", "sit");
}

int sit_bed(string str) {
   if(!str) {
     tell_object(TP,"It looks like the bed or floor are the choices.");
     tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     return 1;
   }
   if(str == "bed" || str == "on bed") {
      tell_object(TP,"You sit on the edge of the bed and oohhh, is it comfy.");
      tell_room(ETP,TPQCN+" sits on the edge of the bed and looks impressed with how comfy it is.",TP);
      return 1;
   }
   tell_object(TP,"You sit down on the hard wooden floor.");
   tell_room(ETP,TPQCN+" sits down on the hard wooden floor.",TP);
   return 1;
}

int pull_drapes(string str) {
   if(!str) {
     tell_object(TP,"What were you trying to pull?");
     return 1;
   }
   if(str == "drapes") {
      tell_object(TP,"Did you want to pull the drapes open or closed?");
      tell_room(ETP,TPQCN+" reaches for the drapes and pauses.",TP);
      return 1;
   }
   if(str == "drapes closed") {
      tell_object(TP,"You pull the heavy drapes closed, blocking out light and further muffling the sounds from outside.");
      tell_room(ETP,TPQCN+" pulls the heavy drapes closed, blocking out light and further muffling the sounds from outside.",TP);
      return 1;
   }
   if(str == "drapes open") {
      tell_object(TP,"You pull the heavy drapes open, which makes the room seem a bit more spacious.");
      tell_room(ETP,TPQCN+" pulls the heavy drapes open, which makes the room seem a bit more spacious.",TP);
      return 1;
   }
   return 0;
}
