#include <std.h>
#include "../morganus.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A private room");
   set_short("%^BOLD%^%^RED%^A private room%^RESET%^");
   set_long("As far as bedrooms go this one is obviously well lived in. Weapon working "
"equipment and other assorted trinkets lurk about as if they dont belong. There is a "
"large %^RED%^bed %^RESET%^that looks very comfortable. In the corner rests a small "
"%^YELLOW%^desk %^RESET%^with a few things upon it. A group of small %^BOLD%^paintings "
"%^RESET%^rest on the mantle of a non-functional fireplace.");
   set_smell("default","This place smells of roasted meat, heady incense and weapon oil. ");
   set_listen("default","This room is completely silent. No sound escapes past the door.");

   set_items(([
     ({"paintings","small paintings"}) : "%^CYAN%^ This is a small collection of three "
"paintings contained in a small three framed picture stand.%^RESET%^ %^BLUE%^ One picture "
"is that of an attractive blonde human leaning on a scythe. A sad smile rest upon his "
"lips.%^RESET%^  %^BOLD%^%^WHITE%^One shows a short dark elf with a strange smile and a "
"holy symbol of Selune. He seems to be standing outside of the gates of the city of Torm "
"along side a rather grim looking half-elf wearing a wolfs head visor. %^RESET%^ "
"%^YELLOW%^The final one shows the same dark elf standing back to back with a female "
"halfling with blue eyes and red hair. She wields a pair of keen looking twin daggers. "
"They stand outside of a dark and twisted stronghold fighting off hoards of "
"goblins.%^RESET%^ %^CYAN%^The pictures are entitled 'Jeremiah', 'Me and Lord Wolf', and "
"'Tara and Morganus: Best Friends'%^RESET%^",
     "bed" : "%^RED%^This bed is made of soft warm cotton sheets and has a down mattress. "
"The pillows are many and look like they are well fluffed.%^RESET%^",
     ({"desk", "small desk" }) : "%^YELLOW%^This desk has an inkwell and a blotter. There "
"is a mirror off to the side and a few hair care products including scent enhancers and "
"combs.%^RESET%^",
   ]));

   set_exits(([
     "south" : ROOMS"bar",
   ]));
   set_door("blue door",ROOMS"bar","south",0);
   set_door_description("blue door", "%^BOLD%^%^CYAN%^This door is made of strong metal dyed a blue tint. "
"It has the symbols of several gods of good etched around the doorframe.%^RESET%^");
}
