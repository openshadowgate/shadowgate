//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("pendant");
    set_id(({"armor","pendant","moon pendant","%^BLACK%^%^BOLD%^m%^RESET%^o%^BOLD%^onsto%^RESET%^n%^BLACK%^BOLD%^e %^YELLOW%^pendant%^RESET%^",}));
    set_short("%^BLACK%^%^BOLD%^m%^RESET%^o%^BOLD%^onsto%^RESET%^n%^BLACK%^BOLD%^e %^YELLOW%^pendant%^RESET%^");
    set_long(
@ARMOR
%^BLUE%^%^BOLD%^As you gaze upon this lovely piece of jewellery you feel a sense of
tranquility overcome you.  A normal looking leather thong holds in its
grasp a lilly white stone of utter beauty.  Embedded in the stone
you can make out a symbol which corresponds with the tide of the moon,
keeping with its time.  Waning and waxing, crescent and full.  A
strange glow illuminates this stone, giving it the properties of an
evening twilight.
ARMOR
        );
    set_weight(0);
    set_size(2);
    set_type("clothing");
    set_limbs(({"neck",}));
    set_ac(2);
    set_property("enchantment",0);
    set_value(5000);
}