#include <std.h>
#include "../kier.h"
inherit VAULT;
int fire;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Rooftop of a Tower");
   set_short("%^RESET%^%^ORANGE%^Rooftop of a Tower%^RESET%^");
   set_long("%^ORANGE%^The rooftop of the tower has a stunning view of the "
"ocean to the east, the mountains to the west, and the sky. You are up high "
"enough that the pounding surf is but a whisper to you, and the wind is "
"constant. There is a large couch to one side covered by a large awning, and "
"the centre of the rooftop is dominated by a large firepit.%^RESET%^");
   set_smell("default",(:TO,"smell":));
   set_listen("default",(:TO,"listen":));

   set_items(([
     ({"firepit"}) : "%^BLACK%^%^BOLD%^A large firepit dominates the top of "
"the tower.%^RESET%^",
     ({"couch"}) : "%^RESET%^%^RED%^Covered in soft red canvas, this couch "
"could either face the firepit or the sea.%^RESET%^",
     ({"stairs"}) : "%^BLACK%^%^BOLD%^Formed out of black wrought iron, these "
"stairs spiral downwards to the lower floor of the tower. The handrail is "
"formed into a shooting star, and the railings are filled with designs of "
"%^RESET%^%^BOLD%^m%^RESET%^o%^BOLD%^o%^RESET%^ns%^BLACK%^%^BOLD%^ and "
"%^RESET%^%^BOLD%^st%^CYAN%^a%^RESET%^r%^BOLD%^s%^BLACK%^%^BOLD%^. The stairs "
"are a work of beauty.%^RESET%^",
     ({"contraption","telescope"}) : "This is a truly strange item. It looks "
"like an oversized spyglass on a tripod. On the side is written, "
"'Grytelephopicenassurifiz Telescopes'. By looking in the viewer, anything "
"on the other end is magnified. It is pointed at the sky, and would be "
"perfect for viewing the moon and stars",
     ({"awning"}) : "Supported on two oak beams, an awning made of "
"%^ORANGE%^tan canvas%^RESET%^ covers half of the rooftop from the elements. It snaps and tugs in the breeze.",           
   ]));

   set_exits(([
     "down" : ROOMS+"bedroom",
   ]));
   fire = 0;
}

void reset() {
   ::reset();
   if(fire) {
     tell_room(TO,"%^RESET%^%^RED%^The last embers in the fireplace splutter "
"and die.%^RESET%^");	
     fire = 0;
   }
}

void init(){
   ::init();
   add_action("light","light");
}

string smell(string str){
   if(fire) return("%^BLACK%^%^BOLD%^The smell of the small fire mixes with "
"the salty breeze.%^RESET%^");
   return("%^CYAN%^The salty breeze envelopes you with the smells of the "
"sea.%^RESET%^");
}

string listen(string str){
   if(fire) return("%^RED%^%^BOLD%^The fire crackles and pops.%^RESET%^");
   return("You can hear the sound of crashing waves on the beach "
"below.%^RESET%^");
}

int light(string str){
   if(!str) return 0;
   if(str != "fire"){
     notify_fail("You can't light that.\n");
     return 0;
   }
   if(fire){
     tell_object(TP,"%^RED%^%^BOLD%^The fire is already lit.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^RESET%^%^RED%^You light the fire, standing back as it "
"roars to life.%^RESET%^");
   tell_room(TO,"%^RESET%^%^RED%^"+TPQCN+" lights the fire, standing back as "
"it roars to life.%^RESET%^",TP);
   fire = 1;
   return 1;
}
