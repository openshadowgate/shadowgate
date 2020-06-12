#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Cherry Street");
	set_long(
	"%^YELLOW%^This part of the city lies in ruins, covered in a black haze.%^RESET%^"
	);
	set_smell("default","It smells of death and decay.");
	set_listen("default","The city is dead.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Cherry street.",
	"fountain" : "There is a large fountain in the center of"+
	" the street.",
	"shops" : "There are many shops along this street.",
	]));
	set_exits(([
	"west" : ROOMS+"street6",
	"east" : ROOMS+"street19",
	]));
   if(!find_object("/d/antioch/antioch2/mons/minstrel"))
        find_object_or_load("/d/antioch/antioch2/mons/minstrel")->move(TO);
//      new(MONS+"minstrel")->move(TO);  
// the check above only works for the master object, we'll load the master *Styx* 8/21/03
}
