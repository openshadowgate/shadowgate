//      Teleport
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit SPELL;

string maindir;

void create() {
    ::create();
    set_spell_name("teleport");
    set_spell_level(([ "mage" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS teleport to <location>");
    set_description("The teleport spell will move the caster from his current location to a specified 'remembered "
"location'.  The remember command is used to retain a location in the caster's memory, <remember here as cave> for example"
".  Then the caster can type <cast classname teleport to cave> and the the spell will move the caster to the location "
"specified.  Be warned, however.  This powerful spell of teleport is not always without error.  The caster may end up far "
"from where he/she intended to teleport to. You may also <unremember location> which will remove a specific location from "
"memory.\nThis spell can only be cast while at peace.\nSee also: remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_casting_time(2);
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string() {
    return "%^CYAN%^%^BOLD%^"+caster->QCN+" chants rapidly.";
}

void spell_effect(int prof) {
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
               TELEPORT->get_room_from_memory(caster,arg)))
            endplace = arg;
    }
    else
        endplace = arg;

    tell_object(caster,"%^BLUE%^%^BOLD%^You recall your destination "+
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
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" disappears in a bright blue flash!",caster);
    tell_room(endplace,"%^BOLD%^%^BLUE%^An outline of a figure appears near you.",caster);
    dest_effect();    
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

