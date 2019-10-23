#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <teleport.h>
inherit DAEMON;

string * flyraces = ({"deva"});
string * flysubraces = ({"fey'ri","rock gnome"});
string * flyprofiles = ({"druid_bird_999","druid_dragon_999","vampire_bat_999"});

string WINGO = "/cmds/mortal/obj/wingObj.c";

int cmd_wing(string args)
{
    object myshape;
    object dest;

    if (TP->query_bound() || TP->query_paralyzed())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(TP->query_casting())
    {
        tell_object(TP,"You're already casting a spell!");
        return 1;
    }

    if(!((member_array(TP->query_race(),flyraces)!=-1) ||
         (member_array(TP->query("subrace"),flysubraces)!=-1) ||
         (member_array(TP->query("relationship_profile"),flyprofiles)!=-1) ||
         (TP->query_property("flying"))))
    {
        tell_object(TP,"You can not fly.");
        return 1;
    }

    if(!(dest = TP->query_rem_room(args)))
    {
        tell_object(TP,"You can't remember "+args);
        return 1;
    }

    if(dest->query_property("indoors"))
    {
        tell_object(TP,"Your destination must be outside.");
        return 1;
    }

    if(ETP->query_property("indoors"))
    {
        tell_object(TP,"Your origin must be outside.");
        return 1;
    }

    if(!TELEPORT->object_can_be_teleported(TP,find_object_or_load(dest),256))
    {
        tell_object(TP,"Something prevents you from flying there.");
        return 1;
    }

    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" flaps "+TP->QP+" wings and off "+TP->QO+" goes.%^RESET%^");
    new(WINGO)->setup(TP,dest);

    return 1;
}



void help()
{
    write(
"%^CYAN%^NAME%^RESET%^

wing - spread your wings and fly away

%^CYAN%^SYNTAX%^RESET%^

wing %^ORANGE%^%^ULINE%^DESTINATION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Wing allows you to move between locations, albeit much slower than teleportation. To use this command you must have wings sufficiently large to overcome winds (bird, bat, dragon, angelic aspect, fell flight, fey'ri, deva). This command will allow you to escape the combat, but you can be intercepted during the flight.

%^CYAN%^SEE ALSO%^RESET%^

remember, unremember, recall
");
}
