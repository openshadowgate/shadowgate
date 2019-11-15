#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Inquisition");
    feat_name("rally");
    feat_syntax("judgment FIRST [SECOND [THIRD]]");
    feat_prereq("Heh");
    feat_desc("");
//    set_required_for(({"second judgement","third judgement"}));
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    return 0;
    if(!objectp(ob)) return 0;
    if(!ob->is_class("inqusitor"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_judgement(string args)
{
    int i=3;
    string j;
    string *jtoactivate=({}),*argss;
    string *active_judgements = ({});

    if(!objectp(TP))
        return 0;


    return 1;
}


void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
