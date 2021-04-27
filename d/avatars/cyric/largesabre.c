//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("sabre");
    set_id(({"weapon","sabre","sabre","%^CYAN%^%^BOLD%^Large Sabre%^RESET%^",}));
    set_short("%^CYAN%^%^BOLD%^Large Sabre%^RESET%^");
    set_long(
@WEAPON
%^CYAN%^%^BOLD%^This is quite a large sword.  It if finely crafted, and may very well be enchanted.
WEAPON
        );
    set_weight(10);
    set_size(3);
    set_type("slashing");
    set_prof_type("large blades");
    set_ac(0);
    set_property("enchantment",1);
    set_value(100);
    set_wc(1,12);
    set_large_wc(1,18);
}