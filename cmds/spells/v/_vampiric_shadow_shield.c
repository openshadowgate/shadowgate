#include <std.h>
#include <priest.h>
inherit SPELL;

int timer,flag,stage,toggle,counter;

void create()
{
    ::create();
    set_spell_name("vampiric shadow shield");
    set_spell_level(([ "mage" : 5, "assassin" : 3]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS vampiric shadow shield");
    set_damage_desc("negative energy on living");
    set_description("You raise shadows of the undead to guard you from those who mean you harm. Up to six livings that attack you will be harmed and its essence will be used to heal you.");
    set_save("reflex");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
    return "%^BLUE%^As "+caster->QCN+" chants in low undertones shadows raise and surround "+caster->QO+".%^RESET%^";
}

int preSpell()
{
    if(caster->query_property("vampiric shadow shield"))
    {
        tell_object(caster,"You are already protected by this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place,"%^BLUE%^"+caster->QCN+" completes "+caster->QP+" the chant and is surrounded by restless shadows.",caster);
    tell_object(caster,"%^BLUE%^You complete your chant and are surrounded by restless shadows!");
    caster->set_property("vampiric shadow shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^BLUE%^ (%^BOLD%^%^BLACK%^engulfed in shadows%^RESET%^%^BLUE%^)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    counter = 6*clevel;
}

void execute_attack()
{
    object *attackers,room;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = ENV(caster);
    if(!objectp(caster) || !objectp(place) || counter<0)
    {
        dest_effect();
        return;
    }

    attackers = caster->query_attackers();
    attackers = filter_array(attackers,(:!$1->is_undead():));

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(place,"%^BLUE%^Shadows around "+caster->QCN+" caress "+caster->QP+" enemies as!",({caster,target}));
        tell_object(caster,"%^BLUE%^%^Shadows around you caress your enemies.");
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i]))
                continue;
            if(do_save(attackers[i],0))
                continue;

            tell_object(attackers[i],"%^BLUE%^You are caressed by the shield of shadows as you strike "+caster->QCN+"!");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage/2,"negative energy");
            if(i<8)
                caster->add_hp(sdamage/16);
        }
    }
    place->addObjectToCombatCycle(TO,1);
    counter--;
}

void dest_effect(){
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^BLUE%^The shadows retreat, leaving "+caster->QCN+" vulnerable once again.");
        caster->remove_property("vampiric shadow shield");
        caster->remove_property_value("added short",({"%^BLUE%^ (%^BOLD%^%^BLACK%^engulfed in shadows%^RESET%^%^BLUE%^)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
