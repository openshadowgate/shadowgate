// /d/magic/symbols/tyr_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","tyr_holy_symbol","shield","small shield"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("small shield");
   set_short("a small shield");
   set_long("This light shield is neither sturdy nor large enough to be of much use in battle. It is engraved with a detailed picture of a war hammer in the center of the shield. Atop the hammer sits the equally balanced scales of justice.");
}
