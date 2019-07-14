#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;
mixed endplace;

void create() {
    ::create();
    set_spell_name("psionic teleport");
    set_spell_level(([ "psion" : 5 ]));
    set_discipline("nomad");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS psionic teleport to <location>");
    set_description("This power will move the nomad from his current location to one he has previously memorized.  The "
"nomad merely concentrates, setting his sights on the place he would like to be, and his mind manipulates time and space "
"to place him there.  An example of the power's usage is <remember here as cave>.  Then later on, the nomad would type, "
"<cast psion psionic teleport to cave>.  Again, you may also <unremember cave> to forget that particular location. Note: "
"The teleport power is not guaranteed, and the nomad may end up in a place he did not intend.\n\nSee also: remember, "
"unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_casting_time(2);
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^GREEN%^%^BOLD%^"+caster->QCN+" focuses intently.";
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

    tell_object(caster,"%^GREEN%^%^BOLD%^You recall your destination "+
                "in your mind, focusing to bring yourself to it.");

    spell_successful();
    
    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wring with your focus and lose concentration on your power.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();

    }
    tell_room(endplace,"%^BOLD%^%^GREEN%^An outline of a figure appears near you.",caster);
    call_out("spell_effect_next",ROUND_LENGTH);
}

void spell_effect_next()
{
    if(!TELEPORT->teleport_object(caster,caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wring with your focus and lose concentration on your power.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
    }
    dest_effect();    
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

