// Monster Summoning 1 - Coded by Vashkar@shadowgate
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/monster_summoning.c";

create() {
    ::create();
    set_spell_name("monster summoning 1");
    set_spell_level(([ "mage" : 1, "bard" : 1, "cleric" : 1 ]));
    set_syntax("cast CLASS monster summoning 1");
}

object createMon(){
        int chooser=random(10);
        switch (chooser) {
        case(1): return new("/d/magic/mon/kobold.c");
            break;
        case(2): return new("/d/magic/mon/gnoll.c");
            break;
        case(3): return new("/d/magic/mon/goblin.c");
            break;
        case(4): return new("/d/magic/mon/orc.c");
            break;
        case(5): return new("/d/magic/mon/hobgoblin.c");
            break;
        case(6): return new("/d/magic/mon/giantrat.c");
            break;
        case(7): return new("/d/magic/mon/giantbat.c");
            break;
        case(8): return new("/d/magic/mon/rat.c");
            break;
        case(9): return new("/d/magic/mon/bat.c");
            break;
        case(0): return new("/d/magic/mon/bandits.c");
            break;
        }
}
