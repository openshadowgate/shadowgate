#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("RadiantServant");
    feat_name("supreme healer");
    feat_prereq("Radiant servant L7");
    feat_desc("Supreme healer will allow the Radiant Servant to cast any wound-curing spell that she knows without needing the healing spell prepared and without using any spell slots, at will and an unlimited amount of times per day.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->usable_feat(ob,"radiant aura") || ob->query_class_level("radiant_servant") < 7)
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

