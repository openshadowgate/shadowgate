#include <std.h>
#include "../morganus.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A strange bar");
   set_short("%^MAGENTA%^A strange bar%^RESET%^");
   set_long("This is a strange excuse for a %^ORANGE%^bar.%^RESET%^ There are barrels "
"that double as seats while still providing beverages. The bar itself is a disorganized "
"mess with many mismatched glasses. Several candles and %^CYAN%^odd glowing "
"runes%^RESET%^ cause this place to be slightly illuminated. The tables all look mostly "
"like abandoned boards and half barrels. There is a series of planks supported loosely by "
"logs in the corner that must act as a %^BLUE%^stage%^RESET%^. There is a menu here you "
"can read.");
   set_smell("default","The smell of old ale and roasting meat lingers in the air.");
   set_listen("default","A few hushed conversations can be heard.");

   set_items(([
     "bar" : "%^ORANGE%^This bar is nothing more than a collection of crates, barrels, "
"and scavenged shelves.%^RESET%^",
     "stage" : "%^BLUE%^This stage is very poorly made. It is held together poorly by "
"twine and rope. A set of planks and boards rest over some logs%^RESET%^",
     ({"glowing runes ", "odd glowing runes", "runes" }) : " %^CYAN%^These odd glowing "
"runes may have some other arcane function, however their primary use seems to be to "
"offer some sort of illumination.%^RESET%^",
   ]));

   set_exits(([
     "south" : ROOMS"foyer",
     "north" : ROOMS"bedroom",
     "east" : ROOMS"shrines",
     "west" : ROOMS"bunkhouse",
   ]));
   set_door("blue door",ROOMS"bedroom","north","morg key");
   set_door_description("blue door", "%^BOLD%^%^CYAN%^This door is made of strong metal dyed a blue tint. "
"It has the symbols of several gods of good etched around the doorframe.%^RESET%^");
}

void reset() {
   ::reset();
    if(!present("gax")) find_object_or_load(MONS"gax")->move(TO);
   switch(random(8)) {
     case 0:
     tell_room(TO,"%^BLUE%^Strange music fills the air here as several forms dance wildly "
"in the dim light.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^CYAN%^A young female drow sings somewhere in the room, the melody is "
"inspiring.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^ORANGE%^The patrons give a rousing toast to the gods as another "
"round is served.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^RED%^A goblin wearing priestly robes comes from east, gestures for "
"the noise level to be dropped, then returns to the eastern room.%^RESET%^");
     break;
     default: break;
   }
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
   object ob;
   int i;
   if(str!="menu") return notify_fail("Read what?");
   ob=present("gax");
   if (!ob){
     write("There's noone here to serve you right now.");
     return 1;
   }
   else{
write("\t=-=-=-=-=-=-=-=-=-= FOOD =-=-=-=-=-=-=-=-=-=");
write("\t  Roast pheasant\t\t "+ (int)ob->get_price("roast pheasant")+" silver");
write("\t  Fresh escargot\t\t "+ (int)ob->get_price("fresh escargot")+" silver");
write("\t  Steak and eggs\t\t "+ (int)ob->get_price("steak and eggs") +" silver");
write("\t  Cucumber sandwiches\t\t "+ (int)ob->get_price("cucumber sandwiches") +" silver");
write("\n\t=-=-=-=-=-=-=-=-=- DRINKS -=-=-=-=-=-=-=-=-=");
write("\t  Water\t\t\t\t  "+(int)ob->get_price("water")+" silver");
write("\t  Hot chocolate\t\t\t "+(int)ob->get_price("hot chocolate")+" silver");
write("\t  Mushroom wine\t\t\t "+(int)ob->get_price("mushroom wine")+" silver");
write("\t  Dwarven dark ale\t\t "+(int)ob->get_price("dwarven dark ale")+" silver");
write("\t  Horragh\t\t\t "+(int)ob->get_price("horragh")+" silver");
write("\n\t=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=");
     return 1;
   }
}
