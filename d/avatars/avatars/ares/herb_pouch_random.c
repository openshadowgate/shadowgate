// random herb pouch inherit for use with the random pouches the treasure daemon spawns
#include <std.h>

inherit "/d/common/obj/brewing/herb_pouch.c";

string *herbs = ({});
int rand_herbs, rand_special_herbs,filled;


void fill_pouch(int rand_herbs,int rand_special_herbs)
{
    int i;
    object ob;

    if (!filled)
    {
        for (i = 0;i < rand_herbs;i++)
        {
            ob = new("/d/common/obj/brewing/herb_inherit.c");
            ob->move(TO);
            filled = 1;
        }

        for (i = 0;i < rand_special_herbs;i++)
        {
            if (sizeof(herbs))
            {
                ob = new("/d/common/obj/brewing/herb_special_inherit.c");
                ob->set_herb_name(herbs[random(sizeof(herbs))]);
                ob->move(TO);
                filled = 1;
            }
        }
    }

    filled = 1;
}


void create()
{
    ::create();
}

