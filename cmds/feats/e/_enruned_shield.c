#include <std.h>
#include <daemons.h>

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
    set_required_for(({ "greater enruned shield" }));
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

int cmd_enruned_shield()
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (!(int)TP->is_wearing_type("shield"))
    {
        tell_object(TP, "%^RESET%^%^BOLD%^You must be wearing a shield.%^RESET%^");
        return 1;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "dark black");
}

void execute_feat()
{
    object obj;
    int duration;

    if (!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "enruned shield"))
    {
        obj = query_active_feat("enruned shield");
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster, cm("You scribe a rune in your shield."));
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("enruned shield", 1);

    if (FEATS_D->has_feat(caster, "greater enruned shield")) {
        duration = (int)caster->query_class_level("magus") * 600;
    }
    else {
        duration = (int)caster->query_class_level("magus") * 60;
    }

    call_out("dest_effect", duration);

    return;
}

void dest_effect()
{
    if (objectp(caster))
    {
        caster->remove_property_value("active_feats", ({ TO }));
        caster->remove_property("enruned shield");
        tell_object(caster, cm("The rune in your shield vanishes."));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}