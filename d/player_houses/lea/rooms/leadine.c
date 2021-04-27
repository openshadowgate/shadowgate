//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Dining Room");
    set_long(
    	"%^BOLD%^%^CYAN%^"+
    	"This is a formal dining room and could seat several guests.  There is a "+
	"%^RESET%^%^ORANGE%^mahogany %^BOLD%^%^CYAN%^table that runs the center of the "+
	"room.  An iron chandelier hangs from the ceiling above the table.  Along the back "+
	"wall is a cabinet which holds dishes and other finery for serving guests in this "+
	"room.  The hardwood floor has been polished to a bright shine.  The door in the "+
	"north wall leads into the kitchen.\n"+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You can smell the beeswax that was used to polish the floor "+
    	"and the table.");
    set_listen("default","Occassional noises can be heard from behind the north door.");
    set_items(([
        "table" : "\n%^RESET%^This is a brightly polished %^ORANGE%^mahogany "+
        	"%^RESET%^table with chairs spaced evenly around it that could easily seat "+
        	"ten people at one time.\n",
        "cabinet" : "\n%^RESET%^The cabinet is filled with fine dishes, silver eating "+
		"utensils, and silk napkins.  There is more than enough of each item to set "+
		"places at the table for at leat ten people at a time.",
        "chandelier" : "This is an iron chandelier that can be filled with many "+
        	"candles.  Enough candles can be placed on the chandelier to brightly "+
        	"illuminate the entire room."
        ]));

    set_door("door",LROOMS+"leakitch","north","brass key");
    set_locked("door",0,"lock");
     (LROOMS+"leakitch")->set_open("door",0);
     (LROOMS+"leakitch")->set_locked("door",0,"lock");
    set_string("door","open","The door opens to the kitchen.\n");

    set_exits(([
	"east" : LROOMS+"leahall",
	"north" : LROOMS+"leakitch"
    ]));
}