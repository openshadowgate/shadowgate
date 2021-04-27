//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LYARD;

int OPEN2;

void create(){
   ::create();
   set_name("yard1");
  	set_exits(([
   	"south" : LROOMS+"yard0",
   	"northwest" : LROOMS+"yard2",
   	"northeast" : LROOMS+"yard4",
		"north" : LROOMS+"yard3",
		"west" : LROOMS+"post0",
		"east" : LROOMS+"post1"
	]));

   set_door("portcullis",LROOMS+"yard0","south","ruby key");
   set_door_description("portcullis","This is a gate of heavy iron bars that "+
  		"is lowered from the ceiling, the mechanism for raising and lowering "+
  		"is not locaked within this room.\n");
  	set_string("portcullis","open","The portcullis raises allowing "+
  		"you entrance to the yard to the south.\n");

  	OPEN2 = 0;
}
void init() {
  	::init();
  	add_action("open_em","open");
  	add_action("yell_em","yell");
}
int open_em(string str) {
  	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "portcullis"){
  		if(OPEN2 == 1){
  			tell_object(TP,"%^BOLD%^The portcullisis already open, DUH!\n");
  			return 1;
  		}
		tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" strains until it "+
			"looks like "+TP->query_subjective()+" will burst a vein "+
			"in "+TP->query_possessive()+" forehead, but is unable to budge the gate.\n");
   	return 1;
   }
}
int yell_em(string str) {
  	if(!str) {
        	tell_object(TP,"Yell what?");
        	return 1;
   }
  	if(str == "raise portcullis"){
		tell_object(TP,"%^BOLD%^You yell for the guards to raise the portcullis!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to raise the portcullis!\n",TP);
    	tell_room(ETP,"%^BOLD%^You hear a clanking as the portcullis is raised.\n");
    	tell_room((LROOMS+"yard0"),"%^BOLD%^You hear a clanking as the "+
    		"portcullis is raised.\n");
    	set_open("portcullis",1);
     		(LROOMS+"yard0")->set_open("portcullis",1);
  		return 1;
	}else if(str == "lower portcullis"){
		tell_object(TP,"%^BOLD%^You yell for the guards to lower the portcullis!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to lower the portcullis!\n",TP);
    	tell_room(ETP,"%^BOLD%^You hear a clanking as the portcullis "+
    		"is lowered.\n");
    	tell_room((LROOMS+"yard0"),"%^BOLD%^You hear a clanking as the "+
    		"portcullis is lowered.\n");
    	set_open("portcullis",0);
     		(LROOMS+"yard0")->set_open("portcullis",0);
  		return 1;
	}
	TP->force_me("emote yells: %^BOLD%^"+str+"!");
	return 1;
}