#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit "/cmds/spells/n/_necrotic_burst";

string element;

void create()
{
    ::create();
    set_spell_name("orb of the void");
    set_spell_level(([ "mage" : 8,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS orb of the void on TARGET");
    set_description("This spells represents necromancer's ability to channel negative energies. You will open a huge rip in fabric of the reality near your target and it will release burst of pure negative energy, directed at your enemies near it.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}
