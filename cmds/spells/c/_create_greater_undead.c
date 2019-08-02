#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/c/_create_undead";

string* list_undead()
{
    return ({"shadow","wraith","spectre"});
}

void create()
{
    ::create();
    set_spell_name("create greater undead");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create greater undead [on shadow|wraith|spectre]");
    set_description("Next step in the art of necromancy is to use the very soul of the fallen to create a new form of undead. The being created walks in between the worlds and is truly terrifying as it can not be destroyed without arcane. The necromancer seen performing this ritual in civilized societies will certainly be noted.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check your undead pool size use %^ORANGE%^<poolsize>%^RESET%^");
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

