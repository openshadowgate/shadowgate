// Stefano's idol for devil rituals

#include <std.h>

inherit "/std/Object";

void create() {
   ::create();
   set_name("idol");
   set_id(({"idol","block"}));
   set_short("%^RESET%^%^WHITE%^An ugly, squat %^BOLD%^%^BLACK%^block of onyx %^RESET%^%^WHITE%^chained to a %^BOLD%^%^WHITE%^marble pedestal%^RESET%^");
   set_long(
      "%^BOLD%^%^BLACK%^A solid block of onyx, about the size of an ogre's head, shaped into an"+
      " irregular rectangle. The edges are rounded and blunted, the curves of them"+
      " flowing downwards like part-molten wax. On closer inspection, it appears"+
      " that it may be a box of some description. A faint line around the top looks"+
      " suspiciously like a lid, and there are a couple of notches at the back"+
      " which could be hinges. The top of a large, %^RESET%^%^RED%^dull red ruby %^BOLD%^%^BLACK%^can be seen in the"+
      " lid, the surrounding onyx almost covering, as if the gem has sunk into the"+
      " surrounding stone like a victim into quicksand. A single, %^BOLD%^%^GREEN%^elaborate green"+
      " sigil %^BOLD%^%^BLACK%^has been inscribed on the front of the box."
   );
   set_weight(1000);
   set_property("no animate",1);
   set_value(0);
}

void init() {
   ::init();
   add_action("look_pedestal","look");
   add_action("look_chains","look");
   add_action("look_gem","look");
   add_action("vibrate_block","vibrate");
   add_action("glow_block","glow");
   add_action("fade_block","fade");
   add_action("rattle_block","rattle");
   add_action("fly_block","fly");
}

int look_pedestal(string str) {
   if(str != "pedestal") {
   return 0;
   }
   tell_object(TP,
      "%^BOLD%^%^WHITE%^The m%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^rble pedestal is quite low, standing only two feet from the floor."+
      " Its top and base are circular, and the pillar is thick, as if designed to"+
      " bear great weight. %^RESET%^Chains %^BOLD%^%^WHITE%^loop up from the pedestal, holding the %^BOLD%^%^BLACK%^onyx block%^BOLD%^%^WHITE%^"+
      " in place.");
   tell_room(ETP,""+TPQCN+" looks over the pedestal.",TP);
   return 1;
}

int look_chains(string str) {
   if(str != "chains") {
   return 0;
   }
   tell_object(TP,
      "%^RESET%^The chains are made from adamantite and look very thick and heavy. They"+
      " wrap tightly around the %^BOLD%^%^BLACK%^onyx block %^RESET%^and some of them loop beneath it,"+
      " holding it securely in place. A single, very solid looking lock secures all"+
      " the chains together. It has no obvious keyhole.");
   tell_room(ETP,""+TPQCN+" looks over the chains.",TP);
   return 1;
}

int look_gem(string str) {
   if(str != "gem") {
   return 0;
   }
   tell_object(TP,"The ruby seems to glow with a %^RESET%^%^RED%^sullen red l%^BOLD%^%^RED%^i%^RESET%^%^RED%^ght%^RESET%^, deep in its core.");
   tell_room(ETP,""+TPQCN+" looks over the gem.",TP);
   return 1;
}

int vibrate_block(string str) {
   if(str != "block") {
   return 0;
   }
   tell_object(TP,
      "%^BOLD%^%^BLACK%^The strange onyx block begins to %^BOLD%^%^WHITE%^shake %^BOLD%^%^BLACK%^and %^BOLD%^%^YELLOW%^tremble %^BOLD%^%^BLACK%^on its pedestal, the"+
      " vibrations running through the floor to your feet.");
   tell_room(ETP,"%^BOLD%^%^BLACK%^The strange onyx block begins to %^BOLD%^%^WHITE%^shake %^BOLD%^%^BLACK%^and %^BOLD%^%^YELLOW%^tremble %^BOLD%^%^BLACK%^on its pedestal, the"+
      " vibrations running through the floor to your feet.",TP);
   return 1;
}

int glow_block(string str) {
   if(str != "block") {
   return 0;
   }
   tell_object(TP,
      "%^RESET%^Suddenly, an %^RESET%^%^RED%^eerie red light %^RESET%^starts to glow from the gem set into the"+
      " %^BOLD%^%^BLACK%^strange onyx block%^RESET%^. As seconds pass it grows %^RESET%^%^RED%^br%^BOLD%^%^RED%^i%^RESET%^%^RED%^ghter and %^BOLD%^%^RED%^br%^RESET%^%^RED%^i%^BOLD%^%^RED%^ghter%^RESET%^.");
   tell_room(ETP,"%^RESET%^Suddenly, an %^RESET%^%^RED%^eerie red light %^RESET%^starts to glow from the gem set into the"+
      " %^BOLD%^%^BLACK%^strange onyx block%^RESET%^. As seconds pass it grows %^RESET%^%^RED%^br%^BOLD%^%^RED%^i%^RESET%^%^RED%^ghter and %^BOLD%^%^RED%^br%^RESET%^%^RED%^i%^BOLD%^%^RED%^ghter%^RESET%^.",TP);
   return 1;
}

int fade_block(string str) {
   if(str != "block") {
   return 0;
   }
   tell_object(TP,"The %^RESET%^%^RED%^glow %^RESET%^from the gem set into the block fades abrubtly and disappears.");
   tell_room(ETP,"The %^RESET%^%^RED%^glow %^RESET%^from the gem set into the block fades abrubtly and disappears.",TP);
   return 1;
}

int rattle_block(string str) {
   if(str != "block") {
   return 0;
   }
   tell_object(TP,
      "%^RESET%^The chains wrapped around the %^BOLD%^%^BLACK%^strange onyx block %^RESET%^begin to rattle, then go"+
      " completely taut and quiet. In the near silence that follows, you can hear a"+
      " faint sound of straining metal, and you realise that the %^BOLD%^%^BLACK%^block %^RESET%^is growing,"+
      " its increasing size stretching the chains to their limits.");
   tell_room(ETP,"%^RESET%^The chains wrapped around the %^BOLD%^%^BLACK%^strange onyx block %^RESET%^begin to rattle, then go"+
      " completely taut and quiet. In the near silence that follows, you can hear a"+
      " faint sound of straining metal, and you realise that the %^BOLD%^%^BLACK%^block %^RESET%^is growing,"+
      " its increasing size stretching the chains to their limits.",TP);
   return 1;
}

int fly_block(string str) {
   if(str != "block") {
   return 0;
   }
   tell_object(TP,
      "%^BOLD%^%^YELLOW%^There is a sudden, %^BOLD%^%^CYAN%^painfully shrill wailing %^BOLD%^%^YELLOW%^and the %^BOLD%^%^BLACK%^onyx %^BOLD%^%^YELLOW%^block lifts a"+
      " couple of inches into the air, carrying its chains and its pedestal with"+
      " it. It holds there for a couple of seconds, then collapses back onto the"+
      " floor in silence.");
   tell_room(ETP,"%^BOLD%^%^YELLOW%^There is a sudden, %^BOLD%^%^CYAN%^painfully shrill wailing %^BOLD%^%^YELLOW%^and the %^BOLD%^%^BLACK%^onyx %^BOLD%^%^YELLOW%^block lifts a"+
      " couple of inches into the air, carrying its chains and its pedestal with"+
      " it. It holds there for a couple of seconds, then collapses back onto the"+
      " floor in silence.",TP);
   return 1;
}
