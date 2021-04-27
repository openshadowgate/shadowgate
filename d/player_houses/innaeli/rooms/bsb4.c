#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create(){  
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("A dark chamber"); 
   set_short("%^BOLD%^%^BLACK%^A d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^"
"rk %^RESET%^%^RED%^c%^BOLD%^%^BLACK%^ham%^RESET%^%^RED%^b%^BOLD%^"
"%^BLACK%^er%^RESET%^"); 
   set_long("%^BOLD%^%^BLACK%^Welcome to the playroom! As your eyes "
"adjust to the pervading darkness, you realize that the lack of "
"light was a comfort - theres no mistaking the singular purpose "
"of this place. Primitive torches line the crudely cut stone walls "
"and pierce the dimness, revealing the instruments of %^RESET%^"
"%^RED%^t%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^rt%^BOLD%^%^BLACK%^u"
"r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ that await you here. A rack "
"of %^BOLD%^%^WHITE%^s%^RESET%^h%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^"
"n%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^ "
"swords, daggers, maces and flails sits off to the side, while an "
"impressive collection of %^RESET%^%^RED%^whips%^BOLD%^%^BLACK%^ "
"hangs above it. A couple cages are piled in the corner, and rope "
"hangs through iron rings on the walls. There are %^RESET%^manacles"
"%^BOLD%^%^BLACK%^ everywhere - a twisted ornamentation to the "
"walls, chairs and tables. A %^BOLD%^%^RED%^b%^RESET%^%^RED%^la"
"%^BOLD%^%^BLACK%^z%^RESET%^%^MAGENTA%^i%^ORANGE%^n%^BOLD%^%^RED%^"
"g%^RESET%^%^RED%^ fire%^BOLD%^%^BLACK%^ burns in a centralized "
"fire pit, but in this atmosphere there is nothing remotely warm "
"or cozy about it. The room is hazy and smells of death, smoke, "
"blood and decay. It feels small and claustrophobic here. You begin "
"to long for fresh air and the light of day...%^RESET%^");

   set_smell("default","%^RESET%^%^RED%^Fire crackles...%^RESET%^"); 
   set_listen("default","%^RESET%^%^ORANGE%^The stagnant air is "
"stifling and awful.%^RESET%^"); 

   set_items(([ 
({"torch","torches"}):"%^BOLD%^%^BLACK%^The torches are small, "
"providing little light. They are crude and primitive, and are "
"easily pulled from the walls.%^RESET%^",

({"instruments"}):"%^BOLD%^%^BLACK%^Here is a stretching rack, "
"there an iron chair. Crude crosses hang on the walls, iron rings "
"with rope for hanging, nooses, blades, metal boots and gloves, "
"cages, iron balls, clamps and so much more! One could literally "
"spend hours here, figuring out the %^RESET%^%^RED%^morbid"
"%^BOLD%^%^BLACK%^ purposes of all these toys. Twisted %^BOLD%^"
"%^WHITE%^s%^RESET%^p%^BOLD%^%^BLACK%^ik%^RESET%^e%^BOLD%^%^WHITE%^"
"s%^BOLD%^%^BLACK%^ cover almost every surface, their shining tips "
"glimmering in the dim light.%^RESET%^",

({"walls","wall"}):"%^BOLD%^%^BLACK%^The walls are cut from stone, "
"rather crude and jaggedly. They are blackened from the smoke that "
"lingers in the air. They also appear to be smeared with %^BOLD%^"
"%^RED%^b%^RESET%^%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^BOLD%^"
"%^BLACK%^, forming words and images - offerings and praises to the "
"dark gods.%^RESET%^",

({"whips","rack","weapons"}):"%^BOLD%^%^BLACK%^Some of these "
"implements appear well-loved and cared for, while others are "
"rusty and old. There are swords, long and short, curved and "
"serrated. Metal flails, wooden clubs, fiery whips, and barbed "
"leather lashes... all things imaginable are found here. A lot of the "
"weapons bear a signet - a small engraving of a face, its mouth open "
"and wide in %^RESET%^%^CYAN%^laughter%^BOLD%^%^BLACK%^, which upon "
"closer inspection becomes %^RESET%^%^RED%^horrid anguish%^BOLD%^"
"%^BLACK%^.%^RESET%^",

({"cages"}):"%^BOLD%^%^BLACK%^The lockable cages come in a variety "
"of sizes and are made of metal, lined with sharp barbs. One or two "
"are simply iron boxes, which would be excellent for %^RESET%^"
"sensory depravation%^BOLD%^%^BLACK%^. None appear to be clean, and "
"each appears to be used, evident by the %^BOLD%^%^RED%^b%^RESET%^"
"%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ thats "
"smeared across the inside.%^RESET%^",

({"manacles"}):"%^BOLD%^%^BLACK%^Spiked manacles are available to "
"hold anyone to any surface. Some are %^RESET%^metal%^BOLD%^"
"%^BLACK%^, others are %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLACK%^. "
"Obviously, they are intended to keep people in their place. %^RESET%^",

({"fire","fire pit","firepit"}):"%^BOLD%^%^BLACK%^A circle of "
"black stones marks the borders of this large pit of fire. Hot "
"%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^als%^BOLD%^"
"%^BLACK%^ blaze beneath the flames. %^RESET%^Chains%^BOLD%^"
"%^BLACK%^ dangle from the ceiling above the pit, their links "
"blackened from the searing fire. How creepy.%^RESET%^",

"knob":"%^BOLD%^%^BLACK%^At a closer look, you realise there is a small knob "
"beside the outline of the door.%^RESET%^",

({"door","outline"}):"%^BOLD%^%^BLACK%^At the top of a couple steps is the "
"outline of a door. Its surface is cold and flat, and there is a small knob on "
"the wall beside it.%^RESET%^",
   ])); 

   set_search("default","You find nothing odd.");
   set_search("walls","%^BOLD%^%^BLACK%^You wander up a couple steps "+
"and find the outline of a door at the top. Its surface is cold and "+
"flat, and there is a small knob on the wall beside it.%^RESET%^");
   set_search("wall","%^BOLD%^%^BLACK%^You wander up a couple "+
"steps and find the outline of a door at the top. Its surface is cold "+
"and flat, and there is a small knob on the wall beside it.%^RESET%^");
} 

void init() {
   ::init();
   add_action("unlock_fun","turn");
}

int unlock_fun(string str) {
   if(!str) return 0;
   if(sizeof(TP->query_attackers())) {
     tell_object(TP,"You can't do that, you're too busy fighting!");
     return 1;
   }
   if(str == "knob") {
     if(member_array("north",TO->query_exits()) != -1) {
       tell_object(TP,"%^BOLD%^%^WHITE%^You turn the knob back to its "+
"original position, and the hidden door closes.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" turns the knob, and the "
"hidden door swings shut.%^RESET%^",TP);
       TO->remove_exit("north");
       if(member_array("fireplace",ROOMS"bsb3"->query_exits()) != -1) {
         tell_room(ROOMS"bsb3","%^BOLD%^%^BLACK%^The hidden doorway in the "
"fireplace swings closed.%^RESET%^");
         ROOMS"bsb3"->remove_exit("fireplace");
       }
       return 1;
     }
     tell_object(TP,"%^BOLD%^%^WHITE%^You turn the knob, and a hidden "+
"doorway swings open.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" turns the knob, and a hidden doorway swings open.%^RESET%^",TP);
     TO->add_exit(ROOMS"bsb3","north");
       if(member_array("fireplace",ROOMS"bsb3"->query_exits()) == -1) {
         tell_room(ROOMS"bsb3","%^BOLD%^%^BLACK%^A hidden doorway in the "
"fireplace swings open!%^RESET%^");
         ROOMS"bsb3"->add_exit(ROOMS"bsb4","fireplace");
       }
     return 1;
   }
   return 0;
}
