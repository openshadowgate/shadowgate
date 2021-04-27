//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
  	::create();
   set_name("Torture chamber");
   set_short("torture chamber");
   set_long(
   	"%^RESET%^"+
   	"A few torches line the walls of this dim room, providing "+
   	"it with very little light.   The walls are made of "+
    	"crudely %^BOLD%^%^BLACK%^carved gray stones%^RESET%^ "+
  		"and are bare, except for four sets of manacles which "+
  		"hang, currently unused, along with whips and other "+
  		"metal devices. In the corner of the room sits a "+
  		"%^ORANGE%^wooden chair %^RESET%^covered with "+
  		"%^BOLD%^%^RED%^metal spikes%^RESET%^, and a stretching "+
  		"rack, which is also covered with small "+
  		"%^BOLD%^%^RED%^metal spikes%^RESET%^.  A stone table "+
  		"sits upon a raised platform that is lined with "+
  		"%^BOLD%^%^BLACK%^small black candles%^RESET%^, incense "+
  		"burners and a vase of %^BOLD%^%^BLACK%^black roses%^RESET%^.  "+
  		"Behind the altar hangs a %^MAGENTA%^purple tapestry %^RESET%^which "+
  		"displays a %^YELLOW%^golden nine-stranded whip%^RESET%^. \n"
  	);
  	set_terrain(STONE_BUILDING);
  	set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The smell of stale incense and blood fills the air.");
   set_listen("default","The chamber is cold and silent.");
   set_items(([
		({"manacle","manacles"}) : "The manacles are made of a copper "+
			"colored metal, and although currently unused, you can "+
			"envision the countless prisoners who have been brought "+
			"here, waiting for their death.\n",
		"chair" : "This chair looks far from comfortable.  It is entirely "+
			"metal, with small spikes protruding from it.  Blood is "+
			"dried between the small cracks of the chair. Underneath, "+
			"you notice the floor is burnt, as if someone had recently "+
			"built a fire there.\n",
		"rack" : "This is a typical stretching rack. It is made of wood, "+
			"but covered with small metal nails.  Leather cords are "+
			"attached to large wheels, which can be turned to bring "+
			"discomfort to anyone who has the displeasure of being "+
			"laid upon this horrible device.\n",
		"table" : "A purple cloth is laid out over the table, along with "+
			"four black candles and the vase. Otherwise, the table "+
			"remains bare.\n",
		"tapestry" : "The purple tapestry sways strangely despite the "+
			"still air.  You recognize the design as the Holy Symbol "+
			"of Loviatar.\n"
	]));

// set_property("no teleport",1);


  	set_exits(([
		"up" : DROOMS+"foyer"
  	]));

  	set_door("copper door",DROOMS+"foyer","up","marble key");
   set_door_description("copper door","The door is made from a "+
   	"common wood covered in copper sheets.");
   set_string("copper door","open","You open the door into the foyer.\n");
}
void init() {
  	::init();
  	add_action("sit","sit");
  	add_action("bind_em","shackle");
  	add_action("unbind_em","unshackle");
  	add_action("open_em","crush");
}
int sit(string str) {
  	if(!str) {
    	tell_object(TP,"Sit where?");
     	return 1;
  	}
  	if(str == "chair" || str == "on chair"){
     	tell_object(TP,"%^BOLD%^%^RED%^As you sit, the metal spikes sink into your "+
     		"flesh causing you to quickly hop to your feet.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" winces "+
        	"as "+TP->query_subjective()+" sits "+
        	"in the chair, and quickly hops "+
        	"to "+TP->query_possessive()+" feet.\n%^RESET%^",TP);
		TP->do_damage("torso",random(10)+10);
		return 1;
 	}
}
int bind_em(string str) {
	object ob;

	if(!str) {
     	notify_fail("Shackle who?\n");
     	return 0;
   }
	ob = find_player(str);
   if(!ob) {
     	notify_fail("That person is nowhere to be found!\n");
     	return 0;
   }
	if(ob->query_bound()){
		notify_fail("That person is already bound!\n");
		return 1;
	}
	if(ob->query_unconscious()){
		tell_object(TP,"You fasten the manacles about the wrists of "+
			"your unconscious captive.\n");
		tell_room(ETP,""+TPQCN+" fastens the unconscious captive into a "+
			"set of manacles connected to the wall.\n",TP);
		ob->set_bound(random(1000)+1000,"%^RED%^You are chained to the wall "+
			"awaiting torture, how will you do that!%^RESET%^");
		return 1;
	}else{
		tell_object(TP,"Your captive is conscious and refuses to be shackled.\n");
		tell_object(ob,""+TPQCN+" tries to chain you to the wall!\n",TP);
		tell_room(ETP,""+TPQCN+" tries to chain "+ob->query_cap_name()+" to "+
			"the wall unsuccessfully.\n",({TP,ob}));
		return 1;
	}
}
int unbind_em(string str) {
	object ob;

	if(!str) {
       	notify_fail("Unshackle who?\n");
        	return 0;
    	}
	ob = find_player(str);
    	if(!ob) {
        	notify_fail("That person is nowhere to be found!\n");
        	return 0;
    	}
	if(ob->query_bound()){
		tell_object(TP,"You unfasten the manacles and free your captive!\n");
		tell_room(ETP,""+TPQCN+" unfastens the manacles holding the captive.\n",TP);
		ob->set_bound(0,"You are free!");
		return 1;
	}else{
		tell_object(TP,"The person you are trying to unshackle is already free!\n");
		return 1;
	}
}
int open_em(string str) {
   if(!str) {
     	tell_object(TP,"Crush what?");
     	return 1;
   }
  	if(str == "black rose" || str == "a black rose"){
   	if(member_array("south",TO->query_exits()) != -1) {
    		tell_object(TP,"You crush a black rose!");
     		tell_room(ETP,""+TPQCN+" crushes a black rose.\n",TP);
        	return 1;
     	}
   	tell_object(TP,"You crush a black rose to dust and the illusion "+
   		"covering the exit in the south wall dissolves!\n");
   	tell_room(ETP,""+TPQCN+" crushes a black rose and suddenly "+
   		"there is an opening in the south wall.\n",TP);
   	add_exit(DROOMS+"hblood0","south");
   		return 1;
  	}else{
   	tell_object(TP,"You can't crush that.");
     	tell_room(ETP,""+TPQCN+" tries to crush "+str+" unsuccessfully.",TP);
     	return 1;
   }
}
