#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("improved dodge");
    feat_prereq("Thief L8");
    feat_desc("This feat grants thief knowledge how to avoid backstabs from the thief of the same level.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("thief") < 20) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
