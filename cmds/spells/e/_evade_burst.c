//AOE avoidance for psywarriors
#include <priest.h>
#include <daemons.h>
inherit SPELL;

int feattracker;

void create() {
    ::create();
    set_spell_name("evade burst");
    set_spell_level(([ "psywarrior" : 3, "psion" : 7 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS evade burst");
    set_description("Using this power, the psionic character gains the "
       "ability to avoid damage from certain spells and powers as if he "
       "had the evasion feat. For more specific information, please see "
       "<help evasion>. This power does not stack with the evasion feat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
	string *TmpFeats;
	TmpFeats = caster->query_temporary_feats();
	if(!sizeof(TmpFeats)) TmpFeats = ({});
   	if(member_array("evasion",TmpFeats) != -1) 
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
        tell_object(caster, "%^RESET%^%^RED%^You send a pulse of mental energy "
           "through your muscles and sinew, heightening your alertness and "
           "readying your body to move at a moment's notice.%^RESET%^");
        tell_room(place,"%^RESET%^%^RED%^"+caster->QCN+" closes "+MINE+" "
           "eyes briefly, and you feel a brief pulse of energy rushing toward "
           ""+caster->QO+".%^RESET%^",caster);
    }
    if(pointerp(caster->query_temporary_feats()))
    {
        if(member_array("evasion",(string*)caster->query_temporary_feats()) == -1) 
        {
            caster->add_temporary_feat("evasion");
            feattracker = 1;
        }
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(CASTER)) {
      tell_object(caster,"%^RESET%^%^RED%^You feel sluggish and somehow drained "
         "as you lose your heightened mental agility.%^RESET%^");
      if(feattracker == 1) caster->remove_temporary_feat("evasion");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}