#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Bazaar of Tonovi");
   set_room_type("bazaar");
    set_long(
      "   Bazaar of Tonovi\n"
      +"This is the northeastern corner of the bazaar of Tonovi.  "+
      "To the east the bazaar opens up into Main Street.  "+
      "To the south and west the bazaar is all around.  "+
      "An outside entrance way to the north of here leads up to a "+
      "door.");
    set_smell("default", "You smell several strange smells, especially strong are those of fruits.");
    set_listen("default", "You can hear the merchants peddling their wares from all around.");

    set_items( ([
	"walls" : "The walls of the city are there to protect it and you from attackers.",
      ]) );
    set_exits( ([
	"east" : RPATH "street8",
	"west" : RPATH "bazaar2",
	"south" : RPATH "bazaar6",
 	"north" : "/d/player_houses/lusell/rooms/shop_entrance"
      ]) );
}
