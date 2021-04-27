//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;

void create(){
	::create();
	set_name("bath");
   set_short("bath");
   set_long(
   	"%^BOLD%^%^BLUE%^"+
   	"This room is quite elegant.  "+
   	"There is a bath tub nestled into the far left corner of "+
   	"the room. It seems that the pipes have been magically "+
   	"enchanted to bring up heated water from somewhere else to "+
   	"fill the tub with.  There is a little sink on the right side "+
   	"of the room with a spigot pump to get cold water from a well "+
   	"for washing your face and hands with. Towels are stacked in "+
   	"one corner of the room for the occupant and there are "+
   	"several wash clothes.  Shelves line the back wall and they "+
   	"are full of fine soaps and oils of all sorts. A thick "+
   	"absorbant rug has been placed here, stretching from one "+
   	"end of the room to the other. The rest of the floor is "+
   	"covered in some sort of tiling. In the far back right "+
   	"corner of the room is a little latrine. It also appears "+
   	"to be the more expensive magical kind, whisking away "+
   	"everything to a different spot for dumping, a small but "+
   	"permanent gate spell. In the center of the room hangs a "+
   	"little stone that has been enchanted with a permanent "+
   	"light spell to bring light to the room."+
   	"%^RESET%^"
   );
  	set_terrain(STONE_BUILDING);  
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_smell("default","The room smells of perfumes, soaps, and oils.");
	set_listen("default","A faint and distant dripping sound can be heard.");
	set_items(([
   	"floor" : "The floor is covered in some sort of tile and a large "+
			"absorbant rug is laid over it, reaching from the door to the back"+
        	" of the wall by the tub.\n",
      "rug" : "This absorbant rug is rather narrow and is laid"+
        	" down to cover the floor between the sink and the bath tub. It"+
        	" will keep your feet from getting cold on the tile while you dry"+
        	" off.\n",
    	({"tile","tiles"}) : "Tile covers the bathroom floor, probably to"+
        	" keep the water off of the wood. It is mostly white with a few"+
        	" blue stripes and checkers on each large tile.\n",
      ({"shelf","shelves"}) : "Wooden shelves line the back wall of the"+
        	" room and they are filled with fine soaps and oils for washing.\n",
      "sink" : "The little porcelain sink is tucked into the right hand"+
        	" corner of the room. It has a spigot type pump and you can use"+
        	" it to fill the sink with water for washing. There is a handle"+
        	" release to allow the sink to drain out through the pipes.\n",
    	({"bathtub","bath tub","tub"}) : "The tub is placed in the back"+
      	" left corner of the room, and takes up about half the wall. It"+
        	" is very large and luxurious, with a pillow on the top for you"+
        	" to rest your head against. It appears to"+
        	" be kept quite clean. The water drains out at the bottom if you"+
        	" remove the plug. There is also a handle for cold water and "+
        	"hot water so that you can mix the two, it probably"+
        	" taps into a well somewhere nearby.\n",
    	"pillow" : "There is a little pillow at the back of the"+
        	" bath tub for you to lean your head back against as you soak.\n",
    	({"soap","soaps"}) : "There are many fine soaps on the back shelves.\n",
      ({"oil","oils"}) : "Bottles of expensive looking oils line the"+
        	" back shelves. You can add them to your bath tub so that you"+
        	" smell good.\n",
    	"latrine" : "This is one of the new magical latrines with a small"+
        	" permanent gate spell, taking the waste to a designated area"+
        	" for elimination. It is quite convenient.\n",
      ({"handle","handles"}) : "There are two handles at the bath tub"+
        	" that you can turn. One is red for hot water and the other "+
        	"blue for cold water.\n",
    	({"stone","light","enchanted stone"}) : "A stone that has been"+
        	" enchanted with a continuous light spell hangs down from the"+
        	" ceiling. It is perfectly round and glows white.\n",
 	]));
   set_exits(([
		"north" : SROOMS+"living_area"
  	]));
   set_door("bathroom door",SROOMS+"living_area","north");
   set_door_description("bathroom door","This is a simple wooden door with a lock.\n");
  	set_string("bathroom door","open","The door opens quietly into the living area.\n");
}