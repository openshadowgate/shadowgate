//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Dark Pit");
    set_long(
        "%^BOLD%^%^BLACK%^" +
        "You find yourself at the bottom of a dark deep pit.  The floor of the pit does not " +
        "sound and feel like there is solid earth below it.  Upon closer examination you see " +
        "that the floor actually contains a trapdoor.  It appears the only way out is through " +
        "the trapdoor or to climb back up the way you came.  \n" +
        "%^RESET%^"
        );
    set_property("indoors", 0);
    set_property("light", 1);
    set_smell("default", "You can smell old dirt.");
    set_listen("default", "You hear nothing, but the occassional sound of life up above " +
               "the pit.");

    set_door("trapdoor", MROOMS + "meltout", "down", "mithril key");
    set_locked("trapdoor", 1, "lock");
    (MROOMS + "meltout")->set_locked("trapdoor", 1, "lock");
    lock_difficulty("trapdoor",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    set_door_description("trapdoor", "The trapdoor is a door that is set into the floor.");
    set_string("trapdoor", "open", "You lift the trapdoor and see into a tunnel below you.\n");

    set_trap_functions(({ "trapdoor" }), ({ "gas_em" }), ({ "pick" }));

    set_exits(([
                   "down" : MROOMS + "meltout"
               ]));
    set_climb_exits((["climb" : ({ MROOMS + "mel0", 20, 6, 100 })]));
    set_fall_desc("%^BOLD%^%^RED%^You fall at least 50 feet and land on the hard floor of " +
                  "a pit!\n Sharp branches and debris poke into your back.  You are winded " +
                  "and pain racks your body!%^RESET%^\n");
}

int gas_em(string str)
{
    int poison;
    if (str != "lock") {
        return 0;
    }
    toggle_trap("trapdoor", "pick", "lock");
    tell_object(TP, "As you work on the lock with your tools you feel a sudden hitch " +
                "and then a louder click.");
    tell_object(TP, "%^BOLD%^%^GREEN%^You hear a hissing as a cloud of sickly green " +
                "gas issues from the lock.");
    TP->force_me("emote gulps");
    tell_room(TO, "%^BOLD%^%^GREEN%^A sickly green mist issues from the lock!");
    if ((int)TP->query_stats("dexterity") > random(25)) {
        tell_object(TP, "%^BOLD%^%^GREEN%^You manage to turn away and the spray misses " +
                    "your face by inches.");
        TP->force_me("emote turns away from the gas and avoids it barely");
        return 0;
    }

    tell_room(TO, "%^BOLD%^%^GREEN%^The mist sprays directly into the face of " + TPQCN + "!", TP);
    tell_object(TP, "%^BOLD%^%^GREEN%^The mist hits you right in the face and " +
                "starts burning into your skin causing immense pain!");
    TP->do_damage("head", roll_dice(10, 10));
    TP->add_attacker(TO);
    TP->continue_attack();
    if ((int)TP->query_stats("constitution") > random(25)) {
        tell_object(TP, "You get a whiff of the deadly vapor, but hopefully not " +
                    "enough to cause you permanent damage.");
        TP->force_me("emote coughs a little as he inhales some of the gas\n");
        return 0;

        poison = roll_dice(30, 10);
        TP->force_me("emote coughs and gags as the gas works its way " +
                     "to " + ETO->query_possessive() + " lungs\n");
        TP->add_poisoning(poison);
        TP->setPoisner(TO);
        return 0;
    }
}
