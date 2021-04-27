#include <std.h>

inherit VAULT;
#define OWNERS ({"slore", "mystra"})

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A library");
    set_long(
"This room is clearly a library.  Tall shelves line every wall and a lectern "
"with a large book stands in the middle of the room.  The library appears to "
"have fallen on hard times, however.  Every single book except that on the "
"lectern has been removed.  Candles throughout the room provide illumination.  "
"A suit of armor stands in the southwest corner, halberd in hand and at "
"attention."  
    );
    set_listen("default","It is quiet here, as libraries should be.");
    set_smell("default","The sweet aroma seems to fade a little.");
    set_items(([
      "lectern" : "The lectern is a simple wooden book stand, about chest "
          "high to read from. It is attached to the floor."
    ] ));
    set_exits(([
       "north" : "/d/player_houses/slore/backroom",
       "east" : "/d/player_houses/slore/lab",
       "west" : "/d/player_houses/slore/bedroom",
    ] ));
   set_door("door","/d/player_houses/slore/bedroom","west");
   set_door("heavy door","/d/player_houses/slore/backroom","north",0,"steel lock");
   set_door_description("heavy door","This is a heavy panel door, clearly "
       "intended to keep unwanted intruders out.");
   set_locked("heavy door",1,"steel lock");
   lock_difficulty("heavy door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"steel lock");
   set_lock_description("heavy door","steel lock","It appears to be a type "
       "that you can lock or unlock from this side without a key.");
}

void init() {
   ::init();
   add_action("unlock_me","waves");
}

void unlock_me(string str) {
   if(str != "hands" && str != "hands twice") return 0;
   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   tell_object(TP,"You wave your hands over your eyes, leaving them a "
        "bright-silver color momentarily and you hear the lock click.");
   tell_room(ETP,""+TPQCN+" waves her hands over her eyes, leaving them a "
        "bright-silver color momentarily as you hear a soft click.",TP);
   find_object_or_load("/d/player_houses/slore/backroom");
   if(!query_locked("heavy door","steel lock")) {
       TO->set_open("heavy door",0);
       TO->set_locked("heavy door",1,"steel lock");
       "/d/player_houses/slore/backroom"->set_locked("heavy door",1,"steel lock");
       "/d/player_houses/slore/backroom"->set_open("heavy door",0);
       return 1;
   }
   TO->set_locked("heavy door",0,"steel lock");
   "/d/player_houses/slore/backroom"->set_locked("heavy door",0,"steel lock");
   return 1;
}
