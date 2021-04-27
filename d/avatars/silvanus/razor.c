//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("black razor");
    set_id(({"weapon","black razor","razor","%^BOLD%^%^BLACK%^Black Razor%^RESET%^",}));
    set_short("%^BOLD%^%^BLACK%^Black Razor%^RESET%^");
    set_long(
@WEAPON
%^BLUE%^This weapon is made from a %^RED%^jagged%^BLUE%^ and rugged looking %^BOLD%^%^BLACK%^black%^RESET%^%^BLUE%^ metal. Each edge of the blade is sharpened, giving it a terribly %^RED%^wicked%^BLUE%^ appearance. Engraved into the blade of the weapon are several mysterious %^WHITE%^runes%^BLUE%^, each the representation of a %^RED%^gruesome%^BLUE%^ scene. Meeting the blade through a %^BOLD%^%^BLACK%^dark grey%^RESET%^%^BLUE%^ pommel is a handle made from an equally dark and %^RED%^blood%^BLUE%^ stained andomanium%^RESET%^.
WEAPON
        );
    set_weight(10);
    set_size(2);
    set_type("slashing");
    set_prof_type("medium blades");
    set_ac(0);
    set_property("enchantment",2);
    set_value(400);
    set_wc(1,12);
    set_large_wc(1,10);
}