// Monster Summoning 2 - Coded by Vashkar@shadowgate
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/monster_summoning.c";

create() {
    ::create();
    set_spell_name("monster summoning 2");
    set_spell_level(([ "mage" : 2, "bard" : 2, "cleric" : 2, "blackguard" : 2 ]));
    set_syntax("cast CLASS monster summoning 2");
}

object createMon(){
    int chooser=random(10);
        switch (chooser) {
        case(1):
            return new("/d/magic/mon/skeleton.c");
            break;
        case(2):
            return new("/d/magic/mon/gnoll.c");
            break;
        case(3):
            return new("/d/magic/mon/hobgoblincaptain.c");
            break;
        case(4):
            return new("/d/magic/mon/orccaptain.c");
            break;
        case(5):
            return new("/d/magic/mon/goblincaptain.c");
            break;
        case(6):
            return new("/d/magic/mon/koboldcaptain.c");
            break;
        case(7):
            return new("/d/magic/mon/eagle2.c");
            break;
        case(8):
            return new("/d/magic/mon/spider.c");
            break;
        case(9):
            return new("/d/magic/mon/wolf.c");
            break;
        case(0):
            return new("/d/magic/mon/bandits.c");
            break;
        }
}
