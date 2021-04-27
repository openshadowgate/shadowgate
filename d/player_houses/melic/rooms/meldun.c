//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Dungeon");
    set_long(
    "%^ORANGE%^"+
    "This room is a plain jail cell. The walls are solid mountain rock.  %^YELLOW%^Hay "+
    "%^RESET%^%^ORANGE%^is spread out over the floor and there are a couple of thin "+
    "blankets just inside the door. No torches light this room.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",1);
    set_smell("default","The smell old hay and unwashed bodies dominates the room.");
    set_listen("default","It is damp, cold and lonely in here.");
    set_search("walls","You find some bricks in the northeast corner that look to be "+
		"loose.");
    set_search("bricks","The bricks appear to be loose and maybe you can move them if you "+
		"pushed!");
    set_items(([
    	({"blankets","blanket"}):"The blankets are made of thick wool and while they don't "+
		"smell very clean they should keep a person warm enough.",
	"hay":"The hay is not clean, but at least there are no rats living in it."
		]));
		
    set_door("iron door",MROOMS+"melgua","south","mithril key");
    set_door_description("iron door","The door is massive and made entirely of iron.");
    set_string("iron door","open","You open the door to guardroom and freedom!\n");
    set_exits(([
	"south":MROOMS"melgua"
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
     		"You see only darkness in the next room.  \n");
     tell_room(ETP,""+TPQCN+" pushes some loose bricks and a hole open in the wall to "+
		"the northwest.  \n",TP);
     add_exit(MROOMS+"mel8d2","hole");
     return 1;
     }
}
