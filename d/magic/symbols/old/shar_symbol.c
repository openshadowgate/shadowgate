// /d/magic/symbols/shar_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","shar_holy_symbol","disk","obsidian disk"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("obsidian disk");
   set_short("an obsidian disk");
   set_long("This smooth disk is quite plain but finely crafted. It is simply a circle of obsidian surrounded by a thin - barely noticeable - ring of deeply-colored amethyst.");
}
