#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;
mixed endplace;

void move_caster(object endplace);

void create()
{
    ::create();
    set_spell_name("word of recall");
    set_spell_level(([ "druid" : 8 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS word of recall to <location>");
    set_description("The word of recall spell will allow a druid to travel to a location that he or she has previously "
        " remembered from the 'remembered location' list.  To remember a new location use 'remember here as <location>', to see a list of all "
        "remembered locations, use 'recall locations'.\nThis spell must be cast while at peace.\nSee also: remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_peace_needed(1);
	set_helpful_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^GREEN%^You close your eyes and concentrate, slowly fading into the essence of the world.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" closes "+caster->QP+" eyes and concentrates, slowly fading away!",caster);
    return "display";
}

void spell_effect(int prof) {

    int power, prob;

    endplace = caster->query_rem_room(arg);

    spell_successful();

    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and loose concentration.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();

    }
    call_out("spell_effect_next",ROUND_LENGTH);
}

void spell_effect_next()
{
    if(!TELEPORT->teleport_object(caster,caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and loose concentration.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
    }
    dest_effect();    
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


