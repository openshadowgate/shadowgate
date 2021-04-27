#include <std.h>
#include "../yuki.h"

inherit STORAGE"court.c";

void create(){
   ::create();
   set_long(::query_long()+"%^BOLD%^%^ORANGE%^A large square has been set into the flagstone "+
   "and filled with a layer of sand. At each corner of the square stands large braziers. Often "+
   "groups of young soldiers both men and women can be seen practicing their skills in spars, "+
   "or following an officer in kata training.%^RESET%^.\n");
   set_exits(([
	  "west" : ROOMS"c1",
   ]));
}

void reset(){
    ::reset();
        if(!present("captain"))
		switch(random(3)){
            case 0:
                new(MOBS"kiera.c")->move(TO);
            break;
            default:
                new(MOBS"hitokiri.c")->move(TO);
            break;
    }
}
