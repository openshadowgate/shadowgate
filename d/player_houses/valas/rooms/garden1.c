#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("Garden");
    set_short("Garden");
    set_long("The garden is filled with grass.  Amongst the grass there are huge blocks of stone that seem to be strewn about but are quite aesthetically placed. The grass comes to about knee height but is not thick enough to become a nuisance.  The garden is surrounded by a wall made up of huge blocks of granite.  In the center of a garden a solid looking tower juts up.");
    set_smell("default","The air is clean here and it smells of fresh grass.");
    set_listen("default","It is quiet except for the sounds of birds off in the distance.");

    set_items(([
        ({"tower","onyx tower"}) : "This tower looks to be made out of onyx, the top is only slightly more narrow than the bottom.  The sides are ribbed with several outcroppings that go from the base to the top.  Four pointed tips jut outwards and up at the top of the tower, they look almost claw-like",
        "stone" : "There are blocks of stone about, grass grows around them and they are buried some more than others",
        ({"gate","gates"}) : "There is a rune-etched mithril gate that appears to be the only entrance.  There seems to be a sparkle of magical energy about it, and as you look closer you realise it is transparent - you can walk right through it.",
    ]));
    set_exits(([
        "southwest" : ROOMS"garden2",
        "southeast" : ROOMS"garden4",
        "north" : ROOMS"entrance",
    ]));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"The gate shimmers as you pass straight through it!");
   if(!TP->query_invis()) tell_room(TO,"The gate shimmers as "+TP->QCN+" passes straight through it.",TP);
   return 1;
}

void reset() { if(!present("statue")) new(OBJ"statue1")->move(TO); }

// gate password: artsym