#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("recall death");
    set_spell_level(([ "psion" : 8 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS recall death on TARGET");
    set_description("This spell parts the fabric of time, revealing wounds your foe has received in the past (or is yet to "
"receive) that are potentially fatal. That target takes considerable damage as the past (or future) impinges briefly on the "
"present.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^You reach out and splay your fingers, extending your mental reach.");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" reaches forward and splays "+caster->QP+" fingers.",caster);
    return "display";
}

void spell_effect(int prof) {
    int check, damage;

    if(!present(target,place)) {
        tell_object(caster,""+target->QCN+" has left the area!");
        dest_effect();
        return;
    }
    tell_object(caster,"%^RED%^Your will parts the very fabric of time itself, weaving agony around "+target->QCN+" from a different time and place!");
    tell_object(target,"%^RED%^The air seems to blur around you, and sudden agony wracks your body!");
    tell_room(place,"%^RED%^The air seems to blur around "+target->QCN+", and "+target->QS+" is wracked by sudden agony!",({caster,target}));

// NO immunity from unyielding soul; this is not a mind effecting spell!
// Left off the save for half damage as they have no better direct dmg spell. N, 6/11.
    damage = roll_dice(clevel,8);
    damage_targ(target,target->return_target_limb(),damage,"mental");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}