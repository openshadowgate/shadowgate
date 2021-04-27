//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Castle Meeting Room");
    set_long(
    "%^GREEN%^"+
    "This room is rectangular, about 15 yards from the west wall to the east, and about "+
    "half that between the door and the fireplace on the north wall. A large "+
    "%^ORANGE%^oak%^GREEN%^ table dominates the center of the room.  Several chairs are "+
    "set around the table and the chair facing the door, at the middle of the table, is "+
    "somewhat more decorated than the others.  The other chairs vary in size, from dwarf "+
    "sized to a few large ones that could support even a large firbolg. Behind the "+
    "central chair, a large fireplace is set in the wall. A %^BOLD%^%^ORANGE%^fire "+
    "%^RED%^burns%^RESET%^%^GREEN%^ continuously within it, giving the room added warmth.  "+
    "Bookshelves line the walls next to the door, and maps are hung on the other walls "+
    "between the high windows. The ceiling is about 20 feet high.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You notice a faint smell of %^BOLD%^%^BLACK%^smoke "+
			"%^RESET%^%^ORANGE%^ from the fireplace.");
    set_listen("default","You can hear the roar of the %^BOLD%^%^RED%^fire.%^RESET%^");
    set_items(([
    	"fireplace":"The fireplace has several large logs %^RED%^burning%^RESET%^ in it.  "+
    			"On the floor in front of the fireplace is a huge bear-fur rug.  Leaning "+
			"against the wall is additional wood for the fire and a firepoker and "+
			"tongs",
	({"bookshelves","bookshelf"}):"Row upon row of books are shelved dealing with "+
			"various styles of combat, battle tactics, the best way to slay specific "+
			"monsters, healing and clerical magic.",
	({"map","maps"}):"Maps hanging from the walls covers the surrounding areas and some "+
			"of the closer islands such as Aramanth, Attaya, Graez, Tonerra, "+
			"Laerad, and Deku."
	]));
	
    set_door("door",MROOMS+"mel7","south","mithril key");
    set_door_description("door","A normal wooden door.");
    set_string("door","open","The door swings open allowing you back into the hallway.\n");
    
    set_exits(([
	"south" :MROOMS+"mel7"
    ]));
}
