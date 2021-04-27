// high level random herb pouch for use with the treasure daemon
#include <std.h>

inherit "/d/avatars/ares/herb_pouch_random.c";


void fill_me() { filled = 1; }


void create()
{
    herbs = ({ "corrupted fey lifeblood","eye of newt","nycissa orchid","spirit essence" });

    ::create();

    call_out("fill_pouch", 2, roll_dice(2, 6), roll_dice(1, 8));
    call_out("fill_me", 3);

    set_property("treasure_type", "30B");
}
