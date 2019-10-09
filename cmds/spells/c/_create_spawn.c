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
    set_description("With this spell a vampire can use recently deceased to raise a powerful undead vampire spawn to aid them in combat. This power behaves the same way similar spells of creating undead do, but is unique to vampires.");
    evil_spell(1);
    set_helpful_spell(1);
    set_arg_needed();
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^A vampire knight forms itself of the mist.%^RESET%^";
}

string undead_to_raise()
{
    return "vampire_knight";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("mage",clevel*5/6);
    undead->set_guild_level("fighter",clevel*5/6);
    undead->set_mlevel("mage",clevel*5/6);
    undead->set_mlevel("fighter",clevel*5/6);
    undead->set_skill("spellcraft",clevel);
    undead->set_skill("perception",clevel);
    undead->set_level(clevel);
    undead->set_hd(clevel,8);
    undead->set_max_hp(clevel*12+100);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(10-clevel);
}
