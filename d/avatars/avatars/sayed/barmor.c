//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("%^BLACK%^BOLD%^Body Armor of the Kinnesaruda%^RESET%^");
    set_id(({"armor","%^BLACK%^BOLD%^Body Armor of the Kinnesaruda%^RESET%^","armor","%^BLACK%^BOLD%^Body Armor of the Kinnesaruda%^RESET%^",}));
    set_short("%^BLACK%^BOLD%^Body Armor of the Kinnesaruda%^RESET%^");
    set_long(
@ARMOR
This body armor is built from a special magical mesh that
is light and does not hinder the wearer, perfect for the
assassins and spies of Intruder.  Its protection is like
that of very good plate armor, but is very rare and requires
special care so that it does not disintegrate and lose
it special protective abilities.
ARMOR
        );
    set_weight(4);
    set_size(2);
    set_type("leather");
    set_limbs(({"torso",}));
    set_ac(10);
    set_property("enchantment",6);
    set_value(100000);
}
