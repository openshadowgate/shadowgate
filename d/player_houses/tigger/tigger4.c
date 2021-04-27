// tigger4.c
//
// Tigger's house

#include <std.h>
inherit VAULT;

void create(){
    ::create();
    set_short("A cozy halfling living room");
    set_long(
@DESC
%^YELLOW%^
This room is a lot more darkly lit that the other rooms, only a few lanterns
in the corners make sure its not pitch dark. As you peer around you see
multiple %^RED%^weapon racks%^YELLOW%^ with interesting blades, like the %^GREEN%^venom daggers %^YELLOW%^
and different types of small crossbows. There are several training dummies,
which are all perforated by dagger marks in the back region and around the
throat. You ponder that this would be the perfect weapons room for an
assassin. At the far back end you see a small chest covered with dust.
DESC
    );
    set_indoors(1);
    set_light(1);
    set_smell("default","The room smells old and dusty, its not as finely kept as the others.");
    set_listen("default","You only hear the soft bubbling of the stew from the living room.");
    set_items(([
        "chest":"As you wipe off the dust covering, you see several halfling letters start %^YELLOW%^glowing brightly %^RESET%^on the chest's surface.",

    ]));
    set_exits(([
        "south":"/d/player_houses/tigger/tigger2.c",
    ]));
}

void init(){
    ::init();
//    add_action("open","open_chest");
}

int open_chest(string str){
    if(!str) return 0;
    if(!id(str)) return 0;
    if((string)TP->query_race() != "halfling"){
        write("You get a small shock while trying to open the chest!");
        TP->do_damage("right hand",random(4));
        return 1;
    }
}
