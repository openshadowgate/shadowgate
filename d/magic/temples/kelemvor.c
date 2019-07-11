#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("stone mausoleum");
   set_short("A simple stone mausoleum");
   set_long("%^BOLD%^%^WHITE%^A simple stone mausoleum%^RESET%^\n"
"This plain %^ORANGE%^stone %^RESET%^mausoleum is the only structure within the graveyard, and is not particularly "
"distinctive to look at.  It consists merely of tall walls and a tapered roof of stone tiles, with "
"no door installed at its entry to restrict access.  Within, simple sconces support %^YELLOW%^torches %^RESET%^"
"that seem never to burn down, shedding flickering light across the numerous alcoves that line the "
"walls.  Each bears a small plate marked with a name.  In the centre of the building stands a single "
"%^BOLD%^%^BLACK%^stone sarcophagus%^RESET%^, with the raised image cut into its lid the shape of a man at rest.  His hands lie "
"closed across his chest, holding the hilt of a %^CYAN%^greatsword %^RESET%^with its point towards his feet.\n");
   set_exits(([
      "out":"/d/tharis/cemetery/cemetery8"
   ]));
   set_smell("default","The thick, musty smell of the tomb surrounds you.");
   set_listen("default","It is deathly silent here.");
}