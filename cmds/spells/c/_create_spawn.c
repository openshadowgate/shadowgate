#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/c/_create_undead";

void create()
{
    ::create();
    set_spell_name("create spawn");
    set_spell_level(([ "innate" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create spawn");
    set_description("With this spell a vampire can use the recently deceased to raise a powerful undead vampire spawn to aid them in combat. This power behaves the same way similar spells of creating undead does, but it is unique to vampires.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check how many undead you have rised use %^ORANGE%^<poolsize>%^RESET%^");
    evil_spell(1);
    set_helpful_spell(1);
    set_arg_needed();
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^A vampire knight forms itself out of the mist.%^RESET%^";
}

string undead_to_raise()
{
    if (caster->is_class("vampire_lord")) {
        return "vampire_knight";
    }

    return "vampire_spawn";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("fighter", clevel);
    undead->set_mlevel("fighter", clevel);
    undead->set_skill("perception", clevel);
    undead->set_level(clevel);
    undead->set_hd(clevel, 8);
    undead->set_max_hp(clevel * 12);
    undead->set_attacks_num(clevel / 5 + 1);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(6 - clevel);
}
