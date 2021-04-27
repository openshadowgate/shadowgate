//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("Robe of the Da'i");
    set_id(({"armor","Robe of the Da'i","robe","%^BOLD%^BLACK%^Robe of the Da'i%^RESET%^",}));
    set_short("%^BOLD%^BLACK%^Robe of the Da'i%^RESET%^");
    set_long(
@ARMOR
This is a gray robe which seems to actually hum with
an inner power.  The fabric looks much like linen, but 
makes no sound as it moves.  You also notice that the
robe actually seems to be in different places in a 
small span of time...shifting very slightly in space
while staying in the same general location.
ARMOR
        );
    set_weight(7);
    set_size(2);
    set_type("clothing");
    set_limbs(({"torso",}));
    set_ac(4);
    set_property("enchantment",2);
    set_value(100);
}