#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("black leather gloves");
	set_id(({ "glove", "gloves", "black leather glove", "black leather gloves" }));
	set_short("%^BOLD%^%^BLACK%^Black Leather Gloves%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Black Leather Gloves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These gloves are skin tight and go up almost the entire arms length of the wearer, to provide added warmth and extra protection during combat. They are made from a dull black leather that has been carefully treated, in order to ensure their durability and dependability.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BLUE%^You slip your hands into the comfortable "+query_short()+" %^RESET%^");
	return 1;
}

