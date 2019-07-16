#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HOUND "/d/magic/mon/spectral_hound"
inherit SPELL;

object hound;

void create()
{
    ::create();
    set_spell_name("faithful hound");
    set_spell_level(([ "mage" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS faithful hound");
    set_description("With this spell you conjure up an invisible spectral dog. It will stay in the area for a while and bark if someone approaches. If attacked, it will defend itself, and if someone attacks you it will defend you as well.");
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" stretches "+caster->QP+" arms outward, chanting sonorously.";
}

void spell_effect()
{
    tell_object(caster,"%^RESET%^%^CYAN%^You wave your hand and spectral hound appears, fatefully guarding the area.");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ waves "+caster->QP+" hand, but nothing seems to happen");
    hound = new(HOUND);
    hound->move(place);    
    hound->setup(caster,clevel);

    hound->set_property("spell",TO);
    hound->set_property("spelled", ({TO}) );
    spell_successful();
    call_out("dest_effect",ROUND_LENGTH*4); //20 mins max cause reasons;
}

void dest_effect()
{
    if(objectp(hound))
        hound->remove_hound();
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

