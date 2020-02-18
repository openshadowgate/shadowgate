#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

string *valid_types = ({ "badger", "rat", "dog", "hawk", "snake", "wolf", "ape" });

void create()
{
    ::create();
    feat_type("instant");
    feat_category("SavageCombat");
    feat_name("animal companion");
    feat_prereq("Ranger L4");
    feat_syntax("animal_companion");
    feat_desc("Summons your faithful animal companion.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("ranger") < 4 || ob->query_name() != "elendril")
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_animal_companion(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    
    return;
}

void execute_feat()
{
    object companion;
    
    ::execute_feat();
    
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }    
    if(caster->query_attackers())
    {
        tell_object(caster, "You can't summon your animal companion during combat!");
        return;
    }
    
    companion = caster->query_property("animal_companion");
    
    if(objectp(companion))
    {
        tell_object(caster, "You dismiss your animal companion.");
        caster->remove_property("animal_companion");
        companion && destruct_object(companion);
        return;
    }
       
    
    tell_object(caster, "What type of companion do you want to summon? Valid options are: (" + implode(m_indices(valid_types), ",") + ")] ");
    input_to("finish_feat");
    
    return;
}

void finish_feat(string str)
{
    int class_level,
        comp_hd,
        comp_ac;
        
    object ob;
        
    if(member(valid_types, str) < 0)
    {
        tell_object(caster, "That is not a valid choice for your animal companion.");
        return;
    }
    
    class_level = caster->query_class_level("ranger") / 2;
    comp_hd = class_level + 2;
    comp_ac = class_level + 1;   
    
    ob = new("/d/magic/obj/acompanion");
    ob->set_race(str);
    ob->set_name(str);
    ob->set_short(sprintf("%s's faithful %^BROWN%^%s%^RESET%^ companion.",caster->query_name(),str));
    ob->set_hd(comp_hd);
    ob->set_max_hp(8 * comp_hd);
    ob->set_hp(8 * comp_hd);
    ob->set_alignment(caster->query_alignment());
    ob->set_level("fighter", comp_hd);
    ob->set_overall_ac(-comp_ac);
    ob->set_owner(caster);
    caster->set_property("animal_companion", ob);
    caster->add_pet(ob);
    caster->add_follower(ob);
    ob->set_property("minion", caster);
    ob->move(caster);
    caster->set_property("using instant feat",1);
    
    //Based on SRD stat adjustments for animal companion
    ob->set_stats("strength", 16 + min(class_level / 3, 6));
    ob->set_stats("dexterity", 16 + min(class_level / 3, 6));
    
    //Based on SRD - companion gets "specials" at certain caster levels
    if(class_level >= 3)
        ob->set_monster_feats( ({ "evasion" }) );
    if(class_level >= 6)
        ob->set_monster_feats( ({ "evasion", "resistance" }) );
    if(class_level >= 9)
        ob->set_monster_feats( ({ "evasion", "resistance", "rapid strikes" }) );
    if(class_level >= 15)
        ob->set_monster_feats( ({ "evasion", "resistance", "rapid_strikes", "stalwart" }) );
    
    
    return;
}


void dest_effect()
{
    ::dest_effect();
    remove_feat(this_object());
    return;
}
