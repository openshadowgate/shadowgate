//shry_nectar.c - Drink for Shrydelhi's dining room.  Coded by Circe 9/14/03
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("nectar");
        set_id(({"nectar","golden nectar","drink"}));
        set_short("%^YELLOW%^Golden ne%^MAGENTA%^ct%^YELLOW%^ar%^RESET%^");
        set_long(
           "A large, soft oak leaf has been formed into the shape "+
           "of a cup and filled with a deep golden liquid.  The drink "+
           "is quite thick and looks as though it would be very sweet."
        );
        set_destroy();
        set_strength(1);
        set_my_mess("The sweetness of the nectar overwhelms you as you drain the leaf cup.");
        set_your_mess("drains the leaf cup, smiling slightly.");
        set_type("soft drink");
        set_weight(2);
        set_empty_name("oak leaf cup");
}
