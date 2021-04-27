//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Cottage Path");
    set_long(
    	"%^BOLD%^%^GREEN%^"+
    	"A well groomed cobblestone path leads up to the modest cottage.%^BOLD%^%^YELLOW%^  "+
	"Daisies%^ %^GREEN%^line the path that lead away to the northwest.  You can travel "+
	"northwest to the cottage or south back towards the hot springs. \n"+
	"%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","You can smell flowers along with traces of smoke from a wood fire.");
    set_listen("default","Breezes occassionally carry the sound of nearby wildlife "+
    			"your direction.");
    set_items(([
      ({"cobblestones","stones","stone","cobblestones"}):"\n%^RESET%^The path is made up "+
      		"of these rounded and smooth stones.\n",
	({"daisy","daisies","flower","flowers"}):"\n%^BOLD%^%^WHITE%^White%^RESET%^ flowers "+
			"with %^BOLD%^%^YELLOW%^yellow%^RESET%^ centers spring up along "+
			"pathway.  At first glance they appear to be growing wild, but upon "+
			"closer examination you can tell they were planted here and have been "+
			"well taken care of.\n"
        ]));
    set_exits(([
	"northwest":LROOMS+"lea1",
	"southwest":LROOMS+"leap1"
    ]));
}