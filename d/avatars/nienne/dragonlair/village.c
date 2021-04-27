//village Darnesh, for selunite side-plot
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",2);
    set_name("A small village");
    set_short("%^RESET%^%^GREEN%^A small village%^RESET%^");
    set_long("%^RESET%^This village is nothing more than a small gathering of "
"thatched cottages and buildings - even the title of village is a little "
"extravagant for its size, truthfully.  The ground has been cleared, and "
"%^ORANGE%^dirt paths %^RESET%^wind between the houses to offer passage to "
"and fro.  %^GREEN%^Trees %^RESET%^rise up on all sides, effectively cutting "
"the village off from disturbance, with only a single %^ORANGE%^dirt road "
"%^RESET%^leading out to the main trail beyond the through the forest.\n");
    set_smell("default","The clean, fresh smell of open air reaches your nose.");
    set_listen("default","The occasional call of a child or yap of a dog can be heard.");

    set_exits(([
      "west" : "/d/azha/theater/rooms/azp7",
    ]));
}
