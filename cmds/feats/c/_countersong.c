#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("countersong");
    feat_syntax("countersong TARGET");
    feat_prereq("Bard L1");
    feat_classes("bard");
    feat_desc("With this feat you can try to countersong any inspiration or performance another bard is doing. In the case of inspiration the target can be any affected by the song.");
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
    object feat;
    if (!objectp(TP)) {
        dest_effect();
        return 0;
    }

    feat = new(base_name(TO));
    feat->setup_feat(TP, args);
    return 1;
}

void execute_feat()
{

    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
}

void execute_attack()
{
    ::execute_attack();

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
