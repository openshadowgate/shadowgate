#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Coif of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_id(({ "coif", "Coif", "shadow coif", "Shadow coif", "Shadow Coif" }));
	set_short("%^BOLD%^%^BLACK%^Coif of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("Dark coif");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This dark coif almost looks to be a dark leather or cloth at a glance, though as you get a closer look though you realize it is swirling %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^holding the form of a coif. It is large enough to partially cover the face of the wearer, protect their head, neck, and upper shoulders. Being made of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^, you'd expect the coif to be very light and not hinder the wearer.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
The coif forged of shadows. Worn only by agents of the Shadow Lord, slaves to his will, never to be free, but always willing. Made by the clergy of the Lord of Shadows for agents of their lord for multiple reasons. First is to keep them safe and protected by the Lord himself. Second is to conceal the wearer in an attempt to aid them in their mission. Third is so the clergy and their Lord can watch the agent and control it to whatever end.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to flow in and wrap around %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^head.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^wrap around your head.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETOQCN+" %^BOLD%^%^BLACK%^squints as the %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^funnel away from their head.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Everything seems brighter as the %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^funnel off of your head.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
