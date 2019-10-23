#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit DAEMON;

string * flyraces = ({"deva"});
string * flysubraces = ({"fey'ri"});
string * flyprofiles = ({"druid_bird_999","druid_dragon_999","vampire_bat_999"});


string FLIGHT_ROOM = "/std/flying_room.c";

int cmd_wing(string str)
{
    object myshape;
    return 0;
    if (TP->query_bound() || TP->query_paralyzed())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!TP->query_property("shapeshifted"))
        return notify_fail("Only a bird can <wing>.\n");
    if((string)TP->query("relationship_profile") != "druid_bird_999" &&
       (string)TP->query("relationship_profile") != "druid_dragon_999")
        return notify_fail("Only a bird can <wing>.\n");
    if(!objectp(myshape = TP->query_property("shapeshifted")))
        return notify_fail("Something went wrong with your shape.\n");
    if(TP->query_casting())
        return notify_fail("You're already casting a spell!\n");
    return 1;
}



void help()
{
    write("Bla bla bla cat placed stub");
}
