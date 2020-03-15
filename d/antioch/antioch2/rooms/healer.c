#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "../antioch.h"

inherit HEALER;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("training",1);
	set_property("light",2);
	set_short("Jelip's Apothecary");
	set_long(
	"This is obviously the shop of a healer. The room is lit with"+
	" scented candles and incense burns in holders along the sides"+
	" of the room. Shelves of herbs and jars are stored here and a"+
	" few plants are growing in pots along the top shelves. A"+
	" fountain of water is in one corner of the room. It is in the"+
   " shape of a lotus flower and water continually pours forth from"+
	" the center and drips down the leaves into a pool below. There"+
	" is a counter with a little chair for patients and you can see"+
	" piles of bandages and sharp tools for medical emergencies. A"+
	" screen on the far corner of the room hides a cot where patients"+
	" could take a nap. To get an idea of the services offered here"+
	" you can %^BOLD%^<read list> %^RESET%^to see them."
	);
	set_smell("default","The scent of various herbs is mixed with"+
	" the aroma of sweet incense.");
 	set_listen("default","The light splash of the fountain is"+
	" soothing to your ears.");
	set_items(([
	"fountain" : "%^BOLD%^%^CYAN%^This is a stone fountain that stands about three"+
   " feet in height, in the center is a lotus flower that stands"+
	" upright and spills a continuous trinkle of water forth from"+
	" its center. The water runs down the petals onto the leaves and"+
	" into a pool of water that is contained in a stone circle.",
	({"shelf","shelves"}) : "%^GREEN%^The shelves here are tall and stacked"+
	" with various herbs and jars of different colored liquids. On"+
	" the tops of a few shelves are strange plants growing in pots.",
	"chair" : "%^RED%^A small chair made of cherry wood rests near a counter"+
	" covered in medical items.",
	({"counter","table"}) : "This counter has piles of bandages and"+
	" various medical tools on it, used for treating patients.",
	"cot" : "%^BOLD%^A small cot is partially hidden by a screen and can be"+
	" used by recovering patients.",
	"screen" : "%^BOLD%^%^GREEN%^A screen constructed of wood and green silk partially"+
	" conceals a cot from view.",
	"bandages" : "A pile of bandages are stacked on a counter.",
	"herbs" : "There are many herbs all over the place here.",
	"insence" : "There are several sticks of insence lit around the"+
	" room and they bring a faint spring scent to the room, though"+
	" all the herbs fight to suppress the smell it seems.",
	"plants" : "Some potted plants seem to be growing rather well."
	]));
	set_exits(([
	"east" : ROOMS+"street2",
	]));
   set_name("Jelip");
   set_cl_price(20);
   set_cs_price(45);
   set_cc_price(100);
   set_np_price(150);
   set_cb_price(150);
   if(query_night() == 1) {
      set_bp_price(45);
   }
   else {
      set_bp_price(30);
   }
}

void reset()
{
	::reset();
	if(!present("jelip")) {
		new(MONS+"jelip.c")->move(TO);
	}
}
/*
void init()
{
	::init();
	add_action("list","list");
}


int list(string str)
{
	if(!str) {
		write("%^BOLD%^The available services here are:\n"+
		"cl : cure light wounds for 20 gold\n"+
		"cs : cure serious wounds for 45 gold\n"+
		"cc : cure critical wounds for 100 gold\n"+
		"np : neutralize all poison for 150 gold\n"+
		"bp : buy a healing potion for 30 gold\n"+
           "cb : cure your blindness for 150 gold\n\n%^RESET%^"+
            "These are the standard prices, kits cost 50% more if you barge in here"+
            " during his off-business hours (night time).\n");
		return 1;
	}
}
*/