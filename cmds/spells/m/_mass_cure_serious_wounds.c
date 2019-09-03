// mass cure serious wounds
// cures party members if not given a target, if no party it just cures the caster.
// if aimed at an attacker, it hits all attackers, healing living targets and hurting
// undead targets.  If cast at a neutral, it hits all things in the room, healing
// living things, and hurting undead.

#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;

int calculate_healing();

void create() {
    ::create();
    set_author("ares");
    set_spell_name("mass cure serious wounds");
    set_spell_level(([ "cleric" : 7,"druid" : 8 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS mass cure serious wounds on TARGET");
    set_description("This is a stronger version of the priest spell, cure serious wounds.  When cast without a target or "
"on the caster or any party member, are present in the area.  When cast on a hostile, it will hit all hostiles in the "
"immediate area, healing those that are living, and hurting those that are undead.  When cast on a neutral creature that "
"is neither in the caster's party or hostile to the caster, it will hit all creatures in the area, healing those that are "
"living and hurting those that are undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
	if(!objectp(target))
	{
		tell_object(caster,"You must specify a target for this spell.");
		return 0;
	}
	return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLUE%^You press your hands together as"+
		" you begin to chant a beneficial prayer.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" begins to chant a prayer"+
		" as "+caster->QS+" preses "+caster->QP+" hands together.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;
    object *party_members = ({}),*attackers = ({}),*living = ({}),*targets = ({}), *followers = ({});

    party_members = ob_party(caster);
    attackers = caster->query_attackers();
    followers = caster->query_followers();
    living = all_living(place);

    if(!objectp(target)) { target = caster; }

    if(target == caster ||
       member_array(target,party_members) != -1 ||
       member_array(target,followers) != -1)
    {
        targets = ({ caster });
        targets += filter_array(distinct_array(party_members+(followers-attackers)),(:!$1->is_undead():));
    }
    else if(member_array(target,attackers) != -1)
    {
        targets = filter_array(attackers,(:$1->is_undead():));
    }
    else
    {
        living = filter_array(living,"is_non_immortal",FILTERS_D);
        targets = living;
    }

	targets = distinct_array(targets);

    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" opens "+
	    ""+caster->QP+" hands, releasing a wave of"+
	    " energy as "+caster->QS+" shouts out the final words "+
	    "of the prayer.",caster);

	if(sizeof(targets))
	{
		for(i=0;i<sizeof(targets);i++)
		{
			if(!objectp(targets[i])) { continue; }
			if(!present(targets[i],place)) { continue; }
			if(targets[i]->is_undead())
			{
                tell_room(place,"%^BOLD%^%^BLUE%^A strong blue field radiates out"+
				    " from "+targets[i]->QCN+" as "+caster->QCN+" releases a"+
				    " wave of energy.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^BLUE%^A strong field radiates out "+
				    "from "+targets[i]->QCN+ " as you release a wave of energy.");
                tell_object(targets[i],"%^BOLD%^%^BLUE%^A strong field radiates out"+
				    " from you as "+caster->QCN+" releases a wave of energy.");
				damage_targ(targets[i],targets[i]->return_target_limb(),calculate_healing(),"positive energy");
                spell_kill(target,caster);
			}
			else if(targets[i]->query_property("berserked"))
			{
				tell_object(targets[i],"%^RED%^The rage fights off the healing!%^RESET%^");
			}
			else if(targets[i] == caster)
			{
                tell_object(targets[i],"%^BOLD%^%^BLUE%^A soft blue "+
			        "glow envelopes you.");
				damage_targ(targets[i],targets[i]->return_target_limb(),(-1 * calculate_healing()),"positive energy");
			}
			else
			{
                tell_room(place,"%^BOLD%^%^BLUE%^A strong blue field radiates out"+
				    " from "+targets[i]->QCN+" as "+caster->QCN+" releases a"+
				    " wave of energy.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^BLUE%^A strong field radiates out "+
				    "from "+targets[i]->QCN+ " as you release a wave of energy.");
                tell_object(targets[i],"%^BOLD%^%^BLUE%^A strong field radiates out"+
				    " from you as "+caster->QCN+" releases a wave of energy.");
				damage_targ(targets[i],targets[i]->return_target_limb(),(-1 *calculate_healing()),"positive energy");
			}
		}
	}

	spell_successful();
    dest_effect();
    return;
}

int calculate_healing()
{
    define_base_damage(-3);
    return sdamage;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
