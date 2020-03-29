#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit "/cmds/spells/d/_domination";

int duration, change, quitting;
object clothes, remote;

void create() {
    ::create();
    set_spell_name("infiltrator");
    set_spell_level(([ "classless" : 9, ])); // mage 9
    set_spell_sphere("enchantment_charm");
    set_domains(({}));
    set_syntax("cast CLASS infiltrator on TARGET");
    set_description("

");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_scloth()
{
    return "/d/magic/obj/sclothes_infiltrator";
}
