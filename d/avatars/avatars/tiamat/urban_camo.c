#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("urban pants");
	set_id(({ "pants", "pant", "urban camouflage" }));
	set_short("%^RESET%^Urban C%^BOLD%^%^BLACK%^am%^RESET%^o%^BOLD%^u%^BLACK%^fl%^RESET%^ag%^BOLD%^e%^RESET%^");
	set_obvious_short("%^RESET%^gr%^BOLD%^a%^BLACK%^ve%^RESET%^l colored pants%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a pair of pants made from tough, durable linen.  They are charcoal in color, but composed of a patchwork of %^BOLD%^%^BLACK%^blacks%^RESET%^, greys and dull %^BOLD%^%^WHITE%^whites%^RESET%^.  From a distance, they would blend in with an urban environment.  The pants tie snugly around the waist through the use of a hemp cord in matching grey.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(790);
	set_lore(
@AVATAR
Urban camouflage was developed simultaneously by Tharis spies and the clergy of Kelemvor.  They are favored by those that frequent dark alleyways and deep crypts.  Many pair have fallen into general circulation by the adventuring population, not so much for stealth but for the pants' legendary durability and practical nature.

AVATAR
	);
	set_property("lore difficulty",7);
	set("conbonus",1);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^ "+ETOQCN+" %^RESET%^puts on some very durable pants.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^You put on the pants and feel ready for the long haul.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^RESET%^unties the cord on their pants before removing.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^You untie the hemp cord around the pants%^RESET%^");
	return 1;
}
