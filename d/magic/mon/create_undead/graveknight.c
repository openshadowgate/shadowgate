#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;
int build;

void create()
{
    string mon_desc, * mon_feats, * mon_attack;

    ::create();

    build = roll_dice(1, 3);
    {
        object stuff;

        switch (build) {
        case 1:
            stuff = new("/d/common/obj/armour/shield");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            command("wear shield");
            stuff = new("/d/common/obj/weapon/longsword");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            stuff = new("/d/common/obj/armour/chain");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            command("wear chain");
            mon_feats = ({ "counter", "reflection", "deflection", "shieldbash", });
            mon_desc = "sword and a shield";
            mon_attack = ({ "bashit", });
            break;
        case 2:
            stuff = new("/d/common/obj/weapon/longsword");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            stuff = new("/d/common/obj/weapon/shortsword");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon_2 = stuff;
            command("wield sword");
            stuff = new("/d/common/obj/armour/hide");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            command("wear hide");
            mon_feats = ({ "two weapon fighting", "ambidexterity", "improved two weapon fighting", "whirl", });
            mon_desc = "pair of swords";
            mon_attack = ({ "whirlit", });
            break;
        default:
            set_monster_feats(({ "titan grip", }));
            stuff = new("/d/common/obj/weapon/giant_bastard");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            stuff = new("/d/common/obj/armour/chain");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            command("wear chain");
            mon_feats = ({ "strength of arm", "weapon specialization", "sweepingblow", "titan grip", });
            mon_desc = "giant sword";
            mon_attack = ({ "sweepit", });
            break;
        }
    }

    set_name("graveknight");
    set_id(({ "skeleton", "graveknight", "undead" }));
    set_short("%^BOLD%^%^BLACK%^g%^RED%^r%^BLACK%^a%^RED%^v%^BLACK%^e%^RED%^k%^BLACK%^n%^RED%^i%^BLACK%^g%^RED%^h%^BLACK%^t%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you stands an undead creature, a humanoid skeleton holding a " + mon_desc + " in its skeletal hands. Its bones float in fell aura forming resemblance of a kith being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");

    set_class("fighter");
    set_guild_level("fighter", 6);
    set_level(8);
    set_hd(8, 8);
    add_search_path("/cmds/fighter");

    set_monster_feats(mon_feats + ({ "mounted combat", "ride-by attack", "parry", }));
    set_funcs(mon_attack);
    set_func_chance(5);
    set_fighter_style("soldier");
    command("message in marches in.");
    command("message out marches $D.");
}

void whirlit(object targ) {
    if (!objectp(targ)) return;
    if (!objectp(TO)) return;
    TO->force_me("whirl");
}

void bashit(object targ) {
    if (!objectp(targ)) return;
    if (!objectp(TO)) return;
    TO->force_me("shieldbash " + targ->query_name());
}

void sweepit(object targ) {
    if (!objectp(targ)) return;
    if (!objectp(TO)) return;
    TO->force_me("sweepingblow");
}