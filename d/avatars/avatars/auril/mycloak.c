#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("star cloak");
	set_id(({ "cloak" }));
	set_short("%^BOLD%^%^WHITE%^Seven-%^BOLD%^%^YELLOW%^starred %^RESET%^%^CYAN%^cloak%^RESET%^");
	set_obvious_short("A long suede cloak");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This long suede cloak is made from the finest material. Soft to the touch, it radiates a soft glow that is quite obvious to even those without magical abilities. The cloak depicts a large circle in the center of the cloak that has a %^RESET%^%^RED%^red %^BOLD%^%^WHITE%^tendral of the weave going from the bottom to the top. Around the weave, %^RESET%^%^CYAN%^seven stars %^BOLD%^%^WHITE%^surround it, glittering slightly. This is obviously a beautiful gift, and one to be treasured.

AVATAR
	);
	set_weight(5);
	set_value(10000);
	set_lore(
@AVATAR
Granted to Mystra followers for their devotion.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel proud as you wear the cloak.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-5);
	return 1;
}
