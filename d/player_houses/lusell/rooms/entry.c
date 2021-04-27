//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("entry");
	set_short("keep entrance");
	set_long(
    	"%^RESET%^%^ORANGE%^"+
		"The wide steps here lead up to huge double "+
		"doors bound in iron.  The doors look sturdy "+
		"enough to repel a small army and by the deep "+
		"scars you see in the wood it might have done "+
		"that already.  The stonework around the door "+
		"is engraved with artistic patterns and large "+
		"iron-ring knockers adorn each door.\n"+
		"%^RESET%^"
   );
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The air smells clean with barest hint of weapon oil.");
	set_listen("default","An occassional clank of armor can be heard nearby.");
	set_items(([
		({"walls","wall"}) : "The walls are made from granite, but the "+
			"granite slabs have been polished down to remove most of their "+
			"roughness.  The walls are clean and free from dust and cobwebs.\n",
		({"step","steps"}) : "Four wide steps made of the same cobblestones "+
			"of the courtyard make a half-moon arc as the descend to the courtyard.\n",
		({"knocker","knockers"}) : "The knockers are huge and made of iron. If one "+
			"were strong enough one would use a knocker to knock on the door "+
			"to alert the lord, or lady's, servants that you wished an audience.\n"
   ]));
  	set_exits(([
   	"southwest" : LROOMS+"yard2",
		"southeast" : LROOMS+"yard4",
		"north" : LROOMS+"hall0",
		"south" : LROOMS+"yard3"
   ]));

  	set_door("double doors",LROOMS+"hall0","north","ruby key");
   set_door_description("double doors","The double doors are made "+
   	"of stout oak and bound in heavy bars of iron.  The doors "+
   	"have deep scars as if they had repelled prospective invaders "+
   	"at least once before.\n");
   set_string("double doors","open","The doors opens open wide to "+
   	"a large stone hallway leading north.\n");
   set_locked("double doors",1,"lock");
	(LROOMS+"hall0")->set_locked("double doors",1,"lock");
  	lock_difficulty("double doors", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
}
void init() {
  	::init();
  	add_action("use_em","use");
}
int use_em(string str) {
  	if(!str) {
        	tell_object(TP,"Use what?");
        	return 1;
    	}
  	if(str == "knocker" || str == "knockers"){
  		if((int)TP->query_stat("strength")<14){
  			tell_object(TP,"%^BOLD%^YOu are not strong enough to "+
  				"lift the knocker let alone bang it loud enough for "+
  				"someone to hear on the other side.\n");
  			tell_room(ETP,"%^BOLD%^"+TPQCN+" tries to lift the heavy "+
  				"knocker, but is not up to the task.\n",TP);
  			return 1;
  		}
		tell_room(TO,""+TPQCN+" lifts the knocker with effort and "+
			"slams it back against the door to announce "+
			""+TP->query_possessive()+" presence.\n",TP);
		tell_object(TP,"%^BOLD%^You lift the knocker then slam it against the "+
			"door to announce your presence.\n");
		tell_room((LROOMS+"hall0"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall1"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall2"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall6"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall7"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"dining"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall4"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"lusell"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall5"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall8"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"hall3"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"kitchen"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"barracks"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
		tell_room((LROOMS+"officerq"),"%^RESET%^%^ORANGE%^You hear a knock at "+
			"the doors of the keep.",TP);
    	return 1;
	}
}
void reset(){
	::reset();
	if(!present("monster")){
		new(LMON+"sergeant_nm")->move(TO);
		new(LMON+"sergeant_nm")->move(TO);
	}
}