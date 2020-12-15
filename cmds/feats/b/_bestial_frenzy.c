/*
  _bestial_frenzy.c
  
  Soft rage effect for Beast master and their
  companions.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

object *companions;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("BeastMastery");
    feat_name("bestial frenzy");
    feat_prereq("Beast Master L7");
    feat_syntax("bestial_frenzy");
    feat_desc("Sometimes the thrill of the hunt can be overwhelming, releasing a feral " +
    "wrath within the Beast Master and his pack alike. This manifests as a keen killer instinct. " +
    "The Beast Master and their companions enter a rage, gaining +4 to strength, dexterity, and " +
    "constitution, as well as a +2 to fast healing for its duraton. This does not stack with other " +
    "rage effects.");
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("beast_master") < 7)
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_bestial_frenzy(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);

    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "red and black");
}

void execute_feat()
{
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (FEATS_D->is_active(caster, "bestial frenzy"))
    {
        obj = query_active_feat("bestial frenzy");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }
    if (caster->query_property("using instant feat"))
    {
        tell_object(caster, "%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
        dest_effect();
        return;
    }
    if (caster->query_casting())
    {
        tell_object(caster, "%^BOLD%^You can't enter a bestial frenzy while you're casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    
    companions = caster->query_property("animal_companion");
    
    if(!sizeof(companions))
    {
        tell_object(caster, "%^BOLD%^You can't enter a bestial frenzy without your pack.%^RESET%^");
        return;
    }
    
    companions = filter_array(companions, (: objectp($1) :));
    
    if (caster->query_property("effect_exhausted") || caster->query_property("effect_fatigued")) {
        tell_object(caster, "%^BOLD%^You are fatigued or exhausted and cannot rage.%^RESET%^");
        dest_effect();
        return;
    }
    
    tell_object(caster, cm("You lose yourself to the thrill of the hunt."));
    caster->set_property("active_feats", ({ TO }));
    
    caster->set_property("raged", 1);
    caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    caster->set_property("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    caster->add_stat_bonus("strength", 4);
    caster->add_stat_bonus("dexterity", 4);
    caster->add_stat_bonus("constitution", 4);
    caster->add_property("fast healing", 2);
    
    tell_object(caster, "You rage OK.");

    foreach(object ob in companions)
    {        
        if(!objectp(ob))
        {
            tell_object(caster, "Animal failed.");
            continue;
        }
        if(caster->query_chosen_animal() != ob->query_name())
            continue;
        
        tell_object(caster, cm("Your " + ob->query_name() + " loses itself to the thrill of the hunt."));
        
        ob->set_property("raged", 1);
        ob->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
        ob->set_property("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
        ob->add_stat_bonus("strength", 4);
        ob->add_stat_bonus("dexterity", 4);
        ob->add_stat_bonus("constitution", 4);
        ob->add_property("fast healing", 2);
    }
    
    call_out("dest_effect", ROUND_LENGTH * flevel * 4);
}

void dest_effect()
{
    if (objectp(caster))
    {
        if (FEATS_D->is_active(caster, "bestial frenzy")) {
            tell_object(caster, cm("Your pack comes down from its bestial frenzy."));
            caster->remove_property_value("active_feats", ({ TO }));
            caster->remove_property("raged");
            caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
            caster->add_stat_bonus("strength", -4);
            caster->add_stat_bonus("dexterity", -4);
            caster->add_stat_bonus("constitution", -4);
            caster->add_property("feast healing", -2);
            "/std/effect/status/fatigued"->apply_effect(target, 36);

            foreach(object ob in companions)
            {
                if(!objectp(ob))
                    continue;
        
                ob->remove_property("raged");
                ob->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
                ob->add_stat_bonus("strength", -4);
                ob->add_stat_bonus("dexterity", -4);
                ob->add_stat_bonus("constitution", -4);
                ob->add_property("fast healing", -2);
            }
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}