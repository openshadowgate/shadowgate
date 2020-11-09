#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("enruned shield");
    feat_classes("magus");
    feat_syntax("enruned_shield");
    feat_desc("You may expend a point from the arcane pool to scribe a rune of power on an equipped shield. You can use the hand holding that shield to cast magus spells and you can use spell combat. The rune lasts 10 minutes per level.");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spell_combat(string str)
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (!(int)TP->is_wearing_type("shield"))
    {
        tell_object(TP, "%^RESET%^%^BOLD%^You mustt be wearing a shield.%^RESET%^");
        return 1;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object obj;

    if (!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "enruned shield"))
    {
        obj = query_active_feat("enruned shield");
        tell_object(caster, cm("You release your concentration."));
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster, cm("You combine your magical ability and martial prowess."));
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("enruned shield", 1);

    return;
}

void dest_effect()
{
    if (objectp(caster))
    {
        caster->remove_property_value("active_feats", ({ TO }));
        caster->remove_property("enruned shield");
        tell_object(caster, "%^BOLD%^%^BLUE%^Your concentration fades.");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}