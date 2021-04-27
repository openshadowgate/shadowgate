//little side path, selunite plot for Nienne
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",2);
    set_name("A little clearing");
    set_short("%^RESET%^%^ORANGE%^A little clearing%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This is only a tiny clearing, no more than the "
"size of a small cottage room.  %^ORANGE%^Tall trees %^GREEN%^border all sides "
"of the area, blocking out most of the %^YELLOW%^light %^RESET%^%^GREEN%^that "
"falls upon the soft carpet of grass and foliage below.  Just between a few of "
"their trunks, you can see a %^RESET%^road %^GREEN%^off to the north.%^RESET%^\n");
    set_smell("default","The clean, fresh smell of open air reaches your nose.");
    set_listen("default","The gentle trills of forest birds can be heard all around.");

    set_exits(([
      "north" : "/d/tharis/road/wroad4",
    ]));
}
