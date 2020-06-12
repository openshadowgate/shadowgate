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
	set_short("Ruined Road Through the Woods");
	set_long("%^BOLD%^%^WHITE%^Ruined Road Through the Woods\n"+
	"%^BOLD%^%^BLACK%^This ruined road lays within a thick, poisonous haze. Bones of dead humanoids litter the ground. To the west, is a %^BOLD%^%^WHITE%^gaping black hole%^RESET%^%^BOLD%^%^BLACK%^ in the ground. Tendrils of darkness flow and ebb from the abyss, spewing out towards the sky to turn the entire world black. Getting any closer to the darkness that reigns to the west would be incredibly dangerous. %^RED%^Even here, you feel your skin begin to boil and your soul is slowly crushed by terrible nightmares.%^RESET%^\n"
	);
	set_smell("default","It smells of death and rotting flesh.");
	set_listen("default","You can hear the sound of your worst nightmares lurking to the west.");
	set_items(([
		"mountains" : "The mountains extend as far as the eye can see.",
		({"road","little road","path","trail"}) : "The road is ruined and there is a gaping abyss to the west.",
		({"trees","tree","pines"}) : "The trees are thick and tall but thin out up ahead where the city was.",
	]));
	set_exits(([
	"northeast" : ROOMS+"trail4",
        "southwest" : ROOMS+"trail6",
	]));
}
