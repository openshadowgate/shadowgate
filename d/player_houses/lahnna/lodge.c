#include <std.h>

inherit VAULT;
#define OWNERS ({"lahnna"})
int NUM,uses;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A spacious wooden lodge");
    set_long("A spacious wooden lodge\n"
"The north side of the %^ORANGE%^hardwood floor %^RESET%^is covered by a "
"%^GREEN%^thick green rug%^RESET%^. The southern half is made up of a dining "
"area and kitchen.  The floor itself looks neatly swept.  The dining room "
"set is made out of oak.  There is a large circular table surrounded by six "
"very large and sturdy chairs.  To the southeast is an open kitchen.  An "
"island and counter top are set up in the center of it which is made from "
"large neatly-cut stone slabs.  On the large wall-mounted cupboard, you see "
"several jars of herbs and spices on one shelf with plates, mugs and cutlery "
"on the others.  A %^BOLD%^%^BLACK%^wood-burning stove %^RESET%^is located "
"on the far corner.  A couple of large pots hang on the wall from pegs.  "
"The northern half of the lodge is a large living room.  Located at the "
"center of the northern wall is a large stone made fireplace with a large, "
"%^ORANGE%^mahogany-framed %^RESET%^%^BOLD%^painted portrait%^RESET%^ "
"hanging over it.  Positioned in front of the fireplace is a %^ORANGE%^low "
"walnut coffee table%^RESET%^.  You notice a bowl of "
"beer nuts on the table.  Two large matching %^BOLD%^%^GREEN%^emerald green "
"couches %^RESET%^are positioned on either side of the coffee table.  The "
"beamed ceiling is twelve feet high, making the room very open and spacious.  "
"In the northeast corner is a door that leads to the bedroom."
    );
    set_listen("default","The thick walls muffle most sounds from the outside.");
    set_smell("default","The scent of wood and cooking food fills your nostrils.");
    set_items(([
     ({"rug", "floor"}) : "%^GREEN%^A dark forest green rug stretches "
        "over most of the western half of the richly grained hardwood floor, "
        "blending well with the living room.",
     "stove" : "A large wood-burning stove.  Two cooking pots are currently over "
        "the flames.  You notice what looks to be soup and stew being cooked.",
     "fireplace" : "A large stone made fireplace.  Two or three long logs can be "
        "seen inside the fireplace.  You feel warmth coming from it.  There "
        "are symbols like the ones on the door outside carved in the mantel.",
     ({"couches", "couch"}) : "A pair of large long %^BOLD%^%^GREEN%^emerald-"
        "green couches %^RESET%^sit on opposite sides of the coffee table.  "
        "A %^BOLD%^%^BLACK%^large blanket of bear fur %^RESET%^is draped over "
        "the top of both couches.",
    "ceiling" : "The ceiling is very tall, probably twelve feet in height.  "
        "You notice the criss-crossing of various large log beams supporting "
        "the ceiling, roof, and the frame of the lodge.  Along the main log "
        "beam, which stretches across the middle from one side of the house "
        "to the other, large oil lamps hang down from the beam.  The lamps are "
        "placed at specific intervals to keep the room well lit.",
    ({"painting", "portrait"}) : "You see here a large painted portrait of a "
        "young, %^BOLD%^%^BLUE%^blue-eyed%^RESET%^, female firbolg with "
        "%^BOLD%^%^RED%^long, straight, fiery-red hair%^RESET%^.  She stands "
        "tall and proud, looking towards you.  Her hand rests comfortably on "
        "the hilt of a very long sword that's been impaled down into the "
        "%^ORANGE%^earthy ground%^RESET%^.  Besides wearing knee-high leather "
        "boots and thick padded clothes of %^GREEN%^dark green %^RESET%^and "
        "%^BOLD%^%^BLACK%^black%^RESET%^, a %^BOLD%^%^BLACK%^large cloak of "
        "black fur %^RESET%^is draped around her shoulders, held together by "
        "a %^GREEN%^circular green clasp%^RESET%^.  Thick mahogany wood frames "
        "this lovely large portrait.  Etched into the bottom part of the "
        "frame are the words 'Lahnna of the Fergus Clan'.",
    ({"nuts", "beer nuts" }) : "They look really tasty and you're tempted to "
        "grab a handful to snack on.",
    ] ));
    set_exits(([
       "out" : "/d/player_houses/lahnna/yard",
       "east" : "/d/player_houses/lahnna/bedroom"
    ] ));
   set_door("door","/d/player_houses/lahnna/yard","out");
   set_locked("door",1);
   set_door_description("door","This door is over ten ft. tall, obviously built "
      "for someone or something very large.");
   set_lock_description("door","lock","It appears to be a deadbolt type that you "
      "can lock or unlock from this side without a key.");
   set_door("oak door","/d/player_houses/lahnna/bedroom","east", 0);
//   set_locked("oak door",0);
   NUM = 0;
   uses = random(6)+6;
}

void init() {
   ::init();
   add_action("unlock_me","trace");
 	add_action("sit_em","sit");
 	add_action("snack_em","grab");
 	add_action("stand_em","stand");
}

void unlock_me(string str) {
   if(str != "symbols") return 0;
   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   find_object_or_load("/d/player_houses/lahnna/lodge");
   tell_object(TP,"You trace a pattern over the symbols and hear the lock click.");
   tell_room(ETP,""+TPQCN+" seems to trace a pattern over the symbols on the "
       "fireplace and you hear a soft click.",TP);
   if(!query_locked("door")) {
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/player_houses/lahnna/yard"->set_open("door",0);
      "/d/player_houses/lahnna/yard"->set_locked("door",1,"lock");
      return 1;
   }
   TO->set_locked("door",0);
   "/d/player_houses/lahnna/yard"->set_locked("door",0,"lock");
   return 1;
}

int sit_em(string str) {
  	if(!str) {
        	tell_object(TP,"Sit on what???");
        	return 1;
  	}
  	if((str == "couch") || (str == "on couch")){
  		if(NUM > 6){
  			tell_object(TP,"The couches seem to be full, but maybe someone will "
  			   "let you sit on their lap.\n");
  			return 1;
		}
		tell_object(TP,"You sit down on the plush couch and get comfortable.\n");
		tell_room(ETP,""+TPQCN+" sits down on the couch and looks very "
		  "comfortable.\n",TP);
		NUM++;
		return 1;
     	}
}

int stand_em(string str) {
    	if(!str) {
        	tell_object(TP,"Stand up from what???");
        	return 1;
    	}
  	if((str == "couch") || (str=="up") || (str=="up from couch")){
     		if(NUM == 0){
     			tell_object(TP,"Nice trick...maybe you should sit on the couch "+
     				"before you try to stand up.\n");
     			return 1;
     		}
  		tell_object(TP,"You rise from the couch and stretch.\n");
     		tell_room(ETP,""+TPQCN+" rises from the couch and stretches.\n",TP);
     		NUM = NUM - 1;
     		return 1;
     	}
}

int snack_em(string str) {
  	if(!str) {
     	tell_object(TP,"Grab what???");
     	return 1;
   }
  	if(str == "beer nuts" || str == "nuts" || str == "handful"){
		if(uses == 0){
     		tell_object(TP,"The bowl seems to be empty, you're too late.\n");
     		tell_room(ETP,""+TPQCN+" pokes around in the empty bowl "
     			  "looking disappointed.\n",TP);
     		return 1;
     		}
      tell_object(TP,"You fish around in the bowl and get a handful of the "
         "beer nuts.\n");
     	tell_room(ETP,""+TPQCN+" grabs a handful of beer nuts from the bowl.\n",TP);
     	new("/d/player_houses/lahnna/misc/bnuts")->move(TO);
		TP->force_me("get beer nuts");
		uses = uses - 1;
     	return 1;
     	}
}