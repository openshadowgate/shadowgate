//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

object ob;
int FLAG;

void reset() {
 	::reset();
      if(FLAG == 1)FLAG = 0;
    	if(!present("golem"))new(MMONS+"igolem")->move(TO);
}
void create(){
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_short("Outside Gates of Castle Belegost");
    set_long(
    "%^ORANGE%^"+
    "You are outside the walls of the castle. A massive stone gate is set in the 30 foot "+
    "high stone walls which encircle the castle proper.  Set above the gates, carved in "+
    "the stone deeply and artistically is the word%^BOLD%^%^BLACK%^ BELEGOST "+
    "%^RESET%^%^ORANGE%^.  Towers adorn every corner of the protective eight-sided wall.  "+
    "The wall itself seems to have been melted by intense heat to form a single object.  "+
    "Arrow slits are the only things that disrupt the smoothness of the walls.  On either "+
    "side of the gate statues of %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^ dragons sit.  "+
    "There is a bell set on a pole in the middle of the path leading up to the gates.  "+
    "A large sign hangs on the gates.  \n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","You smell air that is fresh and crisp.");
    set_listen("default","You can hear muffled and distant stirrings from inside the "+
				"castle.");
    set_items(([
    	({"wall","walls"}):"The walls are about 30 feet high and look very solid.  Atop the "+
    				"walls you can see guards on patrol",
	"bell":"The %^ORANGE%^brass%^RESET%^ bell has a rope attached to it, perhaps you can "+
				"pull the rope to ring bell",
	({"guardians","guardian","statue","statues","dragon","dragons"}):"Large statues made "+
				"of obsidian, they look very life-like and their eyes seem to "+
				"follow you about the room.  Their crystal blue eyes seem to "+
				"spark with magic.",
	"sign" : "Maybe you should read the sign."
        ]));

    set_door("gates",MROOMS+"mel2","north","mithril key");
    add_lock("gates","mithril key","padlock","This is a very large padlock.  Opening this "+
    		"lock with brute force would be very difficult.");
    set_locked("gates",1,"lock");
    set_locked("gates",1,"padlock");
    	(MROOMS+"mel2")->set_locked("gates",1,"lock");
    	(MROOMS+"mel2")->set_locked("gates",1,"padlock");
    set_door_description("gates","The gates are massive and made of iron, they seem too "+
		"heavy to be moved by normal means.  You see a sign placed in the middle of "+
		"the gates.  As you look closer you notice a faint red aura surrounding the "+
		"gates.");
    set_string("gates","open","%^BOLD%^%^BLUE%^The massive gates swing fully open without "+
    		"a sound.%^RESET%^\n");

    set_trap_functions(({"gates","gates"}),({"poison_me","poison_me"}),({"pick","pick"}));
	FLAG = 0;
    set_exits(([
	"north":MROOMS+"mel2",
	"south":MROOMS"mel0"
    ]));
}
void init() {
  ::init();
  add_action("read","read");
  add_action("pull","pull");
  add_action("trace","trace");
}
int read(string str) {
  if(!str) {
        tell_object(TP,"Read what?");
        return 1;
    }
  if(str == "sign"){
     write("%^BOLD%^%^BLUE%^"+
		"The sign reads in bold and foreboding letters: \n"+
		"%^BOLD%^%^RED%^All trespassers will be violated with extreme prejudice!!\n"+
		"If you are not an invited guest you will be %^BLACK%^KILLED%^RED%^!!\n"+
		"\n"+
		"                                     Thank You,\n"+
		"                                             - The Lord of the Keep -\n"+
		"%^RESET%^");
     return 1;
     }
}
int poison_me(string str){
	int poison;
	switch (str){
	case "lock":
		toggle_trap("gates","pick","lock");
		poison = roll_dice(30,10);
		break;
	case "massive padlock":
		toggle_trap("gates","pick","padlock");
		poison = roll_dice(30,10);
		break;
	}
	TP->add_poisoning(poison);
	TP->setPoisner(TO);
	tell_object(TP,"%^BOLD%^%^GREEN%^You feel a sharp prick in your hand as you work "+
		"the lock.");
	TP->force_me("emote pulls his hand back in pain and shakes it slightly");
	return 1;
}
int pull(string str) {
  if(!str) {
        tell_object(TP,"Pull what?");
        return 1;
    }
  if(str == "rope"){
  	tell_room((MROOMS+"melup2"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"mely"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melsup"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melm"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"meldun"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melgua"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melbed3"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melbed4"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melbed1"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"melbed2"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"mel3"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"mela"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
  	tell_room((MROOMS+"mel2"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
	tell_room(ETO,"%^BOLD%^%^BLUE%^"+TPQCN+" rings pulls on the rope and the bell "+
		"starts ringing.\n",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^You pull on the rope and the bells starts "+
		"ringing.\n");
     	return 1;
     }
}
int trace(string str) {
  	if(!str) {
        	tell_object(TP,"Trace what?");
        	return 1;
    	}
  	if(str == "third stone"){
		if(FLAG == 0){
			tell_room(ETO,"%^BOLD%^"+TPQCN+" turns his back to you, faces the "+
				"wall to the right of the gates.\n",TP);
    //                    tell_object(TP,"You trace the third stone and nothing "+
      //                          "happens.\n");
	                     tell_object(TP,"You trace the third stone, a compartment "+
                                "opens and your hidden key drops into your hand.\n\nThe "+
                                "compartment closes silently.\n");
                                new(MSTUFF+"mithril_key")->move(TP);
//coded back in by Saide in April 2013, since Raveena is now high mortal.
// currently coded out since the Raveena was kicked out of the castle.
                        FLAG = 1;
     			return 1;
     		}else{
			tell_room(ETO,"%^BOLD%^"+TPQCN+" turns his back to you, faces the "+
				"wall to the right of the gates.\n",TP);
			tell_object(TP,"%^BOLD%^You trace the third stone and nothing "+
                                "happens.\n");
                                return 1;
		}
     	}
}
