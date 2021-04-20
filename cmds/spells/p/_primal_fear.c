#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit "/cmds/spells/c/_cause_fear";

void create() {
    ::create();
    set_spell_name("primal fear");
    set_spell_level(([ "psywarrior" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS primal fear on TARGET");
    set_description("This power allows the psionic character to project "
                    "an aura of fear toward a target, potentially sending him fleeing "
                    "or causing him to cower in terror.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string(){
    return "%^RESET%^%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}
