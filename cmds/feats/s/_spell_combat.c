#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object *exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("spell combat");
    feat_prereq("Magus L1");
    feat_syntax("spell_combat");
    feat_desc("A magus learns to cast spells and wield his weapons at the same time. The magus must have one hand free, while wielding a light or one-handed melee weapon in the other hand. The spell potency has a penalty but its lessened at 8th level and again at 14th level.");
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!ob->is_class("magus"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spell_combat(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str,"dark black");
}

void execute_feat()
{
    object obj;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(FEATS_D->is_active(caster,"spell combat"))
    {
        obj = query_active_feat("spell combat");
        tell_object(caster,cm("You release your concentration."));
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster,cm("You combine your magical ability and martial prowess."));
    caster->set_property("active_feats",({TO}));
    caster->set_property("magus cast", 1);
    return;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property_value("active_feats",({TO}));
        caster->remove_property("magus cast");
        tell_object(caster,"%^BOLD%^%^BLUE%^Your concentration fades.");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
