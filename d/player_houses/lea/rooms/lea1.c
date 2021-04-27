//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Outside White Stone Cottage");
    set_long(
    	"%^WHITE%^"+
    	"The cobblestone path ends facing a small two story white stone cottage in the "+
    	"north.  The cobblestone path leads away from the cottage to the southeast.  Each "+
	"stone of the cottage is shaped, polished, and carefully laid out.  Several "+
	"curtained windows stare warmly at you.  Smoke rises from the chimney and a few "+
	"healthy %^BOLD%^%^RED%^rose%^RESET%^ %^WHITE%^bushes add color to the "+
	"home.%^RESET%^\n"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The smell of roses, daisies and wood smoke intermingle.");
    set_listen("default","It is quiet and peaceful here.");
    set_items(([
      ({"cobblestones","stones","stone","cobblestones"}):"\n %^RESET%^The path is made up "+
      		"of these rounded and smooth stones.\n",
	({"daisy","daisies"}):"\n%^BOLD%^%^WHITE%^White%^RESET%^ flowers "+
			"with %^BOLD%^%^YELLOW%^yellow%^RESET%^ centers spring up along "+
			"pathway.  At first glance they appear to be growing wild, but upon "+
			"closer examination you can tell they were planted here and have been "+
			"well taken care of.\n",
	({"roses","rose","rose bush","rose bushes"}):"\n%^BOLD%^%^RED%^Rose %^GREEN%^bushes "+
			"%^RESET%^bloom with vibrant color and aroma adding much needed color "+
			"to the front of this %^WHITE%^white%^RESET%^ stone cottage.\n",
	({"window","windows"}):"\n%^RESET%^Occassional movement can be seen within this "+
			"modest house.  Curtains adorn they windows and they appear to have "+
			"been recently cleaned.\n"
        ]));

    set_door("door",LROOMS+"leahall","north","brass key");
    set_locked("door",1,"lock");
     (LROOMS+"leahall")->set_open("door",0);
     (LROOMS+"leahall")->set_locked("door",1,"lock");
    lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
    set_door_description("door","This is a heavy oak door set into a heavy oak frame.  "+
    		"the door looks like it could take quite a beating before it would come "+
    		"down.  Maybe if you knock the owner will know you are here.\n");
    set_string("door","open","The door opens to a hallway.  The entrance is well lit and "+
		"inviting.\n");

    set_exits(([
	"southeast" : LROOMS+"leap0",
	"north" : LROOMS+"leahall"
    ]));
}
void init() {
  	::init();
  	add_action("knock","knock");
}
int knock(string str) {
    	if(!str) {
        	tell_object(TP,"Knock on what?");
        	return 1;
    	}
  	if(str == "on door"){
     		TP->force_me("emote knocks on the door loudly.");
     		tell_room((LROOMS+"leahall"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leauphall"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leabalc"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leabath"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leabed1"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leabed2"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leadine"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leakitch"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leasit"),"You hear a knocking at the front door.",TP);
     		tell_room((LROOMS+"leastudy"),"You hear a knocking at the front door.",TP);
     		return 1;
     	}
}