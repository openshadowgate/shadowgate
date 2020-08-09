#include <std.h>
#include "../elf.h"
inherit WATER;

void create(){
   ::create();
   set_short("%^BOLD%^BLUE%^Castle Ruins%^RESET%^");
   set_long(query_short()+"\nThis is the underwater ruins"+
    " inside a %^CYAN%^castle%^RESET%^.  There is a broken %^CYAN%^chair%^RESET%^ behind"+
    " a decaying %^CYAN%^desk%^RESET%^.  The stone walls are falling "+
    "over the ceiling is barely holding up.  "+
    "There looks to be some half burried dead %^CYAN%^bodies%^RESET%^ here.");
   set_listen("default","You hear the swushing of water currents.");
   set_smell("default","It is hard to smell being underwater.");
   set_exits(([
      "north" : ROOMS"/shore/castle0",
     
   ]));
   set_door("gate",ROOMS"/shore/castle1","north","nokey");
   set_open("gate",0);
   set_locked("gate",0);
   set_items(([
      (({"castle"})) :
        "The castle is just rubble.  There should be hallways and windows but everything has fallen down.",
      (({"desk"})) : "The desk is broken.  It is mostly decayed and laying crooked on the ground.",
      (({"bodies"})) : "Bits of bodies can be seen partly sticking out of the mud.  Some of the flesh has been picked clean by fish and only bones remain.",
      (({"chair"})) : "This chair is ruined. Three of the four legs are broken it is just leaning against a rock to stand up.",
   ]));
}
void reset(){
   ::reset();
   if(!present("noble",TO))
      new(MON"capn")->move(TO);
}