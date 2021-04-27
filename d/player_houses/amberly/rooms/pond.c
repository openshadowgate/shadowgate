//Octothorpe (7/28/10)
//Amberly's HM house, Pond

#include <std.h>
#include "../amberly.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_property("fill waterskin",1);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("Deeper in the garden");
   set_short("Deeper in the garden");
   set_long("%^GREEN%^Hidden deeper in the %^BOLD%^foliage, %^RESET%^"+
      "%^GREEN%^nestled in dark, heavy brush and a solid cliff face, "+
	  "is a more secluded portion of the garden. %^BOLD%^Lush grass "+
	  "%^RESET%^%^GREEN%^covers the ground, speckled with sprouts of "+
	  "d%^WHITE%^e%^GREEN%^wy clover and the soft %^MAGENTA%^pink bud "+
	  "tips %^GREEN%^of flowering vines. The forest is so thick around "+
	  "you that the sounds of the busy road are muted to silence, giving "+
	  "the impression of privacy. The area is filled with the %^WHITE%^"+
	  "gentle echo %^GREEN%^of the trees swaying in the breeze and "+
	  "%^ORANGE%^song birds %^GREEN%^frolicking somewhere out of sight. "+
	  "A large %^YELLOW%^k%^BLACK%^o%^YELLOW%^i pond %^RESET%^%^GREEN%^"+
	  "dominates the center of the area, fed by small, %^BLUE%^streaming "+
	  "ripples %^GREEN%^off the cliff face. %^BOLD%^%^WHITE%^Stepping "+
	  "stones, %^BLACK%^beautifully %^RESET%^%^GREEN%^carved, lead to "+
	  "the center of a rocky dais surrounded with %^BOLD%^ferns and "+
	  "moss. %^RESET%^%^GREEN%^Standing in the middle of the structure "+
	  "is the statue of a %^CYAN%^winged woman %^GREEN%^with her arms "+
	  "outstretched to the %^BOLD%^%^CYAN%^heavens. %^RESET%^%^GREEN%^"+
	  "Paper %^ORANGE%^lanterns %^GREEN%^fill hidden crevices around "+
	  "the garden providing an %^RED%^undemanding light %^GREEN%^to "+
	  "twinkle across the %^BLUE%^watery bed. %^GREEN%^On either side "+
	  "of the dais are %^WHITE%^long wooden poles %^GREEN%^festooned "+
	  "with multi colored %^MAGENTA%^r%^BLUE%^i%^WHITE%^b%^ORANGE%^b"+
	  "%^GREEN%^o%^CYAN%^n%^MAGENTA%^s %^GREEN%^and %^WHITE%^feathers. "+
	  "%^GREEN%^With each gust of wind they wave erratically, creating "+
	  "a beautiful sight, though often find themselves %^CYAN%^drifting "+
	  "%^GREEN%^into the forest. The entire area is filled with a sense "+
	  "of %^BOLD%^%^CYAN%^ever shifting winds %^RESET%^%^GREEN%^and "+
	  "somehow remains %^BOLD%^%^WHITE%^p%^RESET%^e%^BOLD%^a%^RESET%^"+
	  "c%^BOLD%^e%^RESET%^f%^BOLD%^u%^RESET%^l.\n");
   set_smell("default","%^BOLD%^%^CYAN%^A damp floral scent drifts across the area.");
   set_listen("default","%^CYAN%^The wind sings as it weaves through the trees.");
   set_items(([
      "statue":"%^BOLD%^%^WHITE%^It is difficult not to stare at the "+
	     "strange, yet %^CYAN%^c%^BLUE%^a%^WHITE%^p%^CYAN%^t%^BLUE%^i"+
		 "%^WHITE%^v%^WHITE%^a%^CYAN%^t%^BLUE%^i%^WHITE%^n%^CYAN%^g "+
		 "%^WHITE%^marble statue of a woman kneeling in %^BLACK%^"+
		 "sorrow. %^WHITE%^Her almost life-like wings lay limp across "+
		 "her back as she seems to beg the %^GREEN%^heavens %^WHITE%^"+
		 "for some %^YELLOW%^boon.%^RESET%^",
      "dais":"%^BOLD%^%^WHITE%^A circular mix of s%^BLACK%^m%^WHITE%^"+
	     "ooth m%^BLACK%^a%^WHITE%^rble and %^RESET%^jagged rocks "+
		 "%^BOLD%^%^WHITE%^surrounded by the %^CYAN%^r%^WHITE%^i%^CYAN%^p"+
		 "%^WHITE%^p%^CYAN%^l%^WHITE%^i%^CYAN%^n%^WHITE%^g %^CYAN%^"+
		 "pond. %^WHITE%^The upraised dais is made up of two %^BLUE%^"+
		 "separate tiers %^WHITE%^and large enough to perform a wide "+
		 "vareity of things on, if needed. A %^BOLD%^%^BLACK%^marble "+
		 "statue %^WHITE%^kneels in the center of the top tier.%^RESET%^",
      ({"stones","stepping stones"}):"%^RESET%^%^MAGENTA%^Each "+
	     "%^BOLD%^%^WHITE%^m%^BLACK%^a%^WHITE%^rble s%^BLACK%^t%^WHITE%^"+
		 "ep %^RESET%^%^MAGENTA%^has been lovingly carved into the "+
		 "shape of one %^GREEN%^creature %^MAGENTA%^or another. The "+
		 "artist seems somewhat biased in that the majority of the "+
		 "stones are %^BOLD%^%^BLACK%^dragons, %^MAGENTA%^butterflies "+
		 "%^RESET%^%^MAGENTA%^and %^RED%^sparrows.%^RESET%^",
      "pond":"%^CYAN%^The water is %^WHITE%^clear %^CYAN%^enough to "+
	     "see the %^BLUE%^smooth stones %^CYAN%^that line the %^BOLD%^"+
		 "%^CYAN%^watery bed %^RESET%^%^CYAN%^and the %^BOLD%^%^BLACK%^"+
		 "c%^ORANGE%^o%^RESET%^l%^ORANGE%^o%^BOLD%^r%^WHITE%^f%^BLACK%^u"+
		 "%^ORANGE%^l fish %^RESET%^%^CYAN%^that dart across the "+
		 "otherwise %^WHITE%^tranquil %^CYAN%^pond.%^RESET%^",
      ({"koi","fish"}):"%^MAGENTA%^A few dozen %^BOLD%^%^BLACK%^m"+
	     "%^YELLOW%^o%^WHITE%^t%^YELLOW%^l%^BOLD%^%^BLACK%^ey s%^YELLOW%^"+
		 "c%^BLACK%^aled %^WHITE%^k%^YELLOW%^o%^WHITE%^i %^RESET%^"+
		 "%^MAGENTA%^swim across the %^BLUE%^liquid bed "+
		 "%^MAGENTA%^peacefully.",
      ({"pole","poles"}):"%^ORANGE%^Long, %^YELLOW%^bamboo poles "+
	     "%^RESET%^%^ORANGE%^decorated with small ornamental %^GREEN%^r"+
		 "%^BLUE%^i%^MAGENTA%^b%^ORANGE%^b%^CYAN%^o%^WHITE%^n%^GREEN%^"+
		 "s %^ORANGE%^and %^BOLD%^%^WHITE%^f%^BLACK%^e%^WHITE%^athers, "+
		 "%^RESET%^%^ORANGE%^rise out of the %^CYAN%^pond %^ORANGE%^on "+
		 "either side of the %^BOLD%^%^WHITE%^dais.%^RESET%^",
      ({"ribbons","feathers"}):"%^GREEN%^Hundreds of %^MAGENTA%^m"+
	     "%^GREEN%^u%^MAGENTA%^l%^CYAN%^t%^MAGENTA%^i%^BLUE%^c"+
		 "%^MAGENTA%^o%^GREEN%^l%^MAGENTA%^o%^GREEN%^r%^MAGENTA%^e"+
		 "%^GREEN%^d ribbons and %^WHITE%^feathers %^GREEN%^dance on "+
		 "the %^CYAN%^breeze.%^RESET%^",
      ({"lanterns","paper lanterns"}):"%^RED%^A gentle %^WHITE%^"+
	     "spattering %^RED%^of %^ORANGE%^light %^RED%^spills over the "+
		 "%^GREEN%^garden, %^RED%^coming from %^BOLD%^paper lanterns "+
		 "%^RESET%^%^RED%^hanging from %^GREEN%^trees %^RED%^and in "+
		 "%^BOLD%^%^BLACK%^hidden crevices %^RESET%^%^RED%^around the "+
		 "%^BOLD%^%^WHITE%^dais.%^RESET%^",
   ]));
   set_exits(([
      "southwest":ROOMS"garden"
   ]));
}

void reset(){
   switch(random(2)){
      case 0:
	     tell_room(TO,"%^MAGENTA%^Somewhere nearby a %^GREEN%^s%^YELLOW%^"+
		    "o%^RESET%^%^GREEN%^ngbird %^MAGENTA%^sings an %^BOLD%^"+
			"%^GREEN%^en%^BLACK%^c%^GREEN%^h%^BLACK%^a%^WHITE%^n"+
			"%^GREEN%^ting tune.%^RESET%^");
		 break;
      case 1:
	     tell_room(TO,"%^GREEN%^The %^BOLD%^t%^ORANGE%^r%^GREEN%^ees "+
		    "%^RESET%^%^GREEN%^rustle against the %^CYAN%^w%^BOLD%^"+
			"%^WHITE%^i%^RESET%^%^CYAN%^nd.");
		 break;
   }
}

void init(){
   ::init();
   add_action("stare_statue","stare");
   add_action("drink","drink");
}

int stare_statue(string str){
   if(str == "statue"){
      tell_room(ETP,"%^CYAN%^"+TPQCN+" can't help but stare at the "+
	     "sorrowful statue.%^RESET%^",TP);
	  TP->move_player(ROOMS"grotto");
	  return 1;
   }
}

int drink(string str){
   if(str != "water" && str != "pond")  return 0;
   if(!str) return 0;     
   if(!TP->add_quenched(50)){
      tell_object(TP,"You are already quite quenched.");
      return 1;
   }
   tell_object(TP,"You take a large drink from the pond.");
   tell_room(TO,TPQCN+" bends down and takes a large drink from the pond.",TP);
   return 1;
}