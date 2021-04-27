//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Groomed Path");
    set_long(
    	"%^BOLD%^%^GREEN%^"+
    	"A well groomed cobblestone path leads away to the northwest. \n"+
	"%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air is heavy with humidity from the hot springs.");
    set_listen("default","In the distance you can hear the slight murmuring and gurgling "+
				"of the hot springs.");
    set_items(([
        ({"cobblestones","stones","stone","cobblestones"}):"\n%^RESET%^The path is made "+
        		"up of these rounded and smooth stones.\n"
        ]));
    set_exits(([
	"northwest":LROOMS+"leap1",
	"southwest":"theworld"
    ]));
}