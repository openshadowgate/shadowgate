//underwater ruined road
#include <std.h>
#include "../elf.h"
inherit WATER;

void pick_critters();

void create(){
   pick_critters();
   set_repop(35);
   ::create();
   set_terrain(DEEP_WATER);
   set_travel(RUBBLE);
   set_climate("arctic");
<<<<<<< HEAD
   set_name("underwater ruin");
   set_short("underwater ruin");
=======
   set_name("under water ruin");
   set_short("under water ruin");
>>>>>>> 6d567c60d0f49d9fb6c20468cb6813cf921e24e8
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      (({"ocean","water"})) :
        "The ocean is littered with ice bergs.",
	  (({"ice berg","berg"})) : "Large blocks of ice float in the ocean.",
	   ]));
    set_smell("default","Near freezing water fills your nose.");
    set_listen("default","You hear swooshing of water currents.");
 
}

string long_desc(){
  
   return("%^CYAN%^This is an ruined road on the sea floor."+
   "  The ocean swirls all around and above are ice bergs "+
   "floating on the water surface.  The road is little more "+
   "than dislodged bricks mixed with gray mud of the sea floor."+
"\n");
 
}
string night_desc() {
   return("%^BLUE%^At night there is barely any light on this"+
   " ruined road.  The road is in a terrible state like an "+
   "earthquake destroyed it.  The years of being under water"+
   " and sediment make it more of a ruin than a road."+
"\n");
}

void reset(){
 ::reset();
 switch(random(7)){
      case 0:  tell_room(TO,"%^CYAN%^Near freezing water chills your bones.");
               break;
<<<<<<< HEAD
=======

>>>>>>> 6d567c60d0f49d9fb6c20468cb6813cf921e24e8
      case 1:  tell_room(TO,"%^CYAN%^You hear a swoosh as water currents flow past you.");
               break;
      case 2:  tell_room(TO,"%^CYAN%^A thunderous crack rumbles"+
	  " through the area as a large block of ice breaks above.");
               break;
      case 3:  tell_room(TO,"%^BOLD%^Several odd fish swim past");
               break;
      case 4:  tell_room(TO,"%^CYAN%^Some strange creature moves along the ocean floor.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^There is a crack and a splash "+
	  "as a berg of ice cavs into the sea.");
               break;	
      case 6:  tell_room(TO,"%^CYAN%^Several bubbles pop up from the ruins");
               break;				   }
 return;
}
void pick_critters(){
      switch(random(11)) {     
        case 0:  break;
        case 1:  set_monsters( ({MON"crab"}),({random(4)+1}));
                 break;
        case 2:  set_monsters( ({MON"lobster"}),({random(2)+1}));
                 break;
        case 3:  set_monsters( ({MON"drowned"}),({1}));
                 break;
		case 4:  set_monsters( ({MON"stingray"}),({random(3)+2}));
                 break;
        default: break;  
      }
return;
}

<<<<<<< HEAD
=======

>>>>>>> 6d567c60d0f49d9fb6c20468cb6813cf921e24e8
