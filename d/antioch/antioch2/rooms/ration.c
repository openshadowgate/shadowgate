#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("The Iron Gullet");
	set_long(
	"This is a very small store and it is stocked full of all sorts"+
	" of dried meats, fruits, and nuts. There is a counter in the"+
	" middle of the room with several bags and a scale on it. Behind"+
	" the counter is a stool for the owner to sit on and shelves"+
	" are beyond that, covered with all sorts of dried items. The"+
	" window sills have long counters in front of them and all along"+
	" these meats and fruits have been laid out to dry. There are"+
	" various barrels of different types of nuts scattered around"+
	" the room. Near the counter are a few pails of fresh fruits that"+
	" are waiting to be dried. The hardwood floor is kept impeccably"+
	" clean and you can see a broom in the corner that the owner must"+
	" use to sweep with regularly. A brown welcome mat has been laid"+
	" out at the entrance for customers to wipe their feet on. Just"+
	" walking in this shop makes your mouth water, it is so filled"+
	" with delicious smells."
	);
	set_smell("default","The smell of dried meats and fruits is"+
	" strong here.");
	if(query_night() == 1) {
		set_listen("default","All is quiet here.");
	}
	else {
		set_listen("default","You can hear the hustle and bustle of"+
		" a busy city through the door.");
	}
	set_items(([
	"broom" : "There is a straw broom with a wooden handle along the"+
	" side of the room.",
	"floor" : "The hardwood floor is kept impeccably clean from dust.",
	"mat" : "This is a brown welcome mat for customers to wipe their"+
	" feet on.",
	({"window","windows"}) : "There are windows on the left and right"+
	" sides of the store, they are very large and made of glass,"+
	" with white wooden frames.",
	({"window sill","window sills"}) : "The window sills have long"+
	" counters about a foot in width that have been secured along"+
	" the length of the store and there are many meats and fruits"+
	" laid out to dry on them.",
	"counter" : "The counter is made of oak and looks quite sturdy,"+
	" on the top are several bags and a scale.",
	({"bags","bag"}) : "These are some small cloth bags used to"+
	" put the meats, nuts, and fruits in.",
	"scale" : "This is a fine metal scale used to carefully weigh"+
	" out the rations in the shop.",
	"shelves" : "The shelves behind the counter are stocked full of"+
	" rations.",
	({"barrel","barrels"}) : "There are many barrels scattered about"+
	" the room containing various nuts. You can recognize peanuts,"+
	" pecans, walnuts, almonds, cashews, and a couple types you"+
	" aren't familiar with.",
	({"pail","pails"}) : "Near the counter are several pails filled"+
	" with fresh fruits. There are apples, peaches, plums, apricots,"+
	" and grapes.",
	({"fruit","fruits"}) : "Throughout the store there are many types"+
	" of dried fruits and even some fresh ones in pails near the"+
	" counter.",
	"nuts" : "Shelled and unshelled nuts of all sorts are kept in"+
	" barrels around the room and in sacks along the back shelves.",
	({"meat","meats"}) : "Many types of meats are in this store. There"+
	" are some kept drying on the window sills and several sack fulls"+
	" of already dried meats on the back shelves. The most common"+
	" type seems to be beef, you think, but meat pretty much looks"+
	" the same dried and it's hard to tell.",
	"stool" : "There is a wooden stool behind the counter for the"+
	" owner of this shop to sit on.",
	]));
	set_exits(([
	"west" : ROOMS+"street17",
	]));
	set_door("door",ROOMS+"street17","west",0);
}

void reset()
{
	::reset();
	if(!present("andy")) {
		new(MONS+"andy.c")->move(TO);
	}
}
