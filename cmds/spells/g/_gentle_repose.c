#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("gentle repose");
    set_spell_level(([ "cleric" : 2, "mage" : 3 ]));
    set_syntax("cast CLASS gentle repose");
    set_spell_sphere("necromancy");    
    set_description("This spell preserves remains of the dead in the area, extending their decay time. Doing so effectively extends the time limit on raising that creature from the dead.");
    set_helpful_spell(1);    
}



