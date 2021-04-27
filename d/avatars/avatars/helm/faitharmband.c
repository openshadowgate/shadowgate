#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather armband");
	set_id(({ "armband", "leather armband" }));
	set_short("%^RESET%^%^ORANGE%^A leather armband%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A leather armband%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This armband is made out of several strips of leather intricately woven into a three inch wide band. It is clearly a work of elven craftsmanship and the weave allows it to stretch slightly so it can slip up the arm and fit various wearers. Something is written in a gently flowing script on one of the wider leather bands.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^YELLOW%^-=-=-=%^RESET%^%^GREEN%^faith%^YELLOW%^=-=-=-%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(15);
	set_type("clothing");
	set_limbs(({ "left arm" }));
	set_size(2);
	set_property("enchantment",0);
}


