//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("sabre");
    set_id(({"weapon","sabre","steel sabre","%^BOLD%^%^GREEN%^Steel Sabre%^RESET%^",}));
    set_short("%^BOLD%^%^GREEN%^Steel Sabre%^RESET%^");
    set_long(
@WEAPON
This looks like a high quality weapon.  It is similar to a longsword, except the blade is slightly curved.  It is lighter than a longsword, but unlike a rapier, it can be used to slash or to stab.  As you approach the sabre, you can almost hear it hum with energy.
WEAPON
        );
    set_weight(10);
    set_size(2);
    set_type("slashing");
    set_prof_type("sabre");
    set_ac(0);
    set_property("enchantment",5);
    set_value(2000);
    set_wc(1,10);
    set_large_wc(1,18);
}