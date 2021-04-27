#include <std.h>
inherit "std/room";
void create()  {
    ::create();
    set_property("outdoors",0);
    set_property("light",1);
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_short("%^BOLD%^%^BLACK%^Up the cliff face%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You've climbed 50 feet up the cliff and are clinging hard to the"
             " mountinside as you attempt to traverse your way up the cliff.  Above you, a few pebbles"
             " tumble down showing the instability of your path.  There is a ledge a little ways"
             " above you, if you can reach it.%^RESET%^");
    
    set_smell("default","%^BOLD%^%^CYAN%^Crisp, cool air chills your nose%^RESET%^");
    
    set_listen("default","%^BOLD%^%^YELLOW%^The clack of pebbles falling above you make their way"
             " past your ears.%^RESET%^");
    
    set_items(([
        ({"rocks","cracks","crevises"}) : "%^BOLD%^%^WHITE%^The mountain appears climbable, though a difficult trek for those inexperienced.%^RESET%^",
        "clouds" :  "%^BOLD%^%^WHITE%^Low lying clouds obscure your view very far up the mountainside.%^RESET%^",
        "pebbles" : "%^BOLD%^%^WHITE%^Small rocks, once part of the cliff your climbing, zip past you on their way down.", 
  ]));
    set_exits(([
        "climb"  :  "/d/shadow/barriercaves/cliff2.c",
        "descend"  :  "/d/shadow/barriercaves/base.c)"
    ]));
}

