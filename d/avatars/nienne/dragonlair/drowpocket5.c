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
    set_name("The top of a mountain peak");
    set_short("%^RESET%^%^BLUE%^The top of a mountain peak%^RESET%^");
    set_long("%^RESET%^%^BLUE%^The top of a mountain peak%^RESET%^\n"
"%^RESET%^%^ORANGE%^You've reached the very top of this mountain, where %^BOLD%^%^BLACK%^stark rocky outcroppings "
"%^RESET%^%^ORANGE%^ form a rough circle to border the flat plateau that crowns its peak.  The area becomes immediately "
"different here, where a massive slab the size of a %^GREEN%^planting field %^ORANGE%^seems to have been set down atop "
"the dark, jagged stones that pave the rest of the mountainside.  The slab itself seems to have been transported in from "
"another time, where the bodies of the %^RED%^dead %^ORANGE%^lie strewn about as remnants of war among struggling "
"patches of grass.  Right at the far side of the slab lies a small, raised ridge of stone like a %^MAGENTA%^bier%^ORANGE%^"
", upon which lies a single lifeless man, his body untouched by time as though caught at the very moment of his "
"demise...%^RESET%^\n");
    set_smell("default","%^CYAN%^An %^BLUE%^uneasy %^CYAN%^feeling hangs in the air like a tangible presence.%^RESET%^");
    set_listen("default","%^MAGENTA%^An occasional %^ORANGE%^om%^BOLD%^%^BLACK%^ino%^RESET%^%^ORANGE%^us ru%^RESET%^mb%^ORANGE%^le %^MAGENTA%^escapes the ever-imminent storm above.%^RESET%^");

    set_exits(([
      "south" : "/d/avatars/nienne/dragonlair/drowpocket4",
    ]));
}

string query_weather(){ return "%^BOLD%^%^BLACK%^The a%^RESET%^%^RED%^ng%^BOLD%^%^BLACK%^ry, roiling mass of dark clo%^RESET%^%^MAGENTA%^ud%^BOLD%^%^BLACK%^s overhead completely hides the sky.%^RESET%^"; }