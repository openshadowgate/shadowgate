// Monster Summoning 2 - Coded by Vashkar@shadowgate
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/monster_summoning.c";

create() {
    ::create();
    set_spell_name("monster summoning 3");
    set_spell_level(([ "mage" : 3, "bard" : 3, "cleric":3,"blackguard":3 ]));
    set_syntax("cast CLASS monster summoning 3");
}

object createMon(){
    int chooser=random(10);
        switch (chooser) {
        case(1):
            return new("/d/magic/mon/bugbear.c");
            break;
        case(2):
            return new("/d/magic/mon/cguard2.c");
            break;
        case(3):
            return new("/d/magic/mon/gscorpion.c");
            break;
        case(4):
            return new("/d/magic/mon/ogre.c");
            break;
        case(5):
            return new("/d/magic/mon/spider2.c");
            break;
        case(6):
            return new("/d/magic/mon/gnome.c");
            break;
        case(7):
            return new("/d/magic/mon/eguard.c");
            break;
        case(8):
            return new("/d/magic/mon/gen_snake.c");
            break;
        case(9):
            return new("/d/magic/mon/wolf2.c");
            break;
        case(0):
            return new("/d/magic/mon/cguard.c");
            break;
        }
}
