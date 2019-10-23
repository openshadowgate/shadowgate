#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shadow evocation");
    set_spell_level(([ "mage" : 5, "bard" : 5 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow evocation on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of a spell or your class of 4th level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage shadow evocation on fireball on goblin>");
    set_arg_needed(1);
}

int preSpell()
{
    int max_level = query_spell_level(spell_type) - 1;
    int slevel;
    object spell_to_cast;
    string spl, sargs;
    string splfn;

    if(!stringp(arg))
    {
        tell_object(caster,"You must provide arguments to this spell!");
        return 0;
    }

    if(sscanf(arg, "%s on %s", spl, sargs)<1)
    {
        tell_object(caster,"You must provide arguments to this spell!");
        return 0;
    }

    spl = replace_string(spl, " ", "_");
    splfn = "/cmds/spells/"+spl[0..0]+"/_"+spl+".c";

    if(!file_exists(splfn))
	{
        tell_object(TP,"Either that spell does not exist, or you do not know it!");
        return 0;
    }

    spell_to_cast = new(splfn);
    slevel = spell_to_cast->query_spell_level(spell_type);
    if(slevel > max_level || slevel == 0)
    {
        tell_object(TP,"This spell is too powerful for shadow evocation!");
        return 0;
    }

    spell_to_cast->use_spell(TP,sargs,clevel,100,spell_type);
    dest_effect();
    return 1;

}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
