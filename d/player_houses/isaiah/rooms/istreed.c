//Coded by Diego//

#include <std.h>
#include "../isaiah.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
    	::create();
   set_terrain(NEW_MOUNTS);
   set_travel(FRESH_BLAZE);
   	set_short("maple tree");
    	set_long(
    		"%^RESET%^%^ORANGE%^"+
    		"You see the hulking trunk of a %^BOLD%^maple %^RESET%^%^ORANGE%^tree "+
    		"ascending upwards.  Looking up among the foilage there looks to be a "+
    		"structure above you, but you will have to climb higher to make sure.  "+
         "The maple tree looms overhead, its leaves blowing here and there as the "+
                    "wind directs.  The leaves are broad and plentiful and hide most of the "+
      "higher branches from view.  The trunk of the tree, and its branches, twist "+
    		"upward snaking their way gracefully into the sky.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",0);
    	set_property("light",2);
    	set_smell("default","You can smell crisp clean air and traces of %^BOLD%^%^YELLOW%^f%^RED%^l%^BLUE%^o%^YELLOW%^w%^RED%^e%^BLUE%^r%^YELLOW%^s%^RESET%^ %^ORANGE%^from the valley below.");
    	set_listen("default","The rustle of leaves and the faint sounds of crashing "+
    		"water can be heard far below.");
	set_items(([
		({"trunk","tree","maple tree"}) : "Though the tree is very large in girth "+
			"there seems to be enough handholds to ascend if you have the skill or "+
			"the tools with which to climb.\n"
      ]));

     	set_exits(([
   		"cliff" : IROOMS+"iscliff"
 	]));

        set_climb_exits((["climb":({IROOMS+"istree",20,6,100})]));
      set_fall_desc("%^BOLD%^%^GREEN%^You lose your grip and fall further down the "+
		"trunk of the tree bouncing from branch to branch all the way "+
		"down!%^RESET%^\n");
}
