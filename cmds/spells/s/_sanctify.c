// Ganked from rope trick/genesis for use with priest version.  -Ares
// Changed to recognize no pocket space for certain boss rooms. Dinji 10/30/2007
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

object portal;
string roomName;

void create() {
    ::create();
    set_spell_name("sanctify");
    set_spell_level(([ "cleric" : 4, "paladin" : 4, "inquisitor" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS sanctify");
    set_description("Calling on the power of his or her god, the caster creates a protected place for him or herself to "
"retreat to in times of need.  The sanctified ground is accessed through an iron gate that is created when the spell is "
"cast.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

void spell_effect(int prof) {
    if (place->query_property("no pocket space")) {
        tell_object(caster, "%^RESET%^%^CYAN%^Something is interferring with your power.");
        TO->remove();
        return 0;
    }
    tell_object(caster, "%^CYAN%^You can feel a resonance of power as"+
		" you murmer an incantation to your god.");
    tell_room(place, "%^CYAN%^"+caster->QCN+" murmurs an incantation of power.", caster);
    spell_successful();
    roomName = base_name(place);
    portal = new(SPELL_OBJ_DIR+"sanctify_gate");
    portal->set_property("spell", TO );
    portal->set_property("spelled", ({TO}) );
    portal->set_spellobj(TO);
    portal->start_magic(place, prof, roomName);
    portal->move(place);
    portal->set_diety((string)caster->query_diety());
    tell_room(place, "%^BOLD%^%^CYAN%^A concussion without sound sends ripples"+
	    " outwards and in the center of their wake is left standing a simple iron gate.");
    addSpellToCaster();
    call_out("dest_effect", (ROUND_LENGTH * 20 * clevel * prof)/100);
}

void dest_effect()
{
    if (find_call_out("dest_effect")) { remove_call_out("dest_effect"); }
     if (objectp(portal))    portal->end_magic();
    if(!objectp(place))
	place = find_object_or_load(roomName);
    tell_room(place, "%^CYAN%^The gate flickers and then winks out of existance.");
     if(objectp(portal))    portal->move(ROOM_VOID);
     if(objectp(portal))    portal->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
