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
    "The hallway is approximately 10 feet wide and twice as high.  The ceiling is a "+
    "long arch and is given extra support by pillars.  Armor and weapon racks line the "+
    "walls here, but most of the items here seem rather old and look to have lost their "+
    "usefulness.  Both sides of the corridor have curtains which partially conceal "+
    "stairs.  The eastern stairs lead downward and the western stairs lead upward.  The "+
    "stairs are covered by long %^RED%^red%^GREEN%^ rugs.  Two huge statues stand facing "+
    "each other at the northern end of the corridor.  The statues are holding halberds "+
    "that cross over the hallway and you would need to walk under the halberds to go "+
    "further north.  The statues are representations of %^BOLD%^%^WHITE%^titans "+
    "%^RESET%^%^GREEN%^and they look quite life-like.  Torches are placed at regular "+
    "intervals along the corridor.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The smell of musty armor and weapons fill the air.");
    set_listen("default","It is silent.");
    set_items(([
    	({"armor","armors","weapon","weapons","rack","racks"}):"Gothic style full-plate "+
    		"armor, huge two-handed swords, warhammers, and various other armors and "+
    		"weapons line the walls."
	]));
    new(MSTUFF+"tstatue")->move(TO);
    new(MSTUFF+"tstatue")->move(TO);
    set_exits(([
	"north" :MROOMS+"mel6",
	"south" :MROOMS+"mel4",
	"down" :MROOMS+"meld1",
	"up" :MROOMS+"melup1"
    ]));
}
