#include <std.h>
//#include "../include/tabor.h"

inherit "/d/common/inherit/hitching_post";

void create() {
        ::create();
        set_property("light",2);
        set_terrain(WOOD_BUILDING);

        set_travel(RUTTED_TRACK);

        set_name("the keep tethering post");
        set_short("%^GREEN%^the keep tethering %^ORANGE%^post%^RESET%^");

        set_long("%^GREEN%^This area of the stables is fairly large,"
                +" probably to accommodate the vast collection of horses"
                +" the owner of the keep maintains.  The whole place is"
                +" well-manicured, many workers running around ensuring"
                +" that is constantly the case.  Old tabards and family"
                +" crests, as well as no longer used tapestries, adorn the"
                +" walls, showing a visual history, if only briefly, of the"
                +" owners family.");
         set_smell("default","The typical horse smells fill the air.");
         set_listen("default","The sounds of horses moving and jockeying"
                    +" for position abound. ");
        set_exits((["east" : "/d/player_houses/lusell/rooms/stable"]) ); 

}



