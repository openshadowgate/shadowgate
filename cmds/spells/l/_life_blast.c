#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("life blast");
    set_spell_level(([ "ranger" : 3, "druid" : 4 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS life blast");
    set_damage_desc("positive energy damage or death to undead");
    set_description("The caster draws upon and absorbs the latent life force in the area to cause a blast of positive energy, harming or killing undead that are nearby.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(3);
}

string query_cast_string() {
    return "%^BOLD%^%GREEN%^"+caster->QCN+" draws in the life energy around "+caster->QP+"self.";
}

void spell_effect(int prof)
{
    object* foes, foe;
    int max;

    tell_object(caster, "%^BOLD%^%^GREEN%^As you finish drawing in life energy, you channel that energy outward.");
    tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " channels life energy outward.", caster);

    foes = target_selector();
    foes = target_filter(foes);
    foes = shuffle(foes);

    max = clevel * 2;

    foreach(foe in foes)
    {
        if (!foe->is_undead()) {
            continue;
        }

        if (do_save(foe, 2) ||
            foe->query_level() > caster->query_level() ||
            foe->query_level() > clevel
            ) {
            tell_object(foe, "%^ORANGE%^%^BOLD%^The light washes over you, but nothing happens!");
            continue;
        }

        max -= foe->query_level();

        tell_object(foe, "%^ORANGE%^%^BOLD%^Your unlife ends, as positive energy destroys your essence!");
        tell_room(place, "%^ORANGE%^%^BOLD%^" + foe->QCN + " crumbles to dust!", foe);
        damage_targ(foe, foe->return_target_limb(), foe->query_max_hp() * 2, "positive energy");
    }

    spell_successful();
    dest_effect();
}
void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
