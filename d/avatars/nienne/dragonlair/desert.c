#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_name("A vast desert");
    set_short("%^RESET%^%^ORANGE%^A vast desert%^RESET%^");
    set_long("%^RESET%^Beneath your feet sift the still-warm %^ORANGE%^sands %^RESET%^of the desert, darkening under the %^BLUE%^dusky %^RESET%^sky.  Evening is falling, and the last dull %^YELLOW%^glow %^RESET%^of the sun is only barely noticeable upon the distant horizon.  %^ORANGE%^Sand %^RESET%^stretches as far as the eye can see in all directions, leaving you to wonder just how far you would have to walk to find anything other than desert.  Only a fine line of distant, %^MAGENTA%^indigo %^RESET%^mountain peaks can be seen to the north, though judging by their size, they could be days travel away.\n");
    set_smell("default","The air is dry and dusty.");
    set_listen("default","Only the faint drifting of the sand dunes can be heard.");
}

string query_weather(){ return "%^BOLD%^%^CYAN%^A chill wind and the darkening sky heralds the coming of night.%^RESET%^"; }
