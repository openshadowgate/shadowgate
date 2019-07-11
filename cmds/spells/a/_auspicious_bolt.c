//_luckbolt.c
//Removing delay to bring it more in line with other
//domain spells ~Circe~ 4/24/08

#include <std.h>
#include <priest.h>
//#define DELAY 1200

inherit SPELL;
int counter;
int flag;
int mybonus, newhp;

void create() 
{
    ::create();
    set_spell_name("auspicious bolt");
    set_spell_level(([ "cleric" : 3 ]));
    set_spell_sphere("combat");
    set_spell_domain("fate");
    set_syntax("cast CLASS auspicious bolt on TARGET");
    set_description("This spell will call on the fates to improve the fortune of the recipient in battle.  To what degree "
        "the fortunes are altered in favor of the target depends on the level of the caster, and of course fate itself.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^BLUE%^%^Crossing your arms before you,"+
        " you begin to intone a quick prayer.");
    tell_room(place,"%^BOLD%^%^BLUE%^Crossing "+caster->QP+" arms before "+
        ""+caster->QO+","+caster->QCN+" begins to intone a quick"+
        " prayer.",caster);
    return "display";
}

int preSpell() 
{
    if (target->query_property("luckbolted")) 
    {
        tell_object(caster,"Your target is already blessed with the luck of Tymora.");
        return 0;
    }
/*
    if ((int)target->query_property("luckbolt time")+DELAY > time()) {
        tell_object(caster,"Your target already has their fortune altered.");
        return 0;
    }
*/
    return 1;
}


void spell_effect(int prof) 
{
    int clevel,mybonus;
    clevel = CLEVEL;
    newhp = random(clevel)+1;
    mybonus = random(clevel/10)+1;
    if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" is suddenly surrounded"+
            "by an iridescent aura!",caster);
        tell_object(target,"%^BOLD%^%^BLUE%^You feel your fate shifting!");
    }
    else
    {
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" points "+caster->QP+" "+
            "palm at "+target->QCN+" and an iridescent bolt flies forth, "+
           "striking "+target->QO+"!",({target,caster}));
        tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" points "+caster->QP+" "+
            "palm at you and an iridescent bolt flies forth, striking you!"+
            "\n %^CYAN%^You feel your fate shifting!");
        tell_object(caster,"%^BOLD%^%^BLUE%^You point the palm of your hand "+
            "at "+target->QCN+" and feel luck surge through you, striking"+
           " "+target->QO+" in an iridescent bolt!");
    }
    target->add_extra_hp(newhp);
    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    target->set_property("luckbolted",1);
    target->set_property("spelled", ({TO}) );
//    target->set_property("luckbolt time",time());
    spell_successful();
    addSpellToCaster();
}

void execute_attack()
{
    if (!flag) 
    {
        ::execute_attack();
        flag = 1;
        return;
    }
    
    if (!objectp(target)) 
    {
        dest_effect();
        return;
    }
    tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" is surrounded by a surge of energy.", target);
    tell_object(target,"%^BOLD%^%^BLUE%^You are surrounded by iridescent energy.");
    target->add_attack_bonus(-1 * mybonus);
    target->add_damage_bonus(-1 * mybonus);
    mybonus = random(clevel/10)+1;
    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    counter++;
    if (counter > clevel) 
    {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO,1);
}

void dest_effect()
{
    if (objectp(target)) 
    {
        target->add_extra_hp(-1* newhp);
        if ((int)target->query_extra_hp() < 0) 
        {
            target->add_extra_hp(-1 * (int)target->query_extra_hp());
        }
        target->add_attack_bonus(-1 * mybonus);
        target->add_damage_bonus(-1 * mybonus);
        target->remove_property("luckbolted");
        tell_object(target,"%^BOLD%^%^BLUE%^The energy around you fades away.");
        tell_room(place,"%^BOLD%^%^BLUE%^The iridescent force around "+target->QCN+" fades away.", target);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}