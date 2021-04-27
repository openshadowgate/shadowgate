#include <std.h>
#include "../kier.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_name("Stairs to a tower");
   set_short("%^RESET%^Stairs to a %^BOLD%^tower%^RESET%^");
   set_long("%^RESET%^Cut into the %^BOLD%^rock%^RESET%^, these stairs are "
"wide and deep. The %^BOLD%^stone%^RESET%^ has been smoothed and polished to "
"be as safe for both people and animals to traverse. The stairs end at a "
"small tower jutting out of the cliff. There is a large %^ORANGE%^double "
"door%^RESET%^ to the tower, and a %^ORANGE%^small barn%^RESET%^ off on the "
"side. A pennant hangs just over the door, and a %^ORANGE%^bell%^RESET%^ "
"hangs beside it.");
   set_smell("default","The salty smell of the sea assails you.");
   set_listen("default","You hear the sounds of sea birds.");

   set_items(([
     ({"stairs","steps"}) : "%^RESET%^%^BOLD%^Cut out of the stone, these "
"steps are impressive in the detail to craftsmanship. They have been polished "
"and smoothed out to be safe for any mount or person.%^RESET%^",
     ({"barn"}) : "%^ORANGE%^This simple barn is made of stout oak, and sits "
"beside the tower. A large open door is big enough for even the largest of "
"animals.%^RESET%^",
     ({"pennant","flag"}) : "%^RESET%^%^BOLD%^A flag, fluttering softly in "
"the breeze. It is made of strong white cloth and bears an ensignia in gold "
"thread of a %^YELLOW%^wolf's paw%^WHITE%^.%^RESET%^",
     ({"bell","doorbell"}) : "%^ORANGE%^A large, plain bronze bell has been "
"hung beside the door. There is a rope tied to it that you could probably "
"%^WHITE%^ring %^ORANGE%^to alert people within the house to your presence."
"%^RESET%^",
   ]));

   set_exits(([
     "barn" : ROOMS+"barn",
     "enter" : ROOMS+"lobby",
     "southeast" : "/d/barriermnts/bpeak/rooms/b3",
   ]));
   set_door("door",ROOMS+"lobby","enter","wolf key");
   set_locked("door",1);
   set_door_description("door", "%^ORANGE%^This oak door is obviously heavy, "
"and large. It is free of design and is opened using a heavy %^BLACK%^%^BOLD%^"
"dark iron ring%^RESET%^%^ORANGE%^ to pull it open.%^RESET%^");
}

void init(){
   ::init();
   add_action("ring_fun","ring");
}

int ring_fun(string str){
   object ob;
   if(!str){
     notify_fail("What do you want to ring?\n");
     return 0;
   }
   if(str != "bell" && str != "doorbell"){
     notify_fail("You can't light that.\n");
     return 0;
   }
   tell_object(TP,"%^ORANGE%^You give a light tug on the bell's rope, and "
"it tolls forth a loud, clear note.%^RESET%^");
   tell_room(TO,"%^ORANGE%^"+TPQCN+" gives a light tug on the bell's rope, "
"and it tolls forth a loud, clear note.%^RESET%^",TP);
   ob = find_object_or_load(ROOMS"lobby");
   tell_room(ob,"%^ORANGE%^You hear the clear toll of a bell from somewhere "
"nearby.%^RESET%^");
   ob = find_object_or_load(ROOMS"bedroom");
   tell_room(ob,"%^ORANGE%^You hear the clear toll of a bell from somewhere "
"nearby.%^RESET%^");
   ob = find_object_or_load(ROOMS"bathroom");
   tell_room(ob,"%^ORANGE%^You hear the clear toll of a bell from somewhere "
"nearby.%^RESET%^");
   ob = find_object_or_load(ROOMS"rooftop");
   tell_room(ob,"%^ORANGE%^You hear the clear toll of a bell from somewhere "
"nearby.%^RESET%^");
   return 1;
}
