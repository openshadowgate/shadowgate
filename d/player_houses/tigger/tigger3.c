// tigger3.c
//
// Tigger's house

#include <std.h>
inherit VAULT;

void create(){
    ::create();
    set_short("A softly lit bedroom");
    set_long(
@DESC
%^YELLOW%^
This is the Bedroom of the little halfling house. It is softly lit and
its walls are painted in a darkred color, to make it a comfortable place
to be in. The light comes from candles, carefully placed around the room.
To the right you see a small drawer, with a mirror on top of it. The room
is dominated by %^RED%^a huge heartshaped bed, %^YELLOW%^that looks large enough for two
humans to to lie in without problems. The bed is covered with silk sheets,
and there are %^RED%^rose petals %^YELLOW%^spread out over the silk sheets.
DESC
);
    set_indoors(1);
    set_light(1);
    set_smell("default","The room has en exotic smell of flowers and different kinds of aromas.");
    set_listen("default","All you can hear in the room is the silent bubbling of the stew from the next room.");
    set_items(([
        "bed":"%^MAGENTA%^The huge bed looks soft and cozy, and you really feel like lying down in it.",
        "drawer":"%^GREEN%^As you look into the drawers all you see is alot of small halfling clothe. nothing really interesting is inside the drawer.",
    ]));
    set_exits(([
        "out":"/d/player_houses/tigger/tigger2.c",
    ]));
    set_door("bedroom door","/d/player_houses/tigger/tigger2","out",0);
}

void init(){
    ::init();
    add_action("lie_on_bed","lie");
    add_action("lie_on_bed","lay");
}

int lie_on_bed(string str){
    if(!str) return 0;
    if(str != "down" && str != "on bed" && str != "down on bed") return notify_fail("Lie where?");
    write("You lie down on the comfy bed.");
    tell_room(TO,TPQCN+" lies down on the comfy bed.",TP);
    return 1;
}

