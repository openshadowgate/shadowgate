// searching around will show a loose brick that one can "push" which will open a stairway to the basement
#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("tower");
    set_short("tower");
    set_long("Entering the tower, reveals a huge dimly lit area.  The ceiling is huge with arching pillars all throughout the room.  Like the outside, the entire area is made of onyx.  There do not seem to be any seams or connections present so it appears like this entire tower was formed from one single stone.  The pillars are big enough to mount items for display.  Most notable there are paintings hung about the room.");
    set_smell("default","The air is clean but somewhat stuffy");
    set_listen("default","your own footsteps echo through this place");

    set_items(([
        "painting 1" : "Brenamen....",
        "painting 2" : "A sable-haired human woman with silvery-gray eyes it is titled Aynetta.",
        "painting 3" : "A lean male human with green eyes and crimson hair it is titled Valas.",
        "painting 4" : "A wondrous human woman with vibrant hair it is titled Saqira.",
        "painting 5" : "A scarred male human clad in magnificent armor it is titled Cedric.",
        "painting 6" : "A svelte female elf with fire red hair and emerald eyes it is titled Marika.",
        ({"paintings", "painting" }) : "There are six paintings in this room",
        "brick" : "This brick looks out of place. Maybe you could push it?",
    ]));
    set_exits(([
        "up" : ROOMS"tower2",
        "north" : ROOMS"tower4",
        "south" : ROOMS"tower",
    ]));
    set_door("door",ROOMS"tower1","south",0);
    set_door_description("door","An ornate metal door.  It is the only visible exit to the tower.");
    set_search("default","One brick looks out of place.");
    set_search("brick","This brick looks out of place. Maybe you could push it?");
}

void init() {
   ::init();
   add_action("push_fun","push");
}

int push_fun(string str) {
   if(!str) return 0;
   if(str != "brick") return 0;
   if(member_array("down",TO->query_exits()) != -1) {
     remove_exit("down");
     tell_object(TP,"You push the loose brick, and the hidden doorway slides closed.");
     tell_room(TO,""+TP->QCN+" pushes a loose brick, and the hidden doorway slides closed.",TP);
     tell_room(ROOMS"basement","The scrape of moving stone from above, alerts you to someone closing the hidden door.");
     if(member_array("up",ROOMS"basement"->query_exits()) != -1) ROOMS"basement"->remove_exit("up");
     return 1;
   }
   add_exit(ROOMS"basement","down");
   tell_object(TP,"You push the loose brick, and a hidden doorway slides open with stairs leading down.");
   tell_room(TO,""+TP->QCN+" pushes a loose brick, and a hidden doorway slides open with stairs leading down.",TP);
   tell_room(ROOMS"basement","The scrape of moving stone from above, alerts you to someone opening the hidden door.");
   if(member_array("up",ROOMS"basement"->query_exits()) == -1) ROOMS"basement"->add_exit(ROOMS"tower1","up");
   return 1;
}