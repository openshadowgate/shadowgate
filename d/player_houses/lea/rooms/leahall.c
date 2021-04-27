//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Hallway");
    set_long(
    	"%^ORANGE%^"+
    	"You step into the main entrance of this home.  This sparsely decorated room leads "+
    	"off to a sitting room to the east, a dining room to the west, and stairs leading "+
	"upward.  There are sconces with candles on the walls to light the room.  In the "+
	"corner of the room is a coat tree.  There is a painting that hangs on the wall "+
	"here.  A long table is along one wall."+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","A flowery scent greets you as you walk in.");
    set_listen("default","The cottage is quiet.");
    set_items(([
        "coat tree":"Made of wood this device is used to hang outer garment on."
        ]));

    set_door("door",LROOMS+"lea1","south","brass key");
    set_string("door","open","The door swings open to the outdoors, a cobblestone path "+
			"leads away.\n");
    set_door_description("door","This is a heavy oak door set into a heavy oak frame.  "+
    		"the door looks like it could take quite a beating before it would come "+
    		"down.\n");

    set_exits(([
	"stairs" : LROOMS+"leauphall",
	"south" : LROOMS+"lea1",
	"east" : LROOMS+"leasit",
	"west" : LROOMS+"leadine"
    ]));
}