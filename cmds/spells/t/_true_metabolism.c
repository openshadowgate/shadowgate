//somewhat based on Aura of Healing by Garrett
//Circe 7/29/05
//Adjusted by ~Circe~ 1/13/16 to improve healing
#include <std.h>
#include <priest.h>

inherit SPELL;

int flag;
int lastattack;

void create()
{
    ::create();
    set_spell_name("true metabolism");
    set_spell_level(([ "psion" : 8 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS true metabolism");
    set_description("This power will allow the psion to focus his energy on making minor bodily adjustments, in effect healing himself over time. The power will gradually expend itself over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if (caster->query_property("true metabolism")) {
      tell_object(caster,"You are already under the effects of this power!");
        return 0;
    }
    return 1;
}



void spell_effect(int prof)
{
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->set_property("true metabolism",1);
    if(caster->is_class("psywarrior"))
        define_base_damage(-6);
    tell_object(caster, "%^RED%^You focus your energies so that your body will repair itself!%^RESET%^");
    if(FEATS_D->usable_feat(caster,"metabolic perfection"))
        sdamage*=5/4;
    if(!FEATS_D->usable_feat(caster,"metabolic perfection"))
        caster->set_property("spelled", ({TO}) );
    spell_successful();
    addSpellToCaster();
    environment(caster)->addObjectToCombatCycle(TO,1);
    if(!FEATS_D->usable_feat(caster,"metabolic perfection"))
        call_out("dest_effect",ROUND_LENGTH*clevel*5);

}

void execute_attack()
{
    if(!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    place = environment(caster); // In the case caster moves
    if(lastattack == time()){
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    place->addObjectToCombatCycle(TO,1);
    lastattack = time();

    if((int)caster->query_hp() < (int)caster->query_max_hp())
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^You make a mental adjustment, healing some of your wounds!%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^Some of "+caster->QCN+"'s wounds seem to heal!%^RESET%^",caster);
        damage_targ(caster,caster->return_target_limb(),-sdamage,"positive energy");
    }
}


void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("true metabolism");
        tell_object(caster,"%^CYAN%^You feel the hyper awareness of your body's injuries fade away.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
