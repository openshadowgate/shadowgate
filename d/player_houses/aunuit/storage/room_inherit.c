//basic inherit to add protection from scrying and teleport
//~Circe~ 8/25/13

#include <std.h>
#include "../aunuit.h"
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
inherit VAULT;

object blocker;


void create()
{
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary")); //assuming lvl 40, casterlevel 46+ bonus of 20, +random 6 +items
    //adding a note here that because of the way teleport has changed, no-one aside from a level 60 archmage specialized in conjuration can get through this currently.  Putting relevant code in the next lines - Odin 3/25/2020
    /*from /std/teleport.c, lines 32-38:
       int startpower, endpower;
       startpower = environment(teleportee)->query_property("teleport proof");
       endpower = destination->query_property("teleport proof");
       if ((clevel - 9 + random(20) < startpower) ||
        (clevel - 9 + random(20) < endpower)) {
        return 0;
       }*/
}

void reset()
{
    ::reset();
    if (!present("blockerx111")) {
        blocker = SCRY_D->add_block_scrying(TO);
        if (!objectp(blocker)) {
            tell_room(TO, "%^BOLD%^RED%^Something has gone wrong with "
                      "the scry protection! Please tell Circe.%^RESET%^");
            return;
        }
        blocker->set_block_power("/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
}
