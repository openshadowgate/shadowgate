//Coded by Diego//
//Updated by Circe 1/29/04

#include <std.h>
#include "../lusell.h"

inherit VAULT;
int uses;

void create(){
   ::create();
      set_name("dining");
	set_property("indoors",1);
	set_property("light",2);
      set_terrain(STONE_BUILDING);
      set_travel(PAVED_ROAD);
	set_short("dining hall");
	set_long(
         "%^BOLD%^%^MAGENTA%^The room is both ostentatious and "+
         "elaborate in its presentation.  A long %^RESET%^%^ORANGE%^"+
         "table %^BOLD%^%^MAGENTA%^dominates the south wall of this "+
         "large room.  The %^RESET%^%^ORANGE%^table %^BOLD%^%^MAGENTA%^"+
         "will seat about twenty to thirty people easily and is made "+
         "from a %^RESET%^%^ORANGE%^stout wood%^BOLD%^%^MAGENTA%^.  "+
         "Above the table hang three %^YELLOW%^chandeliers%^MAGENTA%^.  "+
         "The room seems to be fitting for use as a dining hall, "+
         "conference room, and ballroom.  In the north wall of the room "+
         "is a huge %^RED%^fire%^YELLOW%^p%^RED%^lace %^MAGENTA%^capable "+
         "of burning six foot logs and would provide ample %^RESET%^%^RED%^"+
         "wa%^BOLD%^%^YELLOW%^r%^RESET%^%^RED%^mth %^BOLD%^%^MAGENTA%^during "+
         "winter nights.%^RESET%^\n"
	);
	set_smell("default","The room smells of furniture polish and pine.");
	set_listen("default","You hear the movement of people in the distance.");
	set_items(([
		"table" : "%^RESET%^%^ORANGE%^The table is immense and made from "+
                  "%^RESET%^oak%^ORANGE%^.  The surface of the table has been "+
                  "finished and polished to a high shine.  The table itself "+
                  "will sit thirteen people to a side and one at each end.  "+
                  "It has the letters %^BOLD%^%^BLACK%^F A I T H %^RESET%^"+
                  "%^ORANGE%^burned into the wood down the center.",
		"fireplace" : "The fireplace is long and could easily accommodate "+
			"a six foot log.  There are rods driven into the stone of the "+
			"firepit with a fork at the top.  The rods can hold another bar "+
			"so that a hog could be roasted right in the room for instance.\n",
		({"chairs","chair"}) : "The chairs look to be comfortable and have red "+
			"velvet covered seats and high back with arms to rest on.\n",
		"chandelier" : "The chandeliers look to be made of glass and "+
			"crystals.  Each chandelier holds several candles and the "+
			"light from each is reflected and enhanced by each piece of "+
			"glass and crystal it touches.\n"
   ]));
  	set_exits(([
		"west" : LROOMS+"hall3"
	]));

  	set_door("door",LROOMS+"hall3","west","ruby key");
   set_door_description("door","The door is made from black walnut "+
   	"and has elaborate carvings about the lintel.\n");
   set_string("door","open","The door opens into a large hallway.\n");
   set_open("door",1);

	if(random(2)){
		switch(random(1)){
			case (0):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"sergeant"));
  				break;
  			case (1):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  			default :
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  		}
  	}
   uses = random(5)+6;
}

void init(){
   ::init();
   add_action("clap_em","clap");
   add_action("read_em","read");
   add_action("order_em","order");
}

int clap_em(string str){
   string mname=TP->query_name();
   if(str != "hands"){
      tell_object(TP,"Umm...you can't clap that.  Try your hands?");
      return 1;
   }
   if((wizardp(TP)) || (mname == "lusell")){
      tell_object(TP,"You clap your hands twice and a serving wench "+
         "appears from a side room, bowing to you.");
      tell_room(ETP,"As "+TPQCN+" claps "+TP->QP+" hands twice, a serving "+
         "wench appears from a side room and bows to "+TP->QO+".",TP);
      tell_room(ETP,"%^MAGENTA%^The serving wench says%^RESET%^: How may I serve you?");
      new(LMON"lusell_wench")->move(TO);
      return 1;
   }
   tell_object(TP,"You clap your hands.");
   tell_room(ETP,""+TPQCN+" claps "+TP->QP+" hands.",TP);
   return 1;
}

int read_em(string str){
   if(!present("serving wench")){
      tell_object(TP,"The servant does not seem to be here.");
      return 1;
   }
   if(str != "list" && str != "menu" && str != "the menu" && str != "the list"){
      tell_object(TP,"You could read the menu the serving wench is carrying.");
   return 1;
   }
   tell_object(TP,"The serving wench shows you a black-bordered card with today's selections.  You may order:\n"+
      "       %^MAGENTA%^An elegant formal dinner%^RESET%^\n"+
      "       %^GREEN%^An appetizer plate%^RESET%^\n"+
      "       %^BOLD%^%^CYAN%^Fresh water%^RESET%^\n"+
      "       %^YELLOW%^Fine brandy%^RESET%^");
   tell_room(ETP,""+TPQCN+" examines the menu carried by the serving wench.",TP);
   return 1;
}

int order_em(string str){
   string mname=TP->query_name();
   if(!present("serving wench")){
      tell_object(TP,"The serving wench does not seem to be here.");
      return 1;
   }
   if(!str){
      tell_object(TP,"The serving wench looks momentarily startled as she tries to figure out what to serve you.");
      return 1;
   }
   if((wizardp(TP)) || (mname == "lusell")){
      if(uses == 0){
         tell_object(TP,"The serving wench turns red in the face as she tells you the kitchen has run out.");
         tell_room(ETP,"The serving wench blushes deeply and whispers to "+TPQCN+".",TP);
         return 1;
      }
      if(str == "dinner" || str == "formal dinner" || str == "elegant formal dinner" || str == "An elegant formal dinner"){
         tell_object(TP,"The serving wench bows her head in acknowledgement and "+
            "hurries off to the kitchen, returning with your order.");
         tell_room(ETP,"The serving wench bows her head and hurries off to the kitchen "+
            "returning with "+TPQCN+"'s order.",TP);
         new(LOBJ"lusell_dinner")->move(TO);
         TP->force_me("get food");
         uses = uses - 1;
         return 1;
      }
      if(str == "appetizer" || str == "plate" || str == "appetizer plate"){
         tell_object(TP,"The serving wench bows her head in acknowledgement and "+
            "hurries off to the kitchen, returning with your order.");
         tell_room(ETP,"The serving wench bows her head and hurries off to the kitchen "+
            "returning with "+TPQCN+"'s order.",TP);
         new(LOBJ"lusell_appetizer")->move(TO);
         TP->force_me("get food");
         uses = uses - 1;
         return 1;
      }
      if(str == "water" || str == "fresh water" || str == "Fresh Water"){
         tell_object(TP,"The serving wench bows her head in acknowledgement and "+
            "hurries off to the kitchen, returning with your order.");
         tell_room(ETP,"The serving wench bows her head and hurries off to the kitchen "+
            "returning with "+TPQCN+"'s order.",TP);
         new(LOBJ"lusell_water")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
      if(str == "brandy" || str == "fine brandy" || str == "Fine brandy"){
         tell_object(TP,"The serving wench bows her head in acknowledgement and "+
            "hurries off to the kitchen, returning with your order.");
         tell_room(ETP,"The serving wench bows her head and hurries off to the kitchen "+
            "returning with "+TPQCN+"'s order.",TP);
         new(LOBJ"lusell_brandy")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
   }
   tell_object(TP,"The serving wench answers only to the Lady of the house.");
   return 1;
}

