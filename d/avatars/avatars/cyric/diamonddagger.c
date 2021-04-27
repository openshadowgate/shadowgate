//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("dagger");
    set_id(({"weapon","dagger","diamond dagger","%^BLUE%^%^BOLD%^D%^WHITE%^i%^BLUE%^a%^WHITE%^m%^BLUE%^o%^WHITE%^n%^BLUE%^d %^WHITE%^D%^BLUE%^a%^WHITE%^g%^BLUE%^g%^WHITE%^e%^BLUE%^r%^RESET%^",}));
    set_short("%^BLUE%^%^BOLD%^D%^WHITE%^i%^BLUE%^a%^WHITE%^m%^BLUE%^o%^WHITE%^n%^BLUE%^d %^WHITE%^D%^BLUE%^a%^WHITE%^g%^BLUE%^g%^WHITE%^e%^BLUE%^r%^RESET%^");
    set_long(
@WEAPON
This is a dagger made entirely from what appears to be a huge blue-white diamond.  Light reflects through the blade, and the whole weapon seems to shimmer with power.  Obviously this is a special weapon.
WEAPON
        );
    set_weight(2);
    set_size(1);
    set_type("piercing");
    set_prof_type("small blades");
    set_ac(0);
    set_property("enchantment",5);
    set_value(20);
    set_wc(1,6);
    set_large_wc(1,8);
}