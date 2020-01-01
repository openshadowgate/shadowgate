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
    set_spell_name("domination");
    set_spell_level(([ "mage" : 5, "psion" : 8 ]));
    set_discipline("telepath");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS domination on TARGET");
    set_description("By casting domination successfully, you will gain control over a chosen target. You can order the victim to do whatever is within his/her capability. For example, if the caster uses <cast domination on targetname>, targetname is the victim of the spell. Next, the mage can use <make targetname do kill kobold> or <make targetname emote kisses your feet>. The spell can be ended with <free targetname>.

%^BOLD%^%^RED%^N.B.%^RESET%^ If used on players this spell provide you only with limited subset of allowed commands.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}


string query_cast_string() {
    return caster->QCN+" glides "+
    caster->QP+" hand from side to side while "+
    "chanting hypnotically.";
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
 
    if(do_save(target))
    {
//        tell_object(caster,"Your attempt to overcome the willpower of"+target->QCN+" has failed!");
//        tell_object(target,""+caster->QCN+" tries to control your mind!\nYou manage to fight "+caster->QO+" off!");
//        tell_room(place,"Both "+caster->QCN+" and "+target->QCN+" seem to both have nasty headaches.\n"+caster->QCN+" stumbles back a bit as"+target->QCN+" recovers.",({caster, target}) );
        tell_room(environment(target),"Outraged at "+caster->QCN+" for"+caster->QP+" attempt at mind control, "+target->QCN+" attacks"+caster->QO+"!", ({target, caster}) );
        tell_object(target,"Outraged at "+caster->QCN+" for "+caster->QP+"attempt at mind control, you attack "+caster->QO+"!");
        tell_object(caster,""+target->QCN+" attacks you, outraged at you for your attempt at mind control!" );
        spell_kill(target, caster);
        if (wizardp(target) || present("clothesx999",target) || (string)target->query_property("no dominate",1) || !present(caster, environment(target)))
           if(objectp(TO)) TO->remove();
        if(objectp(TO)) TO->remove();
        return;
    }
 
    if(mind_immunity_check(target, "default"))
    {
        tell_room(environment(target),"%^RED%^Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, "+target->QCN+" attacks "+caster->QO+"!", ({target, caster}) );
        tell_object(target,"%^RED%^Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, you attack "+caster->QO+"!");
        tell_object(caster,"%^RED%^"+target->QCN+" attacks you, outraged at you for your attempt at mind control!" );
        spell_kill(target, caster);
        damage_targ(target, target->return_target_limb(), sdamage,"mental");
        spell_successful();
        dest_effect();
        return;
    }




    duration=60+clevel*60;
    duration=duration>300?300:duration;

    tell_object(caster,"%^GREEN%^You break into "+target->QCN+"'s mind and "
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
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+" blinks a couple times, then looks around.", target );
        tell_object(target,"%^YELLOW%^You blink a couple times, then look around.");
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
