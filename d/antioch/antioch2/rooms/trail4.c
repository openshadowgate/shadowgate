#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create() 
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Road Through the Woods");
	set_long(
	"%^GREEN%^Road Through the Woods\n"+
	"%^ORANGE%^This is a little %^CYAN%^road%^ORANGE%^ through the %^CYAN%^C%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^aru %^CYAN%^Mou%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n%^BLACK%^s%^RESET%^%^CYAN%^.%^ORANGE%^ It curves to the southwest and back to the east are the ruins of Antioch. The road is mostly dirt, though a few %^CYAN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^ones%^ORANGE%^ have been set along the sides to help define it more. It is easily wide enough for several people to walk side by side. %^BOLD%^%^RED%^To the west, you can see tendrils of darkness rise from the ruined city of New Antioch and the wreckage of a ruined shrine. It fills you with dread and you feel your skin begin to crawl and itch. Best turn back!"
	);
	set_smell("default","You smell the scent of pine trees and death.");
	set_listen("default","The wind whistles through the trees, whispering of your worst nightmares.");
	set_items(([
	"mountains" : "The mountains extend as far as the eye can see.",
	({"road","little road","path","trail"}) : "The road curves"+
	" to the southwest here. It is lined with stones on the side and"+
	" is not very wide.",
	"stones" : "Large flat stones have been placed on either"+
	" side of the road to help define it.",
	({"trees","tree","pines"}) : "The trees are thick and tall"+
	" and block out a lot of the light, casting strange shadows"+
	" on the trail.",
	"tendrils" : "Tendrils of darkness flow from an abyss to the west, turning the sky black and blanketing the world in darkness.",
	]));
	set_exits(([
	"east" : ROOMS+"trail3",
	"southwest" : ROOMS+"trail5",
	]));
}
