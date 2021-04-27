#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A bathroom");
    set_short("%^ORANGE%^A bathroom%^RESET%^");
    set_long("%^BOLD%^The walls in this room are made out of well polished "
"white m%^CYAN%^a%^WHITE%^r%^CYAN%^b%^WHITE%^l%^CYAN%^e %^WHITE%^instead of "
"brick. A very large bathtub is set against one of the walls, easily large "
"enough to fit several people. On another wall hangs a %^CYAN%^mirror "
"%^WHITE%^above a wash basin.%^RESET%^");
    set_smell("default","%^BOLD%^%^MAGENTA%^An intoxicating fragrance of "
"perfume and scented bath oil lies over the room.%^RESET%^");
    set_listen("default","%^BOLD%^%^CYAN%^A soft murmur can be heard from the "
"water pipes.%^RESET%^");
    set_items(([
      "tub" : "%^BOLD%^This roomy and comfortable tub has been sculpted into "
"the m%^CYAN%^a%^WHITE%^r%^CYAN%^b%^WHITE%^l%^CYAN%^e %^WHITE%^. It has "
"%^YELLOW%^gilded %^WHITE%^taps for both %^RED%^warm %^WHITE%^and %^BLUE%^"
"cold %^WHITE%^water, and a bench on each side. The tub could easily hold "
"four people, and still give room for %^CYAN%^aquatic %^WHITE%^fun and "
"games.%^RESET%^",
      "mirror" : "%^BOLD%^%^CYAN%^The mirror has a %^YELLOW%^gilded%^CYAN%^ "
"frame and reflects your image perfectly.",
    ]));
    set_exits(([
      "bedroom" : ROOMS"bed1",
    ]));
    set_door("bath door",ROOMS"bed1","bedroom",0);
    set_door_description("bath door", "%^ORANGE%^This is a standard oak door, "
"made of heavy oaken planks bound together with iron rivets.%^RESET%^");
}
