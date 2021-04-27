#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_name("A vast, cloudswept azure sky");
    set_short("%^BOLD%^%^CYAN%^A vast, %^WHITE%^clo%^RESET%^ud%^BOLD%^swept %^CYAN%^azure sky%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^A scattering of %^WHITE%^soft, fluffy clouds %^CYAN%^spread across this "
"limitless vista of azure sky.  The %^YELLOW%^brilliant light %^CYAN%^of the sun shines down from above, "
"sending its golden rays down upon everything beneath.  Countless miles below you, a spread of %^RESET%^"
"%^ORANGE%^rocky mountains %^BOLD%^%^CYAN%^can be seen, scattered with %^RESET%^%^GREEN%^sparse greenery "
"%^BOLD%^%^CYAN%^and a few dots of %^WHITE%^snow %^CYAN%^on the highest peaks.%^RESET%^\n");
    set("night long","%^RESET%^%^CYAN%^A scattering of %^WHITE%^soft, fluffy clouds %^CYAN%^spread across this "
"limitless vista of %^BLUE%^midnight sky%^CYAN%^.  The %^BOLD%^%^WHITE%^pale light %^RESET%^%^CYAN%^of the "
"moon shines down from above, sending its soft rays down upon everything beneath.  Countless miles below you, "
"a spread of %^ORANGE%^rocky mountains %^CYAN%^can be seen, scattered with %^GREEN%^sparse greenery %^CYAN%^"
"and a few dots of %^WHITE%^snow %^CYAN%^on the highest peaks.%^RESET%^\n");
    set_smell("default","The clean, fresh smell of open air reaches your nose.");
    set_listen("default","It is very quiet here.");
}