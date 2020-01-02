//      Domination
#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int duration, change, quitting;
object clothes, remote;

void create() {
    ::create();
    set_spell_name("control undead");
    set_spell_level(([ "mage" : 7,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS control undead on TARGET");
    set_description("By invoking this spell a necromancer confirms its domain over the undead and takes control of the unliving. Then they can use the next commands to force undead to serve:

%^ORANGE%^<make %^ORANGE%^%^ULINE%^TARGET%^RESET%^ to %^ORANGE%^%^ULINE%^ACTION%^RESET%^>%^RESET%^
  Will force the %^ORANGE%^%^ULINE%^TARGET%^RESET%^ to perform an %^ORANGE%^%^ULINE%^ACTION%^RESET%^.
%^ORANGE%^<free %^ORANGE%^%^ULINE%^TARGET%^RESET%^>%^RESET%^
  Will free the %^ORANGE%^%^ULINE%^TARGET%^RESET%^ from your control.

If the will save succeded or the target is not undead they will be outraged at your attempt and will attack immediately.

%^BOLD%^%^RED%^N.B.%^RESET%^ If used on players this spell provide you only with limited subset of allowed commands.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}


string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" glides "+caster->QP+" hand from side to side while "+ "chanting hypnotically.";
}

void spell_effect(int prof) {

    change = -2;

    if (!interactive(caster) || caster==target) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (!objectp(target)) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        if(objectp(TO)) TO->remove();
        return;
    }
    if (!caster->ok_to_kill(target)) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if(do_save(target,-2)||
       !target->is_undead())
    {
        tell_room(environment(target),"Outraged at "+caster->QCN+" for"+caster->QP+" attempt at mind control, "+target->QCN+" attacks"+caster->QO+"!", ({target, caster}) );
        tell_object(target,"Outraged at "+caster->QCN+" for "+caster->QP+"attempt at mind control, you attack "+caster->QO+"!");
        tell_object(caster,""+target->QCN+" attacks you, outraged at you for your attempt at mind control!" );
        spell_kill(target, caster);
        if (wizardp(target) ||
            present("clothesx999",target) ||
            target->query_property("no dominate",1) ||
            !present(caster, environment(target)))
            if(objectp(TO))
                TO->remove();
        if(objectp(TO))
            TO->remove();
        return;
    }

    duration=60+clevel*60;
    duration=duration>360?360:duration;

    tell_object(caster,"%^BLUE%^%^BOLD%^You break into "+target->QCN+"'s mind and "
        "overcome "+target->QP+" willpower!");
    spell_successful();
    addSpellToCaster();
    change=0;
    clothes=new("/d/magic/obj/sclothes.c");
    clothes->set_property("spelled", ({TO}) );
    clothes->set_master(caster);
    clothes->set_spell(TO);
    clothes->move_is_ok(1);
    clothes->move(target);
    clothes->move_is_ok(0);
    remote=new("/d/magic/obj/remote.c");
    remote->set_property("spelled", ({TO}) );
    remote->set_caster(caster);
    remote->set_target(target);
    remote->set_spell(TO);
    remote->move_is_ok(1);
    remote->move(caster);
    remote->move_is_ok(0);
    call_out("dest_effect", duration);
}

void dest_effect() {
    if (find_call_out("check") != -1)
        remove_call_out("check");
    if (!clothes)
        if(objectp(TO)) TO->remove();
    if (clothes) {
        clothes->move_is_ok(1);
        clothes->move(ROOM_VOID);
        clothes->remove();
    }
    if (remote) {
        remote->move_is_ok(1);
        remote->move(ROOM_VOID);
        remote->remove();
    }
    if (target) {
        tell_room(environment(target),"%^BLUE%^"+target->QCN+" blinks a couple times, then looks around.", target );
        tell_object(target,"%^BLUE%^You blink a couple times, then look around.");
        if (quitting)
            target->force_me("quit");
    }
    if (!caster)
        destruct(TO);
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void set_quitting() {
    quitting=1;
}
