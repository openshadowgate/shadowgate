#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Duelist");
    feat_name("bladesong");
    feat_prereq("Swipe");
    feat_desc("With this feat duelist learns how to use just one hand to channel their spells.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    object *weapons;
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"swipe"))
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
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

