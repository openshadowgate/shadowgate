//landing.c - Cottage landing for Stefano's house
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A plaing landing");
        set_short("A plain landing");
        set_long("A short stretch of hallway with plain white walls and a lavendar "+
           "carpet runs north-south at the top of the stairs, with windows at either "+
           "end. There are doors leading to the main bedroom to the west and the guest "+
           "room to the east."+
           "\n");
        set_smell("default","The scents of flowers and fresh cut grass drift in from the garden.");
        set_listen("default","You can hear the river passing by outside.");
        set_items(([
           "window" : "You can look out of the north or south windows", 
           "north window" : "Glancing out the north window, you see the dense jungles of Attaya.  Just "+
              "within sight is another sandy beach.",
           "south window" : "The stream passes by to the south of the cottage, and beyond "+
              "that you can make out a mountain range.",
        ]));
        set_exits(([
       "down" : SHOUSE"cottagemain",
       "east" : SHOUSE"guestroom",
       "west" : SHOUSE"bedroom"
   ]));
        set_door("guest door",SHOUSE"guestroom","east",0);
        set_door_description("guest door", "A solid oak door");
        set_door("bedroom door",SHOUSE"bedroom","west",0);
        set_door_description("bedroom door", "A solid oak door");
}