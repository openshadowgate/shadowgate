#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" The road continues to the north and to the south of you here. "
	"Away in the distance you notice a large black structure."
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel nervous "
	"about being here."
    );
    set_smell("default",
        "The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"structure":"The structure appears to be a tower of some kind.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/city38",
	"south":"/d/dagger/drow/rooms/city40"
    ]));
}
