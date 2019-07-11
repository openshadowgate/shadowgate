// /d/magic/symbols/xvim_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","xvim_holy_symbol","pendant","onyx pendant"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("onyx pendant");
   set_short("an onyx pendant");
   set_long("The black onyx of the pendant has been carved into the shape of a hand. Two glowing green emeralds are set in the palm of the hand.");
}

