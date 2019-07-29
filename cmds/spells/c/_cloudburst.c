// Cloudburst - Water Domain 4/7
//Altered by ~Circe~ 5/6/08 - made to not drop weapons as 
//that's a little too powerful for a level 2 spell.  
//Rebalancing domains
//Extremely useless compared to same-level (soundburst); boosted damage to give it a useful niche. N, 02/11.

#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_author("cythera");
    set_spell_name("cloudburst");
    set_spell_level(([ "cleric" : 2 ]));
    set_spell_sphere("elemental water");
    set_spell_domain("water");
    set_syntax("cast CLASS cloudburst on TARGET");
    set_description("The spell allows the priest to gather the water in the atmosphere to form a cloud, from which he can "
"release a torrential surge of rain over the target.  As the caster grows in power, he is able to draw more moisture into "
"the cloud, creating a larger surge of water.  The target may find it difficult to retain their footing among the surge.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
     tell_object(caster,"%^BLUE%^%^As you chant through the flowing"+
        " prayer, clouds whirl into existance above your head.");
    tell_room(place,"%^BLUE%^As "+caster->QCN+" chants through a "+
        "flowing prayer, clouds whirl into existance above "+
        ""+caster->QP+" head",caster);
    return "display";
}

void spell_effect(int prof){
    int damage, i;

    if(!present(target,place)){
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

    damage = sdamage;

    tell_object(caster,"%^CYAN%^With a peal of thunder, you direct the clouds let loose a torrent of water "
"over "+target->QCN+".");
    tell_object(target,"%^CYAN%^%^BOLD%^With a peal of thunder, the clouds let loose a torrent of water that "
"comes crashing down onto you.");
    tell_room(place,"%^BOLD%^%^CYAN%^With a peal of thunder, the clouds release a torrent of water over "
+target->QCN+".",({target,caster}));
    damage_targ(target,"torso",damage,"bludgeoning");
    spell_kill(target,caster);
    if(!do_save(target,0) && random(2))
        target->set_tripped(random(2)+1,"%^CYAN%^You are knocked flat by the surging water");
    else{
        tell_object(target,"%^BOLD%^%^CYAN%^You are able to retain your footing among the raining torrent.");
        tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" is able to retain "+target->QP+" footing despite the "
"raining torrent.",target);
    }
    spell_successful();
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
