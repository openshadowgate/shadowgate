#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <teleport.h>
inherit DAEMON;

#define WING_DELAY 120

string * flyraces = ({"deva"});
string * flysubraces = ({"fey'ri","rock gnome"});
string * flyprofiles = ({"druid_bird_999","druid_dragon_999","mage_dragon_999","mage_demon_999","vampire_bat_999","vampire_lord_999"});

string WINGO = "/cmds/mortal/obj/wingObj.c";

mapping preset_destinations;
preset_destinations =
    ([ "asgard" :"/d/laerad/parnelli/asgard/as59",
       "azha"   :"/d/tharis/road/wroad30",
       "deku":"/d/deku/forest/dforest15-5",
       "eldebaro":"/d/islands/common/eldebaro/newrooms/east_oasis15",
       "graez":"/d/undead/rooms/town/street12",
       "juran":"/d/shadow/room/forest/owagon26",
       "kinaro":"/d/dagger/kinaro/path3",
       "muuldaan":"/d/shadow/room/muuldaan/rooms/path6",
       "seneca":"/d/attaya/newseneca/rooms/boardwalk3",
       "tabor":"/d/darkwood/tabor/road/road1",
       "tharis":"/d/tharis/road/road8",
       "tonovi":"/d/dagger/tonovi/crossrd",
       "torm":"/d/dagger/Torm/road/path12",
       "antioch":"/d/antioch/antioch2/rooms/trail6",
        ]);

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

    if(TP->query_property("wing delay")+WING_DELAY > time())
    {
        tell_object(TP,"Your wings are tired, you'll have to wait a bit.");
        return 1;
    }

    if(!(dest = TP->query_rem_room(args)))
    {
        if(member_array(args,keys(preset_destinations))!=-1)
        {
            dest = find_object_or_load(preset_destinations[args]);
        }
        else
        {
            tell_object(TP,"You can't remember "+args+".");
            return 1;
        }
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

    if(!TELEPORT->object_can_be_teleported(TP,find_object_or_load(dest),TP->query_character_level()/2))
    {
        tell_object(TP,"Something prevents you from flying there.");
        return 1;
    }

    TP->remove_property("wing delay");
    TP->set_property("wing delay",time());
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" flaps "+TP->QP+" wings and off "+TP->QS+" goes.%^RESET%^");
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

Wing allows you to move between locations, albeit much slower than teleportation. To use this command you must have wings sufficiently large enough to overcome winds (bird, bat, dragon, angelic aspect, fell flight, fey'ri, deva and others). This command will allow you to escape combat, but you can be intercepted during the flight.

You can travel to well known cities and destinations:
  Antioch
  Asgard
  Azha
  Deku
  Eldebaro
  Graez
  Juran
  Kinaro
  Muuldaan
  Seneca
  Tabor
  Tharis
  Tonovi
  Torm

Your memory has a higher priority in the case you want to overwrite any of these.

%^CYAN%^SEE ALSO%^RESET%^

remember, unremember, recall
");
}
