//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("gauntlets");
    set_id(({"armor","gauntlets","fiery gauntlets","%^BOLD%^%^BLUE%^Fiery Gauntlets%^RESET%^",}));
    set_short("%^BOLD%^%^BLUE%^Fiery Gauntlets%^RESET%^");
    set_long(
@ARMOR
These are a pair of armored gloves to protect the hands from injury in combat.  Icy cold blue flames gush around the gauntlets, seemingly fed from a glowing gem set into the palm of each glove.
ARMOR
        );
    set_weight(2);
    set_size(2);
    set_type("armour");
    set_limbs(({"right hand",}));
    set_ac(1);
    set_property("enchantment",-1);
    set_value(5000);
}