#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Crown of Thorns");
	set_id(({ "crown", "crown of thorns", "thorns" }));
	set_short("%^RESET%^%^RED%^Crown of Th%^ORANGE%^o%^RED%^rns%^RESET%^");
	set_obvious_short("%^RED%^a barbed crown%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^Two barbed %^GREEN%^vines%^RED%^ have been entwined to create this malicious headpiece. The sharp, tiny jaggers jut out sharply as a constant reminder of %^RESET%^pain%^RED%^ to the wearer. The crown has been stained a deep red, most likely by the blood of the masochist who wears it.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
}


