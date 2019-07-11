// /d/magic/symbols/bane_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define SDESC ({"a black spiked gauntlet","a steel amulet"})

string sdesc;

void create(){
   ::create();
   if(!sdesc)
      sdesc = SDESC[random(sizeof(SDESC))];
   set_id(({"holy symbol","symbol","bane_holy_symbol"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_short(""+sdesc+"");
   if(sdesc == "a black spiked gauntlet"){
      set_long("This wicked looking spiked gauntlet is made from blackened steel.  Sharp menacing spikes rise off the gauntlet, giving it a fearful appearance.  The fingers of the gauntlet taper to wide, thick claw-like appendages.  On the back of the gauntlet the image of green rays squeezed forth from a black hand cannot be missed.");
      add_id("gauntlet");
   }
   if(sdesc == "a steel amulet") {
      set_long("Threaded on a twisted knotted cord, a round blackened steel amulet hangs.  The amulet is perfectly round and quite large.  The image of green rays being squeezed forth from a black fist hold attention in the center of the amulet.  The colors are quite bold and striking.");
      add_id("amulet");
   }
}

