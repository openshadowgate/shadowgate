#include <std.h>
#include "../yuki.h"
inherit CVAULT;
object ob;
int mykey;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("comfortable study");
    set_short("%^ORANGE%^comfortable study%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This small room in the bowels of the %^BLACK%^%^BOLD%^fortress%^RESET%^%^ORANGE%^ "+
	"is only slightly more comfortable then the rest of the fortress. The %^RESET%^bare stone walls%^RESET%^%^ORANGE%^ "+
	"are three walls by %^BOLD%^oak bookcases%^RESET%^%^ORANGE%^ filled with countless tomes. On the last wall "+
	"a %^RESET%^giant map%^RESET%^%^ORANGE%^ of the realm hangs, as well framed with oak. The floor is covered "+
	"with a %^RESET%^%^RED%^thick area rug%^RESET%^%^ORANGE%^. In the center of the room sits a %^CYAN%^large "+
	"crystal ball%^RESET%^%^ORANGE%^ with several comfortable chairs sitting around it. The room is lit oddly "+
	"enough by a %^RESET%^bur%^BLACK%^%^BOLD%^n%^RESET%^ish%^BLACK%^%^BOLD%^e%^RESET%^d "+
	"s%^BOLD%^i%^RESET%^lver ch%^BOLD%^a%^RESET%^ndel%^BLACK%^%^BOLD%^ier%^RESET%^%^ORANGE%^ filled "+
	"with %^RESET%^%^BOLD%^small white candles%^RESET%^%^ORANGE%^.\n%^RESET%^");
    set_smell("default","%^RESET%^%^ORANGE%^The scent of books fills the air.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^Its almost silent here.%^RESET%^");

    set_items
    (([
        ({"rug", "floor"}) : "%^RESET%^%^RED%^The floor is covered in a thick red throw rug that offers more "+
		"warmth and comfort then the bare stone most of the rest of the fortress enjoys.%^RESET%^",
        ({"books", "bookcases"}) : "%^RESET%^%^ORANGE%^Along three of the walls are bookcases filled "+
		"with countless tomes.%^RESET%^",
		({"map", "realm map"}) : "Along one wall is a giant map of the realm. Each city is marked, as "+
		"well as what looks like political borders and trade routes. There are several notations on the "+
		"map that are in code, and seem to denote some plan. Small pins are also stuck into the map, "+
		"the majority of the pins stuck to the place on the map this fortress resides on.%^RESET%^",
		({"candles", "chandelier"}) : "%^BLACK%^%^BOLD%^A burnished silver chandelier hangs from the "+
		"ceiling, offering light with its %^RESET%^%^BOLD%^small white candles%^BLACK%^%^BOLD%^ that "+
		"flicker softly .%^RESET%^",
    ]));
	   set_exits(([
          "west" : ROOMS"sec2",
   ]));

}

void reset() {
   if(mykey) mykey = 0;
  switch(random(3)){
     case 0..1:
       tell_room(TO,"%^BLACK%^%^BOLD%^You hear soldiers marching past.%^RESET%^");
     break;
     case 2..3:

tell_room(TO,"%^RESET%^%^BOLD%^The candles in the chandelier flicker.%^RESET%^");
     break;
   }
   
      if(!present("crystal ball")){
      ob = new("/d/magic/obj/crystal_ball");
          ob->move(TO);
          ob->set_short("%^RESET%^%^CYAN%^A la%^RESET%^r%^RESET%^%^CYAN%^ge "+
		  "cryst%^BOLD%^a%^RESET%^%^CYAN%^l b%^RESET%^a%^RESET%^%^CYAN%^ll%^RESET%^");
          ob->set_long("%^RESET%^%^CYAN%^This large crystal ball is obviously well "+
		  "cared for, and expensive. Its size alone and the fact that it is not "+
		  "marred by a single smudge or crack suggests its value to the owner.");
    }

}

void init() {
    ::init();
    add_action("lift", "lift");
}

int lift(string str){
   if(!str) return 0;
   if(str != "map") return 0;
   if(mykey){
     tell_object(TP,"%^BLACK%^%^BOLD%^There is a small empty "+
	 "alcove behind the map.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^You lift the map slightly and a "+
   "key falls out%^RESET%^.");
   new(OBJ"key")->move(TP);
   mykey = 1;
   return 1;
}
