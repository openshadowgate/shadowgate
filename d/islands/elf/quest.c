#include <std.h>
#include "elf.h"

inherit "/std/rquestroom.c";

void create() {
    object ob;
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^Back Room%^RESET%^");
    set_long(query_short()+"\n%^GREEN%^You are standing in a back "+
    "room of the animal ranch.  A stall has"+
    " been set up for a strange sort of "+
    "character here.   There are some boxes"+
    " and a simple desk with a stool behind it."
    );
    set_smell("default","The room smells of animals and grass.");
    set_listen("default","You can hear the strange sounds of exotic animals.");
    set_exits(([
       "south" : ROOMS"stable",

    ] ));

    set_quest_daemon("/daemon/quests_high");
   
}
