#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_1.c";

create() {
    ::create();
    set_spell_name("monster summoning 2");
    set_spell_level(([ "mage" : 2, "bard" : 2, "cleric" : 2, "paladin" : 2 ]));
    set_syntax("cast CLASS monster summoning 2");
}
