#include <spell.h>

inherit SPELL;

create() {
    ::create();
    set_spell_name("modify memory");
    set_spell_level(([ "assassin" : 4, "bard": 4, "psion" : 4 ]));
    set_spell_sphere("enchantment_charm");
    set_discipline("telepath");    
    set_syntax("cast CLASS modify memory on TARGET");
    set_description("This spell alters victim's memory so they won't remember who you are. Should their will falter they will forget your name and will be momentarily dazed.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_silent_casting(1);
    set_save("will");    
}

string query_cast_string()
{
    tell_room("%^RESET%^%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ looks at "+target->QCN+"%^RESET%^%^BLUE%^ intently.");
    return "display";
}

void spell_effect(int prof)
{
    if(!present(target,place)){
        tell_object(caster,"Your target has left.");
        dest_effect();
        return;
    }

    if(!do_save(target,-4)){
        spell_successful();
        tell_object(caster,"%^BLUE%^You sense your memory attempt succeeded, and your victim is momentarily dazed.%^RESET%^");
        target->set_paralyzed(random(3),"%^RESET%^%^BLUE%^You feel oblivious and momentarily distracted.%^RESET%^");
        target->remove_relationship(caster->query_name());
    }
    tell_object(caster,"%^BLUE%^You sense your memory altering attemp failed.%^RESET%^");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

