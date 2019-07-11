// Monster Summoning 2 - Coded by Vashkar@shadowgate
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05
// removed satyrs as a choice since they stun the caster as well as the
// rest of the room. Will figure out a fix later. ~Circe~ 5/4/11

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/monster_summoning.c";

create() {
    ::create();
    set_spell_name("monster summoning 7");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_syntax("cast CLASS monster summoning 7");
}

object createMon(){
    int chooser=random(9);
        switch (chooser) {
        case(1):
            return new("/d/magic/mon/basilisk.c");
            break;
        case(2):
            return new("/d/magic/mon/korred.c");
            break;
        case(3):
            return new("/d/magic/mon/behir.c");
            break;
        case(4):
            return new("/d/magic/mon/bulette.c");
            break;
/*        case(5):
            return new("/d/magic/mon/satyr.c");
            break;
*/
        case(5):
            return new("/d/magic/mon/chimera.c");
            break;
        case(6):
            return new("/d/magic/mon/hydra12.c");
            break;
        case(7):
            return new("/d/magic/mon/bbear.c");
            break;
        case(8):
            return new("/d/magic/mon/umber_hulk.c");
            break;
        case(0):
            return new("/d/magic/mon/troll.c");
            break;
        }
}
