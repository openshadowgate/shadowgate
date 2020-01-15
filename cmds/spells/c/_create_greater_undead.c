#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/c/_create_undead";

void create()
{
    ::create();
    set_spell_name("create greater undead");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create greater undead");
    evil_spell(1);
    set_components(([
      "mage" : ([ "drop of blood" : 1, ]),
    ]));
    set_helpful_spell(1);
    set_arg_needed();
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^You cut your %^BOLD%^%^CYAN%^wrists and %^CYAN%^s%^BLACK%^i%^CYAN%^n%^CYAN%^g%^CYAN%^ low in %^CYAN%^f%^BLACK%^ell%^CYAN%^ tongues.%^RESET%^");
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" cuts "+caster->QP+"%^BOLD%^%^CYAN%^wrists and %^CYAN%^s%^BLACK%^i%^CYAN%^n%^CYAN%^g%^BLACK%^s%^CYAN%^ low in %^CYAN%^f%^BLACK%^ell%^CYAN%^ tongues.%^RESET%^";
}

string undead_to_raise()
{
    return "skelemage";
}

void setup_undead_scaling(object undead)
{
    undead->set_level(clevel * 4 / 3);
    undead->set_guild_level("mage",clevel*4/5);
    undead->set_mlevel("mage",clevel*4/5);
    undead->set_skill("spellcraft",clevel);
    undead->set_skill("perception",clevel - 10);
    undead->set_property("spell penetration", clevel);
    undead->set_hd(clevel,8);
    undead->set_max_hp(clevel*12+100);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(10-clevel);
}
