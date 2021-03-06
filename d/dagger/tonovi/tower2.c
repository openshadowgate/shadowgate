#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
    set_property("light", 2);
    set_short("A lookout station");
    set_long(
      "You have entered the base floor of a lookout post to watch the roads to Tonovi.  There is a ladder leading up to the second floor in the corner, but the door is closed and locked.  There is also a table, several chairs, and two bunkbeds."
    );

    set_smell("default", "There is the smell of unwashed socks here.");
    set_listen("default", "You hear the wind howl across the dorway.");

    set_items( ([
	"table" : "it's a large wooden table",
	"chairs" : "These are sturdy wooden chairs",
	({"bed", "beds"}) : "There are 4 beds here in a bunkbed configuration.",
	"ladder" : "There is a locked door closing off the way to the second floor.",
      ]) );

    set_exits( ([
        "north" : "/d/dagger/tonovi/2path4",
      ]) );

}
