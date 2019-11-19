#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define ALARM "/d/magic/obj/inv_alarm"
inherit SPELL;

object alarm;

void create()
{
    ::create();
    set_spell_name("invisibility alarm");
    set_spell_level(([ "bard" : 1, "inquisitor" : 1, "ranger" : 1, "psion":1, "mage":1 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS alarm");
    set_description("You draw an invisible alarm rune on the surface. If an alarm detects anyone hidden or invisible in the room but you and your followers it will convey a telepathic message directly into your mindYou can have as many alarms as you need, but after a while magic in them will dissipate.");
	set_helpful_spell(1);
}

void spell_effect()
{
    tell_object(caster,"%^RESET%^%^CYAN%^You touch the ground, inscribing an invisibility alarm rune onto it.");
    tell_room(place,"%^RESET%^"+caster->QCN+" thouches the ground.",({caster}));
    alarm = new(ALARM);
    alarm->move(place);
    alarm->setup(caster,TO);
    alarm->set_property("spell",TO);
    alarm->set_property("spelled", ({TO}) );
    spell_successful();
    addSpellToCaster();
    call_out("dest_effect",ROUND_LENGTH*240); //20 mins max mostly cause reasons related to room resets.
}

void dest_effect()
{
    if(objectp(alarm))
        alarm->remove_alarm();
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
