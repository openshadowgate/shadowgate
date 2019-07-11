#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_light(2);
   set_indoors(1);
   set_smell("default","The air is filled with the tang of incense burning upon bronze.");
   set_listen("default","The pulse of the myriad crystals resonate their own harmonic chime.");
   set_name("A crystalline shrine");
   set_short("A crystalline shrine");
   set_long("%^BOLD%^%^CYAN%^A mountaintop shrine%^RESET%^\n"+
"%^CYAN%^You are in what appears to be the hollow of a massive geode.  "+
"Crystals in many a hue adorn the sides of the spherical wall like so "+
"many stalactites.  The smooth floor, composed of worked %^BOLD%^"+
"%^BLACK%^obsidian%^RESET%^%^CYAN%^ tiles, was grouted with "+
"%^YELLOW%^molten %^RESET%^%^ORANGE%^bronze%^CYAN%^, lending its "+
"surface a veined, living appearance.  Three beaten %^ORANGE%^bronze "+
"censers%^CYAN%^, each burning a heady incense, surround a massive "+
"%^BOLD%^%^WHITE%^crystal monolith%^RESET%^%^CYAN%^ in a triangular "+
"pattern.  The monolith itself sits atop a burnished %^ORANGE%^bronze "+
"ziggurat%^CYAN%^ and features an unusual %^BOLD%^cyan glow%^RESET%^"+
"%^CYAN%^ within.  The %^BOLD%^glow%^RESET%^%^CYAN%^ emanates from a "+
"large, stylized eye, held within the crystal monolith's center.\n%^RESET%^"
   );
   set_exits(([
      "out":"/d/darkwood/tabor/room/auppenser4"
   ]));
}