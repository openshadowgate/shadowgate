//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Melic's Bedroom");
    set_long(
    "%^BOLD%^%^CYAN%^"+
    "A large bed stands against the west wall here. The bed has warm blankets for covers "+
    "and looks like it's not very soft, but still comfortable. A fireplace is set in the "+
    "east wall. A pile of firewood lies next to it. The floor is covered with a thin "+
    "%^RESET%^%^RED%^red%^BOLD%^%^CYAN%^ rug. There is a small table next to the bed "+
    "with a candle and a %^BLUE%^waterbowl%^CYAN%^.  Mounted on the west wall is a dragon "+
    "head made from %^ORANGE%^brass%^CYAN%^.  Shields, plates and maces adorn this "+
    "otherwise plain room.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The smell of oil and steel is in the air.");
    set_listen("default","The fire crackles softly.");
    set_items(([
    	({"dragon head","dragon"}):"%^RESET%^The dragon head is not real, but is a very "+
    		"good replication of a %^BOLD%^%^ORANGE%^metallic%^RESET%^ dragon.  The artist "+
		"was obviously very skillful and took great care to re-create a dragon's head "+
		"to the most minute detail.  The dragon's teeth are made of what seems to be "+
		"%^BOLD%^%^WHITE%^ivory%^RESET%^ or maybe even belonged to a real dragon at "+
		"one time.  Huge glittering %^BOLD%^%^RED%^rubies%^RESET%^ are set in place "+
		"of the dragon's eyes.  One dragon tooth appears to be a little discolored as "+
		"if it has been touched more than the others.  The dragon is so realistic, one "+
		"wonders if his %^RED%^searing%^RESET%^ breath was reproduced as well",
	({"tooth","dragon tooth"}):"When the tooth is examined closely it looks to have a "+
		"different setting than the other teeth, almost as if it was meant to be "+
		"pressed."
	]));
	
    set_door("north room door",MROOMS+"meluph2","south","mithril key");
    set_door_description("north room door","The door is wooden, much as you would expect.");
    set_string("north room door","open","You open the door into the castle hallway.\n");
    
    set_exits(([
	"south" :MROOMS+"meluph2"
	]));
}
void init() {
  ::init();
  add_action("press","press");
}
int press(string str) {
    if(!str) {
        tell_object(TP,"press what?");
        return 1;
    }
  if(str == "dragon tooth"){
     if(member_array("west",TO->query_exits()) != -1) {
        	tell_object(TP,"You press the dragon tooth, but nothing happens!.");
            return 1;
            }
     tell_object(TP,"You press the dragon tooth until you hear a click!\n"+
     		"A section of the west wall slides open.\n");
     tell_room(ETP,""+TPQCN+" puts his hand in the dragon's mouth and a section of the "+
     		"west wall slides open.\n",TP);
     add_exit(MROOMS+"mel8u","west");
     return 1;
     }
}
