//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("mace");
    set_id(({"weapon","mace","elfshine","%^GREEN%^Emerald Mace%^RESET%^",}));
    set_short("%^GREEN%^Emerald Mace%^RESET%^");
    set_long(
@WEAPON
%^BLUE%^This mace seems to glow with an inner pulsating %^CYAN%^light%^BLUE%^ and though it seems to be made from a simple steel, it appears to be somehow quite powerful, and capable of causing a great deal of damage. It has obviously been finely crafted by whatever hands where responsible and bears several mysterious and awkward %^RED%^runes%^BLUE%^ up and down the shaft. Along with this there is engraved into the shaft the simple word, "%^RED%^Elfshine%^BLUE%^"%^RESET%^
WEAPON
        );
    set_weight(8);
    set_size(2);
    set_type("bludgeoning");
    set_prof_type("mace");
    set_ac(0);
    set_property("enchantment",2);
    set_value(200);
    set_wc(1,12);
    set_large_wc(1,14);
}