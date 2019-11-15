#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

string * JUDGEMENT_TYPES;

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
    object controller;
    int i;
    string j;
    string *jtoactivate=({}),*argss;

    if(!objectp(TP))
        return 0;
    if(!sizeof(TP->query_attackers()))
    {
        tell_object(TP,"You can't use judgement outside of combat.");
        return 1;
    }
    argss = explode(args," ");
    clevel = TP->query_guild_level("inquisitor");
    JUDGEMENT_TYPES = "/cmds/feats/obj/judgement"->query_judgement_types();


    if(FEAT_D->usable_feat(TP,"third judgement"))
        i = 3;
    else if(FEAT_D->usable_feat(TP,"second judgement"))
        i = 2;
    else
        i = 1;

    foreach(j in argss)
    {
        if(member_array(j,JUDGEMENT_TYPES)!=-1)
        {
            jtoactivate+=({j});
        }
        else
        {
            tell_object(TP,"Wrong judgement type: "+j);
        }
        i--;
        if(i<1)
            break;
    }

    if(present("judgement_obj",TP))
    {
        controller = present("judgement_obj",TP);
    }
    else
    {
        controller = new("/cmds/feats/obj/judgement");
        controller->setup_judgement(TP,clevel);
        controller->move(TP);
    }
    controller->activate_judgements(jtoactivate);

    return 1;
}


void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
