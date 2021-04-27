//dining_room.c - Shrydelhi's dining room.  Coded by Circe 9/12/03
#include <std.h>
#include "shry.h"
inherit ROOM;
int NUM,uses,uses2;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("dining room");
   set_short("dining room ");
   set_long("This room is a perfect circle, surrounded on all sides by large "+
      "windows. Other than the stairs that lead up into the room and continue up to "+
      "another level, the room is completely bare with the exception of a very "+
      "large round table set in the center of the room, surrounded by several "+
      "chairs.  Opposite of the stairs a bar curves around, manned by a tiny "+
      "looking fairy that flits about."+
      "\n"
   );
   set_smell("default","You smell the scent of freshly baked goods and wines.");
   set_listen("default","You hear the flutter of the constantly moving wings.");
   set_items(([
      "windows" : "These windows line the walls and extend from the floor to the "+
         "ceiling, allowing plenty of light in.  From this level, the view of the "+
         "surrounding %^RESET%^%^GREEN%^forest %^RESET%^is absolutely stunning.",
      "table" : "A large round table sets in the middle of the room, supported by large green "+
         "%^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s "+
         "%^RESET%^that have been woven together to create a strong base for the "+
         "%^RESET%^%^ORANGE%^wooden surface, %^RESET%^and magically enchanted so that "+
         "they will never lose their form or color. The surface of the table is flat "+
         "and smooth, carved out of the finest of woods. The "+
         "%^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^v"+
         "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s of v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n"+
         "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s %^RESET%^have been carved as edging for the "+
         "surface, and add a delicate touch.",
       ({"chair", "chairs"}) : "Several hand carved chairs set around the table.  "+
         "The legs of the chairs have been carved to resemble %^GREEN%^v%^BOLD%^%^GREEN%^i"+
         "%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s %^RESET%^that circle up "+
         "out of the floor, allowing their %^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^a"+
         "%^RESET%^%^ORANGE%^v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s %^RESET%^to fan out to "+
         "support the seats, while the %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n"+
         "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s %^RESET%^continue up to come together and "+
         "create the back of the chair. The %^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e"+
         "%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s "+
         "%^RESET%^on the back of the chair open up in the center to reveal the carving of a "+
         "%^BOLD%^%^WHITE%^crescent moon %^RESET%^inlaid with %^BOLD%^%^WHITE%^s%^RESET%^i"+
         "%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^er.%^RESET%^",
      "bar" : "%^RESET%^%^GREEN%^A bar curves around the opposite end of the room, and looks "+
         "to be made from thick %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^e"+
         "%^RESET%^%^GREEN%^s that are woven together, creating a strong base for the flat "+
         "surface on top.  The surface of the bar itself is made of %^RESET%^%^ORANGE%^wood, "+
         "%^RESET%^%^GREEN%^intricately carved with the images of %^GREEN%^v%^BOLD%^%^GREEN%^i"+
         "%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s and %^RESET%^%^GREEN%^l"+
         "%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^GREEN%^e"+
         "%^RESET%^%^GREEN%^s lining the outer edges."
   ]));
   set_exits(([
      "up" : SHRY"bedroom",
      "down" : SHRY"living_room"
   ]));
   NUM = 0;
   uses = random(4) + 4;
   uses2 = random(4) + 4;
}

void init(){
   ::init();
   add_action("sit","sit");
   add_action("stand","stand");
   add_action("feed_em","prepare");
   add_action("pour_em","pour");
}

int sit(string str) {
   if(str != "chair" && str != "on chair") {
      tell_object(TP,"You can't sit there!");
      return 1;
   }
   else{
      if(NUM > 5){
         tell_object(TP,"All the chairs are filled!  You'll have to stand.");
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^GREEN%^The carved wooden chair seems to mold itself to you as you sit.");
      tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" takes a seat in one of the wooden chairs around the table.",TP);
      NUM++;
      return 1;
   }
}

int stand(string str){
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
      tell_object(TP,"%^GREEN%^The chair seems to relax around you as you stand up.");
      tell_room(ETP,"%^GREEN%^"+TPQCN+"'s chair seems to move slightly as "+TP->query_subjective()+" stands.",TP);
     	NUM = NUM - 1;
     	return 1;
      }
}

int pour_em(string str) {
	string mname=TP->query_name();
    	if(str != "nectar") {
        	tell_object(TP,"Pour what???");
        	return 1;
    	}
      else{
	    	if((wizardp(TP)) || (mname == "shrydelhi")){
     			if(uses == 0){
     				tell_object(TP,"The leaf pitcher seems to be empty.  You'll "+
                           "have to gather more.");
     				tell_room(ETP,""+TPQCN+" picks up a leaf pitcher, frowns slightly "+
                           "and puts it back down.",TP);
     				return 1;
     			}
     			tell_object(TP,"You pick up the delicate leaf pitcher and pour "+
                     "the golden nectar into matching leaf cups.");
     			tell_room(ETP,""+TPQCN+" picks up a leaf pitcher and pours a "+
                     "golden liquid into a matching leaf cup.",TP);
     			new(OBJ"shry_nectar")->move(TO);
			TP->force_me("get nectar");
			uses = uses - 1;
     			return 1;
     		}
     		tell_object(TP,"You reach for the pitcher but it folds under your hands.");
     		tell_room(ETP,""+TPQCN+" reaches for the pitcher, but it folds under "+
               ""+TP->query_possessive()+" hands.",TP);
     		return 1;
     	}
}

int feed_em(string str) {
	string mname=TP->query_name();
    	if(str != "fruit") {
        	tell_object(TP,"Prepare what???");
        	return 1;
    	}
      else{
	    	if((wizardp(TP)) || (mname == "shrydelhi")){
     			if(uses2 == 0){
     				tell_object(TP,"You find no more fresh fruit chilling at the bar.");
     				tell_room(ETP,""+TPQCN+" searches around at the bar and sighs.",TP);
     				return 1;
     			}
     			tell_object(TP,"You carefully arrange the chilled fruit on a beautiful "+
                     "platter made of a live oak leaf.");
     			tell_room(ETP,""+TPQCN+" arranges several pieces of fresh fruit on an oak leaf.",TP);
     			new(OBJ"shry_fruit_platter")->move(TO);
			TP->force_me("get fruit");
			uses2 = uses2 - 1;
     			return 1;
     		}
     		tell_object(TP,"You can't seem to find any place where fruit is kept.");
     		tell_room(ETP,""+TPQCN+" looks confused as "+TP->query_subjective()+" searches the bar.",TP);
     		return 1;
     	}
}

void reset()
{
        ::reset();
        if(!present("sprite")) {
                new(MON"shry_fairy")->move(TO);
        }
}
