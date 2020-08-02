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
    set_listen("You hear the swushing of water currents.");
   set_exits(([
      "north" : ROOMS"castle0",
     
   ]));
   set_door("gate",ROOMS"castle1","north","nokey");
   set_open("gate",0);
   set_locked("gate",0);
}

void reset(){
   ::reset();
   if(!present("noble",TO))
   new(MON"capn")->move(TO);
}
