//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("piwafwi");
    set_id(({"armor","piwafwi","cloak","%^RESET%^%^BLACK%^Piwafwi%^RESET%^",}));
    set_short("%^RESET%^%^BLACK%^Piwafwi%^RESET%^");
    set_long(
@ARMOR
This is a piwafwi, the black cloak typical of drow outerwear.  The material is obviously enchanted, as the cloth seems to cling to shadows, or vice versa.
ARMOR
        );
    set_weight(2);
    set_size(2);
    set_type("clothing");
    set_limbs(({"neck",}));
    set_ac(2);
    set_property("enchantment",1);
    set_value(4000);
}