#include <std.h>
//change lock difficulty on picking

inherit VAULT;
#define OWNERS ({"lahnna"})

void squishing(object tp, int num);
int set;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("clearing in the woods");
    set_short("A clearing in the woods");
    set_long( (: TO,"ldesc" :) );
    set_items(([
       "logs" : "Huge pile of long, large logs are stacked six feet high "+
          	"near the chopping block and above the door on the roof.",
       ({"block", "stone axe"}) : "A large stone axe is embedded into the "
           "large chopping block. A few small pieces of wood still remain on "
           "top of the block.",
       ({"tree","trees"}) : "Some of the trees nearby are over a hundred ft. "
          "tall.  In the branches overhead in a few near the front of the lodge, "
          "you notice some vines hanging curiously.",
       "vines" : "In looking closer, you notice some logs hanging among the "
          "branches and vines.",
    ] ));
    set_exits(([
       "lodge" : "/d/player_houses/lahnna/lodge",
       "southeast" : "/d/dagger/road/road90"
    ] ));
   set_door("door","/d/player_houses/lahnna/lodge","lodge","lahnna key");
   set_locked("door",1,"lock");
   lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("rare"),"lock");
   set_smell("default","The scent of pine from the great evergreens is quite "
      "strong.");
   set_listen("default","You can often hear the call of a hawk in the distance "
      "over the normal forest sounds.");
   set_trap_functions(({"lock"}),({"squash_me"}),({"pick"}));
   set = 1;
}

int squash_me(string str){
	if(interactive(TP)){
		toggle_trap("lock");
		tell_object(TP,"As you attempt to pick the lock you hear an "+
			"ominous click and then a rumble from up above!");
		tell_room(ETP,""+TPQCN+" bends down to the lock and then freezes "+
			"when a click sounds from the lock and a rumble sounds from above!",TP);
		TP->force_me("emote %^YELLOW%^gulps!%^RESET%^");
        	TP->set_paralyzed(5000,"You are too busy dodging logs!");
        	squishing(TP,0);
        	set = 0;
        	return 1;
     	}
}

void init() {
   ::init();
   add_action("unlock_me","trace");
   add_action("set_trap", "stack");
}

void unlock_me(string str) {
   if(str != "symbols") return 0;
   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   find_object_or_load("/d/player_houses/lahnna/lodge");
   tell_object(TP,"You trace a pattern over the symbols and hear the lock click.");
   tell_room(ETP,""+TPQCN+" seems to trace a pattern over the symbols on the "
       "door and you hear a soft click.",TP);
   if(!query_locked("door")) {
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/player_houses/lahnna/lodge"->set_open("door",0);
      "/d/player_houses/lahnna/lodge"->set_locked("door",1);
      return 1;
   }
   TO->set_locked("door",0);
   "/d/player_houses/lahnna/lodge"->set_locked("door",0);
   return 1;
}

void set_trap(string str) {
   if(str != "logs") return;
   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   tell_object(TP,"You pull a rope to reset the braces on the roof.  Rope "
       "rigging falls into place, allowing you to begin hoisting the logs "
       "back to the rooftop.");
   tell_room(ETP,TPQCN+" pulls a rope to reset the braces on the roof.  Rope "
       "rigging falls into place, and "+TP->query_objective()+" begins "
       "hoisting logs to the rooftop.",TP);
 	TP->set_paralyzed(50,"You are too busy hoisting logs!");
   if(!random(50)) {
		tell_object(TP,"%^BOLD%^%^RED%^Something goes awry and a few of the "+
			"logs come crashing down on you!");
		tell_room(ETP,"%^RED%^Something seems to go awry and a few of the "
		   "logs come crashing back down on "+TPQCN+".",TP);
		TP->do_damage("torso",roll_dice(1,10));
		TP->do_damage("torso",roll_dice(1,20));
		TP->do_damage("torso",roll_dice(1,10));
		TP->do_damage("torso",roll_dice(1,20));
		TP->add_attacker(TO);
		TP->continue_attack();
   	TP->remove_attacker(TO);
		return;
   }
   if(!trapped("door"))  toggle_trap("door");
   set = 1;
   return;
}

void squishing(object tp,int num){
	switch(num){
      	case(0):
      		if((int)TP->query_stats("dexterity")>random(25)){
				tell_object(TP,"%^BOLD%^%^CYAN%^You start to dodge, "+
					"tuck ,and roll, and miss taking several logs in "+
					"the chest, but you did not survive unscathed.");
				tell_room(ETP,"%^RED%^Logs begin to roll down from the "
				   "roof!  "+TPQCN+" starts dodging like "
				   +TP->query_possessive()+" head was on "
					"fire and the ass was catching!\n",TP);
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
			}else{
				tell_room(ETP,"%^BOLD%^%^RED%^Logs start falling from the "+
					"roof like rain and "+TPQCN+" has no umbrella!",TP);
				tell_object(TP,"%^BOLD%^%^RED%^Several logs roll from the "+
					"roof and hit you with great force!");
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
			}
			TP->add_attacker(TO);
			TP->continue_attack();
			TP->remove_attacker(TO);
			break;
    		case(1):
      		if((int)TP->query_stats("dexterity")>random(25)){
				tell_object(TP,"%^BOLD%^%^CYAN%^You almost let your "+
					"guard down, but then you notice another bunch "+
					"of logs falling your way.");
				tell_room(ETP,""+TPQCN+" starts dodging as more logs "+
					"roll from the roof!",TP);
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
			}else{
				tell_room(ETP,"%^BOLD%^%^RED%^More logs fall from the "+
					"roof onto "+TPQCN+"!",TP);
				tell_object(TP,"%^BOLD%^%^RED%^More logs roll from "+
					"the roof smashing into your body!");
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
			}
			TP->add_attacker(TO);
			TP->continue_attack();
			TP->remove_attacker(TO);
			break;
            case(2):
      		if((int)TP->query_stats("dexterity")>random(25)){
				tell_object(TP,"%^BOLD%^%^CYAN%^Another wave of logs "+
					"drop from the roof of the lodge, but you manage "+
					"to dodge much of the damage.");
				tell_room(ETP,""+TPQCN+" continues to dodge logs, "+
					"but looks to be tiring!",TP);
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
			}else{
				tell_room(ETP,"%^BOLD%^%^RED%^Logs continue to roll "+
					"from the roof onto the hapless thief!",TP);
				tell_object(TP,"%^BOLD%^%^RED%^The logs fall into "+
					"you with crushing force.  When will it end??");
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
			}
			TP->add_attacker(TO);
			TP->continue_attack();
			TP->remove_attacker(TO);
			break;
           	case(3):
      		if((int)TP->query_stats("dexterity")>random(25)){
				tell_object(TP,"%^BOLD%^%^CYAN%^More logs fall from "+
					"the roof toward you.  You know you cannot dodge "+
					"them much longer as you are tiring.");
				tell_room(ETP,""+TPQCN+" dodges another wave of logs, "+
					"but not without "+
					"receiving "+TP->query_possessive()+" lumps!",TP);
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
				TP->do_damage("torso",roll_dice(1,10));
			}else{
				tell_room(ETP,"%^BOLD%^%^RED%^More logs fall.  It will "+
					"be a miracle if there is anything left of "+TPQCN+"!",TP);
				tell_object(TP,"%^BOLD%^%^RED%^More logs roll from the "+
					"roof onto you hitting you with incredible force!");
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
				TP->do_damage("torso",roll_dice(1,20));
			}
			TP->add_attacker(TO);
			TP->continue_attack();
			TP->remove_attacker(TO);
			break;
            case(4):
 			tell_room(ETP,"%^BOLD%^%^MAGENTA%^Logs stop falling from above "+
 				"and eventually rest on the ground on top of and "+
 				"around what is left of "+TPQCN+"!",TP);
           		tell_object(TP,"%^BOLD%^%^GREEN%^You lie dazed and tired as a "+
           			"forest of logs lies about you and on top of you.");
                  TP->set_paralyzed(0);
   			tell_room(("/d/player_houses/lahnna/lodge"),"%^BOLD%^%^YELLOW%^You "+
   				"hear a loud crash and uproar from just outside the door.\n");
                 return;
   	}
    	num++;
    	call_out("squishing",0,tp,num);
    	return;
}

void reset(){
   ::reset();
   if(!trapped("door") && !random(5)) {
      toggle_trap("door");
      set = 1;
   }
}

string ldesc() {
   if(!set) {
//      if( (: (TO, "trapped", "door") :) ) {
      return("In the middle of this large clearing, you see a large lodge "
"made out of giant wooden logs.  A stone chimney can be seen poking out of the "
"west side of the roof.  Small rectangular stone slabs are lined up all around the "
"base of the house.  You notice vegetation and plants have been cleared a "
"couple of feet away from the house.  A huge pile of logs lies near the back, "
"about five feet away from the house, with a %^ORANGE%^large chopping block " "%^RESET%^and a stone axe nearby.  Oddly, there are also a number of logs "
"strewn about in front of the door.  Glancing at the ten feet tall door, you "
"notice a large "
"stone knocker located at the center with a few %^RED%^carved symbols %^RESET%^"
"right above it.  %^GREEN%^Tall, dense trees %^RESET%^and many small plants "
"surround this large clearing.\n");
    }else {
    return("In the middle of this large clearing, you see a large lodge made "
"out of giant wooden logs.  A stone chimney can be seen poking out of the west "
"side of the roof.  Small rectangular stone slabs are lined up all around the "
"base of the house.  You notice vegetation and plants have been cleared a "
"couple of feet away from the house.  A huge pile of logs lies near the back, "
"about five feet away from the house, with a %^ORANGE%^large chopping block ""%^RESET%^and a stone axe nearby.  There are, also, many logs piled on the "
"roof above the door.  Glancing at the ten feet tall door, you notice a large "
"stone knocker located at the center with a few %^RED%^carved symbols %^RESET%^"
"right above it.  %^GREEN%^Tall, dense trees %^RESET%^and many small plants "
"surround this large clearing.\n");
   }
}
