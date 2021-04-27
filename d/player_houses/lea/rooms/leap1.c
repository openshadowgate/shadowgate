//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Groomed Path");
    set_long(
    	"%^BOLD%^%^GREEN%^"+
    	"A well groomed cobblestone path leads away to the northeast and the southeast. \n"+
	"%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air has lessened in humidity and flowers accompanied by wood "+
    				"smoke tickles your nose.");
    set_listen("default","Sounds of birds and breezes slowly overcome the distant sounds "+
    				"of the hot springs.");
    set_items(([
        ({"cobblestones","stones","stone","cobblestones"}):"\n%^RESET%^The path is made "+
        		"up of these rounded and smooth stones.\n"
        ]));
    set_exits(([
	"northeast":LROOMS+"leap0",
	"southeast":LROOMS+"leap2"
    ]));
}