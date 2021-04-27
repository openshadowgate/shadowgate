/*  bug on the break wire trap, Vendel said the second trap isn't showing up on find traps either, just an extra blank line
I can't see anything obvious but maybe someone else will be able to eventually by having this info.  *Styx*  5/17/03

Error in call out.
Can't load objects when no effective user.
program: adm/obj/simul_efun.c, object: adm/obj/simul_efun line 62
'        do_trap' in '        std/Object.c'
('d/player_houses/saradin/rooms/hallway')line 903
'      screw_em1' in 'd/player_houses/saradin/rooms/hallway.c'
('d/player_houses/saradin/rooms/hallway')line 186
'      tell_room' in 'adm/obj/simul_efun.c' ('  adm/obj/simul_efun')line 62
*/

//Coded by Diego//

#include <std.h>
#include "../saradin.h"

inherit VAULT;
int TRIPPED;

void create(){
	::create();
	set_name("hallway");
   set_short("hallway");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This hallway is surprisingly clean and well kept.  The wall "+
   	"to the north is bare except for a tiny lever against the "+
   	"east wall.  The hallway also leads to "+
   	"another knobless door in the south.  The floor is made out "+
   	"of finely cut stone that seems to have been fitted perfectly "+
   	"into place by great craftsmen.  A small knob is affixed to "+
   	"the east side of the hallway and seems to have a wire that "+
   	"attaches to the %^RESET%^%^ORANGE%^doors %^BOLD%^%^BLACK%^in "+
   	"the north and the south.\n"+
   	"%^RESET%^"
   );
  	set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",1);
	set_smell("default","The air is surprisingly clean.");
	set_listen("default","The room is silent save for the noises you make.");
	set_items(([
		"floor" : "The floor is clean and made of finely cut stone that has "+
			"been expertly fitted together.\n",
		"ceiling" : "The ceiling is about ten feet above you and lost in the shadows.\n",
		"knob" : "The knob is attached to the wall and a fine wire extends "+
			"from it to both doors.\n",
		"wire" : "A very fine wire extends from the knob on the wall "+
			"to the doors in the north and south.\n",
		"lever" : "This is a small lever and may be pulled."
        	]));
   set_exits(([
		"south" : SROOMS+"living_area"
  	]));

   set_door("inner door",SROOMS+"living_area","south","black skeleton key");
   set_door_description("inner door","This door is made from solid oak "+
   	"and there is no knob on this side of the door.\n");
  	set_string("inner door","open","The door opens smoothly into an "+
   		"opulent living area.\n");

	set_search("knob","A fine wire does indeed run from the knob to "+
		"the doors, for what reason is anyone's guess.  Maybe the knob "+
		"can be turned, but the wire will almost certain be disturbed "+
		"by this action.\n");
	set_search("wire","The wire looks very thin and fragile.\n");
	set_search("lever","The lever looks innocent enough, but who knows?\n");

	set_trap_functions(({"knob","wire","wire"}),
			({"screw_em","screw_em1","screw_em2"}),
			({"turn","break","cut"}));
	TRIPPED = 0;
}
void init() {
  	::init();
//  	add_action("unlock_em","push");
  	add_action("open_em","open");
  	add_action("push_em","push");
  	add_action("arm_em","rewire");
  	add_action("pull_em","pull");
}
/* Per Saradin, the behind_boxes room was closed per T for being too inaccessible 
   Removing these functions that no longer apply and putting the hidden key here now
   *Styx*  5/17/03

int unlock_em(string str) {
   if(!str) {
     	tell_object(TP,"push what?");
     	return 1;
   }
	if(str == "knob twice"){
     	tell_object(TP,"You push the knob twice, careful not to disturb the "+
     		"wire, and you hear a click in the door to the north.\n");
     	tell_room(TO,""+TPQCN+" blocks your vision so you cannot see "+
     		"what he does to the knob, then you hear a click.\n",TP);
     	set_locked("door",1,"lock");
   		(SROOMS+"behind_boxes")->set_locked("door",1,"lock");
   	return 1;
	}
  	if(str == "knob"){
     	tell_object(TP,"You push the knob, careful not to disturb the "+
     		"wire, and you hear a click in the door to the north.\n");
     	tell_room(TO,""+TPQCN+" blocks your vision so you cannot see "+
     		"what he does to the knob, then you hear a click.\n",TP);
     	set_locked("door",0,"lock");
   		(SROOMS+"behind_boxes")->set_locked("door",0,"lock");
   	return 1;
	}
}
*/

int screw_em(string str){
	int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);

	if(str != "knob"){
		tell_object(TP,"%^BOLD%^What are you trying to turn?\n");
		return 0;
	}
	if(TRIPPED == 1){
		tell_object(TP,"%^BOLD%^You turn the knob and notice that the "+
			"wire already dangles broken.\n");
		tell_room(TO,"%^BOLD%^"+TPQCN+" turns the knob and you "+
			"notice the wire already dangles broken.\n",TP);
		return 1;
	}
	TRIPPED = 1;
	tell_object(TP,"%^BOLD%^You carefully turn the knob, but the "+
		"wire grows taut and then snaps with a %^BLACK%^twang%^WHITE%^.  "+
		"Next you hear an ominous click then the room is filled "+
		"with a hissing sound.");
	tell_room(TO,"%^BOLD%^%^GREEN%^A glowing grey-green noxious "+
		"vapor hisses out suddenly and rapidly fills the hallway!  "+
		"Breathing the gas is unavoidable!\n%^RESET%^");
	tell_room(TO,"%^BOLD%^GREEN%^The effects of the gas quickly spread "+
		"through your limbs with the agony of many daggers and you feel "+
		"yourself loosing contact with reality.\n%^RESET%^");

  	for(i=0;i<j;i++) {
   	if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i] == TP) continue;
  		inven[i]->do_damage("torso",inven[i]->query_max_hp()+50);;
   }
	TP->do_damage("torso",TP->query_max_hp()+50);

	add_item("wire","The fine wire is broken.\n");
	set_search("wire","It is easy to see the wire is broken.\n");
	tell_room((SROOMS+"living_area"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bath"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bedroom"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"torture"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"hall"),"%^BOLD%^%^RED%^A bell rings twice.",TP);

	return 0;

//I intentionally did not make this trap kill//
}
int screw_em1(string str){
	int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);

	if(str != "wire"){
		tell_object(TP,"%^BOLD%^What are you trying to break?\n");
		return 0;
	}
	if(TRIPPED == 1){
		tell_object(TP,"%^BOLD%^It is obvious the wire is already broken.\n");
		tell_room(TO,"%^BOLD%^"+TPQCN+" reaches for the wire and "+
			"finds it is broken.\n",TP);
		return 1;
	}
	TRIPPED = 1;
	tell_object(TP,"As you quietly beak the wire you hear an "+
		"unfortunate click and then a loud hissing sound.");
	tell_room(TO,"%^BOLD%^%^GREEN%^A glowing grey-green noxious "+
		"vapor suddenly and completely fills the hallway with "+
		"the hissing of a thousand vipers!  Beathing the gas is "+
		"unavoidable!\n%^RESET%^");
	tell_room(TO,"%^BOLD%^GREEN%^The effects of the gas quickly spread "+
		"through your limbs with the pain of many daggers and you "+
		"feel yourself loosing contact with reality.\n%^RESET%^");

  	for(i=0;i<j;i++) {
   	if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i] == TP) continue;
  		inven[i]->do_damage("torso",inven[i]->query_max_hp()+50);;
   }
	TP->do_damage("torso",TP->query_max_hp()+50);
	add_item("wire","The fine wire is broken.\n");
	set_search("wire","It is easy to see the wire is broken.\n");
	tell_room((SROOMS+"living_area"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bath"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bedroom"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"torture"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"hall"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	return 0;

//I intentionally did not make this trap kill//
}
int screw_em2(string str){
	int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);

	if(str != "wire"){
		tell_object(TP,"%^BOLD%^What are you trying to cut?\n");
		return 0;
	}
	if(TRIPPED == 1){
		tell_object(TP,"%^BOLD%^The wire is already broken.\n");
		tell_room(TO,"%^BOLD%^"+TPQCN+" reaches out to cut the "+
			"wire and finds it is already severed.\n",TP);
		return 1;
	}
	TRIPPED = 1;
	tell_object(TP,"As you quietly cut the wire you hear a "+
		"click and then a loud hissing sound.");
	tell_room(TO,"%^BOLD%^%^GREEN%^A glowing grey-green "+
		"noxious vapor suddenly and completely fills the "+
		"hallway with the hiss of a thousand vipers!  Beathing "+
		"the gas is unavoidable!\n%^RESET%^");
	tell_room(TO,"%^BOLD%^GREEN%^The effects of the gas quickly spread "+
		"through your limbs with the pain of many daggers and you "+
		"feel yourself loosing contact with reality.\n%^RESET%^");

  	for(i=0;i<j;i++) {
   	if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i] == TP) continue;
  		inven[i]->do_damage("torso",inven[i]->query_max_hp()+25);
   }
	add_item("wire","The fine wire is broken.\n");
	set_search("wire","It is easy to see the wire is broken.\n");
	TP->do_damage("torso",TP->query_max_hp()+25);
	tell_room((SROOMS+"living_area"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bath"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"bedroom"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"torture"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	tell_room((SROOMS+"hall"),"%^BOLD%^%^RED%^A bell rings twice.",TP);
	return 0;

//I intentionally did not make this trap kill meant to subdue and incapacitate for a time//
}
int open_em(string str) {
  	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "inner door"){
		tell_room(TO,""+TPQCN+" tries to open the inner door and fails.\n",TP);
		tell_object(TP,"You try to open the inner door and fail.\n");
   	return 1;
   }
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
   }
  	if(str == "inner door"){
		tell_room(TO,""+TPQCN+" pushes open the inner door.\n",TP);
		tell_object(TP,"You push open the door and see the next room.\n");

    	set_open("inner door",1);
     		(SROOMS+"living_area")->set_open("inner door",1);

    	return 1;
	}
}
int arm_em(string str) {
	if(!str) {
     	tell_object(TP,"%^BOLD%^%^CYAN%^Rewire what?");
      return 1;
   }
  	if(str == "trap"){
      if(!trapped("knob")){
      	TRIPPED = 0;
      	tell_object(TP,"%^BOLD%^You carefully splice the broken "+
      		"wire back together.\n%^RESET%^");
      	tell_room(TO,"%^BOLD%^"+TPQCN+" oh so very carefully splices the "+
      		"broken wire back together.\n%^RESET%^",TP);
			add_item("wire","A very fine wire extends from the knob on the wall "+
				"to the doors in the north and south");
			set_search("wire","The wire looks to have been broken and the spliced "+
				"back together.\n");
      	return 1;
      }else{
      	tell_object(TP,"%^BOLD%^The wire does not seem to be "+
      		"broken, are you sure you want to fiddle with it?  "+
      		"You might set it off.\n");
      	tell_room(TO,"%^BOLD%^"+TPQCN+" reaches for the wire, looks "+
      		"at it more closely then suddenly yanks his hand back.\n",TP);
			return 1;
      }
   }
}
int pull_em(string str) {
   if(!str) {
   	tell_object(TP,"%^BOLD%^Pull what?");
      return 1;
   }
  	if(str == "lever"){
  	  	if(member_array("north",TO->query_exits()) != -1) {
        	tell_object(TP,"%^BOLD%^You pull the lever and close the "+
        		"secret exit.\n");
     		tell_room(ETP,"%^BOLD%^"+TPQCN+" pulls the lever closing the "+
     			"secret exit.\n",TP);
        	remove_exit("north");
        	tell_room("/d/shadow/juran/city/rb2d","%^BOLD%^You hear a grating noise as "+
        		"the crates swing in covering the exit in the south.\n");
        	("/d/shadow/juran/city/rb2d")->remove_exit("south");
         return 1;
      }
     	tell_object(TP,"%^BOLD%^You pull the lever and an exit to the north "+
     		"opens with a grating noise.\n");
     	tell_room(ETP,"%^BOLD%^"+TPQCN+" pulls the lever and you hear a grating noise.\n",TP);
      add_exit("/d/shadow/juran/city/rb2d","north");
      tell_room("/d/shadow/juran/city/rb2d","%^BOLD%^You hear a grating noise as "+
      	"the crates swing away from the south wall revealing an exit "+
      	"to the south.\n");
      ("/d/shadow/juran/city/rb2d")->
      	add_exit("/d/player_houses/saradin/rooms/hallway","south");
		return 1;
	}
	return 1;
}