//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("ribbon");
    set_id(({"armor","ribbon","red ribbon","%^RESET%^%^RED%^Red Ribbon%^RESET%^",}));
    set_short("%^RESET%^%^RED%^Red Ribbon%^RESET%^");
    set_long(
@ARMOR
This is a cute red ribbon which can be worn to keep your hair out of your face.
ARMOR
        );
    set_weight(1);
    set_size(2);
    set_type("clothing");
    set_limbs(({"head",}));
    set_ac(0);
    set_property("enchantment",1);
    set_value(20);
}