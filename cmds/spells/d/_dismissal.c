#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("dismissal");
    set_spell_level(([ "mage" : 5, "cleric" : 4, "inquisitor" : 4, ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS dismissal");
    set_damage_desc("destroys spelled creatures");
    set_description("This spell forces summoned creatures that attack you to be dismissed.");
}

void spell_effect(int prof){
    object *attackers, theirspell;
    int i;
    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    tell_room(place,"%^BLUE%^"+caster->QCN+" releases waves of arcane energies.%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^%^CYAN%^Waves fail to touch anything.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(attackers[i]->is_undead())
            continue;
        theirspell = attackers[i]->query_property("spell_creature");
        if(!objectp(theirspell))
            continue;
        if(theirspell->query_clevel() - clevel - 6 + roll_dice(1,12) < 0)
            continue;
        tell_room(place,"%^CYAN%^"+attackers[i]+" disappears in a flash.");
        attackers[i]->move("/d/shadowgate/void");
        attackers[i]->remove();
    }
    spell_successful();
    dest_effect();
}
