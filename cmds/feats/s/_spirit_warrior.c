#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("RagingProphet");
    feat_name("spirit warrior");
    feat_prereq("Raging Prophet L4");
    feat_syntax("spirit_warrior");
    feat_desc("A rage prophet can enter the realm of spirits, gaining partial immunity to corporeal damage.");
    permanent(1);
}

//blep blep mew mew

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("raging_prophet") < 7)
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

