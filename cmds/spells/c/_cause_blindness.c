// Created by Pator@Shadowgate
// 11/3/1995, revised 7/26/1996
//Revised 9/05 - Cythera
#include <priest.h>
#include <magic.h>
inherit SPELL;

int combatrounds, normrounds;

void create() {
    ::create();
    set_author("pator");
    set_spell_name("cause blindness");
    set_spell_level(([ "cleric" : 3, "paladin" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause blindness on TARGET");
    set_description("By touching your opponent's eyes, you take the light from "+
        "them.  You should remember that although "+
        "it is a powerful spell, it is curable.  Should you fail to touch "+
        "the target's eyes, the spell will disperse harmlessly.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
    set_save("reflex");
}

void spell_effect(int prof) 
{
    int clevel,effect, bonus;
    if(!objectp(caster)) 
    {
        dest_effect();
        return;
    }
    if(!objectp(target))
    {
        tell_object(caster, "That is not here.");
        dest_effect();
        return;
    }


    place = environment(caster);
    if (environment(target)!=place) 
    {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }
    
    if (CASTER->query_invis() && !CASTER->query_true_invis()) CASTER->set_invis();

    spell_successful();
    tell_object(caster,"%^YELLOW%^Radiant streams of light swirl with "+
        "dark shadows around your hand, as you reach out to "+target->QCN+".");

    tell_room(place,"%^YELLOW%^Radiant streams of light swirl with dark shadows"+
        " around "+caster->QCN+"'s hand as "+caster->QS+" reaches out to "+
    target->QCN+".",({target,caster}));

    tell_object(target,"%^YELLOW%^Radiant streams of light swirl with dark shadows"+
        " around "+caster->QCN+"'s hand as "+caster->QS+" reaches out to touch you!");

    if(do_save(target,0)) 
    { 
        tell_object(caster,"%^YELLOW%^The shadows and light burst from your "+
        "hand, but do not seem to affect "+target->QCN+".");
        tell_room(place,"%^YELLOW%^The shadows and light burst from "+
        caster->QCN+"'s hand, but "+target->QCN+" seems unaffected.",({target,caster}));

        tell_object(target,"%^YELLOW%^The shadows and light burst from "+
        caster->QCN+"'s hand, but you are unaffected!");
        dest_effect();
        return;
    }   
    tell_object(caster,"%^YELLOW%^The shadows and light burst from your hand, "+
        "rendering "+target->QCN+" blind.");
    tell_room(place,"%^YELLOW%^The shadows and light burst from "+caster->QCN+"'s "+
        "hand, sending "+target->QCN+" stumbling blindly.",({target,caster}));
    tell_object(target,"%^YELLOW%^The shadows and light burst from "+	
    caster->QCN+"'s hand, removing your sight!");
    target->set_blind(1);

        //per garrett's suggestion - now to last 2d6 combat rounds or roughly 5min out of combat, 	//whichever comes first
    combatrounds = roll_dice(2,6);
    normrounds = 300/ROUND_LENGTH;
    call_out("test", ROUND_LENGTH);
}

void test() 
{
    if (!objectp(target)) 
    {
        dest_effect();
        return;
    }
    if(!target->query_blind()) 
    { //effect has already been removed
        dest_effect();
        return;
    }
    if(combatrounds < 1 || normrounds < 1) 
    { // can effect once either hits zero
        target->set_blind(0);
        dest_effect();
        return;
    }
    normrounds--;
    if(sizeof(target->query_attackers())) combatrounds--;
    call_out("test", ROUND_LENGTH);
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}