//BWANA fortress- Hallway Level Template  - LoKi


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
    set_name("darkened hallway");
    set_short("%^BLACK%^%^BOLD%^da%^RESET%^r%^BLACK%^%^BOLD%^"+
	"ken%^RESET%^e%^BLACK%^%^BOLD%^d hall%^RESET%^w%^BLACK%^%^BOLD%^a"+
	"y%^RESET%^");
    set_long("%^RESET%^%^BOLD%^The hallways of the fortress are such a "+
	"ch%^RESET%^a%^RESET%^%^BOLD%^otic %^RESET%^m%^RESET%^%^BOLD%^ix of "+
	"styles. It is as if two designers worked on it. The floor is "+
	"perfectly placed l%^RESET%^i%^RESET%^%^BOLD%^ght til%^RESET%^"+
	"e%^RESET%^%^BOLD%^s in very specific organized patterns. %^RESET%^Th"+
	"e w%^RESET%^%^BOLD%^a%^RESET%^lls start from the bottom as %^BOLD%^w"+
	"hite marble%^RESET%^%^BOLD%^ v%^RESET%^e%^RESET%^%^BOLD%^ined with g"+
	"r%^BLACK%^%^BOLD%^a%^RESET%^y. Thou%^RESET%^%^BOLD%^g%^RESET%^h rando"+
	"mly along the walls, the builder switched to a b%^BLACK%^%^BOLD%^l%^RESET%^a"+
	"ck volca%^BLACK%^%^BOLD%^n%^RESET%^ic rock. %^BLACK%^%^BOLD%^From the h"+
	"igh vaulted ceilings hang iron braziers, and %^RESET%^i%^BLACK%^%^BOLD%^ro"+
	"n cage%^RESET%^s%^BLACK%^%^BOLD%^ that are home to crows that %^RESET%^c"+
	"aw%^BLACK%^%^BOLD%^ and rustle constantly. Along the walls stand pendan"+
        "ts with %^RESET%^%^RED%^banners%^BLACK%^%^BOLD%^ hung on them.\n\n%^RESET%^");
    set_smell("default","%^BLACK%^%^BOLD%^You smell cold stone...%^RESET%^");
    set_listen("default","%^RESET%^%^ORANGE%^The constant cawing of "+
	"crows fills the hallways%^RESET%^");

    set_items
    (([
        ({"ground", "stone", "stones"}) : "%^RESET%^%^BOLD%^The ground of the "+
		"fortress is set with interlocking stones%^RESET%^",
        ({"cages", "crows"}) : "%^BLACK%^%^BOLD%^Large wrought iron cages hold "+
		"many crows comfortably. The crows %^RESET%^rustle%^BLACK%^%^BOLD%^ and "+
		"caw%^RESET%^. %^RESET%^",
		({"pendants", "flags"}) : "%^BLACK%^%^BOLD%^spaced along the hallway "+
		"are %^RESET%^%^ORANGE%^long poles%^BLACK%^%^BOLD%^"+
                " with a crosspeice. From the crosspeice hangs a %^RESET%^%^RED%^red "+

		"pendant%^BOLD%^%^BLACK%^ with a %^RESET%^%^BOLD%^stylized"+
                " feather%^BLACK%^%^BOLD%^ in %^RESET%^black thread%^BLACK%^%^BOLD%^. The "+

		"pendants stand still. %^RESET%^",
                ({"walls"}) : "%^RESET%^The walls inside the fortress are a mismatch of stones%^RESET%^.",
		
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
   switch(random(4)){
      case 0..2: break;
      case 3:  set_monsters( ({MOBS"crow_soldier"}),({1}) );
               break;

}
  switch(random(4)){
     case 0..1:
       tell_room(TO,"%^BLACK%^%^BOLD%^The crows fill the air with the cacaphony of cawing.%^RESET%^");
     break;
     case 2..3:

       tell_room(TO,"%^BLACK%^%^BOLD%^Soldiers march down the hallways.%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^BLACK%^%^BOLD%^The wrought iron cages creak as they sway.%^RESET%^");
     break;
   }

}

