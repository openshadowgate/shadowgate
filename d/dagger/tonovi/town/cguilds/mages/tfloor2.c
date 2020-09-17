//updated by Circe with color, etc 5/30/04
// Level 2 Landing in the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010206
// Tabor
// tfloor2.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Floor 2");
    set_short("Level 2 Landing in the Tower of the Arcane, Tabor");
    set_long(
"%^BOLD%^Level 2 Landing in the Tower of the %^CYAN%^A"+
"%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, "+
"Tabor%^RESET%^\n"+
"%^BOLD%^%^BLACK%^This is the second level of the %^CYAN%^Tower "+
"of the Arcane%^BLACK%^.  From here you can look down a lavish "+
"%^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k "+
"ma%^BOLD%^%^BLACK%^rb%^RESET%^le%^BOLD%^%^BLACK%^ staircase carved "+
"with images of to %^WHITE%^angels%^BLACK%^, demons, %^RED%^dragons%^BLACK%^, "+
"and other %^BLUE%^magical creatures %^BLACK%^in an appropriately "+
"colored marble that leads down to the first level.  Another "+
"staircase, less ornate, but still of fine construction, leads up "+
"to the next level.  A mystical %^YELLOW%^light %^BLACK%^shines "+
"down from somewhere above, lighting the landing.\n\n"+
"%^RESET%^To the north, you can see a decent sized library through "+
"the doorway arch.  To the east, there is a store that looks like "+
"it contains a great deal of clutter and what looks like "+
"miscellaneous items.\n"
    );
    set_property("light",2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_property("indoors",1);
    set_smell("default","A number of strange smells are coming from the east.");
    set_listen("default","You hear a cacaphony of sound to the east.");
    set_items(([
       "angels" : "%^BOLD%^The angels have been carved from "+
                  "brilliant white ivory.  They are shown in "+
                  "several poses - some in flight while others "+
                  "kneel in prayer.",
       "demons" : "%^BOLD%^%^BLACK%^The demons are carved from "+
                  "glittering black marble, deeper than the "+
                  "black of the staircase.  They have %^RED%^"+
                  "rubies %^BLACK%^for eyes and are shown in "+
                  "all manner of poses, most often tormenting "+
                  "mortals.",
       "dragons" : "The dragons are shown in "+
                   "various colors - %^BOLD%^%^RED%^red%^RESET%^, "+
                   "%^BOLD%^%^BLUE%^blue%^RESET%^, %^BOLD%^%^BLACK%^"+
                   "black%^RESET%^, %^BOLD%^%^GREEN%^green%^RESET%^,"+
                   " %^YELLOW%^gold%^RESET%^, and even %^BOLD%^"+
                   "silver%^RESET%^!  Each is depicted in flight.",
       ({"creatures","magical creatures"}) : "In addition to the "+
                   "demons, dragons, and angels, there are many "+
                   "other creatures that are connected to magical "+
                   "lore.  The fae creatures stand alongside the "+
                   "phoenix, roc, and darker creatures such as the "+
                   "illithid.",
       ({"steps","stairs"}) : "This grand staircase has been worn "+
          "by countless feet.  It is made of deep black marble, and "+
          "it still glitters like new.",
       "light" : "The strange light is bright as sunlight, but it "+
          "seems to have a bluish glow.  There seems to be no source "+
          "for it, but it permeates the area and seems to come from "+
          "somewhere above."
    ]));
    set_exits( ([
        "north" : ROOMDIR+"tlib",
        "east"  : ROOMDIR+"compstore2",
        "down"  : ROOMDIR+"tfloor1",
        "up"    : ROOMDIR+"tfloor3",
    ]) );
}
