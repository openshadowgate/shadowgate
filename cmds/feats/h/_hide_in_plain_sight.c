#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("Assassin");
    feat_name("hide in plain sight");
    feat_syntax("hide_in_plain_sight");
    feat_desc(".");
    set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("4") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_tracklessstep(string str) {
    object feat;
    if(!objectp(TP))
        return;
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat() {
    object obj;
    ::execute_feat();
    caster->set_hidden(1);
    obj = new("/cmds/mortal/obj/hide_in_plain.c");
    obj->set_player(caster);
    obj->move(caster);
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
