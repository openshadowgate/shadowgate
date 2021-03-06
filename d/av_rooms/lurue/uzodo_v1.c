// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_v1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^YELLOW%^A small village%^RESET%^");

    set_long("%^RESET%^The forest gives away here to a winding clearing.  Small %^GREEN%^saplings %^RESET%^grow up amongst %^ORANGE%^mud and waddle huts %^RESET%^that are set back from the game trail you have been "
	"following.  The saplings provide a bit of shade to the otherwise exposed huts, including the tiny patches of growing %^GREEN%^gardens %^RESET%^which lay beside the buildings.  Doorways and windows are"
	" protected by %^BOLD%^%^BLACK%^heavy pelts %^RESET%^of some furry beast, while braided ropes of %^ORANGE%^woody fibers %^RESET%^are used to suspend the gutted remains of the day's catch from the stron"
	"ger branches of the trees.  A hunting-and-gathering society, the little village couldn't have more then a few dozen residents all told.%^RESET%^"
	);

    set_smell("default","
There is a copper tang in the air along with the smell of turned soil.");
    set_listen("default","Trees move in the wind and in the distance you can hear the ocean.");

    
set_items(([ 
	({ "huts", "daub and waddle huts" }) : "%^RESET%^%^ORANGE%^The huts are made using a framework of wooden beams that is then plastered with several layers of dried mud. The effect of which makes for a deep brownish gray wall that blends well with the forested setting.%^RESET%^",
	({ "trees", "tree", "foliage", "plants" }) : "%^BOLD%^%^GREEN%^The trees grow thickly together here creating a natural blind and preventing you from seeing further into the island.  Cypress, cedar, fir, hemlock, pine, spruce, and juniper cluster and spread their thickly nettled branches outward.%^RESET%^",
	({ "doors", "windows", "pelts" }) : "%^BOLD%^%^BLACK%^Strips of dark fur covered pelts hang over the windows and doorways of the huts.  The fur looks shaggy and old, making you wonder just how old the buildings are.%^RESET%^",
	({ "meat", "carcass", "remains" }) : "%^RED%^The remains hang from some of the higher branches of the saplings.  Keeping them safe from animals that might wander in out of the forest, while allowing them to cure in the air.  They've been skinned and gutted, though you imagine they're deer or wild pig but the look of them.%^RESET%^",
	"saplings" : "%^BOLD%^%^GREEN%^The saplings appear to have been planted rather then grown naturally.  Each one is quite small compared to the surrounding forest, but their limbs reach out to provide a bit of shade to the huts below them.  From a few, hunks of meat are suspended, probably to dry and cure them as much as to keep forest animals from taking them.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/uzodo_h1",
		"east" : "/d/av_rooms/lurue/uzodo_v2",
	]));

    set_door("hut door","/d/av_rooms/lurue/uzodo_h1","south");
    set_open("hut door",0);
    set_string("hut door","knock","knock on the");
    set_string("hut door","open","You lift the fur pelt that covers the doorway and peer into the hut's gloom.");
    set_string("hut door","close","You drop the fur covered pelt back into place across the doorway.");
    set_door_description("hut door","The doorway is covered with a thick pelt of shaggy fur.");
}