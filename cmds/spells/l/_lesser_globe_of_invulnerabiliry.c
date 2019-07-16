#include <spell.h>
#include <daemons.h>
inherit SPELL;

void create() 
{
    ::create();
    set_spell_name("lesser globe of invulnerability");
    set_spell_level(([ "mage" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS lesser globe of invulnerability");
    set_description("With this spell, you surround yourself with anti-magic field that disrupts intrinsic connections in the weave, briefly preventing spells of level 3 or less from entering the globe around you. This spell affects only targeted spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

