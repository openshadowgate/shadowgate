#include <std.h>
#include <arena.h>

inherit ROOM;

void create(){
    ::create();
    set_property("no teleport", 1);
    set_property("arena entrance", 1);
    set_travel(DIRT_ROAD);  // added to master for easier maint. *Styx*  12/15/02
    set_terrain(CITY);
}

void init(){
    ::init();
    add_action("enter", "enter");
}

int enter(string str){
    if(!str || (str != "safe" && str != "live")){
      tell_object(TP, "You must specify to 'enter safe' or 'enter live'");
      return 2;
    }

    if(TP->query_property("safe arena")) TP->remove_property("safe arena");
    TP->set_property("arena allowed", 1);
    if(str == "safe"){
      tell_object(TP, "You are entering the arena prepared for mock combat.");
      TP->set_property("safe arena", 1);
      TP->move_player(query_property("enter room"));
    }
    if(str == "live"){
      tell_object(TP, "You are entering the arena prepared for %^BOLD%^REAL%^RESET%^ combat.");
      if(TP->query_property("safe arena")) TP->remove_property("safe arena");
      TP->move_player(query_property("enter room"));
    }
    return 1;
}

void set_enter_room(string str) { set_property("enter room", str); }
