//little side path, drow plot for Nienne
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_name("A rocky path near the top of a mountain peak");
    set_short("%^RESET%^%^BLUE%^A rocky path near the top of a mountain peak%^RESET%^");
    set_long("%^RESET%^%^BLUE%^A rocky path near the top of a mountain peak%^RESET%^\n"
"%^RESET%^%^ORANGE%^You're standing near the end of a narrow pathway, barely discernable amongst the %^BOLD%^%^BLACK%^"
"jagged stones %^RESET%^%^ORANGE%^of this mountainside.  Only a few steps further down, sheer cliffs plunge earthwards to "
"offer no easy way to descend, leaving the only option to travel further upwards.  The ground is lost far below to "
"darkness and the ever-present %^BOLD%^%^BLACK%^black clo%^RESET%^%^MAGENTA%^ud%^BOLD%^%^BLACK%^s %^RESET%^%^ORANGE%^that "
"skulk menancingly across the sky, rumbling their displeasure at any mortal daring enough to pass below.  Further upwards"
", the cliff's summit is visible as a massive slab of earth the size of a planting field that seems to have been left, "
"oddly out of place in this pit of the damned.%^RESET%^\n");
    set_smell("default","%^CYAN%^An %^BLUE%^uneasy %^CYAN%^feeling hangs in the air like a tangible presence.%^RESET%^");
    set_listen("default","%^MAGENTA%^An occasional %^ORANGE%^om%^BOLD%^%^BLACK%^ino%^RESET%^%^ORANGE%^us ru%^RESET%^mb%^ORANGE%^le %^MAGENTA%^escapes the ever-imminent storm above.%^RESET%^");

    set_exits(([
      "northeast" : "/d/avatars/nienne/dragonlair/drowpocket4",
      "south" : "/d/avatars/nienne/dragonlair/drowpocket2",
    ]));
}

string query_weather(){ return "%^BOLD%^%^BLACK%^The a%^RESET%^%^RED%^ng%^BOLD%^%^BLACK%^ry, roiling mass of dark clo%^RESET%^%^MAGENTA%^ud%^BOLD%^%^BLACK%^s overhead completely hides the sky.%^RESET%^"; }