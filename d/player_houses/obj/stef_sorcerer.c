//stef_sorcerer.c - Drink for Stefano's lounge.  Coded by Circe 9/27/03
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("sorcerer's brew");
        set_id(({"brew","sorcerer's brew","drink"}));
        set_short("%^GREEN%^Sorcerer's brew%^RESET%^");
        set_long(
           "A mug of cool liquid, a somewhat uninspiring %^BOLD%^%^GREEN%^green"+
           "%^RESET%^ color, with an inconsitent, lumpy constituency."
        );
        set_destroy();
        set_strength(15);
        set_my_mess("taking a breath, you swallow down the unpleasant looking drink. Surprisingly, the taste as it hits your tongue is sublime, a smooth blend of exotic fruit flavors overlain with hints of vanilla. Slightly sweet without being sickly, the brew is refreshing and clears your palate perfectly.");
        set_your_mess("makes a face while drinking the drink, then gives a surprised smile");
        set_type("soft drink");
        set_weight(2);
        set_empty_name("mug");
}
