#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_short("In the walls of Tonovi");
    set_room_type("walls");
    set_long(
      "You are on one of the three towers guarding the southwest corner of the city.  The tower looks out over the hills of the Yniam plains keeping watch in two of the more vulnerable directions watching for attacks.  The tower itself is sparsely furnished, with just a cloth on poles to provide protection from the sun and rain."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"staircase" : "This staircase leads up through the ceiling and onto the archers posts.",
	"gates" : "The great gates stand open ready to be closed in an instant to defend the city.",
	"cloth" : "This thick waterproof fabric is held up on four poles to provide the archers with some protection from the elements.",
	"hills" : "The emerald hills of the plains roll off into the distance.",
      ]) );

    set_exits( ([
	"down" : RPATH "tower7",
      ]) );
}
