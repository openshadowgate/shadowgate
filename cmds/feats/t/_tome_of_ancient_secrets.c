#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("TomeBoundMaster");
    feat_name("tome of ancient secrets");
    feat_prereq("Tome Bound Master L7");
    feat_desc(""
"With this feat, the Tome Bound Master has achieved what they originally sought "
"out to do : unlock access to ancient and powerful invocations, unknown to most lesser "
"beings. This feat expands the invocations lists of the warlock, increasing the pool of "
"masterable spells they can choose from. This feat does not automatically grant these "
"spells, only expands the pool of spells to choose from. In addition, the Warlock is "
"given two bonus mastery points (stacks with spell knowledge feat).");
    permanent(1);
    set_required_for(({ "tome of ancient secrets" }));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("tome_bound_master") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}