// Monster Summoning 2 - Coded by Vashkar@shadowgate
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/monster_summoning.c";

create() {
    ::create();
    set_spell_name("monster summoning 6");
    set_spell_level(([ "mage" : 6, "bard" : 6, "cleric" : 6 ]));
    set_syntax("cast CLASS monster summoning 6");
}

object createMon(){
    int chooser=random(10);
        switch (chooser) {
        case(1):
            return new("/d/magic/mon/bugbear.c");
            break;
        case(2):
            return new("/d/magic/mon/hydra10.c");
            break;
        case(3):
            return new("/d/magic/mon/manticore.c");
            break;
        case(4):
            return new("/d/magic/mon/ogre1.c");
            break;
        case(5):
            return new("/d/magic/mon/ogre2");
            break;
        case(6):
            return new("/d/magic/mon/wspider.c");
            break;
        case(7):
            return new("/d/magic/mon/ehater.c");
            break;
        case(8):
            return new("/d/magic/mon/troll.c");
            break;
        case(9):
            return new("/d/magic/mon/cguard.c");
            break;
        case(0):
            return new("/d/magic/mon/python.c");
            break;
        }
}
