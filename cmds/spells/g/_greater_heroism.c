// midlevel enchantment school specialty spell. Nienne, 08/09.
#include <priest.h>
#include <skills.h>
#include <magic.h>
inherit "/cmds/spells/h/_heroism";

void create() {
    ::create();
    set_spell_name("greater heroism");
    set_spell_level(([ "mage" : 6, "bard" : 5 ]));
    set_syntax("cast CLASS greater heroism [on TARGET]");
    set_damage_desc("+4 to attack and damage bonus, saving throws, skills");
    set_description("This spell allows the caster to draw upon their personal presence and charm, granting them or an ally a bonus to morale on attacks, saves and core skills. It does not stack with other morale-boosting spells, such as good hope.");

}

int query_heroism_bonus()
{
    return 4;
}
