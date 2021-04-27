// mid level random herb pouch for use with the treasure daemon
#include <std.h>

inherit "/d/avatars/ares/herb_pouch_random.c";


void fill_me() { filled = 1; }


void create()
{
    herbs = ({ "dream fragment","breath of winter","living stone","patch of demonskin","tendril of flame" });
    
    ::create();

    call_out("fill_pouch", 2, roll_dice(4, 6), roll_dice(1, 6));
    call_out("fill_me", 3);

    set_property("treasure_type", "20B");
}
