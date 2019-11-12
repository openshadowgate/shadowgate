#include <priest.h>

inherit SPELL;

int counter;

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
    traveling_aoe_spell(1);
    set_heart_beat(1);
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

int preSpell() {
    if (caster->query_property("aura_of_healing")) {
      tell_object(caster,"You are already under the effects of this spell!");
        return 0;
    }
    counter = clevel*10 + 4;
    return 1;
}

void spell_effect(int prof)
{
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->set_property("aura_of_healing",1);
    tell_object(caster, "%^CYAN%^You feel a magical aura of energy from your "+
        "god surround you!%^RESET%^");
    caster->set_property("spelled", ({TO}) );
    spell_successful();
    addSpellToCaster();
    counter = clevel*10 + 4;
}

void heart_beat()
{
    object *people;
    object dude;
    int i;

    if(!objectp(caster) || !objectp(environment(caster)) || counter<0){
        dest_effect();
        return;
    }

    place = environment(caster); // In the case caster moves

    people = ({});

    if(caster->query_party())
    {
        object *party;
        party = PARTY_D->query_party_members(caster->query_party());
        if(sizeof(party))
            for(i=0;i<sizeof(party);i++)
            {
                if(environment(party[i]) == environment(caster))
                    people += ({ party[i] });
            }
    }
    if(member_array(caster,people)==-1)
        people+=({caster});

    define_base_damage(0);//lazy reroll
    if(sizeof(people))
        foreach(dude in people)
        {
            if((int)dude->query_hp() < (int)dude->query_max_hp())
            {
                tell_object(dude,"%^CYAN%^The magical energy adds a bit of strength to you!%^RESET%^");
                tell_room(place,"%^CYAN%^Some of "+dude->QCN+"'s wounds seem to heal!%^RESET%^",caster);
                damage_targ(dude,dude->return_target_limb(),-sdamage,"untyped");
            }
        }
    counter --;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("aura_of_healing");
        tell_object(caster, "%^CYAN%^You feel the magical aura of energy from your "+
            "god subside!%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
