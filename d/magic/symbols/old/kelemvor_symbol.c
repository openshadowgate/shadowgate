// /d/magic/symbols/kelemvor_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","kelemvor_holy_symbol","badge","small badge"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("small badge");
   set_short("a small badge");
   set_long("This is a small piece of steel-gray cloth, which might normally be woven into another garment. A bone-colored skeletal arm is raised in the center of the cloth, evenly balancing the golden scales of justice in its clenched fist.");
}

