//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
    set_short("Castle Hallway");
    set_long(
    "%^GREEN%^"+
    "The hallway is approximately 10 feet wide and twice as high.  The ceiling is a "+
    "long arch and is given extra support by pillars.  Armor and weapon racks line the "+
    "walls here, but most of the items are rather old and looks to have lost their "+
    "usefulness in battle.  When new, the items must have been great weapons of war.  "+
    "To the north the hallway continues.  Toward the south are large wooden doors leading "+
    "to the courtyard.  Torches are placed at regular intervals along the corridor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The smell of musty armor and weapons fill the air.");
    set_listen("default","You hear faint snoring sounds");
    set_items(([
    	({"armor","armors","weapon","weapons","rack","racks"}):"Gothic style full-plate "+
    		"armor, huge two-handed swords, warhammers, and various other armors and "+
    		"weapons line the walls."
	]));
	
    set_door("door",MROOMS+"mely","south","mithril key");
    set_door_description("door","This door leads into the castle yard.  It is "+
    		"approximately 10 feet tall and made of wood.");
    set_string("door","open","The door swings open to the castle yard.\n");
    
    set_exits(([
	"north" :MROOMS+"mel5",
	"south" :MROOMS+"mely"
    ]));
}
