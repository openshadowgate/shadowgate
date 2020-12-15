/*
  _animal_companion.c
  
  Feat that allows a ranger to summon an animal
  companion.
  
  -- Tlaloc -- 2.18.20
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

#define CHOSEN_MAX 2

inherit FEAT;

//Format - type : ({ STR, DEX, CON, INT, WIS, CHA, SIZE, AC BONUS, }),
mapping valid_types = ([ 
                         "ape" :       ({ 13, 17, 10, 2, 12, 7, 3, 2,  }),
                         "badger" :    ({ 10, 17, 15, 2, 12, 10, 2, 4, }),
                         "bear" :      ({ 15, 15, 13, 2, 12, 6, 3, 4,  }),
                         "bird" :      ({ 15, 15, 13, 2, 14, 6, 1, 2,  }),
                         "boar" :      ({ 13, 12, 15, 2, 13, 4, 2, 12, }),
                         "camel" :     ({ 18, 16, 14, 2, 11, 4, 3, 2,  }),
                         "cheetah" :   ({ 12, 21, 13, 2, 12, 6, 2, 2,  }),
                         "crocodile" : ({ 15, 14, 15, 1, 12, 2, 2, 8,  }),
                         "dinosaur" :  ({ 11, 17, 17, 2, 12, 14, 2, 2, }),
                         "dog" :       ({ 13, 17, 15, 2, 12, 6, 2, 4,  }),
                         "horse" :     ({ 16, 13, 15, 2, 12, 6, 3, 8,  }),
                         "lion" :      ({ 13, 17, 13, 2, 15, 10, 3, 2, }),
                         "snake" :     ({ 15, 17, 13, 1, 12, 2, 3, 4,  }),
                         "wolf" :      ({ 13, 15, 15, 2, 12, 6, 2, 4,  }),
                       ]);

object companion, *companions;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("SavageCombat");
    feat_name("animal companion");
    feat_prereq("Ranger L4");
    feat_syntax("animal_companion [TYPE] to summon or animal_companion to dismiss");
    feat_desc("Summons or dismisses your faithful animal companion. This companion will follow you through thick and thin, will level up with you, and gains several perks as it grows. The TYPE of animal will determine its base stats and natural armor.  The animal companion gains its own feats as follows:

  LEVEL  3 - Evasion
  LEVEL  6 - Resistance
  LEVEL  9 - Precise Strikes
  LEVEL 15 - Stalwart
  
The Animal Companion will hide if you use the 'hide_in_shadows' command, allowing you to effectively sneak about with your faithful friend.

The Animal Companion can also be customized through several commands, which will allow you to change its description:

  'animal short [DESCRIPTION]' - Changes the short description of the companion.
  'animal long  [DESCRIPTION]' - Changes the long description of the companion.

  To have the animal companion follow you, use 'animal follow'.  
  To command the animal companion, use %^ORANGE%^<animal command %^ULINE%^ACTION%^RESET%^ORANGE%^>.%^RESET%^");
  
    set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("ranger") < 4)
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
    int class_level,
        comp_hd,
        comp_ac,
        num,
        mod;
    
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
    
    companions = caster->query_property("animal_companion");
    
    if(!pointerp(companions))
        companions = ({  });
    
    foreach(object ob in companions)
    {
        if(objectp(ob))
        {
            tell_object(caster, "You dismiss your animal companion.");
            ob && ob->remove();
        }

        caster->remove_property("animal_companion");
        return;
    }
    
    if(!arg || member_array(arg, keys(valid_types)) < 0)
    {
        tell_object(caster, "That is not a valid choice for your animal companion.");
        tell_object(caster, "Valid options are: (" + implode(m_indices(valid_types), ",") + ") ");
        return;
    }
    
    class_level = caster->query_guild_level("ranger");
    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companions = ({  });
    num = 1;
    
    if(FEATS_D->usable_feat(caster, "pack leader") && arg == caster->query_chosen_animal())
    {
        num += CHOSEN_MAX;
        mod = 2;
    }
    
    if(mod)
        tell_object(caster, sprintf("You summon your trusty %s companions to your side.", arg));
    else
        tell_object(caster, sprintf("You summon your trusty %s companion to your side.", arg));
    
    for(int x = 0; x < num; x++)
    {    
        companion = new("/d/magic/mon/acompanion");
        companion->set_race(arg);
        companion->set_name(arg);
        companion->set_id( ({ arg, "companion", "animal companion", "greater summon", "animal", caster->query_name() + "'s ally" }) );
        companion->set_short(sprintf("%s's faithful %s companion.",capitalize(caster->query_name()),arg));
        companion->set_level(class_level + mod);
        companion->set_hd(comp_hd, 14 + mod);
        companion->set_attacks_num(2 + class_level / 8);
        companion->set_mlevel("fighter", comp_hd);
        companion->set_max_hp(14 + mod + ((14 + mod) * comp_hd));
        companion->set_hp((14 + mod) * comp_hd + 14 + mod);
        companion->set_alignment(caster->query_alignment());
        companion->set_owner(caster);
        companion->set_property("minion", caster);
        companion->move(environment(caster));
        companion->set_heart_beat(1);
        
        //Setting companion stats based on type per SRD
        companion->set_stats("strength", valid_types[arg][0] + mod + min( ({ class_level / 5, 6 }) ) );
        companion->set_stats("dexterity", valid_types[arg][1] + mod + min( ({ class_level / 5, 6 }) ) );
        companion->set_stats("constitution", valid_types[arg][2] + mod);
        companion->set_stats("intelligence", valid_types[arg][3]);
        companion->set_stats("wisdom", valid_types[arg][4]);
        companion->set_stats("charisma", valid_types[arg][5]);
        companion->set_size(valid_types[arg][6]);
        companion->set_overall_ac(0 - comp_ac - valid_types[arg][7]);
        companion->set_property("damage resistance", mod * 2);
        
        //Based on SRD - companion gets "specials" at certain caster levels
        if(class_level >= 3)
            companion->set_monster_feats( ({ "evasion" }) );
        if(class_level >= 6)
            companion->set_monster_feats( ({ "evasion", "resistance" }) );
        if(class_level >= 9)
            companion->set_monster_feats( ({ "evasion", "resistance", "precise strikes" }) );
        if(class_level >= 15)
            companion->set_monster_feats( ({ "evasion", "resistance", "precise strikes", "stalwart" }) );
        
        caster->add_follower(companion);
        caster->add_protector(companion);
        
        companions += ({ companion });       
    }
       
    caster->set_property("animal_companion", companions);
   
    return;
}

void dest_effect()
{
    remove_feat(this_object());
    ::dest_effect();
    return;
}