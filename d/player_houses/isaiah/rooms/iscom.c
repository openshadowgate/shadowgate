//Coded by Diego//

#include <std.h>
#include "../isaiah.h"
inherit VAULT;
int NUM,uses;
void create(){
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   	set_short("Treehouse");
    	set_long(
    		"%^RESET%^%^GREEN%^You have entered into a small elven home.  "+
    	"%^ORANGE%^Small %^GREEN%^branches have "+
    	"been "+
	"%^ORANGE%^i%^GREEN%^n%^ORANGE%^t%^GREEN%^r%^ORANGE%^i%^GREEN%^c%^ORANGE%^a%^GREEN%^t%^ORANGE%^e%^GREEN%^l%^ORANGE%^y %^GREEN%^w%^ORANGE%^o%^GREEN%^v%^ORANGE%^e%^GREEN%^n "+
	"together to form the walls, floor, and ceiling with a swirling pattern.  "+
	"There are no corners in this room and the many "+
	"%^ORANGE%^circular windows%^GREEN%^ go from the ceiling to the floor.  "+
	"Four large "+
	"%^BOLD%^%^ORANGE%^w%^BLACK%^i%^ORANGE%^c%^BLACK%^k%^ORANGE%^e%^BLACK%^r%^ORANGE%^ c%^BLACK%^h%^ORANGE%^a%^BLACK%^i%^ORANGE%^r%^BLACK%^s%^RESET%^%^GREEN%^ "+
	"are placed throughout the room.  By one window is a large %^BOLD%^carafe "+
	"%^RESET%^%^GREEN%^filled with a %^YELLOW%^golden liquid %^RESET%^%^GREEN%^that "+
	"smells like tea.  Next to the carafe are small cups crafted from %^BOLD%^leaves.  "+
	"%^RESET%^%^GREEN%^In the corner sits a bed made from leaves and straw.\n"+
	"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The faint smell of %^BOLD%^%^YELLOW%^f%^RED%^l%^BLUE%^o%^YELLOW%^w%^RED%^e%^BLUE%^r%^YELLOW%^s%^RESET%^ %^ORANGE%^and the clean air tease your senses.");
    	set_listen("default","The sounds of the vale can be heard through the large windows.");
 	set_items(([
      	({"chair","chairs","wicker chairs","wicker chair"}) : "The chairs are large "+
      		"and are painstakingly woven into intricate patterns.  The chairs are "+
			"padded with soft leaves woven into the seats.\n",
		({"walls","wall","ceiling","floor"}) : "The walls are made from living "+
			"branches of the tree woven together in intricate patterns within "+
			"patterns.  The work is so fine and detailed it must have been done "+
			"by elven hands.\n",
		({"window","windows"}) : "The windows are large and circular stretching "+
			"from the ceiling to the floor.  The windows are set in such as "+
			"way as to allow all the light possible in during the day and as "+
			"much starlight and moonlight at night.  Much of the forest below "+
			"is visible through the windows as well as the sky above.\n",
		"carafe" : "The glass pitcher is filled with a golden liquid that smells "+
			"like tea.\n",
		({"bed","bedding"}) : "The bed looks very primitive at first glance, but "+
			"upon further examination it seems very functional and confortable at "+
			"the same time.  The straw and leaves are much softer that you first "+
			"thought.\n"
      ]));

    	set_door("door",IROOMS+"istree","out","wood key");
    	set_door_description("door","This door looks to be made of a single piece of "+
    		"wood, but you can discern no marks to show that the wood has been cut.  "+
    		"It is, almost, as if the door has grown to fit the opening exactly.");
   	set_string("door","open","You open the door noiselessly to the outside and "+
   		"see the trunk of the great maple tree facing you.\n");

     	set_exits(([
   		"out" : IROOMS+"istree"
 	]));

	set_search("ceiling","You find a trap door hidden within the intricate "+
		"patterns woven into the ceiling.\n");
	NUM = 0;
	uses = random(5) + 2;
}
void init() {
  	::init();
 	add_action("open_em","open");
 	add_action("close_em","close");
 	add_action("sit_em","sit");
 	add_action("pour_em","pour");
 	add_action("stand_em","stand");
}
int close_em(string str) {
    	if(!str) {
        	tell_object(TP,"Close what?");
        	return 1;
    	}
  	if((str == "trapdoor") || (str=="trap door")){
      	if(member_array("up",TO->query_exits()) != -1) {
     			tell_object(TP,"You push the trap door upward and latch it closed "+
     				"and it blends into the ceiling hiding it from view!\n");
     			tell_room(ETP,""+TPQCN+" pushes the trap door up and latches it "+
     				"and the door blends into the ceiling hiding it from view.\n",TP);
     			remove_exit("up");
     			(IROOMS+"isscry")->remove_exit("down");
            	return 1;
            }
     		tell_object(TP,"The trap door is already closed!\n");
    		return 1;
     }
}
int open_em(string str) {
    	if(!str) {
        	tell_object(TP,"Open what?");
        	return 1;
    	}
  	if((str == "trapdoor") || (str=="trap door")){
     		if(member_array("up",TO->query_exits()) != -1) {
        		tell_object(TP,"The trap door is already open! \n");
            	return 1;
            }
     		tell_object(TP,"You unlatch and open the hidden trap door in the ceiling.\n");
     		tell_room(ETP,""+TPQCN+" unlatches and opens a hidden trap door in "+
     			"the ceiling.\n",TP);
     		add_exit(IROOMS+"isscry","up");
     		(IROOMS+"isscry")->add_exit(IROOMS+"iscom","down");
     		return 1;
     }
}
int sit_em(string str) {
    	if(!str) {
        	tell_object(TP,"Sit on what???");
        	return 1;
    	}
  	if((str == "chair") || (str == "in chair") || (str == "on chair")){
  		if(NUM > 3){
  			tell_object(TP,"There are no empty chairs, maybe someone will let you "+
  				"sit on their lap.\n");
  			return 1;
  		}
		tell_object(TP,"You sit in a chair and you hear the woven strands "+
			"protest mildly.\n");
		tell_room(ETP,""+TPQCN+" sits down in a wicker chair.\n",TP);
		tell_object(TP,"Suprisingly the chair is more comfortable than "+
			"it looks.\n");
		NUM++;
		return 1;
     	}

}
int stand_em(string str) {
    	if(!str) {
        	tell_object(TP,"Stand up from what???");
        	return 1;
    	}
  	if((str == "chair") || (str=="up from the chair") || (str=="up from chair")){
     		if(NUM == 0){
     			tell_object(TP,"Nice trick...maybe you should sit in a chair "+
     				"before you try to stand up.\n");
     			return 1;
     		}
  		tell_object(TP,"You rise from your chair reluctantly.\n");
     		tell_room(ETP,""+TPQCN+" rises from a chair.\n",TP);
     		NUM = NUM - 1;
     		return 1;
     	}
}

int pour_em(string str) {
	string mname=TP->query_name();
    	if(!str) {
        	tell_object(TP,"Pour what???");
        	return 1;
    	}
  	if(str == "tea"){
	    	if((wizardp(TP)) || (mname == "isaiah")){
     			if(uses == 0){
     				tell_object(TP,"The carafe seems to be empty, guess you "+
     					"should have made more.\n");
     				tell_room(ETP,""+TPQCN+" picks up the carafe, notices it "+
     					"is empty and puts it back down.\n",TP);
     				return 1;
     			}
     			tell_object(TP,"You pick up the carafe and pour the tea into a cup "+
     				"without spilling a drop.\n");
     			tell_room(ETP,""+TPQCN+" picks up the carafe and pours a cup of "+
				"tea.\n",TP);
     			new(ISTUFF+"istea")->move(TO);
			TP->force_me("get ice tea");
			uses = uses - 1;
     			return 1;
     		}
     		tell_object(TP,"You reach for the carafe, but when you try to "+
     			"grasp the handle it seems to move just out of your reach.\n");
     		tell_room(ETP,""+TPQCN+" reaches for the carafe, but the carafe "+
     			"moves just out of "+TPQCN+"'s grasp.\n",TP);
     		return 1;
     	}
}

int is_human(object ob) {
   if((string)ob->query_race() == "human") return 1;
   else return 0;
}

void reset() {
   object *stuff, *keeping, thetarget;
   int i;
   ::reset();
   if(random(100) > 50) {
     stuff = all_living(TO);

     if(sizeof(stuff)) keeping = filter_array(stuff,"is_human",TO);
     if(sizeof(keeping)) {
       thetarget = keeping[random(sizeof(keeping))];
       i = roll_dice(1,20);
       switch(random(100)) {
         case 0..24:
           if(i > (int)thetarget->query_stats("dexterity") || i == 20) {
             tell_object(thetarget,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks "
"up and the tree creaks, limbs waving in the breeze. Suddenly and violently, "
"the %^RED%^branch %^ORANGE%^beneath your feet shifts and you find yourself "
"falling!%^RESET%^");
             tell_room(TO,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks up and "
"the tree creaks, limbs waving in the breeze. Suddenly and violently, the "
"%^RED%^branch %^ORANGE%^beneath "+thetarget->QCN+"%^RESET%^%^ORANGE%^'s feet "
"shifts and "+thetarget->QS+" tumbles from view!%^RESET%^",thetarget);
             tell_object(thetarget,"%^BOLD%^%^GREEN%^You tumble down the rock "
"face bouncing and cursing all the way!%^RESET%^");
             thetarget->do_damage("torso",roll_dice(6,6));
             thetarget->move("/d/dagger/derro/rooms/a1");
           }
           else {
             tell_object(thetarget,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks "
"up and the tree creaks, limbs waving in the breeze. Suddenly and violently, "
"the %^RED%^branch %^ORANGE%^beneath your feet shifts and you barely manage to "
"catch yourself to avoid falling!%^RESET%^");
             tell_room(TO,"%^ORANGE%^The %^CYAN%^wind %^ORANGE%^picks up and "
"the tree creaks, limbs waving in the breeze. Suddenly and violently, the "
"%^RED%^branch %^ORANGE%^beneath "+thetarget->QCN+"%^RESET%^%^ORANGE%^'s feet "
"shifts and "+thetarget->QS+" barely manages to catch "+thetarget->QO+"self to "
"avoid falling!%^RESET%^",thetarget);
           }
         break;

         case 25..49:
           if(i > (int)thetarget->query_stats("wisdom") || i == 20) {
             tell_object(thetarget,"%^BLUE%^A light creak is all the warning "
"given before a shower of %^GREEN%^leaves %^BLUE%^and debris rains down on "
"you from above, leaving you coated in chips of %^RED%^bark %^BLUE%^and "
"%^ORANGE%^sticky tree sap%^BLUE%^.%^RESET%^");
             tell_room(TO,"%^BLUE%^A light creak is all the warning given "
"before a shower of %^GREEN%^leaves %^BLUE%^and debris rains down on "
+thetarget->QCN+"%^BLUE%^ from above, leaving "+thetarget->QO+" coated in "
"chips of %^RED%^bark %^BLUE%^and %^ORANGE%^sticky tree "
"sap%^BLUE%^.%^RESET%^",thetarget);
             thetarget->set_paralyzed(11,"You're still trying to get free of "
"the twigs and tree-sap!");
           }
           else {
             tell_object(thetarget,"%^BLUE%^You notice a light creak in the "
"branches above your head, and step out of the way as a shower of "
"%^GREEN%^leaves %^BLUE%^and debris rains down from above.%^RESET%^");
             tell_room(TO,"%^BLUE%^You notice a light creak in the branches "
"above your head, and "+thetarget->QCN+"%^RESET%^%^BLUE%^ steps out of the "
"way as a shower of %^GREEN%^leaves %^BLUE%^and debris rains down from "
"above.%^RESET%^",thetarget);
           }
         break;

         case 50..74:
           if(i > (int)thetarget->query_stats("dexterity") || i == 20) {
             tell_object(thetarget,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, collecting you as "
"it swings past and sending you sprawling!%^RESET%^");
             tell_room(TO,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, collecting "
+thetarget->QCN+" as it swings past and sending "+thetarget->QO+
" sprawling!%^RESET%^",thetarget);
             thetarget->do_damage("torso",roll_dice(6,6));
             thetarget->set_tripped(2,"You're still trying to get back on your "
"feet.");
           }
           else {
             tell_object(thetarget,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, nearly collecting "
"you as it swings past!%^RESET%^");
             tell_room(TO,"%^CYAN%^A %^ORANGE%^sturdy branch "
"%^CYAN%^snaps out in the wind and whistles through the air, nearly collecting "
+thetarget->QCN+" as it swings past!%^RESET%^",thetarget);
           }
         break;

         case 75..99:
           if(i > (int)thetarget->query_stats("strength") || i == 20) {
             tell_object(thetarget,"%^GREEN%^Looking down, you realise your leg has become entangled in a nearby branch.  You're not sure quite how it got there, but it is now quite %^RED%^stuck%^GREEN%^!%^RESET%^");
             tell_room(TO,"%^GREEN%^Looking down, you realise "+thetarget->QCN+
"'s leg has become entangled in a nearby branch, and it is now quite "
"%^RED%^stuck%^GREEN%^!%^RESET%^",thetarget);
             thetarget->set_tripped(3,"You're still trying to pull your leg "
"free of the branch.");
           }
           else {
             tell_object(thetarget,"%^GREEN%^Looking down, you realise your "
"leg has become entangled in a nearby branch.  You're not sure quite how it "
"got there, but fortunately you are able to pull it free without much "
"trouble.%^RESET%^");
             tell_room(TO,"%^GREEN%^Looking down, you realise "+thetarget->QCN+
"'s leg has become entangled in a nearby branch.  Fortunately, "+thetarget->QS+ " is able to pull it free without much trouble.%^RESET%^",thetarget);
           }
         break;
       }
     }
   }
}
