
#include <std.h>
#define KHOUSE "/d/player_houses/kiervalan/"
inherit VAULT;

int searched;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
   set_terrain(LIGHT_FOREST);
  set_travel(DIRT_ROAD);
  set_property("smithy",1); 
  set_name("a clearing in the ancient forest");
  set_short("a clearing in the ancient forest");
  set_long("%^BLACK%^%^BOLD%^You are standing, strangely, in the middle of a %^GREEN%^clearing%^BLACK%^%^BOLD%^ "+
  "in an ancient forest. Whether illusion or teleportation the effect is eerie though as just behind you a %^RESET%^freestanding "+
  "arch%^BLACK%^%^BOLD%^ that leads back to the shop stands. The %^RESET%^%^ORANGE%^ancient trees%^BLACK%^%^BOLD%^ "+
  "around you show that this is not a %^GREEN%^clearing%^BLACK%^%^BOLD%^ anywhere near Shadow as the trees must be "+
  "thousands of years old. A %^RESET%^%^BOLD%^thick fog%^BLACK%^%^BOLD%^ lingers between the %^RESET%^%^ORANGE%^"+
  "trunks%^BLACK%^%^BOLD%^ and every once and awhile you realize that there are several %^RESET%^sleek wolves%^BLACK%^%^BOLD%^ "+
  "prowling just out of reach. In the center of the clearing stands a %^RESET%^forge%^BLACK%^%^BOLD%^ built from %^RESET%^%^BOLD%^"+
  "massive rough hewn stones%^BLACK%^%^BOLD%^. Like everything about the clearing, its amazing that the stones are even here, "+
  "that there would be a source of flame out in the middle of nowhere, or how this place could survive in the isolation of "+
  "such a place. There is also a bench you can sit in, safe from the searing heat of the forge, but close enough to glow to "+
  "make you feel safe.%^RESET%^\n");
  set_smell("default", "%^GREEN%^you smell ancient trees.%^RESET%^");
  set_listen("default", "%^BLACK%^%^BOLD%^You hear thunder in the distance.%^RESET%^");
  set_exits(([
	"archway" : KHOUSE+"shop",
  ]));
  set_door("door", KHOUSE+"shop", "archway");
  set_open("door",0);


  set_items( ([
	({"forge", "bench"}): "%^RESET%^%^BOLD%^The forge is made of rough hewn stones that look completely out of place in the "+
	"middle of a forest, but provide an excellent place to make equipment. A deep powerful fire burns in the forge, though "+
	"likewise the source is unknown. A ways away from the forge, at a comfortable distance, is a bench where you could sit and watch.%^RESET%^",
	({"wolves", "mist"}): "%^RESET%^%^BOLD%^In the mist that trails along the trunks of the trees a pack of wolves lurk, running too and fro.%^RESET%^",
	({"trees", "ancient trees"}): "%^RESET%^%^ORANGE%^The ancient trees are huge, easily as big as a wagon across. They must be a thousand years old.%^RESET%^",

  ]) );
}

  query_weather() { return "%^BLACK%^%^BOLD%^\nA storm rolls overhead, but there is no "+
  "rain, just %^YELLOW%^lightning%^BLACK%^%^BOLD%^ and %^RESET%^thunder%^BLACK%^%^BOLD%^."; }

void reset() {
   ::reset();
   if(!present("iron anvil")){
   }
   switch(random(10)) {
	case 0..3 : 	break;
	case 4:  tell_room(TO, "%^YELLOW%^Distant lightning illuminates the clearing for a heartbeat%^RESET%^.");
			break;
	case 5:  tell_room(TO, "%^RED%^The fire flares up, popping and crackling as it illuminates the clearing.%^RESET%^");
			break;
	case 6:  tell_room(TO, "%^RESET%^%^BOLD%^%^You see a handfull of wolves prowling just out of reach in the mist.%^RESET%^");
			break;
	case 7:  tell_room(TO, "%^CYAN%^There, in the distance, you see a young girl walking between the trees.%^RESET%^");
			break;
	case 8:  tell_room(TO, "%^ORANGE%^The trees creak in the wind.%^RESET%^");
			break;
	case 9:  tell_room(TO, "%^BOLD%^%^BLACK%^Distant thunder echos.%^RESET%^");
			break;
   }
}
