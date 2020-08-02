#include <std.h>
#include "../elf.h"


inherit VAULT;

void create(){
   ::create();
    set_short("%^BOLD%^BLUE%^Castle Ruins%^RESET%^");
    set_long(query_short()+"\nThis is the underwater ruins"+
    " outside a castle.  Everything is mostly"+
    " bricks half burried in the sea floor.  "+
    "There is a gate leaning into the crumpled keep to the south.");
    set_smell("default","It is hard to smell being underwater");
    set_listen("default","You hear the swushing of water currents.");
   set_exits(([
      "north" : ROOMS"/shore/ruin12",
      "south" : ROOMS"/shore/castle1",
   ]));
   set_door("gate",ROOMS"/shore/castle1","south","nokey");
   set_open("gate",0);
   set_locked("gate",0);
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
   new("/d/common/obj/misc/street_light")->move(TO);
}