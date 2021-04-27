inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("whiskey");
        set_id(({"whisky","fine brandy","drink"}));
        set_short("A shotglass of whiskey");
        set_long(
           "This %^ORANGE%^dark colored drink %^RESET%^is served in a shotglass made of %^GREEN%^o%^ORANGE%^a%^GREEN%^k leaves.  %^RESET%^The %^ORANGE%^rich aroma %^RESET%^is strong, and is further complimented by the smell of the %^GREEN%^leafy %^RESET%^cup."
        );
        set_destroy();
        set_strength(35);
        set_my_mess("%^ORANGE%^The full flavor of the whiskey burns your throat on the way down.");
        set_your_mess("coughs as the drink goes down.");
        set_type("alcoholic");
        set_weight(2);
        set_empty_name("shot glass");
}