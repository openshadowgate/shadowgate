#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("distressing tone");
    set_spell_level(([ "bard" : 2, "inquisitor" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS distressing tone");
    set_damage_desc("mass sickening");
    set_description(".");
    set_save("fort");
    splash_spell(1);
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = all_living(place);
    attackers = filter_array(attackers, "is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);


    if(!sizeof(attackers)){
        tell_object(caster,"%^CYAN%^Tonal vibrations affect nobody.%^RESET%^");
        dest_effect();
        return;
    }

    tell_room(place,"%^CYAN%^Sickening low tone hits everyone present.%^RESET%^");

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(!do_save(attackers[i],2))
            "/std/effect/status/sickened"->apply_effect(attackers[i],clevel/6 + 1);
    }
    spell_successful();
}
