#include <std.h>
inherit WEAPONLESS;

#define MYTYPES ({"sword","chain whip","dagger","claw","axe"})

void create() {
    string mytype;
    int i;
    ::create();
    set_name("weapon");
    set_id(({"weapon","bladed weapon","monster","summoned monster"}));
    i = random(sizeof(MYTYPES));
    mytype = MYTYPES[i];

    set_gender("neuter");
    set_short("bladed weapon");
    set_long(
        "This is a razor-sharp "+mytype+". Somehow it seems alive, dancing around in the air as if possessed. It looks quite dangerous.");
    set_race("weapon");
    set_body_type("snake");
    set_size(1);
    remove_limb("mouth");
    remove_limb("head");
    remove_limb("tail");
    add_limb("blade","torso",0,0,0);
    set_attack_limbs(({"blade"}));
    set_base_damage_type("slashing");
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",14);
    set_stats("charisma",8);
    set_stats("dexterity",18);
    set_stats("constitution",7);
}