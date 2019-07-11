// /d/magic/symbols/tempus_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","tempus_holy_symbol","gauntlet","spiked gauntlet"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("spiked gauntlet");
   set_short("a spiked gauntlet");
   set_long("Made of strong steel, this is a spiked war gauntlet. A blazing silver sword is on the back of the gauntlet, magically coloured to appear as if always coated in blood.");
}
