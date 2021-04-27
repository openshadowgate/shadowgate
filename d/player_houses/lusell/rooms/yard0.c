//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LYARD;

int OPEN2;

void create(){
   ::create();
   set_name("yard0");
  	set_exits(([
		"north" : LROOMS+"yard1"
	]));

	set_door("portcullis",LROOMS+"yard1","north","ruby key");
  	set_locked("portcullis",0,"lock");
	  	(LROOMS+"yard1")->set_locked("portcullis",0,"lock");
  	set_door_description("portcullis","This is a gate of heavy iron bars that "+
  		"is lowered from the ceiling, the mechanism for raising and lowering "+
  		"is not locaked within this room.");
  	set_string("portcullis","open","The portcullis raises allowing "+
  		"you entrance in the the cobblestone courtyard.\n");

  	OPEN2 = 0;

  "daemon/place_d"->place_in(LROOMS,new(LMON+"sergeant"));
  "daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  "daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  "daemon/place_d"->place_in(LROOMS,new(LMON+"captain"));
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
  			tell_object(TP,"%^BOLD%^The portcullis is already open, DUH!\n");
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
    	tell_room((LROOMS+"yard1"),"%^BOLD%^You hear a clanking as the "+
    		"portcullis is raised.\n",TP);
    	set_open("portcullis",1);
     		(LROOMS+"yard1")->set_open("portcullis",1);
     	return 1;
	}else if(str == "lower portcullis"){
		tell_object(TP,"%^BOLD%^You yell for the guards to lower the portcullis!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to lower the portcullis!\n",TP);
    	tell_room(ETP,"%^BOLD%^You hear a clanking as the portcullis "+
    		"is lowered.\n");
    	tell_room((LROOMS+"yard1"),"%^BOLD%^You hear a clanking as the "+
    		"portcullis is lowered.\n",TP);
    	set_open("portcullis",0);
     		(LROOMS+"yard1")->set_open("portcullis",0);
    	return 1;
	}else	if(str == "lower drawbridge"){
		if(member_array("bridge",TO->query_exits()) != -1) {
   		tell_object(TP,"%^BOLD%^Why are you yelling, the drawbridge is "+
   			"already lowered!");
			return 1;
		}
		tell_object(TP,"%^BOLD%^You yell for the guards to lower the drawbridge!\n");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to lower the "+
			"drawbridge!\n",TP);
		tell_room(ETP,"%^BOLD%^You hear a clanking as the chains from the "+
			"drawbridge are slowly released and the bridge is lowered.\n");
		tell_room((LROOMS+"bridge"),"%^BOLD%^You hear a clanking as the chains from the "+
			"drawbridge are slowly released and the bridge is lowered.\n");
     	(LROOMS+"bridge")->add_exit(LROOMS+"yard0","bridge");
     	add_exit(LROOMS+"bridge","bridge");
     	return 1;
   }else if(str == "raise drawbridge"){
   	if(member_array("bridge",TO->query_exits()) != -1) {
			tell_object(TP,"%^BOLD%^You yell for the guards to raise the drawbridge!\n");
			tell_room(ETP,"%^BOLD%^"+TPQCN+" yells for the guards to raise "+
				"the drawbridge!\n",TP);
			tell_room(ETP,"%^BOLD%^You hear a clanking as the chains from the "+
				"drawbridge are slowly pulled up and the bridge is raised.\n");
			tell_room((LROOMS+"bridge"),"%^BOLD%^You hear a clanking as the chains from the "+
				"drawbridge are slowly pulled up and the bridge is raised.\n");
   		remove_exit("bridge");
   		(LROOMS+"bridge")->remove_exit("bridge");
   		return 1;
 		}else{
   		tell_object(TP,"%^BOLD%^Why are you yelling, the drawbridge is "+
   			"already raised!");
			return 1;
		}
 	}
	TP->force_me("emote yells: %^BOLD%^"+str+"!");
	return 1;
}
