//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("%^RESET%^GREEN%^Staff of %^BOLD%^Living%^RESET%^GREEN%^ Wood%^RESET%^");
    set_id(({"weapon","%^RESET%^GREEN%^Staff of %^BOLD%^Living%^RESET%^GREEN%^ Wood%^RESET%^","staff","%^RESET%^GREEN%^Staff of %^BOLD%^Living%^RESET%^GREEN%^ Wood%^RESET%^",}));
    set_short("%^RESET%^GREEN%^Staff of %^BOLD%^Living%^RESET%^GREEN%^ Wood%^RESET%^");
    set_long(
@WEAPON
This staff is not made of dead wood, but indeed, appears to 
be the straightened branch of a living oak tree.  Etched
into the branch are runes of %^YELLOW%^gold%^RESET%^ and 
also green leaves and buds.  This staff itself is a 
wonder to behold.
WEAPON
        );
    set_weight(10);
    set_size(2);
    set_type("bludgeoning");
    set_prof_type("staff of living wood");
    set_ac(1);
    set_property("enchantment",6);
    set_value(1000);
    set_wc(1,7);
    set_large_wc(1,7);
}
