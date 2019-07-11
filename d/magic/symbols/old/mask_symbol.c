// /d/magic/symbols/mask_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","mask_holy_symbol","mask","silk mask"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("silk mask");
   set_short("a silk mask");
   set_long("This mask is made of thick black silk, tinged with red. It is just large enough to completely cover any distinguishing features of the face of its possessor.");
}
