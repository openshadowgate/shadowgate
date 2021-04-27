//kitchen.c - Stefano's cottage kitchen.  Coded by Circe 9/20/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
int uses;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A large kitchen");
        set_short("A large kitchen");
        set_long("%^BOLD%^%^RED%^The kitchen is swelteringly hot, with the "+
           "fires constantly stoked beneath the large %^BOLD%^%^BLACK%^iron "+
           "range%^BOLD%^%^RED%^ at the far side of the room.  "+
           "%^BOLD%^%^YELLOW%^Shiny copper pots and pans%^BOLD%^%^RED%^ hang along "+
           "the walls, and there are glass fronted cupboards containing an array of "+
           "fine china cups, saucers, plates, dishes, jugs and  bowls. A small, cool "+
           "%^RESET%^pantry %^BOLD%^%^RED%^off to one side stores fresh game and poultry, "+
           "cheeses, vegetables, and eggs. Herbs and spices sit in containers in a neatly "+
           "ordered wall rack. The %^RESET%^cool flagstone floor%^BOLD%^%^RED%^ contrasts "+
           "with the heat of the room, except nearer the range, where even the flagstones "+
           "become warmer. There is a small table and a couple of chairs at one end of the "+
           "room, where a meal could be taken if one did not want to move through to a more "+
           "formal setting."+
           "\n");
        set_smell("default","The smells of great food in preparation are enough to make your mouth water.");
        set_listen("default","The clattering of pots and pans and the crackling of the fire fill the room.");
        set_items(([
            ({"pots","pans"}) : "The pots and pans hang in neat rows. They are polished "+
               "to a high shine and gleam in the flickering stovelight.",
            ({"rack", "herbs", "spices"}) : "The rack is well stocked with fresh and dried "+
               "herbs, from mint and jasmine to rosmary and sage. The spices include tumeric, "+
               "saffron, cumin and nutmeg.", 
            ({"cupboards", "cups", "saucers", "plates", "dishes", "jugs", "bowls"}) : "All the "+
               "crockery is nicely displayed within the glass fronted cupboards. It is made from "+
               "fine %^BOLD%^%^WHITE%^w%^BLUE%^h%^BOLD%^%^WHITE%^ite and b%^BOLD%^%^BLUE%^l"+
               "%^BOLD%^%^WHITE%^ue chi%^BOLD%^%^BLUE%^n%^BOLD%^%^WHITE%^a%^RESET%^. The cupboards "+
               "themselves have been kept clean and dust free.", 
           "pantry" : "The pantry is open-fronted and recessed into the side wall. It is dark and "+
               "cool, markedly in contrast to the rest of the kitchen. It is not obvious quite how "+
               "this has been acheived. In any case, the foods stocked here look fresh and of the "+
               "highest quality.", 
           "table" : "The table is small and plain, with a simple white linen cloth.",
           "range" : "%^BOLD%^%^BLACK%^A large black iron stove and boiler, heated by a wood fire at "+
               "the base. There are compartments for roasting or baking, as well as an iron top "+
               "plate for heating saucepans and kettles. The boiler is able to provide a near "+
               "constant supply of hot water. The %^BOLD%^%^RED%^heat%^BOLD%^%^BLACK%^ from the whole "+
               "affair is immense.%^RESET%^",
        ]));
        set_exits(([
           "out" : SHOUSE"cottagemain"
   ]));
        set_door("kitchen door",SHOUSE"cottagemain","out",0);
        set_door_description("kitchen door","A simple wooden door.");
        uses = random(5) + 4;
  set_search("default","With such a well-stocked kitchen, it wouldn't take much to prepare a meal.");
}

void init() {
  	::init();
 	add_action("feed_em","prepare");
}

int feed_em(string str) {
	string mname=TP->query_name();
    	if(!str) {
        	tell_object(TP,"You might want to try preparing a meal.");
        	return 1;
    	}
  	if(str == "meal"){
//	    	if((wizardp(TP)) || (mname == "stefano")){
         if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1){
     			if(uses == 0){
     				tell_object(TP,"The kitchen seems to have run out.  You really should discipline them.");
     				tell_room(ETP,""+TPQCN+" frowns deeply as "+TP->query_subjective()+" opens "+
                           "the cupboards and finds them lacking.",TP);
     				return 1;
     			}
     			tell_object(TP,"You bustle about in the kitchen, chopping and slicing, "+
                     "washing and marinating, preparing meat and vegetables, rolling pastry, "+
                     "adding spices and doing all those things good cooks do to make their "+
                     "meals taste just that little bit special.");
     			tell_room(ETP,""+TPQCN+" bustles about in the kitchen, chopping and slicing, "+
                     "washing and marinading, preparing meat and vegetables, rolling pastry, "+
                     "adding spices and doing all those things good cooks do to make their meals "+
                     "taste just that little bit special.",TP);
     			new(OBJ"stefano_food")->move(TO);
			TP->force_me("get food");
			uses = uses - 1;
     			return 1;
     		}
     		tell_object(TP,"The kitchen staff looks appalled that an uninvited guest would try to prepare food.");
     		tell_room(ETP,""+TPQCN+" seems about to prepare food before seeing the horrified looks "+
               "on the faces of the kitchen staff.",TP);
     		return 1;
     	}
}