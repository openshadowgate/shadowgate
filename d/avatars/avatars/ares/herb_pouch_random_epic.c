// epic level random herb pouch for use with the treasure daemon
#include <std.h>

inherit "/d/avatars/ares/herb_pouch_random.c";

string *extra_herbs;


void fill_me() { filled = 1; }


void special_fill(int special)
{
    int i;
    object ob;

    if (!filled)
    {
        for (i = 0;i < special;i++)
        {
            ob = new("/d/common/obj/brewing/herb_special_inherit.c");
            ob->set_herb_name(extra_herbs[random(sizeof(extra_herbs))]);
            ob->move(TO);
        }
    }
}


void create()
{

    extra_herbs = ({ "bone dust","reptile scales","fur","peryton talon","spiderweb","werebeast fang","dream fragment","breath of winter","living stone","patch of demonskin","tendril of flame","corrupted fey lifeblood","eye of newt","nycissa orchid","spirit essence" });

    herbs = ({ "divine essence","dragon scales","heart of an ancient wyrm","lich dust" });

    ::create();

    call_out("fill_pouch", 2, roll_dice(1, 8), roll_dice(1, 2));
    call_out("special_fill", 2, roll_dice(2, 6));
    call_out("fill_me", 3);

    set_property("treasure_type", "40B");
}
