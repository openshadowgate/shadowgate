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
    "The walls in the tunnel are smooth stone here. Apperently a dead end, the only exit is "+
    "the ladder that comes up from a hole in the floor.  Undisturbed dust lays heavy on "+
    "the floor here. The north wall is covered in %^BLUE%^shadows%^BLACK%^.  Nothing "+
    "disturbs the quiet darkness up here.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room has a musty and dusty smell.");
    set_listen("default","You can only hear your own breathing.");
    set_items(([
    	"ladder":"The %^ORANGE%^ladder%^RESET%^ is made out of hard wood and looks sturdy.",
	"rope":"You see the end of a rope hanging out an inch from a small hole in the wall."
	]));
    set_search("north wall","You feel the end of a rope hanging out a few inches from a "+
		"small hole in the wall.");
    set_search("shadows","You feel the end of a rope hanging out a few inches from a "+
		"small hole in the wall.");
    set_exits(([
	"down" :MROOMS+"mel8"
    ]));
}
void init() {
  ::init();
  add_action("pull","pull");
}
int pull(string str) {
    if(!str) {
        tell_object(TP,"pull what?");
        return 1;
    }
  if(str == "rope"){
     if(member_array("east",TO->query_exits()) != -1) {
        	tell_object(TP,"You pull on the rope, but nothing happens!");
        	tell_room(ETP,""+TPQCN+" reaches into the shadows, but nothing happens!\n",TP);
            return 1;
            }
     tell_object(TP,"You pull the rope until you hear a clicking!\n"+
     		"A section of the east wall slides open.\n");
     tell_room(ETP,""+TPQCN+" reaches into the shadows and a section of the east wall "+
     		"slides open.\n",TP);
     add_exit(MROOMS+"melbed4","east");
     return 1;
     }
}
