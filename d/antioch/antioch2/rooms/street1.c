//Updated due to the addition of a jail in Antioch. Kismet. 
//Ready to be installed: Proper path is: /d/antioch/antioch2/rooms/street1 Remove this line. Kismet. 

#include <std.h>
#include "../antioch.h" 
#include <daemons.h> 

inherit CVAULT;

void create() 
{
   set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1 }));
   ::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_property("outdoors",0);
	set_property("light",2);
	set_short("A cobbled street");
	set_long("A cobbled street.\n"+
	"%^BOLD%^%^BLACK%^The city lies in ruins, covered in a dark, black haze. To the west, a gaping hole has opened up into the abyss. Tendrils of darkness spew out from it, blanketing the world in shadows. %^RED%^Even here, you feel your skin begin to boil and your soul is slowly crushed by terrible nightmares. %^RESET%^");
    set_smell("default","The smell of death hangs in the air.");
    set_listen("default","You hear the sound of your worst nightmares to the west.");
	set_items(([
        ({"guard tower","tower"}) : "There's a guard tower on the"+
        " right, it looks like there's an entrance to it to the north.",
        ({"gate","gates","gates of antioch","Gates of Antioch","gates of Antioch"}) : "The enormouse iron gates are behind you and"+
        " they are still quite impressive, they look like they would"+
        " keep just about anything out.",
        "plaque" : "It's a wooden plaque with the symbol of a healer"+
        " engraved into it.",
        "street light" : "There's a street light up ahead.",
        "square" : "There is a square to the west.",
        ({"street","cobblestones","cobbles","road","path"}) : "The"+
        " street is paved with cobblestones.",
        ]));
	set_exits(([
        "east" : ROOMS+"gates",
        "west" : ROOMS+"square",
        "north" : ROOMS+"street2",
        ]));
    set_pre_exit_functions(({"east"}),({"go_east"}));
		"/d/antioch/antioch2/obj/sign"->move(TO);
}

int go_east()
{
	object obj;

    find_object_or_load("/d/antioch/antioch2/rooms/gates");
		"/d/antioch/antioch2/rooms/gates"->set_dir("east");
        return 1;
}

		
