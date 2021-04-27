


#include <std.h>
#include "../yuki.h"
inherit CVAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("summoning room");
    set_short("%^BLACK%^%^BOLD%^summoning room%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^What strikes you about this room is not what is in it, "+
	"but by the sudden o%^RESET%^p%^BLACK%^%^BOLD%^pre%^RESET%^s%^BLACK%^%^BOLD%^ive "+
	"fe%^RESET%^e%^BLACK%^%^BOLD%^l of it. It is as if the air has never moved and you "+
	"find you have to work harder to draw a breath. The room is a circle, with "+
	"%^RESET%^%^RED%^gly%^BOLD%^p%^RESET%^%^RED%^hs%^BLACK%^%^BOLD%^ covering each "+
	"wall from gloor to ceiling. The floor is set with %^RESET%^%^ORANGE%^"+
	"stones%^BLACK%^%^BOLD%^ forming ever smaller concentric circles. Although the "+
	"stones seem tightly packed, %^RESET%^wh%^BOLD%^i%^RESET%^ffs of sm%^BOLD%^"+
	"o%^RESET%^ke%^BLACK%^%^BOLD%^ puff every once and awhile. When that happens, "+
	"the %^RESET%^%^RED%^gly%^BOLD%^p%^RESET%^%^RED%^hs%^BLACK%^%^BOLD%^ flare to "+
	"life. Along the wall sits a %^RESET%^%^ORANGE%^small desk%^BLACK%^%^BOLD%^ "+
	"and %^RESET%^%^ORANGE%^chair%^BLACK%^%^BOLD%^, but you cant think of how "+
	"someone could stand to be in this room long enough to write anything "+
        "meaningful. \n%^RESET%^");
    set_smell("default","%^BLACK%^%^BOLD%^You smell cold stone.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^You hear soft whispers.%^RESET%^");

    set_items
    (([
        ({"circle", "floor"}) : "%^BLACK%^%^BOLD%^The floor is set with small stones "+
		"that are arranged in ever smaller concentric circles. The effect is as if the "+
		"floor is a spiral. You find you cannot walk closer into the circle without "+
		"feeling great discomfort.%^RESET%^",
        ({"glyphs", "runes"}) : "%^RESET%^%^RED%^gly%^BOLD%^p%^RESET%^%^RED%^hs%^RESET%^%^RED%^ "+
		"on the walls %^BOLD%^flare%^RESET%^%^RED%^ to life every once and awhile, bathing "+
		"the room in a red %^BOLD%^glow%^RESET%^%^RED%^.%^RESET%^",
		({"desk", "chair"}) : "%^RESET%^%^ORANGE%^A small desk "+
		"and chair sit off to one side of the room. The desk is "+
		"covered in papers.%^RESET%^",
		({"papers", "drawings"}) : "%^CYAN%^The papers on the desk "+
		"look to be drawings of the circle, the runes, and several "+
		"beasts of unknown origin.%^RESET%^",
    ]));
	   set_exits(([
          "south" : ROOMS"sec2",
   ]));

}

void reset() {
  switch(random(4)){
     case 0..1:
       tell_room(TO,"%^BLACK%^%^BOLD%^You hear soft voices in unknown languages.%^RESET%^");
     break;
     case 2..3:

       tell_room(TO,"%^RESET%^%^RED%^The glyphs flare to life.%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^RESET%^%^BOLD%^A whiff of smoke escapes the circle, drifting off.%^RESET%^");
     break;
   }
}
