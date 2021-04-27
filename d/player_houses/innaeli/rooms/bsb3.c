#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game January 2008 :: Nienne 
// Wizard assisted by Lurue 

int burning;
string fire_desc();

void create(){ 
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("Kitchen of the Bloody Scourge"); 
   set_short("%^BOLD%^%^BLACK%^Kitchen of the "+
"%^RESET%^%^RED%^B%^BOLD%^%^RED%^lo%^RESET%^%^RED%^od%^BOLD%^"+
"%^RED%^y %^RESET%^%^RED%^S%^BOLD%^%^RED%^c%^RESET%^%^RED%^ou"+
"%^BOLD%^%^RED%^rg%^RESET%^%^RED%^e%^RESET%^"); 
   set_long("%^RESET%^You find yourself in the kitchen of the "+
"%^BOLD%^%^BLACK%^Bloody Scourge Inn%^RESET%^. Wonderful scents "+
"entice your senses from all the fantastic food served here. "+
"It is somewhat %^BOLD%^%^BLACK%^din%^RESET%^%^ORANGE%^g"+
"%^BOLD%^%^BLACK%^y%^RESET%^, and a little%^RESET%^ "+
"%^ORANGE%^d%^BOLD%^%^BLACK%^i%^RESET%^r%^ORANGE%^ty%^RESET%^. "+
"Used dishes cover the counters, as well as %^RESET%^%^ORANGE%^"+
"crumbs%^RESET%^ and some rotting %^BOLD%^%^GREEN%^v"+
"%^RESET%^%^GREEN%^e%^YELLOW%^g%^RESET%^%^ORANGE%^e%^BOLD%^"+
"%^GREEN%^t%^RESET%^%^GREEN%^a%^YELLOW%^b%^RESET%^%^ORANGE%^l"+
"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s%^RESET%^, which have "+
"unfortunately attracted a couple %^BOLD%^%^BLACK%^fli%^RESET%^"+
"e%^BOLD%^%^BLACK%^s%^RESET%^. There is a large %^BOLD%^"+
"%^BLACK%^stove%^RESET%^ and a %^BOLD%^pantry%^RESET%^ off to "+
"the side, along with a wide %^RESET%^%^RED%^fir%^BOLD%^%^RED%^"+
"ep%^RESET%^%^RED%^lace%^RESET%^. A %^RESET%^%^ORANGE%^wo"+
"%^BOLD%^%^BLACK%^o%^RESET%^d%^RESET%^%^ORANGE%^en b%^RESET%^"+
"%^RED%^u%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^ch%^BOLD%^%^BLACK%^"+
"e%^RESET%^%^ORANGE%^rs blo%^BOLD%^%^BLACK%^c%^RESET%^"+
"%^ORANGE%^k%^RESET%^ sits in the middle of the room, quite in "+
"the way. The floor is a mess and would probably be quite slippery "+
"if it was not for the small %^RESET%^%^CYAN%^throw rug%^RESET%^ "+
"which has collected quite a bit of %^RESET%^%^GREEN%^st"+
"%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^i%^RESET%^%^GREEN%^ns"+
"%^RESET%^ overtime.%^RESET%^");

   set_smell("default","%^RESET%^%^ORANGE%^The scent of food "+
"entices your senses.%^RESET%^"); 
   set_listen("default","%^BOLD%^%^BLACK%^There clatter of pots "+
"and pans is heard over drunken laughter.%^RESET%^"); 

   set_items(([ 
({"counter","counters"}):"%^RESET%^Scraps of %^RESET%^%^ORANGE%^"+
"f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^d%^RESET%^ "+
"litter the counter as well as a myriad of %^RESET%^%^RED%^s"+
"%^BOLD%^%^RED%^t%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^i%^RESET%^"+
"%^RED%^n%^BOLD%^%^RED%^s%^RESET%^ from previously prepared meals. "+
"The %^RESET%^%^ORANGE%^wooden counters%^RESET%^ are rather "+
"unimpressive, as are the %^BOLD%^%^BLACK%^flies%^RESET%^ that flit "+
"around them looking for a tasty morsel of food.%^RESET%^",

({"fireplace","fire"}): (:TO,"fire_desc":),

({"flies","fly"}):"%^BOLD%^%^WHITE%^Theyre hungry, pesky, and not "+
"at all appetizing.%^RESET%^",

({"stove"}):"%^RESET%^Some pots sit atop the stove, %^BOLD%^"+
"%^WHITE%^b%^RESET%^u%^BOLD%^%^WHITE%^bbl%^RESET%^in%^BOLD%^"+
"%^WHITE%^g%^RESET%^ with interesting concoctions.%^RESET%^",

({"pantry"}):"%^RESET%^The pantry hangs open, revealing shelves "+
"of jars, cans, sacks and a couple cooking implements. A sack of "+
"%^RESET%^%^ORANGE%^grain%^RESET%^ is spilled across the floor of "+
"the pantry, and was that a %^BOLD%^%^BLACK%^rat%^RESET%^ that "+
"just scurried from your view?%^RESET%^",

({"block"}):"%^RESET%^This small %^RESET%^%^ORANGE%^wooden "+
"table%^RESET%^ is a cutting board and a knife block all in one. "+
"%^BOLD%^%^WHITE%^Shining%^RESET%^, %^CYAN%^sharp%^RESET%^ knives "+
"are kept in convenient slots cut into the wood. The surface is "+
"scarred with deep cuts and it is stained a deep %^BOLD%^%^RED%^"+
"r%^RESET%^%^RED%^ed%^MAGENTA%^d%^RED%^is%^BOLD%^%^RED%^h%^RESET%^ "+
"hue.%^RESET%^",

({"rug"}):"%^RESET%^Haphazardly tossed onto the floor, the rug is "+
"%^BOLD%^%^BLACK%^black%^RESET%^ with a %^RESET%^%^RED%^"+
"c%^BOLD%^%^RED%^ri%^RESET%^%^RED%^ms%^BOLD%^%^RED%^o%^RESET%^"+
"%^RED%^n%^RESET%^ border. %^RESET%^%^ORANGE%^S%^RESET%^"+
"%^GREEN%^t%^RESET%^%^ORANGE%^ai%^BOLD%^%^GREEN%^n%^RESET%^"+
"%^ORANGE%^s%^RESET%^ cover its surface.%^RESET%^",

({"knob"}):(:TO,"knob_desc":),
   ])); 
   set_exits(([ 
"out":ROOMS"bsb1", 
   ])); 
   set_pre_exit_functions(({"out"}),({"goto_kitchen"}));
   set_search("default","You find nothing odd.");
   set_search("fireplace",(:TO,"search_fire":));
   set_search("fire",(:TO,"search_fire":));
   burning = 1;
} 

void reset() {
   if(!present("marcos the cook")) {
     find_object_or_load(MON"marcos")->move(TO);
     tell_room(TO,"%^BOLD%^%^WHITE%^Marcos swaggers back in, "+
"muttering under his breath.%^RESET%^");
   }
   if(!burning) {
     tell_room(TO,"%^BOLD%^%^WHITE%^The cook glares at the doused "+
"fireplace, and pauses in his work for a moment to relight the "+
"fire.%^RESET%^");
     burning = 1;
   }
}

void init() {
   ::init();
   add_action("douse_fun","douse");
   add_action("unlock_fun","turn");
}

int goto_kitchen(){
   if(!TP->query_true_invis()){
      tell_room(TO,"%^BOLD%^%^WHITE%^The b%^RESET%^ea%^BOLD%^d"+
"%^RESET%^e%^BOLD%^d c%^RESET%^u%^BOLD%^rta%^RESET%^in%^BOLD%^"+
"%^WHITE%^s rattle as they are drawn aside.%^RESET%^");
      tell_room(ROOMS"bsb1","%^BOLD%^%^WHITE%^The b%^RESET%^ea%^BOLD%^d"+
"%^RESET%^e%^BOLD%^d c%^RESET%^u%^BOLD%^rta%^RESET%^in%^BOLD%^%^WHITE%^"+
"s rattle as they are drawn aside.%^RESET%^");
   }
   return 1;
}

string fire_desc() {
   if(burning) return("%^RESET%^A hunk of %^ORANGE%^me%^BOLD%^"+
"%^BLACK%^a%^RESET%^%^ORANGE%^t%^RESET%^ hangs from a spit over "+
"the %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^RESET%^%^MAGENTA%^"+
"a%^ORANGE%^z%^RED%^i%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^g "+
"fi%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^RESET%^. It smells "+
"amazing.%^RESET%^");
   return("%^RESET%^A hunk of %^ORANGE%^me%^BOLD%^"+
"%^BLACK%^a%^RESET%^%^ORANGE%^t%^RESET%^ hangs from a spit over "+
"the fireplace, cooling over the doused embers.%^RESET%^");
}

string knob_desc() {
   if(burning) return("You do not notice that here.");
   return("%^RESET%^There is a small %^BOLD%^%^BLACK%^knob%^RESET%^, "+
"hidden in a niche at the back of the fireplace.%^RESET%^");
}

int douse_fun(string str) {
   if(!str) {
     tell_object(TP,"Douse what?");
     return 1;
   }
   if(str != "fire" && str != "fireplace" && str != "flames") {
     tell_object(TP,"You realise that wouldn't be very helpful.");
     return 1;
   }
   if(!burning) {
     tell_object(TP,"The fireplace has already been put out.");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You grab a boiling pot off the "+
"stove and toss it over the fire! The smoldering embers hiss.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" grabs a boiling pot off "+
"the stove and tosses it over the fire! The smoldering embers "+
"hiss.%^RESET%^",TP);
   if(present("marcos the cook")) {
     tell_room(TO,"%^RESET%^%^MAGENTA%^Marcos grumbles loudly: %^RESET%^"+
"Whadda ye tink ye be doin?! Git outta me kitchen!%^RESET%^");
     tell_room(ROOMS"bsb4","%^BOLD%^%^WHITE%^You hear some shouting "+
"coming from upstairs.%^RESET%^");
   }
   burning = 0;
   return 1;
}

int search_fire(string str) {
   if(burning) {
     tell_object(TP,"%^BOLD%^%^RED%^The fire scorches your fingers as "+
"you reach into the fire. Wow, that was really stupid. Maybe you should "+
"have %^BOLD%^%^BLACK%^doused%^BOLD%^%^RED%^ the flames first.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^RED%^"+TP->QCN+" goes to poke around at the "+
"fireplace and only ends up with burnt fingers. Wow, that was really "+
"stupid.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^You poke around in the fireplace and "+
"come out covered in soot. After some extensive prodding and poking you "+
"suspect the back wall is hollow. You find a small knob, nestled in a "+
"niche at the back.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TP->QCN+" pokes around in the "+
"fireplace and comes out covered in soot.%^RESET%^",TP);
   return 1;
}

int unlock_fun(string str) {
   if(!str) return 0;
   if(str == "knob") {
     if(burning) {
       tell_object(TP,"How could you reach it through the flames?");
       return 1;
     }
     if(member_array("fireplace",TO->query_exits()) != -1) {
       tell_object(TP,"%^BOLD%^%^WHITE%^You turn the knob back to its "+
"original position, and the hidden entry in the fireplace closes.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pokes around in the "+
"fireplace, and the hidden entry suddenly swings shut.%^RESET%^",TP);
       TO->remove_exit("fireplace");
       if(member_array("north",ROOMS"bsb4"->query_exits()) != -1) {
         tell_room(ROOMS"bsb4","%^BOLD%^%^BLACK%^The hidden doorway on the "+
"wall swings closed.%^RESET%^");
         ROOMS"bsb4"->remove_exit("north");
       }
       return 1;
     }
     tell_object(TP,"%^BOLD%^%^WHITE%^You turn the knob, and a hidden "+
"entry in the fireplace swings open.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pokes around in the "
"fireplace, and a hidden entry suddely swings open.%^RESET%^",TP);
     TO->add_exit(ROOMS"bsb4","fireplace");
     if(member_array("north",ROOMS"bsb4"->query_exits()) == -1) {
       tell_room(ROOMS"bsb4","%^BOLD%^%^BLACK%^A hidden doorway in the "
"wall swings open!%^RESET%^");
       ROOMS"bsb3"->add_exit(ROOMS"bsb3","north");
     }
     return 1;
   }
   return 0;
}