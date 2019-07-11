#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <priest.h>
inherit SPELL;

int newhp;

void create() {
    ::create();
    set_spell_name("warriors constitution");
    set_spell_level(([ "mage" : 6, "bard" : 6 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS warriors constitution on TARGET");
    set_description("This spell will grant the target of the spell the endurance of a strong and true warrior.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "drop of blood":1, "crane's feather":1, ]),
    ]));
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^RED%^With a shout and a body wide flex, "+caster->QCN+" starts to cast a spell.";
}

void spell_effect(int prof) 
{
    object Vob;
    int i, dice, roll_1, roll_2, bonuses, targlevel,diff;
    string file;
    if (!objectp(target)) {
        TO->remove();
        return;
    }
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if (caster == target) {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to the strength of your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+caster->QCN+"'s body.",({caster}));
    } else {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to strengthen "+target->QCN+"'s body.");
        tell_object(target,"%^RED%^You feel the force of "+caster->QCN+"'s will strengthen your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+target->QCN+"'s body.",({target}));
    }

    file = DIR_CLASSES+"/fighter.c";
    if(!file_exists(file)) {
        tell_object(caster,"There is an error loading the fighter class file, please notify a wiz with this message.");
        TO->remove();
        return;
    }
    if(objectp(Vob = caster->query_property("VigorOb"))) Vob->dest_effect();
    
    
    dice = file->hit_dice(); 
    newhp = 20;
    targlevel = target->query_level();

    for(i=0;i<targlevel;i++) {
      roll_1 = roll_dice(1,dice);
      roll_2 = roll_dice(1,dice);
      if(roll_1 > roll_2) newhp += roll_1;
      else newhp += roll_2;
    }
    bonuses = ((int)target->query_stats("constitution") - 10)/2;
    if(FEATS_D->has_feat(target,"toughness")) bonuses++;
    if(FEATS_D->has_feat(target,"improved toughness")) bonuses++;
    newhp = newhp + (targlevel*bonuses);
    
    // giving warrior's con a limited heal effect
    if(target->query_hp() < target->query_max_hp())
    {
        diff = target->query_max_hp() - target->query_hp();
        if(diff > newhp)
        {
            target->add_hp(newhp);
            dest_effect();
            return;
        }
        else
        {
            target->add_hp(diff);
            newhp = newhp - diff;
        }        
    }    
    
    newhp = newhp - (int)target->query_max_hp();
    newhp = newhp - (int)target->query_extra_hp();
    if (newhp < 0) newhp = 0;

    target->add_extra_hp(newhp);
    target->set_property("spelled",({TO}));
    spell_successful();
    //removing from dispell list - installing code that allows removal when recasted - Saide
    //addSpellToCaster();
    caster->set_property("VigorOb",TO);
    call_out("check_removal",ROUND_LENGTH);
}

void check_removal() {
   if(!objectp(target)) return;
   if(target->query_extra_hp() <= 0) dest_effect();
   else call_out("check_removal",ROUND_LENGTH);
}

void dest_effect() {

    if(objectp(target)) 
    {
       target->add_extra_hp(-1* newhp);
       if ((int)target->query_extra_hp() < 0) 
       {
           target->add_extra_hp(-1 * (int)target->query_extra_hp());
       }
    target->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
