#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

void create(){

    ::create();
    set_name("vampire");
    set_id(({"vampire knight","vampire","undead","Vampire knight", "knight"}));
    set_short("%^RESET%^%^RED%^Vampire %^BOLD%^%^BLACK%^knight%^RESET%^");
    set_long("%^RED%^Before you floats a powerful humanoid figure encased into heavy armour, wielding a huge two-handed sword. It's skin is gray, ears are bat like and eyes glow with undead red hatred towards all living. Despite being in heavy armor it floats above the ground with ease and moves with supernatural agility.");
    set_race("human");
    set_class("fighter");

    set_guild_level("fighter",6);
    set_guild_level("mage",6);
    set_level(8);
    set_hd(8,8);

   set_property("vampire", 1);
   set_property("fast healing", 5);

   set_property("spell damage resistance", 5);
   set_property("silver resistance", 5);
   set_property("electricity resistance", 5);

    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",10);
    set_stats("intelligence",18);
    set_stats("wisdom",18);
    set_stats("charisma",22);

    set_property("cast and attack",1);
    set_spells(({"cause blindness",
                    "dispel magic",
                    "orders oath",
                    "vapiric touch",
                    "call lightning"}));
    set_spell_chance(15);

    set_alignment(3);

    {
        object stuff;

        stuff = new("/d/common/obj/weapon/bastard_two");
        stuff->set_property("monsterweapon", 1);
        stuff->set_short("%^BOLD%^%^RED%^Two handed sword.");
        stuff->move(TO);
        weapon = stuff;
        command("wield sword");
        stuff = new("/d/common/obj/armour/plate");
        stuff->set_property("monsterweapon", 1);
        stuff->set_short("%^BOLD%^%^BLACK%^Black plate.");
        stuff->move(TO);
        command("wear plate");
        stuff = new("/d/common/obj/armour/greaves");
        stuff->set_property("monsterweapon", 1);
        stuff->set_short("%^BOLD%^%^BLACK%^Black greaves.");
        stuff->move(TO);
        command("wear greaves");
    }

    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "strength of arm",
                    "blade block",
                    "light weapon",
                    "sweepingblow",
                    "weapon focus",
                    }));

    set_fighter_style("soldier");

    set_property("flying", 1);
    command("message in floats in.");
    command("message out floats $D.");
}

heart_beat()
{
    ::heart_beat();

    if (!sizeof(query_attackers()) && query_hp() < query_max_hp() * 4 / 5) {
        add_hp(roll_dice(1, 12));
    }
}

void die(object obj)
{
    tell_room(ETO, "%^BOLD%^%^RED%^Vampire knight turns into dust.");
    TO->remove();
    return;
}
