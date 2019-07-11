//by Circe 8/29/04 - desc provided by Lukas
#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(RUINS);
        set_travel(FOOT_PATH);
        set_name("Druids circle");
        set_short("%^YELLOW%^Druids circle%^RESET%^");
        set_long("%^YELLOW%^The grass is shorter here, the sandy soil "+
           "from a nearby%^RESET%^ %^BLUE%^creek%^RESET%^ %^YELLOW%^"+
           "providing soft ground to walk upon.  The circle is made "+
           "up of a mixture of%^RESET%^ %^WHITE%^natural boulders"+
           "%^RESET%^ %^YELLOW%^and a few large chunks of%^RESET%^ "+
           "%^WHITE%^stone%^RESET%^ %^YELLOW%^taken from the ruined "+
           "walls.  In the center of the circle is a larger, flat stone, "+
           "almost like a natural podium.  Smaller animals move through "+
           "the area seemingly without fear.  Druids move in and out of "+
           "the area, taking up seats on the rocks, conducting forums "+
           "of matters natural, whilst others tend to the surrounding "+
           "wilderness with happiness and pride.%^RESET%^\n");
        set_items(([
           ({"circle","stone circle"}) : "%^YELLOW%^Large stones have "+
              "been placed in a circle, providing decent seats%^RESET%^",
           ({"stone","boulders"}) : "%^YELLOW%^Large boulders are "+
              "positioned amongst those of the ruins, all of them too "+
              "big for even the largest of ogres to lift!%^RESET%^", 
           ({"ground","soil"}) : "%^YELLOW%^This sandy soil is "+
              "comfortable to walk upon and all%^RESET%^ %^GREEN%^grasses"+
              "%^RESET%^ %^YELLOW%^seem able to grow in it.%^RESET%^"
        ]));
        set_smell("default","%^GREEN%^The smell of trees is thick in "+
           "the air.%^RESET%^");
        set_listen("default","%^BLUE%^Calm voices of druids can be "+
           "heard, mixed with the occasional burst of mellow laughter.%^RESET%^");
        set_exits(([
           "east" : "/d/magic/temples/mielikki_center"
        ]));
}