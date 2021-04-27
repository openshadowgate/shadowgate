//village Darnesh, for selunite side-plot
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",2);
    set_name("A small mountain village");
    set_short("%^RESET%^%^GREEN%^A small mountain village%^RESET%^");
    set_long("%^RESET%^This village is nothing more than a small gathering of "
"very crude and rough habitations - even the title of village is a little "
"extravagant for its size and quality, truthfully.  The ground has been somewhat "
"cleared, but saplings and trees still rise up between the tents.  The %^ORANGE%^tents "
"%^RESET%^themselves are nothing more than sticks and hides and grass, tied and woven "
"together; they look like a good sturdy wind would easily tear many of them down.  "
"%^GREEN%^Trees %^RESET%^rise up on all sides, and taller mountains loom up behind them"
", effectively cutting the village off from disturbance. The only way out of here seems "
"to be into the thicker mass of trees to the south.\n");
    set_smell("default","The clean, fresh smell of mountain air reaches your nose.");
    set_listen("default","A gentle murmur of the village's inhabitants fills the air.");

    set_exits(([
      "south" : "/d/avatars/nienne/dragonlair/beastmen2",
    ]));
}
