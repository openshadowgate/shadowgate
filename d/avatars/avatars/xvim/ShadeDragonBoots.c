#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Red Dragon Scale boots");
	set_id(({ "boots", "red boots" }));
	set_short("%^RED%^Red dragonskin boots%^RESET%^");
	set_obvious_short("%^RED%^A pair of red boots%^RESET%^");
	set_long("%^BLUE%^These boots are covered in the scales of a %^RED%^red dragon %^BLUE%^with the hide of the beast filling the spaces. They seem to be very tough and durable.");
	set_weight(10);
	set_value(500);
	set_lore("The boots are made out of the scales of the feared Red Dragon that terrorized shadow.");
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",4);
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_object(TP,"%^RED%^You wear the hard boots and feel well protected");
	return 1;
}

int remove_func(){
	tell_object(TP,"You remove the hard boots and feel the warmth slip from your toes.");
	return 1;
}
