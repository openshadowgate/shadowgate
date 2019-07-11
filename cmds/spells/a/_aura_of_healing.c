// Garrett 01 - 13 - 2004
//minor typo fixed by Circe 2/6/04
//Fixed so it cant stack from the same 
//priest - Saide 2009
// Based on cure light wounds by  Pator@ShadowGate
// Aug 8 1996

#include <priest.h>

inherit SPELL;

int my_repeats;
string * my_party;
int first_execute = 0;


void create() 
{
    ::create();
    set_author("garrett");
    set_spell_name("aura of healing");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS aura of healing");
    set_description("This spell heals wounds on party members.  The amount and length of the spell are dependent on the "
        "strength of the caster.  The party members must remain with the caster to receive the effect.");
    set_verbal_comp();
    set_somatic_comp();
    set_property("magic",1);
    set_helpful_spell(1);
}


string query_cast_string() 
{
   string cast;

   if (interactive(CASTER)) 
   {
        cast = "%^CYAN%^"+YOU+" starts to concentrate and chant a worshipful incantation to "+MINE+" deity!";
   } 
   else 
   {
        cast = "%^CYAN%^"+YOU+" starts to concentrate and chant a long worshipful incantation !";
   }
}


void spell_effect(int prof) 
{
    int clevel,rnd,i,spell_level;
    object * obarr;
   
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    my_party = ob_party(caster);

    if(caster->has_property(caster->query_name() + "_aura_of_healing")) 
    {
        caster->remove_property(caster->query_name() + "_aura_of_healing");
        caster->set_property(caster->query_name() + "_aura_of_healing", 1);
        tell_object(caster, "%^CYAN%^You refresh the aura of healing "+
            "already surrounding you!%^RESET%^");
        dest_effect();
        return;
    }
   
    caster->set_property(caster->query_name() + "_aura_of_healing", 1);
    tell_object(caster, "%^CYAN%^You feel a magical aura of energy from your "+
        "god surround you!%^RESET%^");
    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack() 
{
    int rnd, spell_level, i, repeats, flag;   //flag var so it doesn't give messages
    object cast, targ, place;                 //unless someone is injured, less spam - Saide

    if (!first_execute) 
    {
        first_execute++;
        ::execute_attack();
        return;
    }
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
   
    cast = caster;
    place = environment(caster);

    for(i=0;sizeof(my_party),i<sizeof(my_party);i++) 
    {
        if(!objectp(my_party[i])) { continue; }
        if(environment(my_party[i]) != place) { continue; }
        targ = my_party[i];
        
        if((int)targ->query_hp() < (int)targ->query_max_hp()) 
        {
            if(!flag) 
            {
                tell_room(place,"%^CYAN%^A slight magical wave radiates out from "+cast->QCN+"!",({ cast }) );
                tell_object(cast,"%^CYAN%^A slight magical wave radiates out from your body from your god!");
                flag = 1;
            }
        }
       
        if(!flag) { continue; }
       
        if(cast != targ)
        {               
            if((int)targ->query_hp() < (int)targ->query_max_hp()) 
            {
                tell_object(cast,"%^CYAN%^You see the power of your deity add "+
                    "a small bit of energy to "+targ->QCN+"!");
            }
        }
       
        if((int)targ->query_hp() < (int)targ->query_max_hp()) 
        {
            tell_object(targ,"%^CYAN%^The magical energy adds a bit of "+
                "strength to you.");
            rnd = (int)CLEVEL / 4;
            rnd = roll_dice(rnd,12) + rnd;
            damage_targ(targ,targ->query_random_limb(),-1*rnd,"positive energy");
        }
        continue;
    }
    
    repeats = 0;
    repeats = caster->query_property(caster->query_name() + "_aura_of_healing");
    repeats++;
    
    if(repeats > ((int) clevel / 2))
    {
        dest_effect();
        return;
    }
    else
    {
        place->addObjectToCombatCycle(TO,1);
        caster->remove_property(caster->query_name() + "_aura_of_healing");
        caster->set_property(caster->query_name() +"_aura_of_healing", repeats);
    }
}


void dest_effect() 
{       
    if(objectp(caster)) 
    { 
        caster->remove_property(caster->query_name() + "_aura_of_healing"); 
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}