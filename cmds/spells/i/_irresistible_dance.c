// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("irresistible dance");
    set_spell_level(([ "bard" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS irresistible dance on TARGET");
    set_description("");
    set_verbal_comp();
    set_somatic_comp();
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
    tell_object(target,"%^BLUE%^A mirroring aura starts to grow around you, seeping into your skin to taint it a %^RESET%^"
"sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.  An overwhelming feeling of weakness comes over you.%^RESET%^");
    tell_room(place,"%^BLUE%^A mirroring aura starts to grow around "+target->QCN+", seeping into "+target->QP+" skin to taint it a %^RESET%^sic%^GREEN%^k%^RESET%^ly %^BLUE%^pallid hue.%^RESET%^",target);
    target->add_ac_bonus(-bonus);
    target->add_saving_bonus("reflex",-bonus);    
    target->set_property("irresistible_dance",1);
    call_out("dest_effect",duration);
    duration = (ROUND_LENGTH * 2) * clevel;    
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^CYAN%^The feeling of weakness finally lifts, and with it fades the sickly color of your "
"skin.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^The sickly color of "+target->QCN+"'s skin fades back into a more healthy "
"shade.%^RESET%^",target);
        target->add_ac_bonus(bonus);        
        target->add_saving_bonus("reflex",bonus);
        target->remove_property("irresistible_dance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
