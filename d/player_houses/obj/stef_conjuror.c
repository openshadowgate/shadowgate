//stef_conjuror.c - Drink for Stefano's lounge.  Coded by Circe 9/27/03
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("conjuror's concoction");
        set_id(({"concoction","conjuror's concoction","drink"}));
        set_short("%^BOLD%^%^YELLOW%^Conjuror's concoction%^RESET%^");
        set_long(
           "A rich, creamy looking liqueur served in a tiny silver cup.  "+
           "There is not much to it, but it smells fairly potent."
        );
        set_destroy();
        set_strength(40);
        set_my_mess("The smooth liqueur seems to melt over your tongue and ease its way soothingly down your throat. The flavor is sweet and creamy and seductively sensual, easing and relaxing your mind into a pleasant, slightly fuzzy state.");
        set_your_mess("tips the tiny silver cup and savors the sweet liqueur.");
        set_type("alcoholic");
        set_weight(2);
        set_empty_name("tiny silver cup");
}
