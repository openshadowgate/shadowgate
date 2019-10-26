#include <priest.h>
#include <daemons.h>
inherit SPELL;

int feattracker;

void create() {
    ::create();
    set_spell_name("biofeedback");
    set_spell_level(([ "psywarrior" : 1, "psion" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS biofeedback");
    set_description("Using this power, the psionic character bolsters "
       "his mental defenses, gaining a small amount of resistance to "
       "magic.  The spell does not stack with the resistance feat or spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
	string *TmpFeats;
	TmpFeats = caster->query_temporary_feats();
	if(!sizeof(TmpFeats)) TmpFeats = ({});
   	if(member_array("resistance",TmpFeats) != -1) 
	{
	      tell_object(CASTER,"You are already under the influence of a similar effect.");
      	return 0;
   	}
   	return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^RESET%^%^CYAN%^You take a few moments to "
           "contemplate the nature of mental attacks, strengthening your "
           "resolve against magic and psionics alike.%^RESET%^");
        tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" closes "+MINE+" "
           "eyes briefly, and you feel a brief pulse of power rushing toward "
           ""+caster->QO+".%^RESET%^",caster);
    }
    if(pointerp(caster->query_temporary_feats()))
    {
        if(member_array("resistance",(string*)caster->query_temporary_feats()) == -1) 
        {
            caster->add_temporary_feat("resistance");
            feattracker = 1;
        }
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(CASTER)) {
      tell_object(caster,"%^RESET%^%^CYAN%^You feel strangely vulnerable as "
         "you let down your mental defenses.%^RESET%^");
      if(feattracker == 1) caster->remove_temporary_feat("resistance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}