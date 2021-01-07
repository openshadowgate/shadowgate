#include <std.h>
inherit "/std/temple";

void create()
{
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_light(2);
    set_indoors(0);
    set_temple("dream");
    set_name("Temple of dream");
    set_short("%^BOLD%^%^GREEN%^Temple of Dream%^RESET%^");
    set_long("This is a monument to Yves'es and Tsera's lazyness.");
    set_smell("default", "The air is filled with the smell of the forest that surrounds you.");
    set_listen("default", "The wind rustles gently through the trees.");
    /* set_exits(([ */
    /*    "out":"/d/tharis/conforest/rooms/path26" */
    /* ])); */
}

void init()
{
    ::init();
    add_action("read_charge", "read");
}

int read_charge(string str)
{
    if (!str || str != "charge") {
        return __Read_me(str);
    }
    write(
        "Eat cookies"
        );
    return 1;
}
