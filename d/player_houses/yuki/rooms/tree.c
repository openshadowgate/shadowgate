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
    set_name("hidden courtyard");
    set_property("light",2);
    set_short("hidden courtyard");
    set_long("%^RESET%^%^GREEN%^You squint your eyes as you leave "+
	"the %^BLACK%^%^BOLD%^inner keep%^RESET%^%^GREEN%^ to a hidde"+
	"n %^RESET%^%^CYAN%^open air%^GREEN%^ courtyard. This spacious "+
	"area is protected by the high walls of the inner keep and i"+
	"s %^RESET%^%^BOLD%^ba%^RESET%^r%^BOLD%^e white m%^RESET%^a%^BOLD%^"+
	"rble%^RESET%^%^GREEN%^. At the center of the area is a %^RESET%^%^RED%^"+
	"you%^BOLD%^n%^RESET%^%^RED%^g ch%^BOLD%^e%^RESET%^%^RED%^rry tr%^BOLD%^"+
	"e%^RESET%^%^RED%^e%^GREEN%^. At the base of the tree, supporting it, are "+
	"hundreds of %^RESET%^small s%^BLACK%^%^BOLD%^t%^RESET%^ones%^GREEN%^ th"+
	"at draw your attention. Around the tree facing it are %^ORANGE%^small "+
	"benches%^GREEN%^. A %^YELLOW%^small sign%^RESET%^%^GREEN%^ sits near t"+
        "he tree.\n%^RESET%^");
    set_exits(([
        "east" : ROOMS"kill",
    ]));  
    set_items(([
        ({"stones"}) : "%^RESET%^%^BOLD%^Each stone is carefully inscribed "+
		"with a name and has been placed at the base of the tree, as if to "+
		"support it. It is obvious that most of the stones are decades, if "+
		"not centuries old. .%^RESET%^",
        ({"tree","cherry tree"}) : "%^RESET%^%^RED%^this you%^BOLD%^"+
		"n%^RESET%^%^RED%^g ch%^BOLD%^e%^RESET%^%^RED%^rry tr%^BOLD%^"+
		"e%^RESET%^%^RED%^e%^ is supported by hundreds of stones.%^RESET%^",
		({"benches"}) : "%^RESET%^%^ORANGE%^The benches face the "+
		"tree%^RESET%^",
		({"sign"}) : "%^YELLOW%^This sign sits near the tree, you "+
		"should read it%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^RED%^You smell cherry blossoms.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^You hear the breeze through "+
"the tree's branches.%^RESET%^");

}


int read(string str){
        object obj;
        int i;
        string *names;
        if(str == "sign") {
                tell_room(TO,""+TPQCN+" reads over the sign.");

                message("Ninfo","%^RESET%^%^BOLD%^      We are swan, and we are Family. The game\n",TP);
                message("Ninfo","%^RESET%^%^BOLD%^      will test us, it will hurt us and it will\n",TP);
                message("Ninfo","%^RESET%^%^BOLD%^      put the winds of war and strife against us.\n",TP);
                message("Ninfo","%^RESET%^%^BOLD%^      But we will prevail. The family that has fallen\n",TP);
                message("Ninfo","%^RESET%^%^BOLD%^      died to support us all, so they will be remembered.\n",TP);
                message("Ninfo","%^RESET%^%^BOLD%^        .Takeda Shuen, First Daimyo of Bwana.\n%^RESET%^",TP);

                return 1;
        }
}
