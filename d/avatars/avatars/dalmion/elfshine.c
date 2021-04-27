//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("sword");
    set_id(({"weapon","sword","elfshine","%^BLUE%^Sword of Doom%^RESET%^",}));
    set_short("%^BLUE%^Sword of Doom%^RESET%^");
    set_long(
@WEAPON
%^BLUE%^This sword is made from the very essence of darkness. Your skin feels frigid while it touches the %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^. You can feel it willing you to commit acts of such extreme hatred that %^RED%^Xvim%^BLUE%^ will take heed and recognize you as one of his own. Engraved into the hilt of this monstrous weapon is the word: "%^RED%^Elfshine"%^RESET%^
WEAPON
        );
    set_weight(8);
    set_size(2);
    set_type("slashing");
    set_prof_type("elfshine");
    set_ac(0);
    set_property("enchantment",3);
    set_value(200);
    set_wc(1,12);
    set_large_wc(1,14);
}