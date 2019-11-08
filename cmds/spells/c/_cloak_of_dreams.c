#include <std.h>
#include <priest.h>
inherit SPELL;

int flag;

void create()
{
    ::create();
    set_spell_name("cloak of dreams");
    set_spell_level(([ "mage" : 6, "bard" : 5, "assassin" : 3]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS cloak of dreams");
    set_damage_desc("perpetually puts present livings to sleep");
    set_description("You become dreamy to look at, that is, everyone who looks at you might fall asleep if their will is weak. This spell won't have an effect if you're hidden or invisible, even if they are seeing the invisible.");
    set_save("will");
}

int preSpell()
{
    if(caster->query_property("cloak of dreams"))
    {
        tell_object(caster,"You are already under this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 2) * clevel;
    tell_room(place,"%^BLUE%^As "+caster->QCN+" sings a lullaby "+caster->QP+" visage becomes dreamy to look at.",caster);
    tell_object(caster,"%^BLUE%^You feel you're surrounded by dreams.");
    caster->set_property("cloak of dreams",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^RESET%^%^BLUE%^ (dreamy visage)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
}

void execute_attack()
{
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    room      = environment(caster);
    if(!caster->query_hidden() &&
       !caster->query_invis())
    {
        attackers = all_inventory(room);
        attackers -= ({caster});
        attackers -= caster->query_followers();
        attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
        attackers = filter_array(attackers,(:$1->is_living():));
        attackers = filter_array(attackers,(:!$1->is_undead():));
        attackers = filter_array(attackers,(:!$1->query_asleep():));
        attackers = target_filter(attackers);
        for(i=0;i<sizeof(attackers)&&i<6;i++)
        {
            if(do_save(attackers[i],4))
                continue;
            tell_room(room,"%^BLUE%^"+attackers[i]->QCN+" falls asleep looking at "+caster->QCN+".%^RESET%^",({attackers[i]}));
            tell_object(attackers[i],"%^BLUE%^You fall asleep looking at a dreamy visage of "+caster->QCN+".%^RESET%^");
            attackers[i]->set_asleep(6, "You are asleep!");
        }
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^BLUE%^The visage around "+caster->QCN+" retreats.%^RESET%^");
        caster->remove_property("cloak of dreams");
        caster->remove_property_value("added short",({"%^RESET%^%^BLUE%^ (dreamy visage)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
