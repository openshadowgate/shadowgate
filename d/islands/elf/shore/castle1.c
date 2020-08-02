#include <std.h>
#include "../elf.h"


inherit VAULT;

void create(){
   ::create();
    set_short("%^BOLD%^BLUE%^Castle Ruins%^RESET%^");
    set_long(query_short()+"\nThis is the underwater ruins"+
    " inside a castle.  There is a broken chair behind"+
    " a decaying desk.  The stone walls are falling "+
    "over the ceiling is barely holding up.");
    set_listen("default","You hear the swushing of water currents.");
    set_smell("default","It is hard to smell being underwater");
   set_exits(([
      "north" : ROOMS"/shore/castle0",
     
   ]));
   set_door("gate",ROOMS"/shore/castle1","north","nokey");
   set_open("gate",0);
   set_locked("gate",0);
}

void reset(){
   ::reset();
   if(!present("noble",TO))
   new(MON"capn")->move(TO);
}