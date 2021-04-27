#include <std.h>
#include "../kier.h"
inherit "/d/common/inherit/hitching_post";
int mykey;

void create() {
   ::create();
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A Small Barn");
   set_short("%^RESET%^%^ORANGE%^A Small Barn%^RESET%^");
   set_long("%^ORANGE%^Built from strong wood, this is a small and simple "
"barn. Open stalls are stocked with %^YELLOW%^piles of hay%^RESET%^%^ORANGE%^ "
"and a trough of %^BLUE%^clean drinking water%^RESET%^%^ORANGE%^. The barn is "
"lit by a solitary lantern that offers only a little light, but also seems to "
"make the room seem cozy. A large %^BLACK%^%^BOLD%^wolf's "
"paw%^RESET%^%^ORANGE%^ is carved into wall of one of the stalls.%^RESET%^");
   set_smell("default","The smell of fresh hay surrounds you.");
   set_listen("default","You can hear the footsteps of someone close by.");

   set_items(([
     ({"paw","wolf's paw","carving"}) : "%^ORANGE%^Carved deeply into the "
"wall of one of the stalls is the shape of a large wolf's paw%^RESET%^",
     ({"hay"}) : "%^YELLOW%^Piles of hay cover the floors of the "
"stall.%^RESET%^",
     ({"troughs"}) : "%^ORANGE%^Large troughs of "
"%^BLUE%^water%^RESET%^%^ORANGE%^ sit at the back of the stalls. Obviously "
"the owner cares deeply for their animals.",
   ]));

   set_exits(([
     "out" : ROOMS+"path",
   ]));
   mykey = 0;
}

void init(){
   ::init();
   add_action("trace","trace");
}

void reset() {
   ::reset();
   if(mykey) mykey = 0;
}

int trace(string str){
   if(!str) return 0;
   if(str != "carving") return 0;
   if(mykey){
     tell_object(TP,"Nothing happens.");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^As you run your hand along the carving, your "
"finger catches on a small iron key that drops into your hand.%^RESET%^");
   new(OBJ+"key")->move(TP);
   mykey = 1;
   return 1;
}
