#include <std.h>
#include "../defs.h"
inherit VAULT;
 
void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain("barren");
        set_travel("paved road");
        set_name("Fancy Foyer");
        set_short("%^BOLD%^%^BLACK%^A Fancy Foyer%^RESET%^");
        set_long(" %^BOLD%^%^BLACK%^You have stepped into the lavish foyer of a great %^RESET%^%^MAGENTA%^home%^BOLD%^"
"%^BLACK%^.  The floor is a polished %^BLUE%^black marble%^BLACK%^ with shiny fine %^BOLD%^%^MAGENTA%^v%^RESET%^"
"%^MAGENTA%^i%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^BLACK%^lines "
"that seem to almost %^YELLOW%^g%^WHITE%^l%^YELLOW%^o%^WHITE%^w%^BLACK%^ in the dim %^GREEN%^n%^BLACK%^e%^GREEN%^c"
"%^BLACK%^r%^GREEN%^m%^BLACK%^a%^GREEN%^n%^BLACK%^t%^GREEN%^i%^BLACK%^c glow that is everwhere but doesn't seem to come "
"from anywhere.   Oddly enough , whatever brought you to this room must have been a %^RESET%^%^CYAN%^one way %^BOLD%^"
"%^BLACK%^entrance.  There is no %^RESET%^%^GREEN%^'%^RED%^turning back%^GREEN%^'%^BOLD%^%^BLACK%^ If you happen to look "
"up you'll experience a vast sense of %^RESET%^%^BLUE%^space %^BOLD%^%^BLACK%^and a very complete feeling of looking at "
"nothing.  To the east is a set of %^BLUE%^black%^RESET%^%^ORANGE%^-%^BOLD%^%^BLUE%^carpeted %^RESET%^%^ORANGE%^stairs"
"%^BOLD%^%^BLACK%^ that seem to spiral down.  Near the first few steps on the wall is a %^RESET%^%^ORANGE%^u%^RED%^s"
"%^ORANGE%^t%^RED%^e%^ORANGE%^d %^BOLD%^%^BLACK%^iron plaque.  To the west  are a set of %^BOLD%^%^WHITE%^white marble "
"%^RESET%^%^ORANGE%^stairs %^BOLD%^%^BLACK%^that spiral up and out of your line of sight.  There is a %^YELLOW%^b%^RESET%^"
"%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^s%^YELLOW%^s%^BLACK%^ plaque on the wall near the base of this set of steps.  "
"To the north you see 20 foot high %^RESET%^%^RED%^double doors%^BOLD%^%^BLACK%^ made of thick %^WHITE%^white %^RESET%^"
"%^ORANGE%^pine %^BOLD%^%^BLACK%^which has been saturated in some kind of %^BLUE%^black pitch%^BLACK%^.  The double doors "
"are reinforced by a %^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^ alloy "
"that bands the wood together.  The bands are covered in %^BLUE%^r%^MAGENTA%^u%^GREEN%^n%^WHITE%^e%^CYAN%^s %^BLACK%^and "
"sigils.\n");
        set_smell("default","You smell yourself and your equipment, nothing else.");
        set_items(([
          ({"iron plaque","plaque 1"}) : "%^RESET%^%^RED%^The iron plaque has bold three dimensional characters that read "
"%^YELLOW%^Descend to the End.",
          ({"brass plaque","plaque 2"}) : "%^BOLD%^%^BLACK%^The brass plaque has bold three dimensional characters that "
"read %^GREEN%^Climb to the Beginning.",
          "front door" : "%^RESET%^%^ORANGE%^These doors are closed.  There is a %^BOLD%^%^BLUE%^black %^BLACK%^rusted "
"knocker %^RESET%^%^ORANGE%^on each of the great doors.",
        ]));
        set_exits(([
          "down" : ROOMS"theend",
          "up" : ROOMS"start",
          "north" : ROOMS"dithasimage"
        ]));
        set_door("double doors",ROOMS"dithasimage","north",0);
        set_door_description("double doors","%^BOLD%^%^CYAN%^You see 20 foot high double doors made of thick white pine "
"which has been saturated in some kind of black pitch.  The double doors are reinforced by a silver alloy that bands the "
"wood together.  The bands are covered in runes and sigils.%^RESET%^");
}
