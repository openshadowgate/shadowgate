// /d/magic/symbols/loviatar_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","loviatar_holy_symbol","whip","black whip"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("black whip");
   set_short("a black whip");
   set_long("A small, nine-stranded black whip. The ends are barbed and painted blood-red, but the whip is not intended for use as a weapon.");
}
