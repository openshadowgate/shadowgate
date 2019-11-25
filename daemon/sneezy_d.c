#include <std.h>
#include <magic.h>

inherit DAEMON;

void create()
{
    seteuid(getuid());
}

void sneezy()
{
    object * players;
    int i, num;

    players = real_users();
    players = filter_array(people,
                           (:!avatarp($1):));

    num = random(sizeof(players));
    for (i=random(sizeof(players)-num); i<num; i++)
    {
        players[i]->force_me("sneeze");
    }

    call_out("sneezy",(20+random(60))*ROUND_LENGTH);
}
