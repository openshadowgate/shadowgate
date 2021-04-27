#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armband");
	set_id(({ "armband" }));
	set_short("%^BOLD%^%^CYAN%^A%^YELLOW%^r%^CYAN%^mb%^YELLOW%^a%^CYAN%^nd of %^YELLOW%^A%^CYAN%^nhur%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^S%^BLUE%^t%^CYAN%^e%^BLUE%^e%^CYAN%^l %^BLUE%^B%^CYAN%^l%^BLUE%^u%^CYAN%^e %^BLUE%^A%^CYAN%^rmb%^BLUE%^a%^CYAN%^nd%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a fine silk %^BLUE%^Armband%^CYAN%^ with an embroidered symbol of %^YELLOW%^A%^CYAN%^nh%^YELLOW%^u%^CYAN%^r. You feel it has some %^GREEN%^power%^CYAN%^ to it.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^These armbands are the mark of expert soldiers of Anhur. Once worn by powerful legionaries of the %^RESET%^%^ORANGE%^desert%^BOLD%^%^CYAN%^, some of these fell into the hands of %^BLACK%^Cyrists%^CYAN%^ as a way of infiltrating the brotherhood. They are still widely known as marks of bravery, despite the tarnishment at the hands of the mad murderers.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}



