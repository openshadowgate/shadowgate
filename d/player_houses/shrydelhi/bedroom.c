//bedroom.c - Shrydelhi's bedroom.  Coded by Circe 9/13/03
#include <std.h>
#include "shry.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("bedroom");
   set_short("bedroom");
   set_long(
      "%^RESET%^%^GREEN%^This room is quite attractive to look at.  The "+
      "ceiling itself is made of a canopy of %^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e"+
      "%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s, "+
      "dense enough to block out any rain that may be falling, yet light still "+
      "manages to filter through, casting a dancing %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l"+
      "%^BOLD%^%^WHITE%^v%^RESET%^er %^RESET%^%^GREEN%^radiance of light  on the floor "+
      "as the slight breeze rustles the %^RESET%^%^GREEN%^l%^RESET%^%^ORANGE%^e"+
      "%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s "+
      "and fills the room with fresh air. A soft looking bed is here, as well as a "+
      "small storage chest."+
      "\n");
   set_smell("default","The fresh scent of the outside forest lingers in the air here.");
   set_listen("default","The soft sound of the breeze playing through the canopy of leaves above.");
   set_items(([
      "bed" : "A soft bed is here, decorated in %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lv"+
         "%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^colored furs and large, soft %^BOLD%^%^BLACK%^g"+
         "%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y pillows embroidered with tiny "+
         "%^RESET%^%^CYAN%^blue moons.%^RESET%^",
      "ceiling" : "%^RESET%^%^GREEN%^Is composed entirely of the leaves of the "+
         "tree. They are dense enough to keep out the rain, but still allow light and "+
         "fresh air to filter in.%^RESET%^",
      "chest" : "This is an intricately carved chest. The image of the "+
         "%^BOLD%^%^YELLOW%^heavens %^RESET%^is carved upon the top, mapping out the "+
         "constellations in perfect detail.  The front of the chest has a "+
         "%^BOLD%^%^WHITE%^silver %^RESET%^lock, shaped to look like a "+
         "%^BOLD%^%^WHITE%^crescent moon.%^RESET%^"
   ]));
   set_exits(([
      "down" : SHRY"dining_room"
   ]));
}

void init(){
   ::init();
   add_action("lay","lay");
   add_action("obtain","obtain");
}

int lay(string str) {
   if(str != "bed" && str != "on bed") {
      tell_object(TP,"Where are you trying to lay?");
      return 1;
   }
   else{
      tell_object(TP,"%^BOLD%^%^BLACK%^You lay down in the luxurious furs and smile at the comforts of the bed.");
      tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" lies down on the bed and smiles as "+TP->query_subjective()+" "+
         "sinks into the luxurious furs.",TP);
      return 1;
   }
}

int obtain(string str) {
	string mname=TP->query_name();
   if(str != "pendant") {
      tell_object(TP,"What are you trying to obtain?");
      return 1;
   }
   else{
	if((wizardp(TP)) || (mname == "shrydelhi")){
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You search through the chest and find a small brooch.");
      tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" searches through the small chest and pulls out something.",TP);
      new(OBJ"shry_pendant")->move(TO);
      TP->force_me("get pendant");
      return 1;
      }
   }
}