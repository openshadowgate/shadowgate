//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("dagger");
    set_id(({"weapon","dagger","dragon dagger","%^BLUE%^Dragon %^RED%^Dagger%^RESET%^",}));
    set_short("%^BLUE%^Blue Metal Shard%^RESET%^");
    set_long(
@WEAPON
%^BOLD%^%^WHITE%^This dagger is only near one foot in length and is made from what seems to be a %^BLACK%^darkened%^RESET%^%^BLUE%^ blue%^BOLD%^%^WHITE%^ metal, shaped into the form of a small claw. The handle and blade of the weapon %^CYAN%^flow%^WHITE%^ together into a solid piece of material with a slightly curved, %^YELLOW%^sharpened%^WHITE%^ edge. One end of the material is rounded with grips used to hold it firmly in hand.%^RESET%
WEAPON
        );
    set_weight(4);
    set_size(1);
    set_type("slashing");
    set_prof_type("dragon dagger");
    set_ac(0);
    set_property("enchantment",5);
    set_value(2000);
    set_wc(1,14);
    set_large_wc(1,16);
}