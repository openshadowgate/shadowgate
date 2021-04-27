//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
    set_short("Dark Tunnel");
    set_long(
    "%^BOLD%^%^BLACK%^"+
    "The walls in the tunnel are smooth stone here. There is a%^RESET%^%^ORANGE%^ ladder "+
    "%^BOLD%^%^BLACK%^here that comes up from a hole in the floor and continues up "+
    "through the ceiling. The walls seem solid and unmarked. Dust covers everything.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room has a musty and dusty smell.");
    set_listen("default","You can only hear your own breathing.");
    set_items(([
    	"ladder":"The %^ORANGE%^ladder%^RESET%^ is made out of hard wood and looks sturdy. "+
		"Only one of the middle rungs seem a bit loose",
	"rung":"The rung is somewhat loose and could be twisted."
	]));
    set_exits(([
	"up" :MROOMS+"mel8u",
	"down" : MROOMS+"mel8d"
    ]));
}
void init() {
  ::init();
  add_action("twist","twist");
}
int twist(string str) {
    if(!str) {
        tell_object(TP,"Twist what?");
        return 1;
    }
  if(str == "rung"){
     if(member_array("north",TO->query_exits()) != -1) {
        	tell_object(TP,"The rung twists freely, but nothing else happens!.");
            return 1;
            }
     tell_object(TP,"You twist the rung and it moves freely!\n"+
     		"After a short clicking a section of the north wall slides open.\n");
     tell_room(ETP,""+TPQCN+" twists the rung and a section of the north wall "+
     		"slides open.\n",TP);
     add_exit(MROOMS+"melm","north");
     return 1;
     }
}
