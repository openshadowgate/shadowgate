//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
    set_short("Dark Tunnel");
    set_long(
    "%^BOLD%^%^BLACK%^"+
    "The tunnel is dark and damp. The walls are roughly cut from the mountain. There is a "+
    "sidetunnel that leads off southwest. A hole in the south wall lets some light into "+
    "the tunnel. A ladder leads up into the darkness and down through a hole in the floor "+
    "to an unseen room. There is a slight draft from the southwest tunnel.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","You can smell food.");
    set_listen("default","You hear the echo of your every move.");
    set_items(([
    	"ladder":"The %^ORANGE%^ladder%^RESET%^ is made out of hard wood and looks sturdy."
	]));
    set_exits(([
	"up" : MROOMS+"mel8",
	"down" : MROOMS+"mel8d2",
	"hole" : MROOMS+"melsup",
	"southwest" : MROOMS+"meltout"
    ]));
}
