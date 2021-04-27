//living_room.c - Shrydelhi's living room.  Coded by Circe 9/12/03
#include <std.h>
#include "shry.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("living room");
   set_short("living room");
   set_long("The inside of the tree has grown into a natural hollow. There are "+
      "no corners here, as the room is completely rounded. %^YELLOW%^Light "+
      "%^RESET%^bathes the room through several floor to ceiling windows.  A "+
      "cresent-moon shaped %^RESET%^%^CYAN%^couch %^RESET%^sets perfectly against "+
      "the wall, providing a comfortable place to sit and rest.  A round growth "+
      "from the tree comes up from the floor, mushrooming out to make a flat "+
      "surface that acts much like a coffee table in front of the couch.  In the "+
      "center of the table sets a large vase of arranged "+
      "%^BOLD%^%^YELLOW%^f%^RED%^l%^ORANGE%^o%^CYAN%^w%^MAGENTA%^e%^RED%^r%^YELLOW%^s. "+
      "%^RESET%^Opposite of the couch is another interior growth of the tree, "+
      "forming into steps that spiral up to another level of this home."+
      "\n"
   );
   set_smell("default","You smell the fresh scent of the flowers.");
   set_listen("default","It is pleasantly quiet.");
   set_items(([
      "couch" : "%^RESET%^%^CYAN%^This couch is made of a very soft "+
         "material, perhaps of a suede of sorts, its %^BOLD%^%^BLUE%^s%^CYAN%^a%^BOLD%^%^BLUE%^pp"+
         "%^BOLD%^%^CYAN%^h%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^e blue "+
         "%^RESET%^%^CYAN%^color is absolutely stunning, offset by the numerous "+
         "%^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^RESET%^er "+
         "%^CYAN%^pillows strewn across it.",
      "pillows" : "Several round silver pillows are on the couch for added comfort.",
      ({"window","windows"}) : "Several floor to ceiling windows allow plenty of "+
         "light in during the day, and allows the soft %^BOLD%^%^CYAN%^glow "+
         "%^RESET%^of the %^BOLD%^%^WHITE%^moonlight%^RESET%^ to filter in at night. "+
         "The view from here is lovely, overlooking the %^BOLD%^%^GREEN%^meadow "+
         "%^RESET%^that surrounds the tree.",
      "table" :  "%^RESET%^%^ORANGE%^This is a growth of the tree itself, it is "+
         "quite narrow at the base, but then mushrooms out at the top, forming a "+
         "perfectly smooth surface.  Whats more, it size and shape fits perfectly "+
         "with the couch, making it an ideal coffee table to set your food or drinks "+
         "upon.%^RESET%^",
      "flowers" : "A large %^BOLD%^%^BLUE%^blue vase %^RESET%^holds an arrangement "+
         "of beautiful %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BLUE%^u%^CYAN%^e, "+
         "%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^er, "+
         "%^RESET%^and %^BOLD%^%^WHITE%^white %^RESET%^flowers.",
      ({"stairs","steps"}) : "%^RESET%^%^ORANGE%^These steps grow out of the side "+
         "of the tree itself, and seem to lead up to another level of the house."
   ]));
   set_exits(([
      "out" : SHRY"platform",
      "up" : SHRY"dining_room",
      //"down" :"WIZ"(in the roots of a tree) To be added later with the other parts of Shry's house
   ]));
   set_door("door",SHRY"platform","out","twig_key");
   set_door_description("door","From this side, the door blends almost perfectly with the walls "+
      "of the treehouse.  A small lever may be lifted, allowing the door to swing open.");
   set_locked("door",1);
}

void init(){
   ::init();
   add_action("sit","sit");
}

int sit(string str){
   if(str == "couch") {
      tell_object(TP,"%^BOLD%^You settle down in the comfortable couch.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" settles into the comfortable-looking couch.",TP);
      return 1;
   }
   else{
      tell_object(TP,"Sit where?");
   }
}