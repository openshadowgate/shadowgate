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
    feat_syntax("deadly melody");
    feat_prereq("Bard L20");
    feat_classes("bard");
    set_save("fort");
    feat_desc("With this feat you begin to perform a melody of death. Unless someone countersongs your performance, in three rounds every living that hears you and fails the save will die.");
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

int cmd_deadly_melody(string args)
{
    return 1;
}

void execute_feat()
{
    ::execute_feat();

    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
}

void execute_attack()
{
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
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
