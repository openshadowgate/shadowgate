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
    "The tunnel is dark and damp. The walls are roughly cut out of the mountain. There "+
    "are some loose bricks in the southeast corner and a hint of %^YELLOW%^light%^BLACK%^ "+
    "sneaks in through the cracks. A ladder leads up into the darkness.  \n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is stiff and damp.");
    set_listen("default","You hear the echo of your every move.");
    set_items(([
    	"ladder":"The %^ORANGE%^ladder%^RESET%^ is made out of hard wood and looks sturdy.",
    	"bricks":"The bricks look loose and maybe with a little effort can be pushed out of "+
    		"their place in the wall."
	]));
    set_exits(([
	"up" : MROOMS+"mel8d"
	]));
}
void init() {
  ::init();
  add_action("push","push");
}
int push(string str) {
    if(!str) {
        tell_object(TP,"Push what?");
        return 1;
    }
  if(str == "bricks"){
     if(member_array("hole",TO->query_exits()) != -1) {
        	tell_object(TP,"The bricks have already been pushed out of the way!.");
            return 1;
            }
     tell_object(TP,"You push the loose bricks and they fall away to reveal a hole!\n"+
     		"You see hints of hay in the other room.  \n");
     tell_room(ETP,""+TPQCN+" pushes some loose bricks and a hole open in the wall to "+
		"the southeast.  \n",TP);
     add_exit(MROOMS+"meldun","hole");
     return 1;
     }
}
