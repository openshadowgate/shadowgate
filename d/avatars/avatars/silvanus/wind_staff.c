//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("staff");
    set_id(({"weapon","staff","staff of the winds","%^BOLD%^%^WHITE%^Staff of the %^RESET%^%^RED%^W%^CYAN%^i%^RESET%^%^BLUE%^n%^GREEN%^d%^YELLOW%^s%^RESET%^",}));
    set_short("%^BOLD%^%^WHITE%^Staff of the %^RESET%^%^RED%^W%^CYAN%^i%^RESET%^%^BLUE%^n%^GREEN%^d%^YELLOW%^s%^RESET%^");
    set_long(
@WEAPON
%^BOLD%^%^WHITE%^This staff stands well over six feet tall and it %^RESET%^%^MAGENTA%^radiates%^BOLD%^%^WHITE%^ an obvious power. At the bottom of its %^RESET%^%^RED%^engraved%^BOLD%^%^WHITE%^ shaft is a short %^BOLD%^%^BLACK%^blade%^BOLD%^%^WHITE%^ and at the top three blades intertwine to form a crown. The staff itself is as light as a feather, and almost moves on its own accord%^RESET%^. 
WEAPON
        );
    set_weight(10);
    set_size(2);
    set_type("bludgeoning");
    set_prof_type("staff of the winds");
    set_ac(0);
    set_property("enchantment",2);
    set_value(2000);
    set_wc(1,8);
    set_large_wc(1,9);
}