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

int cmd_hide_in_plain_sight(string str) {
    object feat;
    if(!objectp(TP))
        return;
    caster->set_hidden(1);
    obj = new("/cmds/feats/obj/hide_in_plain.c");
    obj->set_player(caster);
    obj->move(caster);
    return 1;
}

void execute_feat() {
    object obj;
    ::execute_feat();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
