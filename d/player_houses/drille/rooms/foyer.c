#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("An antechamber");
    set_short("%^BOLD%^%^BLUE%^An antechamber%^RESET%^");
    set_long("%^BOLD%^This is the antechamber of the house. The shining white "
"brick walls give a bright feeling to the room. The colour creates a stunning "
"contrast against the floor and the ceiling, which are laden with dark "
"%^RESET%^%^ORANGE%^wooden %^BOLD%^%^WHITE%^panelling. A deep blue "
"%^RESET%^%^BLUE%^rug %^BOLD%^%^WHITE%^runs from the entry up to an "
"%^RESET%^%^ORANGE%^oak door%^BOLD%^%^WHITE%^. To the left of the door, a "
"%^BLACK%^stone staircase %^WHITE%^twists upwards.%^RESET%^");
    set_smell("default","The varnished panels give off a faint smell.");
    set_listen("default","%^BLUE%^The sound of your steps is muffled by the rug.");
    set_items(([
      "rug" : "%^BLUE%^This is a rather thin and rough rug perfectly suitable "
"for a doormat. The hard material cleans that dirt right off your boots.",
    ]));
    set_exits(([
      "livingroom" : ROOMS"living",
      "out" : ROOMS"yard",
      "stairs" : ROOMS"platform",
    ]));
    set_door("oak door",ROOMS"living","livingroom",0);
    set_door_description("oak door","%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_door("front door",ROOMS"yard","out",0);
    set_door_description("front door","%^ORANGE%^This is a standard oak door, "
"made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_locked("front door",1);
}
