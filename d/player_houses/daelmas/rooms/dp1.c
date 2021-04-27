//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit ROOM;

void create(){
  	::create();
   set_name("Dirt path");
   set_short("dirt path");
   set_long(
   	"A small dirt path leads through the woods. The path "+
   	"looks well used, although there are small rocks and twigs "+
   	"in it. While it is well used, it is not well cared for. "+
   	"The trees do not seem heavy along the sides of the path, "+
   	"but thicken so as to be impassable. In the distance, "+
   	"rising over the trees is a cliff, upon which looms a "+
   	"tower of marble.\n"
   );
   set_terrain(SHORE);
   set_travel(DIRT_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_smell("default","The smells of pine and the nearby ocean mix "+
   	"pleasantly here.");
   set_listen("default","Sounds of birds in the trees and the lapping "+
   	"of the distant ocean on the shore fills the air.");
   set_items(([
	]));

   set_exits(([
		"north" : DROOMS+"dp0",
		"southwest" : DROOMS+"dp2",
		"southeast" : DROOMS+"dp3"
	]));
}