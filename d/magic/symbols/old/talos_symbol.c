// /d/magic/symbols/talos_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","talos_holy_symbol","disk","ruby disk"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("ruby disk");
   set_short("a ruby disk");
   set_long("This flat, but extremely polished ruby disk has inset in it a lightning bolt made of pure diamond. Along side the lightning bolt are two white jade bars that cross the disk horizontally. The lightning bolt curves upward to the left between the jade bars, then abruptly ascends into a sharp zigzag.");
}
