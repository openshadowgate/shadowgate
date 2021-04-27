//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Sitting room");
   set_short("sitting room");
   set_long(
   	"%^RESET%^"+
   	"This room is large and lavishly decorated.  The walls are made "+
   	"of %^ORANGE%^polished oak panels%^RESET%^, each carefully "+
   	"designed and carved. They are lined with pictures, statues, "+
   	"and %^YELLOW%^golden candle holders%^RESET%^, which provide the "+
   	"room with ample lighting.  There is a %^ORANGE%^large oak coffee "+
   	"table %^RESET%^in the center of the room, surrounded by a "+
   	"%^ORANGE%^polished oak sofa %^RESET%^and two chairs, with "+
   	"soft satin cushions. The fabric displays a beautiful pattern "+
   	"with deep shades of %^BOLD%^%^MAGENTA%^purple%^RESET%^, "+
   	"%^BOLD%^%^BLUE%^blue%^RESET%^, %^YELLOW%^gold%^RESET%^, and "+
   	"%^BOLD%^%^RED%^crimson%^RESET%^. An ornate rug covers nearly "+
   	"the entire floor, and matches the rich shades of the furniture. "+
   	"Behind the furniture, towards the corner of the room, there is a "+
   	"piano made from %^BOLD%^%^BLACK%^polished black wood%^RESET%^. A "+
   	"large fireplace takes up much of the eastern wall, and above it "+
   	"sits a huge mirror with a %^YELLOW%^golden frame%^RESET%^.  To your "+
   	"right, two steps lead into an alcove, where large windows permit "+
   	"you to look out over the sea.  Heavy %^BOLD%^%^RED%^crimson velvet "+
   	"curtains %^RESET%^are pulled away from the windows, allowing light "+
   	"to enter the room.  The %^ORANGE%^oak floor %^RESET%^and walls of "+
   	"the alcove are covered with %^BOLD%^%^GREEN%^fresh-scented, exotic "+
   	"plants%^RESET%^.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","You smell the wonderful scent of exotic plants and flowers.");
   set_listen("default","The room is warm and quiet.");
   set_items(([
		({"picture","pictures"}) : "Although you cannot be certain, the "+
			"pictures seem to portray the creation-story of Elves.\n",
		({"statue","statues"}) : "The statues rest in small alcoves cut into "+
			"the walls. They are made of white marble, and depict elves "+
			"engaged in various acts, from instrument playing to battling.\n",
		({"candleholder","candleholders"}) :  "The candleholders are golden "+
			"and very stunning. The flames from the white candles dances "+
			"upon the walls and summon shadows from the corners of the "+
			"room.\n",
		"coffee table" : "The table sits in the middle of the room, and is "+
			"made of highly polished oak.\n",
		"sofa" :  "The sofa is fairly small, but can comfortably seat four.  "+
			"The base is made of highly polished oak, and is "+
			"covered with thick velvet cushions.",
		({"chair","chairs"}) : "The base of the chairs are made of highly "+
			"polished oak, and covered with thick velvet cushions.\n",
		"rug" : "This woven carpet is stunning. The threads weave around "+
			"each other to form a beautiful, intricate pattern. The rug "+
			"is so beautiful, it could only be the work of Elven magic "+
			"that holds it together.\n",
		"piano" : "You can see your reflection in the polished black wood "+
			"of the piano.  The keys have been delicately carved from "+
			"ivory. A black bench sits in front of the piano.\n",
		"fireplace" :  "The fireplace is very large and made from marble.  "+
			"The sides are carved into a delicate design, unlike anything "+
			"you have ever seen.\n",
		"mirror" : "You see your reflection in the mirror.\n",
		"alcove" : "The area is large enough that you can easily access the "+
			"window.  It is lined with plants and exotic flowers of various "+
			"colors."
	]));

  	set_door("oak door",DROOMS+"foyer","west","marble key");
   set_door_description("oak door","The door is polished and made from oak.");
   set_string("oak door","open","You open the door into the foyer.\n");

  	set_exits(([
		"west" : DROOMS+"foyer"
   ]));
}
void init() {
  	::init();
  	add_action("sit","sit");
  	add_action("light","light");
  	add_action("play","play");
}
int sit(string str) {
   if(!str) {
     	tell_object(TP,"Sit where?");
     	return 1;
   }
  	if(str == "sofa" || str == "on sofa"){
     	tell_object(TP,"%^BOLD%^You sink into the soft cushions and "+
      	"stretch out.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" plops down on the comfortable sofa, "+
        	"looking quite content.\n%^RESET%^",TP);
		return 1;
   }else if(str == "chair" || str == "on chair"){
      tell_object(TP,"%^BOLD%^You relax back into the comfortable "+
      	"chair.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sighs with contentment "+
       	"as "+TP->query_subjective()+" sits down.\n%^RESET%^",TP);
		return 1;
   }else if(str == "bench" || str == "on bench"){
      tell_object(TP,"%^BOLD%^You sit down on the bench and run your fingers over "+
      	"the piano keys.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sits down on the piano "+
            	"bench.\n%^RESET%^",TP);
		return 1;
	}
}
int light(string str) {
  	if(!str) {
    	tell_object(TP,"Light what?");
     	return 1;
   }
  	if(str == "fire" || str == "a fire" || str == "the fire"){
    	tell_object(TP,"%^BOLD%^%^YELLOW%^You bend down into the fireplace "+
     		"and light the dry wood.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" bends down and lights "+
        	"the dry wood in the fireplace.  The room lights up as large "+
        	"flames dance within.\n%^RESET%^");
		return 1;
   }
}
int play(string str) {
	string mname=TP->query_name();

   if(!str) {
     	tell_object(TP,"Play what?");
     	return 1;
   }
  	if(str == "piano" || str == "the piano"){
    	if(mname == "vaser"){
      	tell_object(TP,"%^BOLD%^%^CYAN%^You start to play at the piano "+
        		"and music beyond your skill begins to issue forth.\n%^RESET%^");
         tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" plays the piano and "+
         	"fills the room with clear and beautiful notes "+
         	"of song.\n%^RESET%^",TP);
			return 1;
      }else{
      	tell_object(TP,"%^CYAN%^You start to play at the piano and clear "+
      		"notes ring out, but without the form of a music.\n%^RESET%^");
        	tell_room(ETP,"%^CYAN%^"+TPQCN+" hammers at the keys of the piano "+
        		"and notes ring out, but no real music issues forth.\n%^RESET%^",TP);
			return 1;
		}
	}
}
