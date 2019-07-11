// /d/magic/symbols/mielikki_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","mielikki_holy_symbol","carving","ivory carving"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("ivory carving");
   set_short("an ivory carving");
   set_long("A flattened disk of ivory, beautifully carved. In the center is a unicorn's head, facing to the left. The head is bright white, standing out from the magically enchanted green background.");
}
