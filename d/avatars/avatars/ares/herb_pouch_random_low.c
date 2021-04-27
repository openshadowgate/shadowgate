// low level random herb pouch for use with the treasure daemon
#include <std.h>

inherit "/d/avatars/ares/herb_pouch_random.c";


void fill_me() { filled = 1; }


void create()
{
    herbs = ({ "bone dust","reptile scales","fur","peryton talon","spiderweb","werebeast fang" });

    ::create();

    call_out("fill_pouch", 2, roll_dice(3, 6), roll_dice(1, 4));
    call_out("fill_me", 3);

    set_property("treasure_type", "10B");
}
