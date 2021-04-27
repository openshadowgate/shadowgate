//Coded by Styx for Abrahil
#include <std.h>

inherit ROOM;
int num;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_name("Gathering room");
    set_short("A gathering room");
    set_long("At first glance, this seems to be an odd room for a such a small, "
"simple abode.  It seems to be some sort of meeting chamber.  A large circular "
"table sits within the middle of the room and many chairs surround it.  On each "
"wall of this room are %^BOLD%^symbols %^RESET%^that attract your attention.  "
"The table has papers strewn about and %^ORANGE%^small earthenware bowls "
"%^RESET%^atop it.");
   set_items(([
   "symbols" : "There are five symbols carefully carved from wood and stained "
      "appropriate colors attached to the walls.  Small text carved into each "
      "indicates they are of "
      "%^GREEN%^Eldath,%^RESET%^ %^ORANGE%^Silvanus, %^BOLD%^%^GREEN%^Mielikki, "
      "%^MAGENTA%^Lathander%^RESET%^, and %^YELLOW%^Selune.",
   "table" : "This is a large sturdy circular table.",
   "chairs" : "Ten or so sturdy but rather plain wooden chairs line the table.",
   "papers" : "The papers again show deeds and titles as well as maps of forest "
      "lines and humanoid encroachment.",
    ] ));
    set_exits(([
       "southwest" : "/d/player_houses/abrahil/kitchen",
    ] ));
   set_smell("default","You smell the moist earth.");
   set_listen("default","Even the sounds of conversation seem to be muted by "
      "the earthen walls.");
}

void init() {
   ::init();
 	add_action("sit_em","sit");
}

void reset() {
   ::reset();
}

int sit_em(string str) {
  	if(!str) {
      tell_object(TP,"Sit on what???");
      return 1;
  	}
  	if(str != "chair" && str != "on chair") {
  	   tell_object(TP, "Try sitting on a chair.");
  	   return 1;
  	}
  	if(str == "chair" || str == "on chair") {
      if( num > sizeof(all_living(TO)) )  num = sizeof(all_living(TO));
  		if(num > 10){
  			tell_object(TP,"The chairs all seem to be occupied, but maybe "
  			  "someone will let you sit on their lap.\n");
  			tell_room(ETP,TPQCN+" seems to be looking for a lap to sit on.");
  			return 1;
		}
		tell_object(TP,"You pull up one of the chairs and sit down.\n");
		tell_room(ETP,TPQCN+" pulls up a chair and sits down.\n",TP);
		num++;
		return 1;
     	}
}
