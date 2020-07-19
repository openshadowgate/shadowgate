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
	"You are on Cherry street.\n"+
	"Directly west is the intersection of Cherry with Pine and"+
	" Apple. The stables are also right there, and you can still"+
	" smell the horses that are kept inside. Pine street runs"+
	" southeast, heading back towards the Antioch gates. Apple"+
	" street travels to the northeast to intersect with Oak"+
	" shortly before the palace. Cherry street runs straight"+
	" east and west. In the center of the street is a large"+
	" fountain. At the far end is a very large stone church."+
	" There are many shops all along this street, including a"+
	" bank just south of the fountain."
	);
	set("night long",
	"You are on Cherry street.\n"+
	"Street lights to the west and east help to light your way."+
	" It looks like most of the shops along this street are"+
	" closed, but the owners might be willing to open up their"+
	" stores for you if it is urgent. In the center of the"+
	" street there is a very large fountain. Past the fountain"+
	" you can see an impressive stone church at the very end of"+
	" the road. Back to the west are the stables and the intersection"+
	" of this street with Pine and Apple. Pine street travels"+
	" southeast towards the Antioch gates, while Apple runs to"+
	" the northeast to meet up with Oak street."
	);
	set_smell("default","The breeze blows in the faint scent of"+
	" horses from the stables.");
	if(query_night() == 1) {
		set_listen("default","You can hear the horses stomping"+
		" about in their stalls.");
	}
	else {
		set_listen("default","The street is alive with busy shoppers.");
	}
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
