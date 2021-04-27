//BWANA fortress- Secret Level Template  - LoKi


#include <std.h>
#include "../yuki.h"
void pick_critters();
inherit CVAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("rough cut tunnel");
    set_short("%^BLACK%^%^BOLD%^rough cut tunnel%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This tunnel has been carved without the niceties of the rest of the fortress"+
	". The ground is set with black flagstone, and the walls are simple rock walls. The way "+
	"is lit by %^RESET%^small scones%^BLACK%^%^BOLD%^ filled with %^YELLOW%^candles%^BLACK%^%^BOLD%^ "+
	"along your path.\n\n%^RESET%^");
    set_smell("default","%^BLACK%^%^BOLD%^You smell cold stone.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^You smell dripping water.%^RESET%^");

    set_items
    (([
        ({"ground", "stone", "walls"}) : "%^BLACK%^%^BOLD%^The ground and walls here "+
		"are rough stone%^RESET%^",
        ({"scones", "candles"}) : "%^BLACK%^%^BOLD%^What little light there is here "+
		"is provided by %^RESET%^small scones%^BLACK%^%^BOLD%^ filled with %^YELLOW%^"+
		"candles%^BLACK%^%^BOLD%^.%^RESET%^",
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
}

void pick_critters(){
   switch(random(5)){
      case 0..3: break;
      case 4:  set_monsters( ({MOBS"crow_soldier"}),({1}) );
               break;

}

}
