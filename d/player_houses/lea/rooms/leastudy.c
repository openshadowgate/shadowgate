//Coded by Diego//
//finish chest if she stays around//

#include <std.h>
#include "../lea.h"
inherit VAULT;

int FLAG;

void create(){
    ::create();
    set_short("Study");
    set_long(
	"%^RESET%^%^ORANGE%^"+
    	"This is a study that, also, seems to double as a library.  There is a wooden desk "+
	"that sits in the corner near a set of double %^BOLD%^%^CYAN%^glass "+
	"%^RESET%^%^ORANGE%^doors.  Along the wall behind the desk is a large bookshelf "+
	"filled from top to bottom with books.  There is a braided rug on the polished "+
	"hardwood floor.  The rug lays in front of the large %^BOLD%^%^BLACK%^stone "+
	"%^RESET%^%^ORANGE%^fireplace.  There are two oversized chairs facing the fireplace "+
	"with a small table between them. \n"+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Hints of wood smoke and leather books fill the air.");
    set_listen("default","Mountain breezes gently tap at the glass doors.");
    set_items(([
      "desk" : "\n%^RESET%^This is a small desk made of a pale %^BOLD%^%^WHITE%^white "+
		"%^RESET%^wood.  The desk appears to have been intricately carved from one "+
		"solid piece of wood with an unusual design carved around the edges.  On top "+
		"of the desk rests a few books, a stack of parchment, and an ink well with a "+
		"writing quill standing in it.  On the corner of the desk is a vase with a "+
		"single %^BOLD%^%^RED%^red %^GREEN%^rose%^RESET%^.\n",
	"rug" : "\n%^RESET%^This is a beautifully hand braided rug of many "+
	     "%^BOLD%^%^GREEN%^c%^RED%^o%^BLUE%^l%^WHITE%^o%^YELLOW%^r%^VIOLET%^s%^RESET%^.  "+
		"It lays on the %^ORANGE%^wooden floor in front of the fireplace to take "+
		"advantage of the warm %^RED%^fire.  It appears to be a good place to curl up "+
		"and read on those cold days here in the mountains.\n",
	"table" : "\n%^RESET%^This small table rests between two large chairs and appears to "+
		"be dwarfed in comparison.  The table is made from the same pale "+
		"%^BOLD%^%^WHITE%^wood %^RESET%^that composes the desk.  Sitting upon the "+
		"table you see a small %^ORANGE%^wooden%^RESET%^ chest with a "+
		"%^BOLD%^%^YELLOW%^gold %^RESET%^lock.  Next to the chest is a diary.  On "+
		"the table, also, rests a pair of wire framed %^BOLD%^%^CYAN%^eyeglasses "+
		"%^RESET%^and a small oil lamp made of brass.  The lamp gives off barely "+
		"enough light to brighten the rooms darkest corners.  The same unusual "+
		"design that adorns the rest of the furniture in this room is found on "+
		"the table as well.\n",
	({"chairs","chair"}) : "\nRESET%^These large overstuffed chairs look to be rather "+
		"comfortable.  Several throw pillows adorn the chairs.  The legs and front of "+
		"the arms of the chairs are made of the same pale %^BOLD%^%^WHITE%^wood "+
		"%^RESET%^as the rest of the furniture.  Upon the arms of the chairs are "+
		"carved the same unusual design found on the other furniture.\n",
	"chest" : "\n%^RESET%^This small chest has a %^BOLD%^%^YELLOW%^gold %^RESET%^clasp "+
		"lock.  The chest appears to be made of %^ORANGE%^oak%^RESET%^.  There "+
		"appears to be no hinges that you can see on the lid of the chest.\n",
	"fireplace" : "\n%^RESET%^The large stone fireplace looks as if each stone were "+
		"painstakingly laid.  Each stone has been carefully carved, shaped, and "+
		"polished before it was set into place.  A small stone at the base appears "+
		"different.  The fireplace crackles with life from the fire that burns "+
		"within.\n",
	"diary" : "The book is bound in leather and appears to be worn from usage.  Maybe "+
		"you can read it.\n"
	]));

    set_search("fireplace","You find a loose stone in the base.\n");
    set_search("stone","The stone is loose.  maybe you can move it.\n");

    set_door("west door",LROOMS+"leauphall","east","brass key");
    set_open("west door",1);
    set_string("west door","open","The door swings open to the second floor hallway.\n");

    set_door("glass doors",LROOMS+"leabalc","west","brass key");
    set_locked("glass doors",1,"lock");
     (LROOMS+"leabalc")->set_open("glass doors",0);
     (LROOMS+"leabalc")->set_locked("glass doors",1,"lock");
    lock_difficulty("glass doors", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
    set_door_description("glass doors","%^RESET%^The large %^BOLD%^%^CYAN%^glass "+
		"%^RESET%^double doors seem to take up the entire back wall.  They give you "+
		"an excellent view of the Dagger Mountains.  You can see a balcony on the "+
		"otherside of the doors.\n");
    set_string("glass doors","open","The door opens to a second story balcony.\n");

    set_exits(([
	"east" : LROOMS+"leauphall",
	"west" : LROOMS+"leabalc"
    ]));
}
void init() {
	::init();
    	add_action("move","move");
	add_action("read_em","read");
    	}
int move(string str) {
  	if(!str) {
    		tell_object(TP,"Move what?");
    	return 1;
  	}
  	if(FLAG == 0) {
      	FLAG = 1;
		if((str == "stone")){
    		tell_object(TP,"%^RESET%^You move the stone and fine a small "+
				"%^BOLD%^%^YELLOW%^gold %^RESET%^key!  \n");
    		tell_room(environment(TP),""+TPQCN+" moves the small stone and finds "+
    				"something hidden behind it. \n");
       	new(LSTUFF+"gold_key")->move(TO);
       	return 1;
  		}
	}else {
      	tell_object(TP,"The stone has already been moved and whatever was hidden there "+
        		"is gone.");
        	return 1;
    	}
}
int read_em(string str){
  	if(!str){
    		tell_room(TP,"And what exactly are you trying to read?");
    		return 1;
  	}
  	if(str == "diary" || str == "page one"){
    		TP->more(LSTUFF+"page1");
    		return 1;
  	}
  	if(str == "page 2"){
    		TP->more(LSTUFF+"page2");
    		return 1;
  	}
  	if(str == "page 3"){
    		TP->more(LSTUFF+"page3");
    		return 1;
  	}
   	if(str == "page 4"){
    		TP->more(LSTUFF+"page4");
    		return 1;
  	}
  	if(str == "page 5"){
    		TP->more(LSTUFF+"page5");
    		return 1;
  	}
  	if(str == "page 6"){
    		TP->more(LSTUFF+"page6");
    		return 1;
  	}
  	if(str == "page 7"){
    		TP->more(LSTUFF+"page7");
    		return 1;
  	}
  	if(str == "page 8"){
    		TP->more(LSTUFF+"page8");
    		return 1;
  	}
  	if(str == "page 9"){
    		TP->more(LSTUFF+"page9");
    		return 1;
  	}
  	if(str == "page 10"){
    		TP->more(LSTUFF+"page10");
    		return 1;
  	}
  	if(str == "page 11"){
    		TP->more(LSTUFF+"page11");
    		return 1;
  	}
  	if(str == "page 12"){
    		TP->more(LSTUFF+"page12");
    		return 1;
  	}
  	if(str == "page 13"){
    		TP->more(LSTUFF+"page13");
    		return 1;
  	}
  	if(str == "page 14"){
    		TP->more(LSTUFF+"page14");
    		return 1;
  	}
  	if(str == "page 15"){
    		TP->more(LSTUFF+"page15");
    		return 1;
  	}
  	if(str == "page 16"){
    		TP->more(LSTUFF+"page16");
    		return 1;
  	}
  	if(str == "page 17"){
    		TP->more(LSTUFF+"page17");
    		return 1;
  	}
 	else{
  		tell_room(TP,"You cant seem to find anything worth reading there.");
  		return 1;
  	}
}