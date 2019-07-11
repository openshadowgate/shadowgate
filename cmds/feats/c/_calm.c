#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("calm");
    feat_prereq("Bard L11");
    feat_syntax("calm TARGET");
    feat_desc("Successful use of this feat will cause the targetted opponent to cease all attacks and combat. However, should the opponent pass their save, they will become angered and may berserk.");
    set_target_required(1);
    set_required_for(({"charm"}));
    set_save("will");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"anger")) {
      dest_effect();
      return 0;
    }
    if(ob->query_class_level("bard") < 11) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_calm(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    if((int)caster->query_property("using calm") > time())     {
        tell_object(caster,"You can't try to calm someone again yet!");
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
        tell_object(caster,"You may only calm living objects.");
        dest_effect();
        return;
    }
    if(target == caster){
        tell_object(caster,"You can't really calm yourself very well.");
        dest_effect();
        return;
    }
    if(!sizeof(target->query_attackers())){
        tell_object(caster,"That target doesn't need calming down.");
        dest_effect();
        return;
    }
    if(pointerp(target->query_property("calmed")) && member_array(caster,target->query_property("calmed")) != -1){
        tell_object(target,"%^BOLD%^"+caster->QCN+" is trying to calm you again.");
        tell_object(caster,"You've already tried that and "+target->QCN+" is ready for it this time!");
        if(!interactive(target)) target->kill_ob(caster,1);
        dest_effect();
        return;
    }
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+" seems to be trying to get "+target->QCN+
"'s attention.",({caster,target}));
    tell_object(caster,"%^BOLD%^You attempt to calm "+target->QCN+".\n");
    tell_object(target,"%^BOLD%^You feel a sense of strangeness come over you as "+caster->QCN+" looks at you.");
    caster->set_property("using instant feat",1);
    caster->remove_property("using calm");
    caster->set_property("using calm",time() + 30); //doubled timer to be on par with whirl etc. Nienne, 08/09.
    spell_kill(target,caster);
    return;
}

void execute_attack(){
    int mod, i;
    object *inv;
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        caster->remove_property("using calm");
        dest_effect();
        return;
    }
    mod = roll_dice(1,clevel);
    mod += clevel - (int)target->query_level();
    mod += ((int)caster->query_stats("charisma") -10)/2;
    mod = mod * -1;

    if(!do_save(target,mod) && !target->query_property("no calm")) {
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^You see a transformation take place in "+target->QCN+" as "
+target->QS+" %^BOLD%^%^GREEN%^calms down.",target);
        tell_object(target,"%^BOLD%^%^GREEN%^You suddenly feel unusually calm, and you cease your fighting.");
        target->cease_all_attacks();
        inv = all_inventory(environment(target));
        for(i = 0;i<sizeof(inv);i++){
            if(!living(inv[i])) continue;
            if(target == inv[i]) continue;
            inv[i]->remove_attacker(target);
        }
        target->set("aggressive",0);
    }
    else{
        tell_object(caster,"%^BOLD%^%^BLUE%^You fail to calm "+target->QCN+" and "+target->QS+" rushes at you angrily!");
        tell_object(target,"%^BOLD%^%^BLUE%^You shake off the odd feeling, recognizing "+caster->QCN+" as the source of "
"the deception and you leap to attack "+caster->QS+"!");
        target->set_property("calmed",({caster}));
        tell_room(environment(target), "%^BOLD%^%^BLUE%^"+target->QCN+" glares at "+caster->QCN+" %^BOLD%^%^BLUE%^angrily "
"and attacks with renewed vengeance.",({caster,target}));
        if(!interactive(target) && !target->query_paralyzed()){
            target->kill_ob(caster);
            tell_room(environment(target),"%^BOLD%^%^BLUE%^You see "+target->QCN+" start to berserk.");
            target->execute_attack();
            target->execute_attack();
        }
    }
    timer(caster);
    return;
}

void timer(object tp){
   if(!objectp(tp)) return;
   if(!tp->query_property("using calm")) dest_effect();
   if(!sizeof(tp->query_attackers())) { 
        tp->remove_property("using calm");
        dest_effect();
        return;
   }
   call_out("timer",1,tp);
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}

