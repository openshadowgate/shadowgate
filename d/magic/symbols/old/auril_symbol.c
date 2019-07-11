// /d/magic/symbols/auril_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","auril_holy_symbol","axe","ice axe"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("ice axe");
   set_short("an ice axe");
   set_long("This is a small axe carried for decoration, not for battle. On the silver blade of the axe is a gray diamond with a white border, covered with a detailed etching of a white snowflake.");
}

