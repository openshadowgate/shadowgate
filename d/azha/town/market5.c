// Market Gate, Inside Market Square, Azha
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("Market Gate, Inside Market Square, Azha");
  set_long(
@AZHA
%^BOLD%^Market Gate, Inside Market Square%^RESET%^
  Here merchants and wagoneers cluster right by the gate to 
Market Square as loads of cargo are unloaded from their wagons and
distributed to the booths of their merchants by workers.  You are
astounded by the array of strange and wonderful things you see here.
Market Square spreads out before you in all directions, filled with
everything you can possibly imagine.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/high3",     
	"south" : "/d/azha/town/market2",
	"east" : "/d/azha/town/market6",
	"west" : "/d/azha/town/market4",
	"southeast" : "/d/azha/town/market3",
	"southwest" : "/d/azha/town/market1",
  ] ));     
	set_smell("default","The smells here are so strong and varied that they overwhelm you.");
	set_items(([
		"cargo" : "There are things of all shapes, sizes and, %^RED%^c%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^BLUE%^r%^VIOLET%^s%^RESET%^ here.\n",
		"wagons" : "The wagons are of all sorts, but all are engaged in loading and unloading, carefully watched by their owners.\n",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "market");
}
