inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("shadow conjuration");
    set_spell_level(([ "mage" : 5, "bard" : 5 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow conjuration on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of a conjuration mage spell of 4th level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage shadow evocation on armor on friend>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "conjuration_summoning";
}
