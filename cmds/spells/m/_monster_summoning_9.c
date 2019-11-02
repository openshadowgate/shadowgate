#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_1.c";

create() {
    ::create();
    set_spell_name("monster summoning 9");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_sorc_bloodlines(({"abyssal"}));
    set_syntax("cast CLASS monster summoning 9");
}
