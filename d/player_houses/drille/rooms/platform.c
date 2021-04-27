#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A platform");
    set_short("%^BOLD%^%^WHITE%^A platform%^RESET%^");
    set_long("%^CYAN%^The staircase lands at a small square platform. "
"Straight ahead is another %^ORANGE%^oak %^CYAN%^door. Left of the door is a "
"%^BOLD%^%^WHITE%^glass %^CYAN%^window %^RESET%^%^CYAN%^and on the right is a "
"small alcove.%^RESET%^");
    set_items(([
      "window" : "%^GREEN%^The great deep forest can be seen through the "
"window.%^RESET%^",
      "alcove" : "%^RESET%^This small alcove has been set into the brick "
"wall. An ordinary lamp has been placed in the alcove, providing the room "
"with light.%^RESET%^",          
    ]));
    set_exits(([
      "bedroom" : ROOMS"bed1",
      "stairs" : ROOMS"foyer",
    ]));
    set_door("bedroom door",ROOMS"bed1","bedroom","drille key");
    set_door_description("bedroom door","%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_locked("bedroom door",1);
}
