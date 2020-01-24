#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;
object weap;

void create()
{
    ::create();
    set_spell_name("align weapon");
    set_spell_level(([ "inquisitor" : 2, "cleric" : 2 ]));
    set_spell_sphere("alteration");
    set_domains(({"good", "evil"}));
    set_syntax("cast CLASS align weapon on WEAPON versus good|evil|chaos|law");
    set_damage_desc("divine");
    set_description("Align weapon makes a weapon chaotic, evil, good, or lawful. You must belong to opposite alignment group to align a weapon. A weapon that is aligned can bypass the damage reduction of creatures of opposite alignment group. Effects of this spell are permanent, but can be owerwritten by another spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf, weapstr, alignstr;
    object targ;

    if (sscanf(arg, "%s versus %s", weapstr, alignstr) != 2) {
        tell_object(caster,"Syntax" + query_syntax());
        dest_effect();
        return;
    }

    if (!regexp(alignstr, "good|evil|chaos|law")) {
        tell_object(caster,"Syntax" + query_syntax());
        dest_effect();
        return;
    }

    if (!objectp(targ)) {
        tell_object(caster, "Cant find " + arg + " in your inventory!");
        TO->remove();
        return;
    }

    if (!targ->is_weapon()) {
        tell_object(caster, "That is not a weapon!");
        TO->remove();
        return;
    }

    if (targ->query_property("temp_hit_bonus")) {
        tell_object(caster, "This weapon is already engulfed with magic!");
        TO->remove();
        return;
    }

    switch (alignstr) {
    case "good":
        if (member_array(caster->query_true_align(), ({ 3, 6, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "evil":
        if (member_array(caster->query_true_align(), ({ 1, 4, 7 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "law":
        if (member_array(caster->query_true_align(), ({ 7, 8, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "chaos":
        if (member_array(caster->query_true_align(), ({ 1, 2, 3 })) == -1) {
            wrong_align();
            return;
        }
        break;
    }

    targ = present(weapstr, caster);

    if (objectp(targ)) {

        switch (alignstr) {
        case "good":
            targ->set_property("aligned_weapon", ({ 1, 4, 7 }));
            break;
        case "evil":
            targ->set_property("aligned_weapon", ({ 3, 6, 9 }));
            break;
        case "law":
            targ->set_property("aligned_weapon", ({ 1, 2, 3 }));
            break;
        case "chaos":
            targ->set_property("aligned_weapon", ({ 7, 8, 9 }));
            break;
        }

        tell_object(caster, "%^CYAN%^Chanting in low undertones you move hand over " + targ->query_name() + ", infusing it with energy.");

        addSpellToCaster();
    }
}

void wrong_align()
{
    tell_object(caster,"You're not of appropriate alignment to use this argument!");
}
