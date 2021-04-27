//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Study");
   set_short("study");
   set_long(
   	"%^RESET%^"+
   	"Large oak bookshelves line the walls of the study, "+
   	"holding both ancient and recent literature.  The %^ORANGE%^oak "+
   	"floor %^RESET%^is clean and highly polished.  In a far corner, "+
   	"a large, intricately carved %^ORANGE%^oak desk %^RESET%^and a "+
   	"matching chair is placed next to the wooden wall.  Comfortable "+
   	"chairs and small %^ORANGE%^wooden tables %^RESET%^are scattered "+
   	"about the area.  A %^BOLD%^%^BLACK%^large black book%^RESET%^, "+
   	"lined with %^YELLOW%^gold%^RESET%^, sits upon a pedestal. "+
   	"%^GREEN%^Green %^RESET%^plants add color and a fresh scent "+
   	"to the room.  Along the eastern wall, two large glass doors "+
   	"flood the room with light and allow access to the balcony.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The smell of ancient parchment hangs lightly in the air.");
   set_listen("default","You hear a faint breeze blowing outside.");
   set_items(([
		({"shelf","shelves"}) : "The wooden shelves line the walls and "+
			"are filled with books and scrolls of many ages.\n",
		({"book","books"}) : "Some of the books appear so ancient, you "+
			"fear they may crumble to ashes if you touch them. "+
			"Others appear fairly new.\n",
		"pedestal" : "This is a large wooden pedestal. Upon it is a "+
			"beautiful book, black in color and lined with gold.  "+
			"On the cover, inscribed in gold is the title: Exploits "+
			"of a Monster Hunter.\n"
	]));

   set_door("door",DROOMS+"land5","west","marble key");
   set_door_description("door","The door is made of polished oak.");
   set_string("door","open","You open the door onto the fifth landing.\n");

   set_door("glass door",DROOMS+"balc","east","marble key");
   set_door_description("glass door","The door is made of glass crystal.");
   set_string("glass door","open","You open the door onto the balcony.\n");

   set_exits(([
		"west" : DROOMS+"land5",
		"east" : DROOMS+"balc"
   ]));
}
void init() {
  	::init();
  	add_action("read","read");
  	add_action("clap_em","clap");
}
int read(string str) {
  	if(!str) {
        	tell_object(TP,"Read what?");
        	return 1;
    	}
  	if(str == "book"){
     		write("%^BOLD%^%^BLACK%^"+
			"Exploits of a Monster Hunter\n\n%^MAGENTA%^This book contains "+
			"pages upon pages of illustations and notes about all manner "+
            "of supernatural creature demonic, celestial, fey, and "+
            "everything in between.\n%^RESET%^");
     	return 1;
     	}
}
int clap_em(string str) {
	object ob;

  	if(!str) {
     	tell_object(TP,"You applaud!");
     	return 1;
   }
  	if(str == "once"){
     	tell_object(TP,"%^BOLD%^You clap your hands together loudly "+
     		"one time.\n%^RESET%^");
        tell_room(ETP,"%^BOLD%^"+TPQCN+" claps "+
        	""+TP->query_possessive()+" hands together once.\n%^RESET%^",TP);
        if(!present("alcove ball")){
            tell_room(ETP,"In the far corner, near the desk the wall slides away "+
           	"revealing a well made, expensive crystal ball set in an alcove.\n");
		    ob = new("/d/magic/obj/crystal_ball");
            ob->add_id("alcove ball");
            ob->move(TO);
        }
 		return 1;
  	}else if(str == "twice"){
      tell_object(TP,"%^BOLD%^You clap your hands together loudly twice.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" claps "+
        	""+TP->query_possessive()+" hands together twice.\n%^RESET%^",TP);
      if(ob=present("alcove ball")) {
          tell_room(ETP,"The wall slides shut concealing the crystal ball once again.\n");
          destruct(ob);
      }
		return 1;
  	}else{
     	tell_object(TP,"%^BOLD%^You clap your hands "+str+".\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" claps "+
        	""+TP->query_possessive()+" hands "+str+".\n%^RESET%^",TP);
		return 1;
	}
}
