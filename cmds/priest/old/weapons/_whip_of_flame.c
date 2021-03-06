// Whip of Flame

#include <std.h>

inherit SPELL;

object whip;

create() {
    ::create();
    set_spell_name("whip of flame");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("loviatar");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^RED%^%^BOLD%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls for Loviatar's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A whip formed from fire appears in your hand.");
        tell_room(place,"%^RED%^A whip made of flames appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    whip = new("/d/magic/obj/flamewhip");
    whip->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield whip of flames");
    spell_successful();
    call_out("dest_effect",clevel*8);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(whip) && objectp(caster)) {
        //caster->force_me("unwield whip of flames");
        tell_object(caster,"%^BOLD%^The whip of flames disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^RED%^The whip disappears from "+caster->query_cap_name()+"'s hand.",caster);
        whip->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Whip of Flame
Level  : 2nd Level
Sphere : Combat
Deity  : Loviatar
Syntax : chant whip of flame

This spell will create a whip-shaped formation of pure
flames that will appear in the caster's hand.
HELP
);
    return 1;
}
