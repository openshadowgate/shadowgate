#include <spell.h>
#include <objects.h>
#include <magic.h>
inherit SPELL;

#define DELAY 120

void create() 
{
    ::create();
    set_spell_name("exhume corpses");
    set_spell_level(([ "mage" : 6, "cleric" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS exhume corpses");
    set_description("Blep");
    set_helpful_spell(1);
    evil_spell(1);
    set_components(([
      "mage" : ([ "bit of bone" : 1, "carbon" : 1]),
    ]));    
}

string query_cast_string()
{
    tell_object(caster,"%^CYAN%^Y%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^u%^CYAN%^ close your eyes and turn around slowly, chanting a low song and dusting the ground with %^BOLD%^%^BLACK%^b%^BLACK%^o%^WHITE%^n%^BLACK%^e %^WHITE%^m%^BLACK%^e%^WHITE%^a%^BLACK%^l%^RESET%^%^CYAN%^ and %^CYAN%^c%^CYAN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^b%^CYAN%^o%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^.");
    tell_room(place,"%^CYAN%^"+caster->QCN+" closes "+caster->QP+" eyes and turns around slowly, chanting a low song and dusting the ground with %^BOLD%^%^BLACK%^b%^BLACK%^o%^WHITE%^n%^BLACK%^e %^WHITE%^m%^BLACK%^e%^WHITE%^a%^BLACK%^l%^RESET%^%^CYAN%^ and %^CYAN%^c%^CYAN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^b%^CYAN%^o%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^.",caster);
    return "display";
}

void spell_effect()
{
    int i;

    tell_room(place,"%^CYAN%^A low continuous thunder rolls over the place, and %^BOLD%^%^BLACK%^co%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^s%^CYAN%^e%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^ begin to materialize everywhere.");
    for (i=0; i<clevel; i++)
    {
        object corpse;
        corpse = new(OB_CORPSE);
        corpse->set_name("human");
        corpse->copy_body(caster);
        corpse->set_gender(({"male","female"})[random(2)]);
        corpse->set_long("%^CYAN%^Before you is an %^CYAN%^o%^CYAN%^l%^CYAN%^d %^CYAN%^c%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^s%^CYAN%^e%^CYAN%^ of a human being in tattered clothes. Its features are %^CYAN%^r%^BOLD%^%^BLACK%^ott%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^n %^BLACK%^aw%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^ and are hard to discern. It smells as disgustingly as it looks, %^BOLD%^%^WHITE%^bi%^BLACK%^t%^WHITE%^s %^BLACK%^o%^WHITE%^f %^BLACK%^b%^WHITE%^o%^BLACK%^n%^BLACK%^e%^RESET%^%^CYAN%^ peer through decayed pieces. Who it was in life is impossible to tell at this point.");
        corpse->set_short("%^CYAN%^A human corpse%^RESET%^");
        corpse->set_level(1);
        corpse->move(place);
    }
}

