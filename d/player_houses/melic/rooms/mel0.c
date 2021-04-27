//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_short("Path to the Castle");
    set_long(
    "%^ORANGE%^"+
    "You are walking on the path that leads to a castle to the north.  Behind the castle "+
    "the dagger mountains loom protectively. Very little %^GREEN%^vegetation%^ORANGE%^ "+
    "grows in this area and the path is in reality a good sized road the has seen little "+
    "traffic of late.\n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","You smell clean fresh mountain air.");
    set_listen("default","You hear the wind blowing through the mountain passes.");
    set_items(([
        "road":"Broken stone and dirt make up the surface of this road.",
        "vegetation":"The vegetation seems to have been cleared away from the road, but is "+
        		"a little thicker and less cut back to the west.  Something is different "+
			"about this area of vegetation.",
        "castle":"The castle looks as strong and inpassable as the mountain chain it is "+
        		"set in.",
	  "hole":"The hole looks %^BOLD%^%^BLACK%^dark%^RESET%^ and the edges seem to be "+
	  		"crumbling and unsafe."
	   ]));
    set_exits(([
	"north":MROOMS+"mel1",
	"south":"/d/dagger/elements/path/path1"
    ]));
    set_climb_exits((["descend":({ MROOMS+"melpit",20,6,100})]));
    set_fall_desc("%^BOLD%^%^RED%^You fall at least 60 feet and land on the hard floor of "+
    			"a pit!\n Sharp branches and debris poke into your back.  You are winded "+
    			"and pain racks your body!%^RESET%^\n");
}
void init() {
  ::init();
  add_action("search","search");
}
int search(string str) {
    if(!str) {
        tell_object(TP,"Search what?");
        return 1;
    }
  if(str == "vegetation"){
     tell_object(TP,"You move closer to get a better look at the vegetation.\n"+
     			"As you move forward you find that the difference was a hole in the "+
     			"ground and the edge is now crumbling from beneath your feet!\n"+
			"You find yourself tumbling head over heels till you come to a sudden "+
			"stop at the bottom of a dark pit. \n"+
			"Your entire being is wracked with the pain of the fall!\n");
     tell_room(ETP,""+TPQCN+" moves into the vegetation to have a better look and "+
     			"disappears with a '%^BOLD%^%^YELLOW%^YELP%^RESET%^!'.\n",TP);
     TP->move(MROOMS+ "melpit");
     TP->do_damage("torso",(random(31)+5));
     
     return 1;
     }
}
