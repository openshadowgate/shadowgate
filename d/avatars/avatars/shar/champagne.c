//champagne.c - Drink for SG's anniversary.  Coded by Circe 10/16/04
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("sparkling champagne");
        set_id(({"champagne","sparkling champagne","glass","glass of champagne","drink"}));
        set_short("%^BOLD%^%^WHITE%^A glass of s%^CYAN%^p%^WHITE%^a"+
           "%^CYAN%^r%^WHITE%^k%^CYAN%^l%^WHITE%^i%^CYAN%^n%^WHITE%^g"+
           " %^CYAN%^champagne%^RESET%^");
        set_long(
           "%^BOLD%^A slender fluted glass elegantly holds this "+
           "light sparkling liquid.  A wonderful fragrance "+
           "rises from the drink, and the glass has been etched "+
           "with a message you could read.%^RESET%^"
        );
        set_read(
@CIRCE
        %^BOLD%^To %^BLACK%^ShadowGate

%^WHITE%^10 Years of Wonderful Memories%^RESET%^
CIRCE
        );
        set_destroy();
        set_strength(25);
        set_my_mess("You raise your glass to toast ShadowGate before "+
           "draining the heavenly champagne!");
        set_your_mess("raises the glass to toast ShadowGate before drinking it down.");
        set_type("alcoholic");
        set_weight(1);
        set_empty_name("glass");
}
