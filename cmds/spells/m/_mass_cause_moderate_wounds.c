// mass cause moderate wounds
#include <priest.h>
inherit SPELL;

int calculate_damage();

void create() {
    ::create();
    set_author("ares");
    set_spell_name("mass cause moderate wounds");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS mass cause moderate wounds [on TARGET]");
    set_description("This is a stronger version of the priest spell, cause moderate wounds.  When cast on a target, it "
"will do damage to them if they are living, and it will heal them if they are undead.  If no target is given, it will hit "
"all of the caster's current attackers.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^RED%^You cast your gaze upon your foes as"+
	    " you begin to chant a wounding prayer.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" begins to chant a prayer"+
	    " as "+caster->QS+" casts "+caster->QP+" gaze upon "+caster->QP+""+
	    " foes.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    int i;
    object *attackers = ({});

    attackers = caster->query_attackers();

    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
			if(!objectp(attackers[i])) { continue; }
			tell_object(caster,"%^BOLD%^%^RED%^You send out a moderate wave of magic, "
				"hitting "+attackers[i]->QCN+"!%^RESET%^");
            tell_object(attackers[i],"%^BOLD%^%^RED%^A moderate field radiates out "+
			    "from "+caster->QCN+" stealing a moderate bit of strength from you.");
			tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" sends out a moderate wave of "
				"magic, hurting "+attackers[i]->QCN+"!%^RESET%^",({attackers[i],caster}));
            if((string)attackers[i]->query_race() == "undead")
                damage_targ(attackers[i],attackers[i]->return_target_limb(),(-1 *calculate_damage()),"negative energy");
            else
            {
                damage_targ(attackers[i],attackers[i]->return_target_limb(),calculate_damage(),"negative energy");
                spell_kill(attackers[i],caster);
            }
        }
    }
    else if(objectp(target))
    {
		tell_object(caster,"%^BOLD%^%^RED%^You send out a moderate wave of magic, "
			"hitting "+target->QCN+"!%^RESET%^");
        tell_object(target,"%^BOLD%^%^RED%^A moderate field radiates out "+
		    "from "+caster->QCN+" stealing a moderate bit of strength from you.");
		tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" sends out a moderate wave of "
			"magic, hurting "+target->QCN+"!%^RESET%^",({target,caster}));
        if((string)target->query_race() == "undead")
            damage_targ(target,target->return_target_limb(),(-1 *calculate_damage()),"negative energy");
        else
        {
            damage_targ(target,target->return_target_limb(),calculate_damage(),"negative energy");
            spell_kill(target,caster);
        }
    }
    else
        tell_object(caster,"The spell's power surges about unused.");

    spell_successful();
    dest_effect();
}

int calculate_damage()
{
    int num, max;
    max = 50; // max amount of damage the spell can heal, for ease of adjustment -Ares
    num = roll_dice(2,8) + (clevel);
    if(num > max) { num = max; }
    return num;
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}