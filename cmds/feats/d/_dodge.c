#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("instant");
    feat_category("Evasion");
    feat_name("dodge");
    feat_prereq("Dexterity 13");
    feat_syntax("dodge TARGET");
    feat_desc("This feat allows the character to designate one opponent in the current combat. They will gain a small AC dodge bonus against this foe until the fight is over.");
    set_required_for(({"mobility","evasion","scramble","spring attack"}));
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_base_stats("dexterity") < 13) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_dodge(string str){
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    if (TP->query_bound() || TP->query_tripped() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      dest_effect();
      return;
    }
    ::execute_feat();

    if(!objectp(target)) { 
        tell_object(TP,"There is no such target here!");
        dest_effect();
        return;
    }
    if(TP->query_property("dodging")) TP->remove_property("dodging");
    TP->set_property("dodging",(string)target->query_name());
    tell_object(TP,"You focus your attention upon dodging the attacks of "+(string)target->query_name()+"!");
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
