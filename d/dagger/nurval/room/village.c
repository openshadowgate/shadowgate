#include <std.h>
#include "/d/dagger/nurval/tomb.h"

inherit "/std/rquestroom.c";

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^BLACK%^Gloomy Village");
    set_long(query_short()+"
%^RESET%^%^ORANGE%^A small village of mortals has been set up by this side of %^BOLD%^%^BLACK%^the %^BLACK%^p%^BLACK%^y%^BLACK%^r%^BLACK%^a%^BLACK%^m%^BLACK%^i%^BLACK%^d%^BLACK%^.%^RESET%^%^ORANGE%^ Most houses are newly-build wooden buildings, it seems not much thought had been put into their construction but they look sturdy enough. Several mortals wander around on their business. This place isn't free of looming presence of the pyramid, people of the village occasionally glance over it. To the south, a building out of dark stone bricks with thick smoke rising out of its chimneys. To the east you see a path wide enough to let a wagon to pass, and further %^ORANGE%^a %^BOLD%^%^BLACK%^marbl%^RESET%^%^RED%^e %^RED%^s%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^ct%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^re%^BOLD%^%^BLACK%^%^RESET%^%^ORANGE%^.

%^ORANGE%^Sign to the north reads %^BOLD%^'Inn'%^RESET%^.
%^ORANGE%^Sign to the south reads %^BOLD%^%^RED%^'Forge'%^RESET%^.
" );
    set_smell("default","Your nose catches smells of dozens of people.");
    set_listen("default","You hear humming noise of village's life.");
    set_exits(([
       "west" : ROOMS+"/tomb3",
       "north" : ROOMS+"/inn",
       "south" : ROOMS+"/smithy",
       "east" : ROOMS+"/village2",
    ] ));
    set_quest_daemon("/daemon/quests_mid");

    {
        object ob;
        ob = new("/std/bboard");
        ob->set_id( ({ "board", "bulletin board" }) );
        ob->set_board_id("union_board");
        ob->set_short("%^RESET%^%^ORANGE%^Arcane Bulletin Board%^RESET%^");
        ob->set_long("This corkboard has been nailed to the wall of the inn to allow businesses to advertise and citizens and adventurers to communicate about events.");
        ob->set_max_posts(50);
        ob->set_location(ROOMS+"/village.c");
    }
}

void reset()
{
    ::reset();
    if (!present("street_light", TO))
        new("/d/common/obj/misc/street_light")->move(TO);
    if (!present("guard"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 2"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 3"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("banshee"))
        new(MONS + "/banshee")->move(TO);
    if (!present("banshee 2"))
        new(MONS + "/banshee")->move(TO);
}
