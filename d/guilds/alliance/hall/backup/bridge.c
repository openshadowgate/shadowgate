// /d/guilds/alliance/bridge.c

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_indoors(0);
   set_light(2);
   //set_property("no teleport",1);
   set_property("teleport proof",67);
   set_short("On the Drawbridge");
   set_long("%^CYAN%^On the Drawbridge\n "+
      "%^BOLD%^%^WHITE%^You find yourself walking on a massive "+
	  "drawbridge that leads across the dark%^RESET%^ %^ORANGE%^moat"+
	  "%^RESET%^%^BOLD%^%^WHITE%^ that surrounds the castle. The "+
	  "drawbridge is made of strong oak reinforced with iron. On it "+
	  "you see a large symbol that looks like two gauntlets shaking "+
	  "hands.\n");
   set_listen("default","You hear nothing except for the creaking drawbridge.");
   set_smell("default","The strong smell of the moat and wood fills your nose.");
   set_exits(([
      "north":"/d/guilds/alliance/hall/gate.c",
      "out":"/d/shadow/room/pass/road14.c",
   ]));
   set_items(([
      "moat":" %^BLUE%^This is a moat that surrounds the castle, built to keep attackers from the castle walls. The only way across seems to be by this drawbridge. The water looks dark and cold and the moat seems fairly deep, deep enough to keep a fully armoured warrior from swimming across it.",
   ]));
}