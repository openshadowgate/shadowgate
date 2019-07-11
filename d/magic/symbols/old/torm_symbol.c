// /d/magic/symbols/torm_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","torm_holy_symbol","shield","silver shield"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("silver shield");
   set_short("a silver shield");
   set_long("The shield is made of pure silver. In the center, there is a carving of an open right-handed gauntlet, palm facing outward. Carvings of three black arrows surround the gauntlet, looking as if they are embedded in the shield itself.");
}
