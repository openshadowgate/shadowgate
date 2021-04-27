#include <std.h>
#include <move.h>
#include "sil.h"

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit VAULT;

void create()
{
    ::create();
    set_name("Cage");
    set_short("cage");
    set_long("%^BOLD%^%^BLACK%^This is the inside of a large, iron cage.  Five inch thick round"
             " bars surround the cage at six inch intervals and are reinforced with cross bars every two"
             " feet.  A single iron door stands in the center of the cage with an intricate looking lock"
             " fastening it in place.  The solid iron floor is swept clean and tidy, but there are no mats"
             " or blankets to sit on.  At least you can see through the bars into the laboratory and see"
             " what goes on in there.%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_smell("default", "%^MAGENTA%^A strange, but sweet odor assaults your senses.%^RESET%^");
    set_listen("default", "The silence of the room is stifling.");
    set_items(([]));
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_door("cagedoor", SIL "dungeon", "out", "ivory key");
    set_locked("cagedoor", 1, "lock");
    lock_difficulty("cagedoor",  "/daemon/player_housing"->get_phouse_lock_dc("rare"), "lock");
    set_lock_description("cagedoor", "lock", "The lock is intricate in design and probably not easily picked.");
    (SIL "dungeon")->set_locked("cagedoor", 1, "lock");
    set_door_description("cagedoor", "%^BOLD%^%^BLACK%^The door is made of the same cold iron as"
                         " the rest of the cage.  Try as you might, you cannot wiggle any of the bars free nor squeeze"
                         " between them.");
    set_string("cagedoor", "open", "%^BOLD%^%^BLACK%^The cage door creaks eerily as it swings open.%^RESET%^\n");
    set_exits(([
                   "out" : SIL "dungeon"
               ]));
}

void reset()
{
    object scry_object;
    ::reset();
    if (!present("DungeonListener")) {
        scry_object = new(OBJ "dungeonlistener");
        scry_object->set_caster("/d/player_houses/silesse/cage.c");
        scry_object->set_target("/d/player_houses/silesse/dungeon.c");
        scry_object->move(TO);
    }
}
