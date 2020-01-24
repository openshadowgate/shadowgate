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
    set_description("Align weapon makes a weapon chaotic, evil, good, or lawful, as you choose. A weapon that is aligned can bypass the damage reduction of creatures of opposite alignment group.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf, weapstr;
    object targ;

    targ = present(arg,caster);

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

    if(objectp(targ))
    {
        mapping info = ([]);

        targ->set_property("aligned_weapon",info);

        weap = targ;

        tell_object(caster, "%^CYAN%^A layer of a%^BOLD%^rca%^RESET%^%^CYAN%^n%^BOLD%^e %^RESET%^%^CYAN%^f%^BOLD%^l%^RESET%^%^CYAN%^a%^BOLD%^me%^RESET%^%^CYAN%^s appears on %^WHITE%^"+targ->query_name()+" %^CYAN%^as you move your hand along it.");
        tell_room(place, "%^CYAN%^A layer of a%^BOLD%^rca%^RESET%^%^CYAN%^n%^BOLD%^e %^RESET%^%^CYAN%^f%^BOLD%^l%^RESET%^%^CYAN%^a%^BOLD%^me%^RESET%^%^CYAN%^s appears on %^WHITE%^"+targ->query_name()+" %^CYAN%^as %^GREEN%^"+caster->QCN+" %^CYAN%^moves %^GREEN%^"+caster->QP+" %^CYAN%^hand along it.",({caster}));
        targ->set_property("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^ablaze%^BOLD%^}%^RESET%^" }));
        addSpellToCaster();
    }
}
