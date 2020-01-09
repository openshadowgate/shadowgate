// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("irresistible dance");
    set_spell_level(([ "bard" : 6, "mage" : 8, "oracle":8 ]));
    set_mystery("whimsy");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS irresistible dance on TARGET");
    set_damage_desc("-clevel/8 to reflex save")
    set_description("The subject feels an undeniable urge to dance and begins doing so, complete with foot shuffling and tapping. The spell effect makes it hard for the subject to do anything other than caper and prance in place.");
    set_verbal_comp();
    set_somatic_comp();
    mental_spell(1);
    set_target_required(1);
}

string query_cast_string() {
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+"'s fingers as "+
	caster->QS+" intones a spell.%^RESET%^";
}

void spell_effect(int prof) {
    int duration;
    if(target->query_property("irresistible_dance"))
    {
        tell_object(caster,"%^ORANGE%^Your spell slips away from "+target->QCN+", as they are already dancing!%^RESET%^");
        TO->remove();
        return;
    }
    bonus = clevel/8;
    bonus = bonus<1?1:bonus;
    bonus = bonus>8?8:bonus;
    tell_object(target,"%^ORANGE%^You begin dancing, which significantly distracts you from moving as desired!%^RESET%^");
    tell_room(place,"%^ORANGE%^"+target->QCN+" begins uncontrollably dancing!%^RESET%^",target);
    target->add_ac_bonus(-bonus);
    target->add_saving_bonus("reflex",-bonus);
    target->set_property("irresistible_dance",1);
    addSpellToCaster();
    call_out("dancing_echo",ROUND_LENGTH*2);
    duration = (ROUND_LENGTH * 2) * clevel;
    call_out("dest_effect",duration);
    spell_successful();
}

void dancing_echo()
{
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    tell_room(environment(target),"%^ORANGE%^"+target->QCN+" performs a silly dance!%^RESET%^");
    call_out("dancing_echo",ROUND_LENGTH*roll_dice(1,4));
}

void dest_effect() {
    remove_call_out("dancing_echo");
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^Finally! You no longer feel compelled to dance.%^RESET%^");
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+"'s silly dancing comes to an end.%^RESET%^",target);
        target->add_ac_bonus(bonus);
        target->add_saving_bonus("reflex",bonus);
        target->remove_property("irresistible_dance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
