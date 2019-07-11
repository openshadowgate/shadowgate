// /d/magic/symbols/cyric_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","cyric_holy_symbol","bracelets","silver bracelets"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("silver bracelets");
   set_short("silver bracelets");
   set_long("These wide silver bracelets fit tightly around the wrists. Each bracelet has a black starburst covered by a white jawless skull stamped into the metal.");
}
