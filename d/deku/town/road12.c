#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit VAULT;

void create() {
 ::create();
  set_property("light",2);
        set_property("night light",2);
  set_property("indoors",0);
  set_terrain(VILLAGE);
  set_travel(DIRT_ROAD);
  set_short("Town of Verbobone");
  set_long("%^BOLD%^%^WHITE%^This is the broadway street going through the town of Verbobone. "+
  "The road ends here at a giant %^BOLD%^%^BLUE%^blue iron%^BOLD%^%^WHITE%^ gate. "+
  "Visible beyond the gate you can make out the outline of "+
  "an %^BOLD%^%^BLACK%^ancient%^BOLD%^%^WHITE%^ and %^ORANGE%^delapidated"+
  "%^BOLD%^%^WHITE%^ house. It is hard to see much of it clearly from here as "+
  "a %^BOLD%^%^GREEN%^sickly green%^BOLD%^%^WHITE%^ haze makes it almost impossible "+
  "to see. You only hope that it does not seep further this way, less it might take over "+
  "the entire town.%^RESET%^");

  set_exits(([
   "south" : "/d/deku/town/road11",
   "north" : "/d/deku/hhouse/rooms/cy1",
  ] ));
  
  set_items(([
    ({"house", "delapidated house", "haunted house", 
    "ancient house"}) : "%^BOLD%^%^BLACK%^The house "+
    "north of you looks enormous, but it is difficult to "+
    "make out more than a faint outline of it from here "+
    "because of the sickly green haze.",
			
    ({"haze", "sickly haze", "green haze"}) : "%^BOLD%^%^GREEN%^"+
    "This thick sickly green haze hangs heavily in the "+
    "air north of here. It makes seeing there quite difficult and "+
    "you can only hope that it does not seep further this way.%^RESET%^",
    ]) ); 
	
  
  set_door("blue iron gate", "/d/deku/hhouse/rooms/cy1" ,"north", "","lock");
  set_door_description("blue iron gate","%^BOLD%^%^BLUE%^This giant heavy "+
  "gate has recently been set across the road leading into the courtyard of the "+
  "house. It is quite heavy but thankfully it has been expertly crafted so that it opens "+
  "with little difficulty.%^RESET%^");
  
  set_pre_exit_functions(({"north"}),({"go_north"}));

}


void reset() {
  ::reset();
}

int go_north() 
{
    int x;
    x = ::GoThroughDoor();
    if(!x) return 0;
    if(TP->query_highest_level() < 30) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^An invisible force bars your way and prevents "+
        "you from going through the %^BOLD%^%^BLUE%^blue iron%^BOLD%^%^WHITE%^ gate.%^RESET%^");
        tell_object(TP, "%^B_CYAN%^%^YELLOW%^OOC: This area is now meant for level 30+ "+
        "adventures. In order to prevent needless deaths I have restricted access to level 30. "+
        "Perhaps the keep in the forest or the forest itself might provide better tasks for you? "+
        "**Saide**");
        return 0;
    }

    tell_object(TP, "%^B_CYAN%^%^YELLOW%^You are entering an area that uses some code that "+
    "is, as far as I am aware, unique to the area. I forsee some hiccups and tuning in the days "+
    "and weeks to come. Please do not hesitate to send me a mail (mail saide) with any issues "+
    "you encounter. Or bug report/typo report them as encountered. Enjoy the adventure!%^RESET%^");
    return 1;
}
