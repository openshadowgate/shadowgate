#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

void create() {
    ::create();
    set_spell_name("true strike");
    set_spell_level(([ "mage" : 1, "inquisitor" : 1, "cleric":1]));
    set_spell_sphere("divination");
    set_domains("destruction");
    set_syntax("cast CLASS true strike on TARGET");
    set_damage_desc("clevel to attack bonus for clevel/12+1 rounds");
    set_description("Gaining insight on future events, caster can grant anyone knowledge of how to exploit it to make a strikes unlikely to miss for the next few rounds

%^BOLD%^See also:%^RESET%^ true strikes *feats");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

void spell_effect(int prof) {
    if (!objectp(caster)) return;
    if(!objectp(target))
    {
        tell_object(caster,"You don't see that target here!");
        return;
    }
    if(target != caster){
        tell_object(caster,"%^BOLD%^%^CYAN%^You touch "+target->QCN+", granting "+target->QO+" a temporary insights into events unfold.");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches you, granting a temporary insights into events unfold.");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+target->QCN+", they both seem lethargic for a moment.");
    }
    target->set_property("attack bonus",clevel);
    addSpellToCaster();
    call_out("dest_effect",ROUND_LENGTH*(clevel/12+1),lower);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^CYAN%^An insight into future events fades%^RESET%^");
        target->set_property("attack bonus",-clevel);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
