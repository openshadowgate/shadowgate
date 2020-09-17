//Octothorpe (6/2/16)
//Shadow, Melistel Avenue E (South Bridge)

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Puente Zincharo");
   set_short("%^BOLD%^South Span of the Puente Zincharo, Shadow%^RESET%^");
   set_long("%^BOLD%^South Span of the Puente Zincharo, Shadow%^RESET%^\n "+
      "%^CYAN%^Melistel Avenue %^BOLD%^%^WHITE%^crosses over an "+
      "impressive stone arch bridge to reach the southern shore of the "+
      "%^BOLD%^%^BLUE%^Sarcosta River%^WHITE%^. The bridge is wide "+
      "enough to accomodate the normal flow of pedestrians and wagons "+
      "that %^RESET%^%^CYAN%^Melistel Avenue %^BOLD%^%^WHITE%^sees on "+
      "a typical day, as well as the series of four-story buildings "+
      "that line both sides of the bridge. The view of the river is "+
      "blocked on both sides by the shops. South of the bridge "+
      "%^RESET%^%^CYAN%^Melistel Avenue %^BOLD%^%^WHITE%^leads toward "+
      "the city's southern gate. The bridge continues to the north "+
      "over its center span. %^YELLOW%^Curiously, there seems to be some construction " +
      "occuring here; a path being built to the east.%^RESET%^\n");
   set_smell("default","Your nose catches a whiff of unusual scents "+
      "from the shops.");
   set_listen("default","The sound of the flowing river beneath you "+
      "is drowned out by the dull roar of conversations and "+
      "pedestrians and wagons rumbling over the bridge.");
   set_items(([
      ({"bridge","stone arch bridge","stone bridge"}) : "This ancient "+
         "stone bridge dates to the time of the Zin'Charu Empire. It "+
         "is constructed out of a stout light gr%^WHITE%^a%^RESET%^y "+
         "stone, however multiple parts of the bridge bear the same "+
         "type of stone, yet of differing weathering and color. The "+
         "bridge is roughly 400 feet in length, across three arched "+
         "spans. The arches are high enough to accomodate the flat-"+
         "bottomed boats that travel up river to Tabor. A row of "+
         "four-story buildings line both sides of the bridge, "+
         "containing a multitude of shops.",
      ({"shop","shops","buildings"}) : "Both sides of the bridge are flanked by a series of assorted shops plying their wares.",
   ]));  
   set_exits(([
      "north" : ROOMS"melisteld",
      "south" : ROOMS"melistelf",
   ]));   
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new("/d/common/obj/misc/street_light")->move(TO);
}  