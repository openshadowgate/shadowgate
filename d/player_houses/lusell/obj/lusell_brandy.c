//lusell_brandy.c - Drink for Lusell's keep.  Coded by Circe 1/29/04
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("brandy");
        set_id(({"brandy","fine brandy","drink"}));
        set_short("%^YELLOW%^Fine brandy%^RESET%^");
        set_long(
           "A short brandy glass filled with a fine blend of family spirits."
        );
        set_destroy();
        set_strength(20);
        set_my_mess("The brandy burns your throat but tastes delightful.");
        set_your_mess("drinks a glass of brandy and smiles faintly.");
        set_type("alcoholic");
        set_weight(2);
        set_empty_name("glass");
}
