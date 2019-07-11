// Revised by Pator@ShadowGate
// Aug 8 1996

#include <priest.h>

inherit SPELL;

void create() 
{
    ::create();
    set_author("pator");
    set_spell_name("cleanse disease");
    set_spell_level(([ "cleric" : 4, "bard" : 4, "paladin" : 4, "ranger" : 3, "druid" : 3 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cleanse disease on TARGET");
    set_description("This spell will attempt to cleanse any diseases present on the TARGET. Success is based on "+
    "the level of the caster versus the difficult of the particular disease.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string query_cast_string() 
{
    string cast;

    if (interactive(CASTER)) 
    {
         cast = "%^CYAN%^"+YOU+" starts to intone a long "+
		" incantation!";
    } else {
         cast = "%^CYAN%^"+YOU+" starts to vibrate and a long "+
		" incantation sounds!";
    }
}

void spell_effect(int prof) 
{
    string res;
	tell_room(place, "%^BOLD%^%^WHITE%^A brilliant white aura briefly envelopes "+HIM+"!",({caster, target}));
    if (interactive(caster)) 
    {
        if (target!=caster)
        {
           tell_object(caster, "%^BOLD%^%^WHITE%^A brilliant white aura envelopes "+HIM+" as you attempt to cleanse "+
           target->QO+"!");
        }

    }
    if(living(target)) tell_object(target, "%^BOLD%^%^WHITE%^A brilliant white aura envelopes you as "+caster->QCN+" attempts to cleanse you!%^RESET%^");
    res = DISEASE_D->cure_diseases(caster, target);    	
    if(res == "")
    {
        tell_room(place, HIM+" appears no different", ({target}));
        if(living(target)) tell_object(target, "%^BOLD%^%^WHITE%^You feel no different.%^RESET%^");
    }
    else
    {
        tell_room(place, HIM+" appears to have been cleansed!", ({target}));
        if(living(target)) tell_object(target, "%^BOLD%^%^WHITE%^You have been cleansed of \n"+res+"!");
    }
    spell_successful();
    dest_effect();
    return;
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}