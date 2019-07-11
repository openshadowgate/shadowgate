#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("anger");
    feat_syntax("anger TARGET");
    feat_prereq("Bard L8");
    feat_desc("Successful use of this feat will cause the targetted opponent to fly into a rage and attack anything in sight.");
    set_target_required(1);
    set_required_for(({"calm","charm"}));
	set_save("will");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"rally")) {
      dest_effect();
      return 0;
    }
    if(ob->query_class_level("bard") < 8) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_anger(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    if((int)caster->query_property("using anger") > time())     {
        tell_object(caster,"You can't try to anger someone again yet!");
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
        tell_object(caster,"You may only anger living objects.");
        dest_effect();
        return;
    }
    if(target == caster){
        tell_object(caster,"You can't really anger yourself very well.");
        dest_effect();
        return;
    }
    if(sizeof(target->query_attackers())){
        tell_object(caster,"That target is already angry!");
        dest_effect();
        return;
    }
    if(pointerp(target->query_property("angered")) && member_array(caster,target->query_property("angered")) != -1){
        tell_object(target,"%^BOLD%^"+caster->QCN+" is trying to calm you again.");
        tell_object(caster,"You've already tried that and "+target->QCN+" just ignores you!");
        dest_effect();
        return;
    }

    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+" seems to be trying to get "+target->QCN+
"'s attention.",({caster,target}));
    tell_object(caster,"%^BOLD%^%^BOLD%^You attempt to anger "+target->QCN+".\n");
    tell_object(target,"%^BOLD%^You feel a sense of strangeness come over you as "+caster->QCN+" looks at you.");
    caster->set_property("using instant feat",1);
    caster->remove_property("using anger");
    caster->set_property("using anger",time() + 30);
    spell_kill(target,caster);
    return;
}

void execute_attack(){
    int mod, i, n;
    object *inv;
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        caster->remove_property("using anger");
        dest_effect();
        return;
    }

    mod = roll_dice(1,clevel);
    mod += clevel - (int)target->query_level();
    mod += ((int)caster->query_stats("charisma") -10)/2;
    mod = mod * -1;

    if(!do_save(target,mod) && !target->query_property("no calm")) {
        tell_room(environment(caster),"%^BOLD%^%^RED%^You see a transformation take place in "+target->QCN+" as "
+target->QS+" %^BOLD%^%^GREEN%^becomes frenzied.",target);
        tell_object(target,"%^BOLD%^%^RED%^You suddenly feel enraged and attack everything in sight!");
        if(!avatarp(caster)) log_file("anger", caster->query_name()+" angered "+target->query_name()+" on "+ctime(time())+"\n");

        inv = all_inventory(place);
        for(i = 0;i<sizeof(inv);i++){
          n = 1;
          if(!living(inv[i])) continue;
          if(target == inv[i]) continue;
          if(inv[i]->query_true_invis()) continue;
          while(present(inv[i]->query_name()+" "+n,place)){
            target->force_me("kill "+inv[i]->query_name()+" "+n);
   		n++;
          }
        }
    }
    else{
        tell_object(caster,"%^BOLD%^%^BLUE%^You fail to anger "+target->QCN+" and "+target->QS+" looks startled.");
        tell_object(target,"%^BOLD%^%^BLUE%^You feel more like yourself again and glare at "+caster->QCN+" as you shake "
"your head to clear it.");
        target->set_property("angered",({caster}));
        tell_room(environment(target), "%^BOLD%^%^BLUE%^You see "+target->QCN+" look at "+caster->QCN+" %^BOLD%^%^BLUE%^"
"strangely.",({caster,target}));
    }
    timer(caster);
    return;
}

void timer(object tp){
   if(!objectp(tp)) return;
   if(!tp->query_property("using anger")) dest_effect();
   if(!sizeof(tp->query_attackers())) { 
        tp->remove_property("using anger");
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

