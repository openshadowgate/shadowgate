#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A kitchen");
    set_short("%^RED%^A kitchen%^RESET%^");
    set_long("%^RESET%^This is a very neatly kept kitchen. A large %^BOLD%^"
"%^BLACK%^stove %^RESET%^is the most central element of the room. Beside it "
"stands a strong wooden %^ORANGE%^board %^RESET%^for chopping %^GREEN%^"
"vegetables%^RESET%^, pieces of %^RED%^meat %^RESET%^and other cooking "
"related chores. A large %^ORANGE%^cupboard %^RESET%^is set against one of "
"the white brick walls, presumably holding various dishes and pots.%^RESET%^");
    set_smell("default","%^RED%^The delicious smell of good food dominates the kitchen.");
    set_listen("default","%^ORANGE%^Tiny squeaks can be heard from behind the stove.");
    set_exits(([
      "livingroom" : ROOMS"living",
      "pinkroom" : ROOMS"bed2",
      "forge" : ROOMS"forge",
    ]));
    set_door("kitchen door",ROOMS"living","livingroom",0);
    set_door_description("kitchen door", "%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_door("pink door",ROOMS"bed2","pinkroom",0);
    set_door_description("pink door", "%^BOLD%^%^MAGENTA%^This is a standard "
"oak door, made of heavy oaken planks bound together with iron rivets. What "
"sets it apart from other doors is the fact its painted pink.%^RESET%^");
    set_door("forge door",ROOMS"forge","forge","drille key");
    set_door_description("forge door", "%^ORANGE%^This is an oak door "
"enforced with steel plates. It is made of heavy oaken planks bound together "
"with iron rivets.%^RESET%^");
    set_locked("forge door",1);
}
