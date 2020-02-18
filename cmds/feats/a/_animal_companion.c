/*
  _animal_companion.c
  
  Feat that allows a ranger to summon an animal
  companion.
  
  -- Tlaloc -- 2.18.20
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

//Format - type : ({ STR, DEX, CON, INT, WIS, CHA, SIZE, AC BONUS, }),
mapping valid_types = ([ 
                         "ape" :       ({ 13, 17, 10, 2, 12, 7, 3, 1,  }),
                         "badger" :    ({ 10, 17, 15, 2, 12, 10, 2, 2, }),
                         "bear" :      ({ 15, 15, 13, 2, 12, 6, 3, 2,  }),
                         "bird" :      ({ 15, 15, 13, 2, 14, 6, 1, 1,  }),
                         "boar" :      ({ 13, 12, 15, 2, 13, 4, 2, 6,  }),
                         "camel" :     ({ 18, 16, 14, 2, 11, 4, 3, 1,  }),
                         "cheetah" :   ({ 12, 21, 13, 2, 12, 6, 2, 1,  }),
                         "crocodile" : ({ 15, 14, 15, 1, 12, 2, 2, 4,  }),
                         "dinosaur" :  ({ 11, 17, 17, 2, 12, 14, 2, 1, }),
                         "dog" :       ({ 13, 17, 15, 2, 12, 6, 2, 2,  }),
                         "horse" :     ({ 16, 13, 15, 2, 12, 6, 3, 4,  }),
                         "lion" :      ({ 13, 17, 13, 2, 15, 10, 3, 1, }),
                         "snake" :     ({ 15, 17, 13, 1, 12, 2, 3, 2,  }),
                         "wolf" :      ({ 13, 15, 15, 2, 12, 6, 2, 2,  }),
                       ]);

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
    
    return 1;
}

void execute_feat()
{
    object companion,
           ob;
    
    int class_level,
        comp_hd,
        comp_ac;
    
    ::execute_feat();
    
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    
    if(sizeof(caster->query_attackers()))
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
    
    if(!arg || member_array(arg, keys(valid_types)) < 0)
    {
        tell_object(caster, "That is not a valid choice for your animal companion.");
        tell_object(caster, "Valid options are: (" + implode(m_indices(valid_types), ",") + ") ");
        return;
    }
    
    tell_object(caster, sprintf("You summon your trusty %s companion to your side.", arg));
    
    class_level = caster->query_class_level("ranger") / 2;
    comp_hd = class_level + 2;
    comp_ac = class_level + 1;
    
    ob = new("/d/magic/obj/acompanion");
    ob->set_race(arg);
    ob->set_name(arg);
    ob->set_id( ({ arg, "companion", "animal companion", "animal" }) );
    ob->set_short(sprintf("%s's faithful %s companion.",capitalize(caster->query_name()),arg));
    ob->set_hd(comp_hd);
    ob->set_max_hp(8 * comp_hd);
    ob->set_hp(8 * comp_hd);
    ob->set_alignment(caster->query_alignment());
    ob->set_level("fighter", comp_hd);
    ob->set_owner(caster);
    caster->set_property("animal_companion", ob);
    caster->add_pet(ob);
    caster->add_follower(ob);
    ob->set_property("minion", caster);
    ob->move(environment(caster));
    caster->set_property("using instant feat",1);
    
    //Setting companion stats based on type per SRD
    ob->set_stats("strength", valid_types[arg][0] + min(class_level / 3, 6));
    ob->set_stats("dexterity", valid_types[arg][1] + min(class_level / 3, 6));
    ob->set_stats("constitution", valid_types[arg][2]);
    ob->set_stats("intelligence", valid_types[arg][3]);
    ob->set_stats("wisdom", valid_types[arg][4]);
    ob->set_stats("charisma", valid_types[arg][5]);
    ob->set_size(valid_types[arg][6]);
    ob->set_overall_ac(-comp_ac - valid_types[arg][7]);
  
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
