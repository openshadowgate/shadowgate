//Updated to mention Jarmila's temple, which is moved to north from northwest to improve mapping. Kismet.
//Ready to install: proper path is /d/antioch/antioch2/rooms/trail6  Kismet.   

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
	"%^BOLD%^%^BLACK%^This ruined road lays within a thick, poisonous haze. Bones of dead humanoids litter the ground. To the north is the wreckage of a shrine and to the southwest, a trail takes you into the mountains. To the west, is a %^BOLD%^%^WHITE%^gaping black hole%^RESET%^%^BOLD%^%^BLACK%^ in the ground. Tendrils of darkness flow and ebb from the abyss, spewing out towards the sky to turn the entire world black. Getting any closer to the darkness that reigns to the west would be incredibly dangerous. %^RED%^Even here, you feel your skin begin to boil and your soul is slowly crushed by terrible nightmares.%^RESET%^\n"
	);
	set_smell("default","It smells of death and rotting flesh.");
	set_listen("default","You can hear the sound of your worst nightmares lurking to the west.");
	set_items(([
		"mountains" : "The mountains extend as far as the eye can see.",
		({"road","little road","path","trail"}) : "The road is ruined and there is a gaping abyss to the west.",
		({"trees","tree","pines"}) : "The trees are thick and tall but thin out up ahead where the city was.",
		({"shrine","beautiful shrine"}) : "A ruined shrine lay wrecked to the north",
	]));
	set_exits(([
		"northeast" : ROOMS+"trail5",
		"north" : "/d/magic/temples/jarmila/jarmilaentry",
		"southwest" : "/d/antioch/greaterantioch/rooms/road/road1.c",
		"west" : ROOMS+"gates",
	]));
	set_pre_exit_functions(({"west"}),({"go_west"})); 
}

int go_west()
{
	object obj;

	find_object_or_load("/d/antioch/antioch2/rooms/gates");
		"/d/antioch/antioch2/rooms/gates"->set_dir("west");
	return 1;
}
