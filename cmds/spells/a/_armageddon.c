#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("armageddon");
    set_spell_level(([ "innate" : 1 ]));
    set_syntax("cast innate armageddon");
    set_description("This spell kills everyone online.");
}

spell_effect(int prof)
{

    spell_successful();
    filter_array(users(),(:!avatarp($1):))->die();
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
