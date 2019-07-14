#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;
mixed endplace;

void create(){
    ::create();
    set_spell_name("succor");
    set_spell_level(([ "cleric" : 9 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS succor DESTINATION");
    set_description("The succor spell will transport the priest to a location that he or she has remembered from the "
"'remembered location' list. To remember a new location, use 'remember here as <location>', to see a list of all "
"remembered locations, use 'recall locations'. This spell must be cast while at peace.

%^BOLD%^%^RED%^See also%^RESET%^: remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^MAGENTA%^You begin to whisper a quiet prayer.  "+
		"With each word of the prayer, you feel yourself growing lighter"+
		" and lighter.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" begins to whisper a quiet prayer."+
                " With each word from "+caster->QP+" prayer, "+caster->QP+" voice grows fainter.",caster);
    return "display";
}

void spell_effect(int prof) {

    int power, prob;

    power = clevel>50?50:clevel;
    prob = to_int(25.0 + 65.0*(power/50.0));
    if(roll_dice(1,100)>prob)
    {
        if(!endplace=TELEPORT->scatter_destination(
               caster->query_rem_room(arg)))
            endplace = caster->query_rem_room(arg);
    }
    else
        endplace = caster->query_rem_room(arg);

    tell_object(caster,"%^BLUE%^%^BOLD%^You recall your destination "+
                "in your mind, focusing to bring yourself to it.");

    spell_successful();
    
    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your prayer and loose concentration.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();

    }
    tell_room(endplace,"%^BOLD%^%^WHITE%^A white light grows in your vicinity.",caster);
    call_out("spell_effect_next",ROUND_LENGTH);
}

void spell_effect_next()
{
    if(!TELEPORT->teleport_object(caster,caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your prayer and loose concentration.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
    }
    dest_effect();    
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


