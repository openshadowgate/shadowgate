#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

#define DELAY 300

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

