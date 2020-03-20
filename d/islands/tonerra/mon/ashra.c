#include <std.h>
#include <daemons.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

int coreparty;

void create()
{
    object ob;
    ::create();

    set_name("Avatar of Ashra");
    set_id(({ "ashra", "avatar", "god", "shadow god" }));
    set_short("%^BOLD%^%^BLACK%^A%^RESET%^%^MAGENTA%^v%^BOLD%^a%^WHITE%^t%^BLACK%^ar of A%^RESET%^%^MAGENTA%^s%^BOLD%^h%^WHITE%^r%^BLACK%^a%^RESET%^");
    set_long("This is a god's chosen form. Standing before you is a female figure
clothed in billowing shadows that seem to hungrily consume the light around
them. Her face is covered with a brilliant procelin mask which has been cracked
down the middle. Black tears run from her eyes, but her mouth bears a sinister
smile. Tendrils of blackness consume everything around her.");
    set_body_type("human");
    add_limb("tail", "", 0, 0, 0);
    set_gender("female");
    set_race("god");
    set_hd(60, 9);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_mlevel("fighter", 70);
    set_mlevel("mage", 70);
    set_mlevel("cleric", 70);
    set_guild_level("cleric", 70);
    set_guild_level("mage", 70);
    set_attack_limbs(({ "right claw", "left claw", "mouth" }));
    set_base_damage_type("slashing");
    set_damage(16, 6);
    set_hit_funcs((["mouth" : (: TO, "mouth" :)]));
    set_attacks_num(5);
    set_property("no death", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
    set_overall_ac(-75);
    set_max_hp(60000);
    set_hp(query_max_hp());
    set_property("add kits", 40);
    set_new_exp(50, "boss");
    set_max_level(45);
    set_emotes(30, ({ "Ashra whispers : YOU WILL LIVE IN ENDLESS NIGHTMARE...." }), 20);
    set_func_chance(40);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "perfect caster",
        "blind fight",
        "spell reflection",
    }));
    set_spells(({ "polar midnight",
                  "shadow nova",
                  "unholy orb",
                  "blasphemy",
                  "nightmare maw",
                  "shadow vortex",
                  "entropic storm",
                  "forgotten melody",
                  "visions from within",
                  "unholy aura",
                  "mass harm" }));
    set_spell_chance(85);
    add_money("platinum", random(100000));
    set_property("no paralyze", 1);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("divine essence");
    ob->move(TO);
    set_resistance_percent("divine", 100);
    coreparty = 0;
}

int mouth(object targ)
{
    return 10;
}

void set_paralyzed(int time, string message)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "The Avatar of Ashra seems unaffected by paralysis!");
    return;
}

void init()
{
    int psize;
    ::init();
    if (wizardp(TP) || TP->query_true_invis()) {
        return;
    }

    if (!interactive(TP) && !TP->query_ibrandul() && !TP->is_merc()) {
        TP->set_hp(-1);
    }
    psize = sizeof(filter_array(all_inventory(ETO), (: userp($1) :)));
    psize = psize < 1 ? 1 : psize;
    if (psize > coreparty) {
        set_max_hp(25000 * psize);
        set_hp(query_max_hp());
        set_damage(16, 5 + psize);
        coreparty = psize;
    }
}

die(object ob)
{
    message("shout", "Ashra shouts: %^BOLD%^BLACK%^THE DARKNESS.....IS ETERNAL....%^RESET%^", users());
    tell_room(ETO, "%^BLACK%^BOLD%^The tendrils of shadow seem to collapse in on themselves as they are pulled back through the portal. "
"The darkness coalesces into a swirling miasma as it drains back into the Shadow Plane.%^RESET%^");

    return ::die();
}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }
    if (query_attackers() == ({}) && coreparty) {
        coreparty = 0;
    }
    ::heart_beat();
}
