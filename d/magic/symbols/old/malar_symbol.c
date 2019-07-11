// /d/magic/symbols/malar_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","malar_holy_symbol","claw","beast's claw","beasts claw"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("beast's claw");
   set_short("a beast's claw");
   set_long("Strung onto a piece of leather, this is a sharp claw from an animal. The beast's claw is covered in brown fur and the curved talons are covered in what appears to be fresh blood.");
}
 
