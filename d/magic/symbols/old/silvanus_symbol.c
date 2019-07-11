// /d/magic/symbols/silvanus_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","silvanus_holy_symbol","pin","copper pin"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("copper pin");
   set_short("a copper pin");
   set_long("This is a delicately made copper pin, polished and shining. It is the shape and size of an oak leaf, and it seems to move in the breeze and take on a greenish tint as if it could be alive.");
}
