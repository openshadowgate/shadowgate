#include <std.h>

inherit "/std/monster.c";

int last_hp = 0;

void create()
{
    ::create();
    set_name("dummy");
    set_id(({ "dummy", "test dummy", }));
    set_race("test dummy");
    set_body_type("human");
    set_short("ooc test dummy");
    set_long("Come at me, bro!");
    set_hd(1, 1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(10000000);
    last_hp = query_hp();
}

int do_typed_damage_effects(victim, limb, damage, damage_type)
{
    tell_room(ETO, "%^MAGENTA%^Dummy says%^RESET%^: I got hit to " + limb + " for " + damage + " " + damage_type + " damage!");
    return damage;
}

pre_round()
{
    ::pre_round();

    if (last_hp == query_hp()) {
        return;
    }

    tell_room(ETO, "\n %^BOLD%^%^RED%^--=< %^ORANGE%^DING! New round%^RED%^ >=--\n");

    tell_room(ETO, "%^MAGENTA%^Dummy says%^RESET%^: Your DPR is " + (last_hp - query_hp()));
    last_hp = query_hp();
}
