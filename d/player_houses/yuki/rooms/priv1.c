#include <std.h>
#include "../yuki.h"

inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_property("indoors",1);
    set_property("light",2);
    set_name("spacious room");
    set_short("%^RESET%^%^ORANGE%^spacious room%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This large room is set into two levels. The "+
	"door on the western wall sits on the lower portion. Instead of the %^RESET%^"+
	"cold stone%^ORANGE%^ of the rest of the fortress, the floor here has been "+
	"set with %^RED%^hardwood%^ORANGE%^, offering more comfort. A %^BLUE%^large "+
	"couch%^ORANGE%^ faces a %^BLACK%^%^BOLD%^fireplace%^RESET%^%^ORANGE%^ set "+
	"into the north wall, and a %^CYAN%^small workspace%^ORANGE%^ has been "+
	"arranged against the south wall beside a large window. Three steps "+
	"seperate the lower from the higher level. On the higher level is "+
	"a %^RED%^large bed%^ORANGE%^.\n%^RESET%^");
    set_smell("default","%^RESET%^%^RED%^You smell clean linen%^RESET%^");
    set_listen("default","%^RED%^%^ORANGE%^The sounds of the fortress are muted here%^RESET%^");
    set_exits(([
      "west" : ROOMS"h3",
    ]));

    set_items
    (([
        ({"ground", "hardwood", "floor"}) : "%^RESET%^%^ORANGE%^The floor here "+
		"is hardwood that is warm to the touch.%^RESET%^",
		({"easel", "paints", "brushes"}) : "%^RESET%^%^ORANGE%^A large wooden easel "+
		"sits near the window. Several %^RESET%^blank canvases%^ORANGE%^ sit ready "+
		"and piles of %^YELLOW%^brushes%^RESET%^%^ORANGE%^ and %^RED%^"+
		"paints%^RESET%^%^ORANGE%^ sit organized nearby.%^RESET%^", 
		({"table", "roses"}) : "%^RESET%^%^ORANGE%^beside the easel sits a small table "+
		"with a vase of %^RED%^red roses%^ORANGE%^.%^RESET%^",
        ({"fireplace"}) : "%^BLACK%^%^BOLD%^A large fireplace sits against the north wall.%^RESET%^",
		({"workspace", "area"}) : "%^RESET%^%^ORANGE%^Beside the south window is a large "+
		"workspace. an %^BOLD%^easel%^RESET%^%^ORANGE%^, %^RED%^paints%^ORANGE%^, "+
		"and a %^YELLOW%^table%^RESET%^%^ORANGE%^ with %^RED%^roses%^ORANGE%^. A very "+
		"organized space. %^RESET%^",
		({"bed"}) : "%^RESET%^%^RED%^A bed sits on the raised portion of the room.%^RESET%^",
		
    ]));
	    set_door("wooden door",ROOMS"h3","west","yuki_key");
        set_locked("wooden door",1);
        set_door_description("wooden door","%^RESET%^%^ORANGE%^This heavy oak door looks very sturdy.");
        set_string("wooden door", "open", "The heavy door opens quietly.");
        set_string("wooden door", "close", "The heavy door closes without a sound.");
		set_property("no_phase",1);

}
