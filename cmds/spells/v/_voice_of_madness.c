#include <spell.h>
#include <daemons.h>
inherit "/cmds/spells/s/_scintillating_pattern";

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("voice of madness");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("illusion");
    set_damage_desc("mass confusion");
    set_syntax("cast CLASS voice of madness on TARGET");
    set_description("This invocation will call upon beings beyond, unfathomable and terrifying, to whisper in the ears "
                    "of the target. A weak-willed target will become overwhelmed by the maddening voices, and may babble incoherently, attack "
                    "the closest thing to them, or simply wander away.  When used on a player, it simply causes them to stand and stare blankly.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster, "%^GREEN%^You whisper the words of the invocation under your breath.%^RESET%^");
    tell_room(place, "%^GREEN%^" + caster->QCN + " whispers under " + caster->QP + " breath.%^RESET%^", caster);
    return "display";
}
