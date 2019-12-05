#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Rapage");
    feat_name("ragenextgen");
    feat_syntax("rage");
    feat_prereq("Barbarian L1");
    feat_desc("");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->query_name()!="eekclone")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_ragenextgen(string args)
{
    //Blah
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
