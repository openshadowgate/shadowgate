#include <std.h>
#include "../defs.h"
inherit VAULT;

void pass_step(object theplayer);

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("Entrance");
    set_short("Entrance");
    set_long("Amongst the grassy area, stands the entrance to a grand tower.  It is walled by huge blocks of granite formed together almost seamlessly.  The tower is like a pillar of stone that juts up and can be seen behind the wall.  The gate is made of mithril.  It is etched with many runes.");
    set_smell("default","The air is clean here and it smells of fresh grass.");
    set_listen("default","It is quiet but for the sound of birds in the distance.");

    set_items(([
        ({"tower","wall"}) : "A pillar-like tower can be seen from above the wall.",
        "gates" : "There is a rune-etched mithril gate that appears to be the only entrance.  There seems to be a sparkle of magical energy about it.",
    ]));
    set_exits(([
        "north" : "/d/darkwood/tabor/road/road20",
        "south" : ROOMS"garden1",
    ]));
   set_pre_exit_functions(({"south"}),({"pass_door"}));
}

void reset() {
   ::reset();
   if(!present("blade golem")) {
     new("/d/player_houses/valas/mon/bgolem")->move(TO);
     new("/d/player_houses/valas/mon/bgolem")->move(TO);
   }
}

void init() {
   ::init();
   add_action("say_fun","say");
   add_action("sneak_fun","sneak");
}

int pass_door() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^You walk up to the gate, but it certainly seems solid enough when you bump into it.");
   tell_room(TO,"%^RESET%^"+TP->QCN+" walks up to the gate, and bumps right into it.",TP);
   return 0;
}

int sneak_fun(string str){
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   if(str != "south" && str != "s") return 0;
   tell_object(TP,"You can tell the gate is too solid to sneak through.");
   return 1;
}

int say_fun(string str){
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   str = lower_case(str);
   if(strsrch(str,"artsym") == -1) return 0;
   call_out("pass_step",1,TP);
   return 0;
}

void pass_step(object theplayer) {
   tell_object(theplayer,"%^BOLD%^%^WHITE%^As the words leave your lips you feel a light compulsion, and before you realise it you have stepped forward, straight through the gate!%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^As the words leave "+theplayer->QCN+"'s lips, "+theplayer->QS+" gets a strange look on "+theplayer->QP+" face and abruptly steps forward, straight through the gate!%^RESET%^",theplayer);
   theplayer->move_player(ROOMS"garden1");
}