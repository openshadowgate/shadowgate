//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("darksteel mesh");
    set_id(({"armor","darksteel mesh","armor","%^BLUE%^Darksteel Mesh%^RESET%^",}));
    set_short("%^BLUE%^Darksteel Mesh%^RESET%^");
    set_long(
@ARMOR
This suit resembles robes worn by Shou sex slaves more then actual combat armor.  It is made of thousands of silk-thin strands of %^BLUE%^Darkmetal%^RESET%^, the misterious substance derived from the underbellies of the %^RED%^Driders%^RESET%^ of the %^BLUE%^Underdark%^RESET%^ and other drow controlled regions.  The V shaped neck comes down to the breastbone, and the armor is only long enough to cover the wearer's body down to about middle of the hip.  Slits run up to the belt-like %^BOLD%^silver plated%^RESET%^ strap made of the same material as the rest of the armor.  The qualities of %^BLUE%^Darkmetal%^RESET%^ allow this flimsy armor to offer good protection to its wearer and really makes for a striking outfit
ARMOR
        );
    set_weight(35);
    set_size(2);
    set_type("chain");
    set_limbs(({"torso",}));
    set_ac(10);
    set_property("enchantment",1);
    set_value(2500);
}