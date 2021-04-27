//BWANA fortress- Courtyard Level Template  - LoKi


#include <std.h>

#include "../yuki.h"
void pick_critters();
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("well tended courtyard");
    set_short("%^RESET%^%^ORANGE%^well tend%^YELLOW%^e%^RESET%^%^ORANGE%^d %^GREEN%^cour%^BOLD%^t%^RESET%^%^GREEN%^yard");
    set_long("%^RESET%^%^ORANGE%^The courtyard of the fortress is open the air. The ground has been set with well placed "+
    "%^RESET%^flagstone%^RESET%^%^ORANGE%^. Even with the traffic from soldiers, merchants and horse drawn wagons, the "+
	"entire area is immaculate. Along the wall %^RESET%^%^RED%^small cherry blossom%^RESET%^%^ORANGE%^ trees have been "+
	"planted that add a %^GREEN%^lush green%^ORANGE%^ to the %^RESET%^%^BOLD%^stark white walls%^RESET%^%^ORANGE%^, and a"+
	"scent of %^RED%^cherry%^RESET%^%^ORANGE%^ wafts through the air. In between the trees are tall poles with "+
        "%^BLACK%^%^BOLD%^pendants%^RESET%^%^ORANGE%^ swaying slowly in the wind.\n\n%^RESET%^");
    set_smell("default","%^RESET%^%^RED%^You smell cherry blossom...%^RESET%^");
    set_listen("default","%^RED%^%^ORANGE%^The constant sounds of people echo through the courtyard%^RESET%^");

    set_items
    (([
        ({"ground", "path", "stones"}) : "%^RESET%^The ground of the courtyard is set with well placed flagstones%^RESET%^",
        ({"trees"}) : "%^RESET%^%^GREEN%^Placed along the wall are small cherry blossom trees. They are well cared "+
		"for and contrast the white walls. %^RESET%^",
		({"pendants", "flags"}) : "%^BLACK%^%^BOLD%^In between the trees are %^RESET%^%^ORANGE%^long poles%^BLACK%^%^BOLD%^"+
                " with a crosspeice. From the crosspeice hangs a %^RESET%^black pendant%^BOLD%^%^BLACK%^ with a %^RESET%^%^BOLD%^stylized"+
                " feather%^BLACK%^%^BOLD%^ in %^RESET%^%^BOLD%^pure white%^BLACK%^%^BOLD%^. The pendants sway gently in the wind. %^RESET%^",
		({"walls"}) : "%^RESET%^%^BOLD%^The fortress walls of pure white rise high above you.%^RESET%^",
		
    ]));
}

void reset() {
   int active;
   active = has_mobs();

   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
  switch(random(5)){
     case 0..1:
       tell_room(TO,"%^RESET%^%^ORANGE%^A merchant caravan pulls up into the courtyard, "+
	   "and is quickly unloaded of its cargo of weapons and armor.%^RESET%^");
     break;
     case 2..3:

       tell_room(TO,"%^BLACK%^%^BOLD%^A column of soldiers marches out of the "+
	   "fortress.%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^%^BLACK%^%^BOLD%^The pendants flap in the breeze, "+
	   "the %^RESET%^%^WHITE%^feather%^BLACK%^%^BOLD%^ gleaming.%^RESET%^");
     break;
     case 5:
       tell_room(TO,"%^RESET%^%^RED%^A group of soldiers enter the fortress "+
	   "bloodied, but joking amongst each other.%^RESET%^");
     break;
   }
}

void pick_critters(){
   switch(random(5)){
      case 0..3: break;
      case 4:  set_monsters( ({MOBS"crow_soldier"}),({1}) );
               break;

}

}
