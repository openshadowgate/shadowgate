#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;

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

void spell_effect(int prof){
    mixed endplace;
    int power, prob;

    if (sizeof(caster->query_attackers()))
    {
        tell_object(caster,"Combat distracts you from your spell!");
        tell_room(place,caster->QCN+" is distracted by combat, spell fails.");
        dest_effect();
        return;
    }

    power = clevel>50?50:clevel;
    prob = to_int(25.0 + 65.0*(power/50.0));
    if(roll_dice(1,100)>prob)
    {
        if(!endplace=TELEPORT->scatter_destination(
               caster->query_rem_room(arg)))
            endplace = arg;
    }
    else
        endplace = arg;

    tell_object(caster,"%^MAGENTA%^%^BOLD%^You recall your destination "+
                "in your mind, focusing on it while chanting.");
    if(!(endplace=TELEPORT->teleport_object(caster,caster,endplace,clevel)))
    {
         tell_object(caster,"You sense something blocking your "+
                    "passage and lose concentration on your power.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();
        return;
    }
   
    spell_successful();
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" disappears in a bright blue flash!",caster);
    tell_room(endplace,"%^BOLD%^%^MAGENTA%^An outline of a figure appears near you.",caster);
    dest_effect();    
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

