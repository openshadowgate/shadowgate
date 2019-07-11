// /d/magic/symbols/helm_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","helm_holy_symbol","gauntlets","war gauntlets"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("war gauntlets");
   set_short("war gauntlets");
   set_long("These are steel war gauntlets. An open eye with blue pupil and outline is painted on each of the gauntlets - on the palm of the left hand and the back of the right hand.");
}
