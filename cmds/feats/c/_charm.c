#include <std.h>
#include <daemons.h>
#include <rooms.h>
inherit FEAT;

int duration, change, quitting;
object clothes, remote;
int running;

void create() {
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_syntax("charm TARGET");
    feat_prereq("Calm, Bard L17");
    feat_desc("Successful use of this feat will cause the targetted opponent to calm down, and become much more amenable to suggestions of the character.

%^BOLD%^N.B.%^RESET%^ If used on players this spell provide you only with limited subset of allowed commands.");
    feat_name("charm");
    set_target_required(1);
    set_save("will");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"calm")) {
      dest_effect();
      return 0;
    }
    if(ob->query_class_level("bard") < 17) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_charm(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    if((int)caster->query_property("using charm") > time())     {
        tell_object(caster,"You can't try to charm someone again yet!");
        dest_effect();
        return;
    }
    ::execute_feat();
    if(!objectp(target)) {
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!living(target)) {
        tell_object(caster,"You may only charm living objects.");
        dest_effect();
        return;
    }
    if(target == caster){
        tell_object(caster,"You can't really charm yourself very well.");
        dest_effect();
        return;
    }
    if(present("clothesx999",target)){
        tell_object(caster,"You're still controlling a creature!");
        dest_effect();
        return;
    }
    if(pointerp(target->query_property("charmed")) && member_array(caster,target->query_property("charmed")) != -1){
        tell_object(target,"%^BOLD%^"+caster->QCN+" is trying to charm you again.");
        tell_object(caster,"You've already tried that and "+target->QCN+" is ready for it this time!");
        if(!interactive(target)) target->kill_ob(caster,1);
        dest_effect();
        return;
    }
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+" seems to be trying to get "+target->QCN+
"'s attention.",({caster,target}));
    tell_object(caster,"%^BOLD%^You attempt to charm "+target->QCN+".\n");
    tell_object(target,"%^BOLD%^You feel a sense of strangeness come over you as "+caster->QCN+" looks at you.");
    caster->set_property("using instant feat",1);
    caster->remove_property("using charm");
    caster->set_property("using charm",time() + 5); //doubled timer to be on par with whirl etc. Nienne, 08/09.
    return;
}

void execute_attack(){
    int mod, i, duration;
    object *inv;
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        caster->remove_property("using charm");
        dest_effect();
        return;
    }
    mod = roll_dice(1,clevel);
    mod += clevel - (int)target->query_level();
    mod += ((int)caster->query_stats("charisma") -10)/2;
    mod = mod * -1;

    if(!do_save(target,mod) || target->query_property("no dominate")) {
        tell_object(target,"%^BOLD%^%^GREEN%^You suddenly feel much calmer and agreeable to "+caster->QCN+"'s "
"suggestions.");
        target->cease_all_attacks();
        target->set("aggressive",0);
        duration=60+clevel*60;
        duration=duration>300?300:duration;
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
        running = 1;
        call_out("dest_effect", duration);
    }
    else{
        tell_object(caster,"%^BOLD%^%^BLUE%^You fail to charm "+target->QCN+"!");
        tell_object(target,"%^BOLD%^%^BLUE%^You shake off the odd feeling, recognizing "+caster->QCN+" as the source of "
"the deception attempt.");
        target->set_property("charmed",({caster}));
        tell_room(environment(target), "%^BOLD%^%^BLUE%^"+target->QCN+" glares at "+caster->QCN+" %^BOLD%^%^BLUE%^in "
"annoyance.",({caster,target}));
    }
    return;
}

void dest_effect(){
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
    remove_feat(TO);
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
