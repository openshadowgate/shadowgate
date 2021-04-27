//path2.c - winding path to Shrydelhi's house.  Coded by Circe 9/26/03
#include <std.h>
#include "shry.h"

inherit ROOM;

void create(){
  ::create();
  set_terrain(HEAVY_FOREST);
  set_travel(FOOT_PATH);
  set_property("light",2);
  set_name("A winding path");
  set_short("A winding path");
  set_long(
  "A winding path.\n"+
  "%^CYAN%^The thick trees all around give way for this tiny, winding path.  "+
  "The path climbs over small rises and through bushes, but strangely, no brambles "+
  "prick you here.  Looking closer, you realize that this path must be tended, though "+
  "someone has taken pains to make it look as natural as possible.  Strangely, this "+
  "narrow path seems to end here."+
  "\n"
  );
  set_smell("default","You can smell the fresh scent of pines and mountain air.");
  set_listen("default","The gentle murmuring of a brook rises on the wind.");
  set_items(([
  "trees":"Tall evergreens close in on the path from all sides, making it difficult to see "+
     "if there is anything off the path.",
  ({"mountain", "Mt. Krakus", "krakus", "Krakus"}):"Mt. Krakus overshadows you even hidden "+
     "in these trees, and you wonder of the evil that lies under it.",
  "path":"It looks like someone has taken pains to make sure it wasn't too "+
     "obvious to the casual observer.",
  ]));
  set_search("default","The thick trees make you wonder what could be hidden behind their trunks.");
  set_search("trees","Searching the trees, you think you see a path leading off to the northeast.");
  set_exits(([
  "south":SHRY"path1",
  "northeast":SHRY"meadow",
  ]));
  set_invis_exits(({"northeast"}));
}
