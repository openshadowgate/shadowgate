#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
    set_property("light",0);
    set_property("indoors",1);
    set_short("Kobold Caverns");
    set_long(
@KAYLA
  You are moving deeper into the mountain's side.  All around you
the stone is naturally carved.
KAYLA
    );
      set_listen("default","Peculiar, the cavern is deadly quiet.");
    set_exits(([
       "south" : "/d/deku/new/cave3",
       "north" : "/d/deku/new/cave11"
    ] ));
    set_items(([
          "walls" : "The cavern walls are naturally formed."
    ] ));
    set_pre_exit_functions(({"west"}),({"go_west"}));
}


void reset() {
  ::reset();
  if(!present("hobgoblin")) {
    new("/d/deku/monster/hobgob")->move(this_object());
  }
}

int go_west() {
   object obj;
  if (obj=present("smelly hobgoblin") && !obj->id("undead") ) {
   write("%^MAGENTA%^The hobgoblin says%^RESET%^: No one disturbs the King!");
    return 0;
  }
  return 1;
}
