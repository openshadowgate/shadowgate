//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("claws");
    set_id(({"weapon","claws","black claws","%^BLACK%^%^BOLD%^Black Claws%^RESET%^",}));
    set_short("%^BLACK%^%^BOLD%^Black Claws%^RESET%^");
    set_long(
@WEAPON
%^BLACK%^%^BOLD%^These are a set of four vicious looking daggers attached to a long leather glove.  The entire weapon is charred black, including the blades of the daggers.  The glove is cold to the touch, but the blades are strangely warm.  You realize that this is the infamous weapon of Frederick the sage, who was burned at the stake over five hundred years ago.
WEAPON
        );
    set_weight(11);
    set_size(1);
    set_type("slashing");
    set_prof_type("claws");
    set_ac(0);
    set_property("enchantment",0);
    set_value(0);
    set_wc(1,16);
    set_large_wc(1,12);
}