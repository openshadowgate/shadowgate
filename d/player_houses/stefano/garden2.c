//garden2.c - Part of Stefano's garden, provides entrance to cottage.  Coded by Circe 9/20/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(GRASSLANDS);
        set_travel(FOOT_PATH);
        set_name("A gated garden");
        set_short("A gated garden");
        set_long("%^BOLD%^%^GREEN%^Two more %^RESET%^grey stone buildings"+
           "%^BOLD%^%^GREEN%^ sit among the lawns and %^RED%^f%^MAGENTA%^l%^BLUE%^o"+
           "%^CYAN%^w%^GREEN%^e%^YELLOW%^r %^RED%^b%^MAGENTA%^e%^BLUE%^d%^CYAN%^s"+
           " %^BOLD%^%^GREEN%^here. The "+
           "%^BOLD%^%^BLACK%^black iron fence%^BOLD%^%^GREEN%^ surrounds this part "+
           "of the garden, too, but there is no gate here. The building nearest "+
           "the river looks like a %^RESET%^large country cottage%^BOLD%^%^GREEN%^, "+
           "while a smaller, square building gives scant clue as to its purpose.  "+
           "%^RESET%^Wisps of white smoke%^BOLD%^%^GREEN%^ rise from the chimney of the cottage."+
           "\n");
        set_smell("default","You can smell the sweet perfume of the "+
           "%^BOLD%^%^BLUE%^f%^WHITE%^l%^MAGENTA%^o%^WHITE%^w%^BLUE%^e%^WHITE%^r"+
           "%^MAGENTA%^s%^RESET%^%^ORANGE%^, and the scent of the %^BOLD%^%^GREEN%^fresh cut grass%^RESET%^.");
        set_listen("default","You can hear the babble of the stream flowing by, and "+
           "the creak of the slowly turning water wheel.");
        set_items(([
           "lawns" : "The lawns are neatly maintained and kept quite short. Looking "+
              "closely, you can see two channels of water running through the lawns, "+
              "between the river and the small square building.",
           "fence" : "The twisted %^BOLD%^%^BLACK%^black iron lattice%^RESET%^ has been "+
              "wrought into complex, eye watering patterns. Sometimes there seem to be "+
              "pictures in it, sometimes symbols, but it is hard to focus your eyes and "+
              "concentrate on any one spot. In the gaps between the iron itself, you can "+
              "see that the air shimmers with a %^CYAN%^faint blue haze%^RESET%^.",
           "channels" : "The two channels run more or less parallel to each other, but "+
              "curiously the water flows in opposite directions, one flowing from the river "+
              "to the square building, the other from the building to the river.",
           "cottage" : "The large country cottage has a %^RED%^red tiled roof%^RESET%^ "+
              "and a chimney stack with a little smoke coming out of the chimney. The "+
              "building is in a shortened T shape, with the main entrance on the side "+
              "furthest from the river.",
           ({"small building", "square building", "building"}) : "The smaller, square "+
              "building has a flat roof, and a door with a little steam seeping out at "+
              "the edges. Other than that, there is not much to say about it.",
            ({"flowers","flower beds","beds"}) : "The well-maintained flower beds are filled with "+
               "exotic flowers of all types.  %^BOLD%^%^RED%^Bright snapdragons %^RESET%^stand alongside "+
               "%^BOLD%^%^CYAN%^mul%^GREEN%^ti%^YELLOW%^col%^RED%^or%^MAGENTA%^ed %^BLUE%^lil%^WHITE%^ie%^BLUE%^s"+
               "%^RESET%^.  %^BOLD%^%^GREEN%^Birds %^YELLOW%^of %^MAGENTA%^par%^YELLOW%^a%^MAGENTA%^dise "+
               "%^RESET%^stand tall among the other flowers, their bold colors proudly displayed."
        ]));
        set_exits(([
           "east" : SHOUSE"garden1", 
           "cottage" : SHOUSE"entrancehall",
           "building" : SHOUSE"bathhouse"
   ]));
     	  set_door("cottage door",SHOUSE"entrancehall","cottage",0);
        set_door_description("cottage door", "A simple arched oak door");
  	  set_door("building door",SHOUSE"bathhouse","building",0);
        set_door_description("building door", "A squared stone door, with a faint mist seeping out through the cracks");
}