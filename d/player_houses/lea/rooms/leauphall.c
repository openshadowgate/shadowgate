//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Second Floor Hallway");
    set_long(
    	"%^ORANGE%^"+
    	"The hallway is sparsely decorated.  There are doors in the north, south "+
    	"east and west.  There is a stairs leading down to the lower level as well.\n"+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The hallway smells clean and fresh with a trace of wood polish.");
    set_listen("default","The cottage is quiet.");

    set_door("south door",LROOMS+"leabed1","south","brass key");
    set_locked("south door",0,"lock");
    set_open("south door",1);
     	(LROOMS+"leabed1")->set_open("door",1);
    	(LROOMS+"leabed1")->set_locked("door",0,"lock");
    set_string("south door","open","The door opens to a bedroom.\n");
    set_door_description("south door","This door looks sturdy and is made of oak.  It has "+
    				"a brass door knob and a keyhole");


    set_door("east door",LROOMS+"leabed2","east","brass key");
    set_locked("east door",0,"lock");
    set_open("east door",1);
    	(LROOMS+"leabed2")->set_open("door",1);
     	(LROOMS+"leabed2")->set_locked("door",0,"lock");
    set_string("east door","open","The door opens to the master bedroom.\n");
    set_door_description("east door","This door looks sturdy and is made of oak.  It has "+
    				"a brass door knob and a keyhole");

    set_door("west door",LROOMS+"leastudy","west","brass key");
    set_locked("west door",0,"lock");
    set_open("west door",1);
     	(LROOMS+"leastudy")->set_open("door",1);
     	(LROOMS+"leastudy")->set_locked("door",0,"lock");
    set_string("west door","open","The door opens to a study.\n");
    set_door_description("west door","This door looks sturdy and is made of oak.  It has "+
    				"a brass door knob and a keyhole");

    set_door("north door",LROOMS+"leabath","north","brass key");
    set_locked("north door",0,"lock");
    set_open("north door",1);
     	(LROOMS+"leabath")->set_open(" door",1);
     	(LROOMS+"leabath")->set_locked("door",0,"lock");
    set_string("north door","open","The door opens to bathing room.\n");
    set_door_description("north door","This door looks sturdy and is made of oak.  It has "+
    				"a brass door knob, hinges, and keyhole");

    set_exits(([
	"stairs" : LROOMS+"leahall",
	"south" : LROOMS+"leabed1",
	"east" : LROOMS+"leabed2",
	"west" : LROOMS+"leastudy",
	"north" : LROOMS+"leabath"
    ]));
}