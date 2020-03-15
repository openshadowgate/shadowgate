#include <std.h>
#include "../antioch.h"
inherit VAULT;

int found;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^MAGENTA%^Lilac Room");
	set_long(
	"%^MAGENTA%^The Lilac Room\n"+
	"%^BOLD%^The lilac room is aptly named. The place is decorated"+
	" in lavenders and pastels. The floor is covered in a lilac"+
	" carpet that is thick and soft. The furniture seems to be made"+
	" out of a pale colored pine wood. On the left hand side of the"+
	" room is a large dresser that reaches about eight feet in length"+
	" but is only about three and a half feet in height. Fixed to"+
	" the top of it is a large mirror. The mirror is framed with"+
	" pine wood that has been carved into the image of connected"+
	" lilacs. Next to the dresser in the back corner is a plush rocking"+
	" chair that is covered in a pale pink cushion. Straight across"+
	" from you is the window that overlooks the street. Light purple"+
	" curtains are drawn together to keep people from staring up at"+
	" you. Just in front of the window is a little desk with a wash"+
	" basin on it. Tucked into the right hand corner, facing the door,"+
	" is the bed. It is a four posted bed and is quite large. Any"+
	" lady could sprawl out in it and feel right at home. The pillows"+
	" look like they're made out of goose down and the bed spread"+
	" is a water color mesh of pastel shades. At the foot of the"+
	" bed is a small chest that guests can store belongings in. Candles"+
	" are in sconces around the room, bringing light to the place."
	);
	set_smell("default","It smells like you are walking in a field"+
	" of lilacs");
	set_listen("default","You can hear people passing by on the"+
	" street outside.");
	set_items(([
	"chest" : "There is a large wooden chest at the foot of the bed"+
	" that guests can use to store belongings in.",
	"night stand" : "There is a night stand just in front of the"+
	" window with a wash basin on it.",
	"basin" : "%^BOLD%^%^CYAN%^This is a sky blue wash basin that"+
	" holds water for washing your face off with.",
	"mirror" : "A large rectangular mirror is fixed above the dresser."+
	" It has a pine wood frame that is cut in the shape of connected"+
	" lilacs.",
	"dresser" : "%^BOLD%^This large dresser is made of a pale pine"+
	" wood. It is approximately eight feet in length and three and"+
	" a half feet in height. A mirror is fixed in the center of the"+
	" dresser.",
	({"floor","carpet"}) : "%^MAGENTA%^%^BOLD%^A thick lilac carpet"+
	" covers the floor.",
	"bed" : "A very large bed is tucked into the right hand corner"+
	" of the room, facing the door. It has large fluffy pillows on"+
	" it and a pretty bed spread that is done in pastels.",
	"pillows" : "These fluffy pillows appear to be made out of goose"+
	" down and look to be quite comfortable.",
	"bed spread" : "The bed spread is thick and would keep you very"+
	" warm. It is done in pastel colors and changes from a light"+
	" purple and pink to a pale blue.",
	"candles" : "%^BOLD%^Large white candles are held in scones about"+
	" the room. They seem to be responsible for the wonderful lilac"+
	" scent.",
	"sconces" : "Silver scones line the room, they hold large white"+
	" candles in them.",
	]));
	set_exits(([
	"east" : ROOMS+"inn4",
	]));
	set_door("lilac door",ROOMS+"inn4","east",0);
	set_search("room","Maybe you would have better luck searching"+
	" specific things.");
	set_search("dresser",(:TO,"search_dresser":));
	set_search("chest","You find the chest to be clean and empty.");
}

int search_dresser()
{
	if(found) {
		write("There doesn't appear to be anything here.");
		return 1;
	}
	else {
		say(""+TP->query_cap_name()+" searches in the dresser drawers"+
		" and finds some perfume.");
		write("You search around in the dresser drawers and find a"+
		" bottle of perfume.");
		new(OBJ+"perfume")->move(TO);
		found = 1;
		return 1;
	}
}
