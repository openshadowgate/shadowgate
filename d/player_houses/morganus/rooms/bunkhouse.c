#include <std.h>
#include "../morganus.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A makeshift bunkhouse");
   set_short("%^RED%^A makeshift bunkhouse%^RESET%^");
   set_long("Several old exits fill this area. With the exception to the open archway "
"back to the bar, they have all been %^CYAN%^sealed up.%^RESET%^ Five oddly "
"well-constructed %^ORANGE%^bunk beds%^RESET%^ line the walls. The room has two "
"%^RED%^desks%^RESET%^ and a few other vanity %^MAGENTA%^trappings%^RESET%^. One of the "
"desks is small sized and has settings for the same stature of creature.");
   set_smell("default","The scent of cleaning oils and food linger here.");
   set_listen("default","The room is fairly quite with only the faintest murmurings from the main room.");

   set_items(([
     ({"bunk beds","beds"}) : "%^ORANGE%^These beds look comfortable and clean. They all "
"have soft pillows and soft wool blankets.%^RESET%^",
     "desk" : "%^RED%^This pair of desk have a nice blotter, inkwell, and candle and "
"appropriate sized tools for both small and medium sized creatures.%^RESET%^",
     ({"sealed up","exits","passages"}) : "%^CYAN%^These passages seemed to be rubble "
"filled in addition to being boarded up. The immovable rubble would mean that the boards "
"were merely to increase the aesthetics of the room. Who knows where these deep corridors "
"go. Perhaps a secret method exist to make use of them for travel.%^RESET%^",
     ({"trapping", "trappings"}) : "%^MAGENTA%^Various vanity trappings exist around the "
"room. There are small bottles of exotic smelling perfumes, two sets of full-length "
"mirrors and a collection of hair care products. It would seem the person who stocks this "
"place is rather concerned with hair condition.%^RESET%^",
   ]));

   set_exits(([
     "east" : ROOMS"bar",
   ]));
}

void reset() {
   ::reset();
   switch(random(4)) {
     case 0..1:
     tell_room(TO,"%^BLUE%^The sounds of bizarre singing in exotic tongues linger in from "
"the main bar.%^RESET%^");
     break;
     default: break;
   }
}
