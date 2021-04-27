#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",2);
   set_property("no teleport",1);
    set_name("A rocky mountain ledge");
    set_short("%^RESET%^%^ORANGE%^A %^BOLD%^%^BLACK%^ro%^RESET%^ck%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^mountain ledge%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^A scattering of %^RESET%^%^ORANGE%^wiry trees %^BOLD%^%^CYAN%^and %^RESET%^"
"%^GREEN%^underbrush %^BOLD%^%^CYAN%^lines the upper slope of this rocky ledge, a short way above you.  Here, "
"though, it is %^BLACK%^bare stone %^CYAN%^and open to the azure sky above, from which the %^YELLOW%^brilliant "
"rays %^CYAN%^of the sun shine down to warm the ground.  Miles below you, a spread of %^RESET%^%^ORANGE%^rocky "
"mountains %^BOLD%^%^CYAN%^can be seen, scattered with %^RESET%^%^GREEN%^sparse greenery %^BOLD%^%^CYAN%^and a "
"few dots of %^WHITE%^snow %^CYAN%^on the highest peaks.  You can't begin to imagine how you would get down "
"from here without some form of flight.%^RESET%^\n");
    set("night long","%^RESET%^%^CYAN%^A scattering of %^ORANGE%^wiry trees %^CYAN%^and %^GREEN%^underbrush "
"%^CYAN%^lines the upper slope of this rocky ledge, a short way above you.  Here, though, it is %^BOLD%^"
"%^BLACK%^bare stone %^RESET%^%^CYAN%^and open to the %^BLUE%^midnight sky %^CYAN%^above, from which the "
"%^WHITE%^gentle rays %^CYAN%^of the moon shine down to light the ground.  Miles below you, a spread of "
"%^ORANGE%^rocky mountains %^CYAN%^can be seen, scattered with %^GREEN%^sparse greenery %^CYAN%^and a few dots "
"of %^WHITE%^snow %^CYAN%^on the highest peaks.  You can't begin to imagine how you would get down from here "
"without some form of flight.%^RESET%^\n");
    set_smell("default","The clean, fresh smell of open air reaches your nose.");
    set_listen("default","It is very quiet here.");
}
