#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("starlight gown");
	set_id(({ "gown", "dress", "starlight gown" }));
	set_short("%^RESET%^%^BLUE%^Starlight Gown%^RESET%^");
	set_obvious_short("blue velvet dress");
	set_long(
@AVATAR
%^BLUE%^A short dress made of midnight blue velvet.  The velvet is high quiality and quite soft and plush.  The hem of the gown fall about to midcalf, allowing freedom in movement.  The velvet %^WHITE%^%^BOLD%^sparkles%^RESET%^%^BLUE%^ in the light, as if tiny stars have been almost magically attached to the fabric.  Hidden in the seams of the dress are two pockets.

AVATAR
	);
	set_weight(5);
	set_value(500);
	set_lore(
@AVATAR
The Starlight Gown is said to be a gift of the Lady of Magic, Mystra, to those she feels worthy of her gifts.

AVATAR
	);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" %^BLUE%^appears to be bathed in the a soft light.",ETO);
	tell_object(ETO,"%^BLUE%^You slip on the "+query_short()+" %^BLUE%^and watch as the fabric shimmers for you.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
