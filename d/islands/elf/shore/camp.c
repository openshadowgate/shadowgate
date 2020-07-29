#include <std.h>
#include "../elf.h"
inherit CROOM;

void pick_critters();

void create(){
   ::create();
   set_terrain(GLACIER);
   set_travel(RUBBLE);
   set_climate("arctic");
   set_name("Fishing Camp");
   set_short("Fishing Camp");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      (({"ice"})) :
        "The whole area is frozen.",
      (({"camp"})) : "The camp is simple and humble.",
      (({"fire","fire pit"})) : "The firepit is a pile of stones on top of the ice.",

	   ]));
   set_listen("default",
   "Cracks like thunder echo through the place as the ice shifts.");
   set_smell("default",
   "Your nose is freezing.");
   set_exits(([ "out" : ROOMS"shore6", 
      ]));
       set_door_description("gate","The gates are made of driftwood and rope.");
       set_door("gate",ROOMS"/shore/shore6","out","elfkey");
}

string long_desc(){
  
   return("%^CYAN%^This is a small fishing camp set up by sea elves."+
   "   The camp is set on top of the sea because the ice is so thick"+
   " here.  There is firepit to light fires and places to store "+
   "things.   Several simple shelters are here to ward against the bitter cold."+
"\n");
 
}
string night_desc() {
   return("%^BLUE%^This is a small fishing camp set up by sea elves."+
   "   The camp is set on top of the sea because the ice is so thick"+
   " here.  There is firepit to light fires and places to store "+
   "things.   Several simple shelters are here to ward against the bitter cold."+
"\n");
}

void reset(){
 ::reset();
  set_locked("gate",0);
  set_open("gate", 0);
 switch(random(7)){
      case 0:  tell_room(TO,"%^CYAN%^A gust of wind blows by, chilling your bones.");
               break;
      case 1:  tell_room(TO,"%^CYAN%^You hear strange whispering"+
	  " in your ear but look and nothing is there.");
               break;
      case 2:  tell_room(TO,"%^CYAN%^A thunderous crack rumbles"+
	  " through the area as a large block of ice breaks.");
               break;
      case 3:  tell_room(TO,"%^BOLD%^Sheets of snow fall from the"+
	  " sky, freezing your face.");
               break;
      case 4:  tell_room(TO,"%^CYAN%^The ice underfoot makes"+
      " a cracking noise.  You wonder how safe this place is.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^A wave of cold bears "+
	  "down on you.  You blink and your eyelashes freeze "+
	  "together.  It takes an effort to open your eyes.");
               break;	
      case 6:  tell_room(TO,"%^CYAN%^The wind dies down,"+
	  " leaving a cold hush.");
               break;				   }
 return;
}