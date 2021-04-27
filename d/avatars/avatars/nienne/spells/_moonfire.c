// repainted fireball!
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int clevel,effect,damage,x,i,y;
string tmp,YOU,HIM;
object caster,target,place,victim,tempob,*foes,*oldfoes,*tempfoes,*watchers,*allies;
void damage();

void create() {
    ::create();
    set_spell_name("moonfire");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast <classname> moonfire on <target>");
    set_description("This is a divine variant granted by Eilistraee.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "bat guano":1, "sulfur":1, ]),
    ]));
    set_immunities( ({"fire"}) );
    set_save("reflex");
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" %^BOLD%^%^WHITE%^extends a hand towards "+target->QCN+"%^BOLD%^%^WHITE%^.%^RESET%^";
}

spell_effect(int prof) {
    caster = CASTER;
    target = TARGET;
    place = PLACE;
    clevel = CLEVEL;
    YOU=caster->query_cap_name();

    if(!present(target,caster->is_room()?caster:environment(caster))){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();
    if ( !interactive(caster) && !caster->query_invis() )
        YOU=caster->query_cap_name();
    HIM=target->query_cap_name();
    if(!living(caster)) {
        foes = all_living(environment(target));
        foes = filter_array(foes, "is_non_immortal",FILTERS_D);
    } else {
        foes=caster->query_attackers();
    }
    if (member_array(target,foes) != -1)
        foes -= ({ target});
    
    if(FEATS_D->usable_feat(caster,"perfect caster"))
    {
        foes = filter_array(foes,"perfect_filter",TO);
    }

    tmp="";
    if (interactive(caster))
        tmp="'s palm";
    tell_object(target,"%^BOLD%^%^CYAN%^A blue-white ball of flame appears above "+YOU+tmp+", growing rapidly as a flick of "+caster->QP+" wrist sends it directly at you!%^RESET%^");
    if(living(caster)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^A blue-white ball of flame appears above your palm, growing rapidly as you cast it with a flick of your wrist at "+HIM+"!%^RESET%^");
    }
    tell_room(place, "%^BOLD%^%^CYAN%^A blue-white ball of flame appears above "+YOU+tmp+", growing rapidly as a flick of "+caster->QP+" wrist sends it directly at "+HIM+"!%^RESET%^",({ caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^The ball of moonfire explodes into you!%^RESET%^");
    tell_room(environment(target),"%^BOLD%^%^WHITE%^The ball of moonfire explodes into "+target->QCN+"!%^RESET%^",target);
    oldfoes=foes;
    foes = ({});
    allies = ({});
    y=2+to_int((clevel-5)/2);
    if (sizeof(oldfoes) < y)
        y = sizeof(oldfoes);
    for (x=0;x < y;x++) {
        tempob=oldfoes[random(sizeof(oldfoes))];
	if(do_save(tempob))
            allies += ({ tempob});
        else
            foes += ({ tempob});
        oldfoes -= ({ tempob});
    }
    y=clevel;
/*
    if(y>10)
        y=10;
*/
    damage=0;
    for (i=0;i < y;i++)
        damage += (( 1 + random(6) )*prof)/100;
	if(do_save(target))
        damage_targ(target, "torso", to_int(damage / 2),"fire" );
    else
        damage_targ(target, "torso", damage,"fire" );
    for (x=0;x < sizeof(foes);x++) {
        if (!objectp(foes[x])) continue;
        tell_room(environment(foes[x]),"%^RESET%^%^CYAN%^The blast of the explosion smashes into "+foes[x]->QCN+"!%^RESET%^",foes[x]);
        tell_object(foes[x],"%^RESET%^%^CYAN%^The blast of the explosion smashes into you!%^RESET%^");
        if(do_save(foes[x]))
            damage_targ(foes[x], "torso", to_int(damage / 2),"fire" );
        else
            damage_targ(foes[x], "torso", damage,"fire" );
    }
    damage = damage/2;
    for (x=0;x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
        tell_room(environment(allies[x]),"%^RESET%^%^CYAN%^The blast singes "+allies[x]->QCN+"!%^RESET%^",allies[x]);
        tell_object(allies[x],"%^RESET%^%^CYAN%^The blast of the explosion singes you!%^RESET%^");
	if(do_save(allies[x]))
            damage_targ(allies[x], "torso", to_int(damage / 2),"fire" );
        else
            damage_targ(allies[x], "torso", damage,"fire" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}