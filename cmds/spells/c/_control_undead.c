//      Domination
#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit "/cmds/spells/d/_domination";

void create() {
    ::create();
    set_spell_name("control undead");
    set_spell_level(([ "mage" : 7,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS control undead on TARGET");
    set_description("By invoking this spell a necromancer confirms its domain over the undead and takes control of the unliving. Then they can use the next commands to force undead to serve:

%^ORANGE%^<make %^ORANGE%^%^ULINE%^TARGET%^RESET%^ to %^ORANGE%^%^ULINE%^ACTION%^RESET%^>%^RESET%^
  Will force the %^ORANGE%^%^ULINE%^TARGET%^RESET%^ to perform an %^ORANGE%^%^ULINE%^ACTION%^RESET%^.
%^ORANGE%^<free %^ORANGE%^%^ULINE%^TARGET%^RESET%^>%^RESET%^
  Will free the %^ORANGE%^%^ULINE%^TARGET%^RESET%^ from your control.

If the will save succeded or the target is not undead they will be outraged at your attempt and will attack immediately.

Intelligent undead creatures remember that you controlled them, and they may be slightly upset they were under your power.

%^BOLD%^%^RED%^N.B.%^RESET%^ If used on players this spell provide you only with limited subset of allowed commands.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " glides " + caster->QP + " hand from side to side while " + "chanting hypnotically.";
}

int cant_be_dominated(targ)
{
    return do_save(target, -2) ||
        target->query_property("no dominate") ||
        present("clothesx999", target) ||
        !target->is_undead();
}
