#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("inspire");
    feat_syntax("inspire courage");
    feat_prereq("Bard L1");
    feat_classes("bard");
    feat_desc("");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("bard") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_inspire(string args)
{

    return 1;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
