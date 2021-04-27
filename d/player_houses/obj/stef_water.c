//stef_water.c - Drink for Stefano's lounge.  Coded by Circe 9/27/03
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("pure water");
        set_id(({"water","pure water","glass of pure water","drink"}));
        set_short("Glass of %^BOLD%^%^CYAN%^pure water%^RESET%^");
        set_long(
           "A glass of pure, clean water drawn from a mountain spring."
        );
        set_destroy();
        set_strength(5);
        set_my_mess("You drink the pure, clean water.");
        set_your_mess("drinks a glass of %^BOLD%^%^CYAN%^pure%^RESET%^ water, drawn from a mountain spring.");
        set_type("water");
        set_weight(2);
        set_empty_name("glass");
}
