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
    feat_name("judgement");
    feat_syntax("judgement FIRST [SECOND [THIRD]]");
    feat_prereq("Inquisitor L1");
    feat_desc("Inquisitors have an unusual affinity to pronounce a judgement on their foes, to strengthen themselves with a channeled powers. At the beginning they can choose just one power to pronounce, but as inquisitor grows in power he learns to control up to three such powers. Changing the power is a free action, but any powers an inquisitor has will retreat after the combat and can not be summoned unless already in the combat.

The list of judgements to choose from:

%^BOLD%^Destruction:%^RESET%^ The inquisitor is filled with divine wrath, giving them damage bonus point per every three levels.

%^BOLD%^Healing:%^RESET%^ The inquisitor is surrounded by a healing light, gaining fast healing point per every eighteen levels.

%^BOLD%^Justice:%^RESET%^ This judgment spurs the inquisitor to seek justice, gaining a sacred bonus point to attack per every three levels.

%^BOLD%^Piercing:%^RESET%^ This judgment gives the inquisitor great focus and makes his spells more potent. This grants a level and ten points worth of spell penetration and a caster level point for every twelve levels.

%^BOLD%^Protection:%^RESET%^ The inquisitor is surrounded by a protective aura, granting a sacred armor class point per every five levels.

%^BOLD%^Purity:%^RESET%^ The inquisitor is protected from the vile taint of her foes, gaining a sacred bonus to all saves, worth of a point per every five levels.

%^BOLD%^Resiliency:%^RESET%^ This judgment makes the inquisitor resistant to harm, granting him one point of spell damage resistance per level.

%^BOLD%^See also:%^RESET%^ status effects
");
//    set_required_for(({"second judgement","third judgement"}));
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if(!ob->is_class("inquisitor"))
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


    if(FEATS_D->usable_feat(TP,"third judgement"))
        i = 3;
    else if(FEATS_D->usable_feat(TP,"second judgement"))
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
