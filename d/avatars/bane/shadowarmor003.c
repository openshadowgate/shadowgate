#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Boots of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_id(({ "boots", "Boots", "shadow boots", "Shadow boots", "Shadow Boots" }));
	set_short("%^BOLD%^%^BLACK%^Boots of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("dark boots");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A pair of strange looking boots, made up of swirling %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^they are just slightly see through if you look hard enough and makes it almost look like the wearer is %^BOLD%^%^CYAN%^floating%^BOLD%^%^BLACK%^. The boots have no %^BOLD%^%^WHITE%^buckle %^BOLD%^%^BLACK%^or anything else to fasten them with, just masses of swirling %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^formed to look like a set of boots.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
The boots forged of shadows. Worn only by agents of the Shadow Lord, slaves to his will, never to be free, but always willing. Made by the clergy of the Lord of Shadows for agents of their lord for multiple reasons. First is to keep them safe and protected by the Lord himself. Second is to conceal the wearer in an attempt to aid them in their mission. Third is so the clergy and their Lord can watch the agent and control it to whatever end.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to flow in and wrap around %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^feet.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^wrap around your feet.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to drain off of %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^feet.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^drain off of your feet leaving them feeling a bit cold.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
