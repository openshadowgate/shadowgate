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
    		"You are standing on a cliff overlooking a small clearing.  The mountain "+
    		"range looms all around you.  There is a huge maple tree further up the "+
    		"mountain and it is about the only place you can safely reach from this "+
    		"place without climbing back down the sheer rock face.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",0);
    	set_property("light",2);
  	set_smell("default","You smell the faint oder of sulfur.");
  	set_listen("default","You hear a faint bubbling far to the east.");
  	set_items(([
  		"rock face":"Its a shear rock face with a huge boulder against it.  "+
  			"Maybe you could climb up if you had the skill of the tools.",
	  	"rocks":"They're rocks.",
		({"tree","maple tree"}) : "Though the tree is very large in girth "+
			"there seems to be enough handholds to ascend if you have the skill or "+
			"the tools with which to climb.",
	  	"mountains":"Forboding looking mountains overshadow this little clearing.",
	   	"brush":"Small patches of scrubby vegitation makes passage difficult further "+
	     		"up the mountain."

      ]));

     	set_exits(([
   		"tree" : IROOMS+"istreed"
 	]));

        set_climb_exits((["descend":({"/d/dagger/derro/rooms/a1",20,6,100})]));
     	set_fall_desc("%^BOLD%^%^GREEN%^You loose your grip and fall down the "+
		"rock face bouncing and cursing all the way!%^RESET%^\n");
}
