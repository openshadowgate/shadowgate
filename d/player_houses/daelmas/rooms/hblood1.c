//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
  	::create();
  	set_name("Hallway of Blood");
  	set_short("hallway of blood");
  	set_long(
 		"%^RED%^"+
  		"A very faint light barely manages to illuminate the hallway. "+
  		"The light's source itself is not quickly apparent. Once your "+
  		"eyes adjust to the dimness, you notice just how gigantic the "+
  		"hallway is. The ceiling is so high it is not even visible, "+
  		"disappearing into the pitch black. Stretching for as far as "+
  		"the pale light allows you to see, the walls are lined with "+
  		"extensive copper and brass shelves. Upon the immense shelves "+
  		"rests %^WHITE%^skulls%^RED%^, many different "+
  		"%^WHITE%^skulls%^RED%^, ranging from tiny one's that look as "+
  		"if they were from pixies and quicklings, their tiny, empty "+
  		"eye sockets staring at you, to titanic %^WHITE%^skulls%^RED%^, "+
  		"from %^BLUE%^demons%^RED%^ and %^GREEN%^dragons%^RED%^, with "+
  		"deformed horns twisting towards the blackness of the ceiling. "+
  		"A steady rain of blood comes softly down from the darkness, "+
  		"disappearing suddenly as it makes contact with anything.\n"
  	);
  	set_terrain(STONE_BUILDING);
  	set_travel(PAVED_ROAD);
  	set_property("indoors",1);
  	set_property("light",1);
  	set_smell("default","The smell of dust hangs thick in the air.");
  	set_listen("default","A slowly dripping liquid echoes through the room.");
  	set_items(([
  		"ceiling" : "The ceiling is not visible, just a patch of darkness.\n",
  		({"shelves","shelf"}) : "The shelves are old. They are made of a "+
  			"mix of copper and brass and look rusted in some places. "+
  			"The shelves themselves are so large it is difficult to "+
  			"see the back. Slender, tarnished silver poles hold the "+
  			"shelves up and each shelf is just a flat slab of metal.\n",
		({"skull","skulls"}) : "There are thousands of skulls from numerous "+
			"creatures, some easily recognizable, others so foreign "+
			"and exotic it is impossible to tell what they are.\n",
		"blood" : "Blood drips down from the blackness, where the "+
			"ceiling would be. It seems to be normal blood, from "+
			"a human or demi-human. Strangely it disappears whenever "+
			"it touches it something.\n"
	]));

  	set_exits(([
		"north" : DROOMS+"hblood0",
		"south" : DROOMS+"hblood2"
	]));
}