// /d/magic/symbols/mystra_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","mystra_holy_symbol","medallion","silver medallion"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("silver medallion");
   set_short("a silver medallion");
   set_long("This medallion is finely crafted and sparkles in the light. Molded into the silver is a circle of stars with a stream of mist flowing through the center.");
}
