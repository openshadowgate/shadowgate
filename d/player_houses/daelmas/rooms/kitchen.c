//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Kitchen");
   set_short("kitchen");
   set_long(
   	"%^RESET%^"+
   	"The kitchen is kept very clean and smells faintly of citrus.  "+
   	"The floor is made up of %^BOLD%^%^BLACK%^black %^RESET%^and "+
   	"%^BOLD%^white %^RESET%^marble squares, and the walls are "+
   	"covered with %^RED%^rose %^RESET%^colored paper.  "+
   	"A %^BOLD%^%^BLACK%^black %^RESET%^iron stove, and a %^BOLD%^white "+
   	"marble wash basin %^RESET%^take up most of the southern wall. "+
   	"Above the sink is a small window with rose colored sheer "+
   	"curtains, which allows fresh air to flow into the "+
   	"room.  A %^BOLD%^white marble island %^RESET%^is in the "+
   	"center of the kitchen, with a cutting board on top.  Shiny "+
   	"copper pots and pans hang from a rack over the island. Large "+
   	"wooden cupboards with glass doors are set against the wall, "+
   	"and hold expensive crystal dishes and glasses.  Off to the "+
   	"side is a large circular table, made of black polished wood.  "+
   	"Sitting on the table is a pitcher of some liquid and some porcelin cups.  "+
   	"Four matching chairs surround the table, and a beautiful "+
   	"floral centerpiece sits in the middle of it. Small oil lamps "+
   	"are set against the walls, basking the room in a faint, "+
   	"warm glow.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","A fresh citrus scent fills the room.");
   set_listen("default","The kitchen is warm and quiet.");
   set_items(([
		"stove" : "The stove is large, clean and slightly warm to the touch.\n",
		"basin" : "The basin is empty, but drops of water cling to its "+
			"sides as if it had been used recently.\n",
		"window" : "The window looks out over the path you came in on.\n",
		"island" : "The large marble island rises in the center of the "+
			"kitchen and is very clean. Above it, pots and pans hang "+
			"down, waiting to be used.\n",
		({"cupboards","cupboard"}): "The cupboards are made of wood, but "+
			"the glass doors reveal the beautiful crystal dishes inside.\n",
		"table" : "This is a simple wooden table. Although there are four "+
			"chairs, only two have place mats set in front of them. In "+
			"the center is a floral piece with colorful wild flowers. "+
			"A candle sits in the middle of it.  A pitcher of some liquid "+
			"sits on the table with porcelin cups.\n",
		"pitcher" : "The pitcher is filled with ice tea, maybe you could "+
			"pour some to drink.\n"
	]));

   set_door("western door",DROOMS+"land2","east","marble key");
   set_door_description("western door","The door is polished and made from oak.");
   set_string("western door","open","You open the door onto the second landing.\n");

   set_exits(([
		"east" : DROOMS+"land2"
   ]));

   if(!present("fenegal")){
   	new(DMONS+"fenegal")->move(TO);
   }
}
void init() {
  	::init();
  	add_action("light","light");
  	add_action("sit","sit");
 	add_action("pour_em","pour");
}
int light(string str) {
   if(!str) {
     	tell_object(TP,"Light what?");
     	return 1;
   }
  	if(str == "candle" || str == "a candle"){
     	tell_object(TP,"%^BOLD%^%^YELLOW%^You light a candle to provide "+
     		"romantic lighting for dinner.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" lights a candle which "+
        	"provides perfect dim lighting for a romantic dinner "+
        	"for two.\n%^RESET%^",TP);
		return 1;
   }
}
int sit(string str) {
   if(!str) {
     	tell_object(TP,"Sit where?");
     	return 1;
   }
  	if(str == "table"){
     	tell_object(TP,"%^BOLD%^You sit down at the table and suddenly "+
     		"feel hungry.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sits at the table and looks "+
        	"around anxiously.\n%^RESET%^",TP);
		return 1;
   }
}
int pour_em(string str) {
	if(!str) {
     	tell_object(TP,"Pour what???");
     	return 1;
   }
  	if(str == "tea" || str == "ice tea" || str == "iced tea"){
   	tell_object(TP,"You pick up the pitcher and pour the tea into a cup "+
     		"without spilling a drop.\n");
     	tell_room(ETP,""+TPQCN+" picks up the pitcher and pours a cup of "+
			"tea.\n",TP);
     	new(DOBJ+"istea")->move(TO);
		TP->force_me("get ice tea");
     	return 1;
    }
}
void reset(){
  	::reset();
   if(!present("fenegal")){
   	new(DMONS+"fenegal")->move(TO);
   }
}
