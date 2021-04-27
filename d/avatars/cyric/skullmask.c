//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("mask");
    set_id(({"armor","mask","skull mask","%^RESET%^Skull Mask%^RESET%^",}));
    set_short("%^RESET%^Skull Mask%^RESET%^");
    set_long(
@ARMOR
This is a mask made from the skull of some type creature that is larger than a human.  The lower jawbone is missing, along with the top and back of the skull.  These masks are given only to those warriors who have achieved the fifth rank of honor in Cyric's army of darkness.  Rare indeed is the warrior who has earned it.
ARMOR
        );
    set_weight(1);
    set_size(2);
    set_type("clothing");
    set_limbs(({"head",}));
    set_ac(4);
    set_property("enchantment",4);
    set_value(10);
}