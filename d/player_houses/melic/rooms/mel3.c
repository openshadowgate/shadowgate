//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
   set_travel(FOOT_PATH);
    set_short("Castle Garden");
    set_long(
    "%^BOLD%^%^GREEN%^"+
    "The entirety of the room is a breathtaking garden.  Spires of "+
    "%^ORANGE%^honeysuckles%^GREEN%^ are found mixed amoung innumerable "+
    "beautiful%^CYAN%^ flowers%^GREEN%^. Everything is arranged along the sides "+
    "of the garden, with a small %^RESET%^%^GREEN%^grass%^BOLD%^ glade in the middle. The "+
    "ground is very soft, almost like a bed, and there is a small path of marble stones "+
    "leading through it.\n"+
    "%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The smell of %^BOLD%^%^ORANGE%^honey%^RESET%^%^ORANGE%^ and "+
		"%^BOLD%^%^WHITE%^vanilla%^RESET%^%^ORANGE%^ fills the air coming from an "+
		"enchanted box.");
    set_listen("default","Occassionally you can hear a song bird sing.");
    set_items(([
    	"honeysuckle":"Large bushes of %^BOLD%^%^ORANGE%^honeysuckle%^RESET%^ reach skyward, "+
		"brightening the area and giving off a pleasant fragrance from their "+
		"%^BOLD%^%^WHITE%^white %^RESET%^and %^BOLD%^%^ORANGE%^yellow%^RESET%^ blooms. "+
		"They appear well cared for, and hummingbirds flutter around the flowers.",
	"flowers":"%^BOLD%^%^RED%^Roses%^RESET%^, %^BOLD%^%^CYAN%^orchids%^RESET%^, and "+
		"numerous other flowers abound within the garden, mixed within the trees of "+
		"%^BOLD%^%^ORANGE%^honeysuckle%^RESET%^. Their mingled smells enchant the air.",
	({"stones","stone","path","marble stones"}):"The stepping stones are made of "+
		"%^BOLD%^%^WHITE%^white%^RESET%^ marble.  Upon each is a %^MAGENTA%^purple "+
		"%^RESET%^disk with a %^BOLD%^%^BLACK%^black%^RESET%^ outline painted on them."
	]));
   new(MMONS+"tiger")->move(TO);
   set_exits(([
	"west" :MROOMS+"mely"
    	]));
}
