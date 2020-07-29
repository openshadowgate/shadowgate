#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"shore/shore7", 
     "west": ROOMS"shore/shore5",
    "camp": ROOMS"shore/camp",
     ]));
  set_door("gate",ROOMS"shore/camp","camp","elfkey");
}
void reset(){
  ::reset();
  set_locked("gate",0);
  set_open("gate", 0);

 }