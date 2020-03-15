#include <std.h>
#include "../marsh.h"

inherit MINH;


// long desc is a little different

void create() 
{
    ::create();
    
    set_long(""+ ::query_long() + "\n%^BLUE%^A boggy lake lies to the east blocking "
        "any passage further in that direction. The lake is large and could be explored "
        "only by boat.%^RESET%^");

    add_item("lake","The lake is quite slimy and filled with reeds and weeds.");

    set_exits((["west": RPATH "m13",
                //"east": RPATH "lake1",
    ]));

    if(!present("sorrow_cleric")) { new(MON"harv.c")->move(TO); }
   
    set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor() 
{
    //if(!present("boat",TP)) 
    //{
        write("You can't go east! You don't have a boat!");
	    return 0;
    //}
    //return 1;
}

void reset() 
{
    ::reset();
    if(!present("sorrow_cleric")) { new(MON"harv.c")->move(TO); }
}
