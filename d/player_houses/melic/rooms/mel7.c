//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("Castle Hallway");
    set_long(
    "%^GREEN%^"+
    "The hallway ends at a door in the north wall.  The door is %^ORANGE%^wooden%^GREEN%^ "+
    "and has no visible locks, but it is more massive that others you have seen in this "+
    "corridor.  There are 4 paintings on the walls showing heroes in the midst of heoric "+
    "deeds.  Warmth spreads from the northern door. To the south you can see 2 large "+
    "statues.  Torches are placed at regular intervals along the corridor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells clean.");
    set_listen("default","You can hear the faint crackle of a fire behind the door to "+
    		"the north.");
    set_items(([
    	({"painting","paintings"}):"You can view the paintings by looking at them by number.",
	"painting 1":"This painting, on the west wall, shows a group of a gnome, half-elf, "+
		"and half-orc fighting a huge %^BOLD%^%^RED%^red%^RESET%^ skeleton. The "+
		"battle seems very hard and noone is %^RED%^unbloodied%^RESET%^. It seems as "+
		"though the %^BOLD%^%^ORANGE%^gnome%^RESET%^ in the back is the one with the "+
		"best chance of survival.",
	"painting 2":"The second painting on the west wall displays two half-elves in "+
		"battle with something that looks like a living pile of %^RED%^red%^RESET%^ "+
		"steel. The first half-elf has just cast a huge %^BOLD%^%^RED%^fireball"+
		"%^RESET%^, while the other is about to slam into the beast with his weapon "+
		"first.",
	"painting 3":"The first painting on the east wall is quite large and shows two "+
		"firbolgs, two half-elves, a dwarf and an elf fighting together against a "+
		"large%^BOLD%^BLACK%^ Demon%^RESET%^.  Even though the "+
		"%^BOLD%^%^BLACK%^demon%^RESET%^ looks very powerful and has several smaller "+
		"undead allies with it, the party of adventurers is obviously winning.",
	"painting 4":"This painting is the most detailed one. It depicts a man with short "+
		"%^ORANGE%^brown%^RESET%^ hair, beard, and a grim look on his face.  In one "+
		"hand he holds a hammer and he has just slain %^BOLD%^%^ORANGE%^Ashtar "+
		"%^RESET%^the supreme warrior with a single action. He looks tired and wary, "+
		"but determined."
	]));

    set_door("door",MROOMS+"melm","north","mithril key");
    set_locked("door",0,"lock");
     (MROOMS+"melm")->set_locked("door",0,"lock");
    set_door_description("door","%^RESET%^A normal %^ORANGE%^wooden%^RESET%^ door.");
    set_string("door","open","The door swings open.  Warmth from the room to the north "+
		"creeps out and caresses your face.\n");

    set_exits(([
	"north" :MROOMS+"melm",
	"south" :MROOMS+"mel6"
    ]));
}
