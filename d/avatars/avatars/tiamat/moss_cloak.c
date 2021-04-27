#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("moss cloak");
	set_id(({ "cloak", "cape", "moss" }));
	set_short("%^RESET%^%^GREEN%^Cl%^BOLD%^o%^RESET%^%^GREEN%^ak of M%^ORANGE%^o%^GREEN%^ss%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^m%^ORANGE%^o%^GREEN%^ss covered cloak%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This is mid-length cloak that looks very different on each side.  The inner lining appears to woven into a rough %^ORANGE%^tan colored %^GREEN%^burlap.  Growing over the outside of the cloak is dense layer of wild %^BOLD%^moss %^RESET%^%^GREEN%^flecked with %^ORANGE%^golden %^GREEN%^fibers.  The cloak is not rotten, but surprising strong and durable.  The moss appears to have been grown there on purpose.  It has a subtly pleasant damp pine smell.  The cloak is clasped by a roughly polished bit of %^ORANGE%^cloudy %^YELLOW%^amber%^RESET%^%^GREEN%^.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(130);
	set_lore(
@AVATAR
The object in your hands is often known as a Moss Cloak.  Using a technique perfected by the druids of old, a strong fibrous moss is grown over an otherwise rough and durable cloak.  Because of its strong connection to nature, the cloak is easily enchanted and often given as gifts to young druids and rangers.

AVATAR
	);
	set_property("lore difficulty",9);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^GREEN%^A mildly pleasant pine fragrance surrounds "+ETOQCN+" as they don their moss cloak.",ETO);
	tell_object(ETO,"%^GREEN%^You feel a serene connection to the moss cloak.");
	ETO->set_property("magic resistance",4);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^The lovely pine smell vanishes as "+ETOQCN+" removes their cloak.%^RESET%^",ETO);
	tell_object(ETO,"%^GREEN%^You lose your connection to nature without the cloak.%^RESET%^");
	ETO->set_property("magic resistance",-4);
	return 1;
}
