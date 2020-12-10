#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;
int build;

void create(){
    
    string mon_desc, * mon_feats;

    ::create();

    build = roll_dice(1, 3);

    {
        object stuff;

        set_property("silent_equip", 1);
        switch (build) {
        case 1:
            stuff = new("/d/common/obj/armour/mshield");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            command("wear shield");
            stuff = new("/d/common/obj/weapon/longsword");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            mon_feats = ({ "counter", "reflection", });
            mon_desc = "sword and a shield";
            break;
        case 2:
            stuff = new("/d/common/obj/weapon/shortsword");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            stuff = new("/d/common/obj/weapon/dagger");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon_2 = stuff;
            command("wield dagger");
            mon_feats = ({ "two weapon fighting", "unassailable parry", });
            mon_desc = "sword and a dagger";
            break;
        default:
            stuff = new("/d/common/obj/weapon/bastard_two");
            stuff->set_property("monsterweapon", 1);
            stuff->move(TO);
            weapon = stuff;
            command("wield sword");
            mon_feats = ({ "strength of arm", "weapon specialization", });
            mon_desc = "big sword";
            break;
        }
    }

    set_name("skeletal champion");
    set_id(({"skeleton","skeletal champion","champion","undead"}));
    set_short("%^BOLD%^%^BLACK%^s%^WHITE%^k%^BLACK%^e%^WHITE%^l%^BLACK%^e%^WHITE%^t%^BLACK%^a%^WHITE%^l %^BLACK%^c%^WHITE%^h%^BLACK%^a%^WHITE%^m%^BLACK%^p%^WHITE%^i%^BLACK%^o%^WHITE%^n%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you stands an undead creature, a humanoid skeleton holding a " + mon_desc + " in its skeletal hands. Its bones float in fell aura forming resemblance of a kith being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");
    
    set_class("fighter");
    set_guild_level("fighter", 6);
    set_level(8);
    set_hd(8, 8);
    add_search_path("/cmds/fighter");

    set_monster_feats(mon_feats);

    set_fighter_style("soldier");
    command("message in marches in.");
    command("message out marches $D.");
}
