// /d/magic/symbols/tymora_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define SDESC ({"a silver pendant","a silver anklet","a silver bracelet"})

string sdesc;

void create(){
   ::create();
   if(!sdesc)
      sdesc = SDESC[random(sizeof(SDESC))];
   set_id(({"holy symbol","symbol","tymora_holy_symbol"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_short(""+sdesc+"");
   if(sdesc == "a silver pendant"){
      set_long("What looks to be a silver pendant at first, you come to realize is a silver coin that has been strung on a length of thread.  The silver coin looks well-worn, as if it's been rubbed numerous times.  An image of a female human winking at you appears on the coin.");
      add_id("pendant");
      add_id("silver pendant");
   }
   if(sdesc == "a silver anklet") {
      set_long("This anklet has been made from silver mesh that glitters and sparkles.  The anklet has a fragile clasp on it.  One must take care of they might break it - and that would be unlucky.  Thin silver disks hang from the mesh around the anklet.  The largest disk, you realize, is actually a silver coin that bears the engraved image of a female human winking at you.");
      add_id("anklet");
      add_id("silver anklet");
   }
   if(sdesc == "a silver bracelet") {
      set_long("This bracelet has been made from twisted band of silver that have been braided together.  The bracelet is neither too feminine nor too masculine in design, instead looking like something either sex would wear.  Hanging from the center of the bracelet is a silver coin.  The coin bears the image of a female human winking at you.");
      add_id("bracelet");
      add_id("silver bracelet");
    }
}

