// /d/magic/symbols/lathander_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","lathander_holy_symbol","disk","quartz disk"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("quartz disk");
   set_short("a quartz disk");
   set_long("A piece of rose quartz, enchanted to radiate a warm glow. The disk hangs from a brightly-colored sash.");
}
