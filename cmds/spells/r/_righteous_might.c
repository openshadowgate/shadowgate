#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create(){
    ::create();
    set_author("circe");
    set_spell_name("righteous might");
    set_spell_level(([ "cleric" : 2 ,]));
    set_spell_sphere("alteration");
    set_spell_domain("strength");
    set_syntax("cast CLASS righteous might");
    set_description("By calling upon his deity's aid, the caster imbues himself with divine might.  The caster will find "
"it both easier to hit and to harm those he fights.  The spell does not stack with other bless-type spells.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell(){
    if(!target) { target = caster; }
    if(target->query_property("blessed") || target->query_property("blighted")){
        tell_object(caster,"%^BOLD%^%^BLUE%^Your target is already "+
           "gifted with a similar spell.%^RESET%^");
        return 0;
//won't stack with bless or blight
    }
    return 1;
}

void spell_effect(int prof){
    int duration;

    target = caster; // switching to self-cast only, balanced as per strength of stone.
    duration = (ROUND_LENGTH * 20) * clevel;
    bonus = (clevel/15)+1;
    if(bonus > 4) bonus = 4;

//    if(target == caster){
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" calls out "+
           "in a booming voice for "+caster->QP+" deity's aid, and "+
           "raw %^RED%^power%^BLUE%^ radiates from "+caster->QO+"!%^RESET%^",target);
        tell_object(target,"%^BOLD%^%^BLUE%^With a booming voice, "+
           "you call for "+(string)caster->query_diety()+"'s aid and feel %^RED%^power "+
           "%^BLUE%^flooding your sinews!%^RESET%^");
/*    }else{
        tell_object(caster,"%^BOLD%^%^BLUE%^With a booming voice, "+
           "you call for "+(string)caster->query_diety()+"'s aid "+
           "and send %^RED%^power %^BLUE%^flooding into "+target->QCN+"!%^RESET%^");
    	  tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" calls out "+
           "in a booming voice for "+caster->QP+" deity's aid, "
           "and you feel %^RED%^power %^BLUE%^flooding your sinews!%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" calls out "+
           "in a booming voice for "+caster->QP+" deity's aid, and "+
           "raw %^RED%^power%^BLUE%^ floods into "+target->QCN+"!%^RESET%^",({target,caster}));
    }*/
    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    target->set_property("empowered",bonus);
    addSpellToCaster();
    target->set_property("spelled",({TO}));
    target->set_property("blessed",1); //using this property so it won't stack with similar spells
    call_out("dest_effect",duration);
    spell_successful();
}

void dest_effect(){
    if(objectp(target)){
        tell_object(target,"%^CYAN%^You feel weak as the power "+
           "granted you fades away.%^RESET%^");
        target->add_damage_bonus(-1*bonus);
        target->add_attack_bonus(-1*bonus);
        target->set_property("empowered",(-1*bonus));
        target->set_property("blessed",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
