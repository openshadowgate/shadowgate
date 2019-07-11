// /d/magic/symbols/selune_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","selune_holy_symbol","brooch","silver brooch"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("silver brooch");
   set_short("a silver brooch");
   set_long("A small silver brooch, elaborately decorated. Two dark eyes peer out from the center of the brooch, surrounded by a circle of seven bright stars that sparkle in the moonlight.");
}

