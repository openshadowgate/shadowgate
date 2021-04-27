// BWANA Fortress

#include <std.h>
#include "../yuki.h"

inherit ROOM;

void init() {
  ::init();
  add_action("read", "read");
}

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("solemn room");
    set_property("light",2);
    set_short("%^BLACK%^%^BOLD%^sole%^RESET%^m%^BLACK%^%^BOLD%^n"+
"	ro%^RESET%^o%^BLACK%^%^BOLD%^m%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^There is a %^BLACK%^%^BOLD%^sole%^RESET%^m"+
	"%^BLACK%^%^BOLD%^n feeling to this small room that seems to hang in "+
	"the air. It is perfectly square, with a high ceiling crisscrossed with "+
	"beams several stories high. Far above a single %^RESET%^gl%^BOLD%^"+
	"o%^RESET%^wing o%^BOLD%^r%^RESET%^b %^BLACK%^%^BOLD%^ "+
	"casts dim light, caught by the beams to create "+
	"intricate %^RESET%^shadows%^BLACK%^%^BOLD%^. In the center of the "+
	"room stands a %^YELLOW%^pl%^RESET%^%^ORANGE%^a%^YELLOW%^que "+
	"of %^RESET%^%^ORANGE%^b%^YELLOW%^rass%^BLACK%^%^BOLD%^. At the "+
	"corners of the room sit %^ORANGE%^four incense burners%^BLACK%^%^BOLD%^"+
	". The walls are what draw your attention though, for all along them "+
	"weapons of every type hang. %^RESET%^%^BOLD%^Holy avengers%^BLACK%^%^BOLD%^ "+
	"sit beside %^RESET%^%^GREEN%^venom daggers%^BLACK%^%^BOLD%^, %^RESET%^"+
        "maces%^BLACK%^%^BOLD%^ and a myriad of others.\n%^RESET%^");
    set_exits(([
        "east" : ROOMS"h2",
		"west" : ROOMS"tree",
    ]));  
    set_items(([
        ({"plaque","sign"}) : "%^ORANGE%^This brass plaque is old and "+
		"tarnished. You will have to read it.%^RESET%^",
        ({"weapons","hung weapons"}) : "%^BLACK%^%^BOLD%^On all the "+
		"walls are hung weapons. %^RESET%^%^BOLD%^Holy avengers%^BLACK%^%^BOLD%^ "+
		"sit beside %^RESET%^%^GREEN%^venom daggers%^BLACK%^%^BOLD%^"+
		", %^RESET%^maces%^BLACK%^%^BOLD%^ and a myriad of others.%^RESET%^",
		({"ground", "stone", "stones"}) : "%^RESET%^%^BOLD%^The ground of the "+
		"fortress is set with interlocking stones%^RESET%^",
    ]));

    set_smell("default","%^BLACK%^%^BOLD%^You smell cold stone...%^RESET%^");
    set_listen("default","%^RESET%^%^ORANGE%^The constant cawing of "+
	"crows fills the hallways%^RESET%^");

}


int read(string str){
        object obj;
        int i;
        string *names;
        if(str == "plaque") {
                tell_room(TO,""+TPQCN+" reads over the plaque.");

                message("Ninfo","%^BLACK%^%^BOLD%^      For every foe destroyed in honor.\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      For every dance in the game.\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      The weapon of the revered fallen\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      shall hang. Let it be a reminder\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      of the honor of the fallen, but\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      never a source of pride for the\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^      victor\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^        Tasen Oda: The edicts of the\n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^        Game, thirteenth Shogunate \n",TP);
                message("Ninfo","%^BLACK%^%^BOLD%^        convention\n%^RESET%^",TP);


                return 1;
        }
}
