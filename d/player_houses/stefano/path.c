//path.c - Entrance for Stefano's house from Attaya's beach.  Coded by Circe 12/5/03
#include <std.h>
#include "stefano.h"
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(GRASSLANDS);
        set_travel(FOOT_PATH);
        set_name("A rocky path");
        set_short("A rocky path");
        set_long("Just behind the waterfall, this narrow opening opens further into "+
           "a wide, rocky path.  The rock supporting the falls has been chipped away "+
           "to allow passage through what turns out to be a narrow rock wall.  Cleverly "+
           "designed, this path is all but hidden from view from the waterfall.  Northward, "+
           "the path continues to the surprisingly sandy shore of a smaller stream.  The "+
           "silhouette of a tower rises in that direction."+
           "\n");
        set_smell("default","The clean scent of the waterfalls rides on the air.");
        set_listen("default","The roar of the waterfall drowns out other sounds.");
        set_items(([
           ({"waterfall","falls"}) : "The strong waterfall hides the beach from view.  It "+
              "flows fiercly, muffling sound as well.",
           "tower" : "A gray stone tower rises in the land to the north.",
           ({"path","ground","floor"}) : "The path here is rocky and seems to have been "+
              "worn smooth over time.  Parts of it seem almost too smooth, and it's obvious "+
              "that either magic or mechanical means were employed to create it.",
           ({"rock","opening"}) : "The smooth rock wall behind the falls has been chipped away "+
              "and opens into a wide path, leading to a stone tower."
        ]));
        set_exits(([
           "southeast" : "/d/attaya/beach5",
           "north" : "/d/attaya/tunnels/rooms/stefano_entry"
   ]));
}
