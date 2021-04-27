#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A balcony");
    set_short("%^BOLD%^%^CYAN%^A balcony%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This is fair sized %^WHITE%^balcony%^BLUE%^ "
"overlooking the surrounding %^GREEN%^landscape%^BLUE%^. Like the walls of "
"the house, the balcony is also made of white bricks. A small roof gives some "
"shelter from the rain and the floor is covered by a %^RESET%^%^ORANGE%^"
"bamboo %^BOLD%^%^BLUE%^mat.%^RESET%^");
    set_smell("default","%^BOLD%^%^CYAN%^The air smells fresh and clean.%^RESET%^");
    set_listen("default","%^BOLD%^%^GREEN%^The gentle breeze brings with it "
"the sounds of the forest.%^RESET%^");
    set_items(([
      "landscape" : "%^GREEN%^The vast Tharis forest spreads out in all "
"directions. Great trees of venerable age give shelter to the flourishing "
"fauna of forest wild life. To the west, some sort of a clearing or grove can "
"be seen, dominated by an awe inspiring %^ORANGE%^oak %^GREEN%^of unnatural "
"proportions.",
      "mat" : "%^ORANGE%^The mat consists of a large number of bamboo pipes "
"bound together by strings of hemp.",          
    ]));
    set_exits(([
      "bedroom" : ROOMS"bed1",
    ]));
    set_door("balcony door",ROOMS"bed1","bedroom",0);
    set_door_description("balcony door", "%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");
}
