#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("instant");
    feat_category("DivineSpellcraft");
    feat_name("rally");
    feat_syntax("judgement FIRST [SECOND [THIRD]]");
    feat_prereq("Heh");
    feat_desc("");
//    set_required_for(({"second judgement","third judgement"}));
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    return 0;
    if(!objectp(ob)) return 0;
    if(!ob->is_class("bard")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_rally(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    //if(!stringp(str)) { return 0; }
    return 1;
}

void execute_feat(){

    return;
}

void do_rally(){
    return;
}

void check(){
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    call_out("check",ROUND_LENGTH);
}

void dest_effect(){
    return;
}
