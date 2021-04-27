#include <std.h>
#include "../morganus.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A dark foyer");    
   set_short("%^CYAN%^A dark foyer%^RESET%^");
   set_long("You are what appears to be a %^CYAN%^dimly lit%^RESET%^ entrance hall to "
"what smells like a %^ORANGE%^dirty bar.%^RESET%^ The main entrance to the musty smelling "
"room ahead is etched with strange runes depicting various %^BOLD%^%^WHITE%^deities of "
"good.%^RESET%^ Many of the %^BLUE%^dark marble pillars%^RESET%^ show sign of "
"restoration. On the ground are %^MAGENTA%^symbols of welcome%^RESET%^ from many "
"different races.");
   set_smell("default","The smell of food and incense wafts through on a light breeze.");
   set_listen("default","The sounds of hushed conversation in many languages echo in the chamber.");

   set_items(([
     ({"runes","strange runes"}) : "%^BOLD%^%^WHITE%^These symbols show many of the good "
"gods common to this land. Including Selune, Mystra, Tyr, Tymora, Sune and Lathander.",
     "symbols" : "These symbols instill a feeling of welcome and good will in to those "
"seeing them. Some of them seem a little worn, as if something had been repeatedly rubbed over them.",
   ]));

   set_exits(([
     "north" : ROOMS"bar",
   ]));
}

void init(){
   ::init();
   add_action("symbols_fun","trace");
}

int symbols_fun(string str){
   if(!str) return 0;
   if(str != "symbols") return 0;
   tell_object(TP,"You press your hand against a symbol upon the "
"wall, tracing its outline with a fingertip, and you suddenly appear "
"elsewhere!");
   tell_room(ETP,""+TPQCN+ " presses "+TP->QP+" hand against the "
"wall, and suddenly disappears!",TP);
   TP->move_player("/d/koenig/village/genstore");
   return 1;
}
