//lusell_water.c - Drink for Lusell's keep.  Coded by Circe 1/29/04
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("fresh water");
        set_id(({"water","fresh water","glass of fresh water","drink"}));
        set_short("%^BOLD%^%^CYAN%^Fresh water%^RESET%^");
        set_long(
           "A glass of cool water with a splash of citrus."
        );
        set_destroy();
        set_strength(5);
        set_my_mess("You drink a refreshing glass of water.");
        set_your_mess("sips a glass of water.");
        set_type("water");
        set_weight(2);
        set_empty_name("glass");
}
