#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("circle of death");
    set_spell_level(([ "mage" : 6, "cleric" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS circle of death");
    set_description("The caster draws a circle around herself and channels negative energy ourwards, destroying undead creatures that are not able to withstand it, but not affecting at all those of the strong will.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" draws a circle of darkness around "+caster->QP+"self.";
}

void spell_effect(int prof)
{
    object *foes, foe;

    tell_object(caster,"%^BOLD%^%^BLUE%^As you finish drawing a circle of life, you channel energy out of it.");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" channels blinding energy out of the circle of darkness.",caster);

    foes = all_living(place);
    foes = filter_array(foes, "is_non_immortal",FILTERS_D);
    foes = target_filter(foes);

    foreach(foe in foes)
    {
        if(do_save(foe,8) ||
           foe->query_property("no death") ||
           ((string)foe->query_race() == "undead") ||
           foe->query_property("undead"))
        {
            tell_object(foe,"%^BLUE%^%^BOLD%^The darkness washes over you, but nothing happens!");
            tell_room(place,"%^BLUE%^%^BOLD%^"+foe->QCN+" seems to be unaffected by the fell powers!",foe);
            continue;
        }
        tell_object(foe,"%^BLUE%^%^BOLD%^Your life ends, as negative energy destroys your very soul!");
        tell_room(place,"%^BLUE%^%^BOLD%^"+foe->QCN+" crumbles to dust!",foe);
        damage_targ(foe, foe->query_target_limb(),foe->query_max_hp()*2,"negative energy");
    }

    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
