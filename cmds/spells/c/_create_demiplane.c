#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int mylevel;
object portal;
string roomName;

void create() {
    ::create();
    set_spell_name("create demiplane");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS genesis");
    set_description("");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof)
{
    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }
    if (place->query_property("no pocket space")) {
        tell_object(caster, "Something is interferring with your power.");
        if(objectp(TO)) TO->remove();
        return 0;
    }
    portal = new("/d/magic/obj/demiplane_portal");

    //messages here

    spell_successful();
    roomName = base_name(place);
    portal->set_property("spell", TO );
    portal->set_property("spelled", ({TO}) );
    portal->set_spellobj(TO);
    portal->start_magic(place,roomName);
    portal->move(place);

    //Portal poofs in message

    addSpellToCaster();
}

void dest_effect() {
	if(!objectp(portal))
	{
		::dest_effect();
        if(objectp(TO))
            TO->remove();
		return;
	}

    portal->end_magic();
    if(!objectp(place))
        place = find_object_or_load(roomName);

    //Poof message

    portal->move(ROOM_VOID);
    portal->remove();

    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
