#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("Pine Street");
    set_long(
        "%^GREEN%^You are on %^GREEN%^Pine street%^RESET%^^RESET%^\n" +
        "To the north is the intersection of Pine with Apple and" +
        " Cherry. There is also a sign with the symbol of a stables" +
        " on it, hanging over the doorway of a building on the west" +
        " side. To the east of that %^MAGENTA%^Cherry street%^RESET%^continues into the" +
        " main part of town. Apple street runs off to the northeast." +
        " To the southwest %^GREEN%^Pine street%^RESET%^continues back to intersect" +
        " with Crescent."
        );
    set_smell("default", "You smell the scent of horses.");
    set_listen("default", "The sounds of horses stomping about" +
               " in their stalls drifts in from the north.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is Pine Street.",
                   "sign" : "There is a wooden sign to the north with the" +
                   " symbol of a stables on it.",
               ]));
    set_exits(([
                   "north" : ROOMS + "street6",
                   "southeast" : ROOMS + "street4",
               ]));
}
