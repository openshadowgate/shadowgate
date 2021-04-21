#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("danger sense");
    feat_prereq("Barbarian L3, Thief L3");
    feat_desc("This feat gives precognitive, experience-based sense of incoming dangers, effectively granting them +1 dodge bonus to armor class and +1 to reflex saves per 5 levels.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("thief") < 3 ||
        ob->query_class_level("barbarian") < 3) {
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
