#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Bracers of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_id(({ "bracers", "Bracers", "shadow bracers", "Shadow bracers", "Shadow Bracers" }));
	set_short("%^BOLD%^%^BLACK%^Bracers of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("Dark bracers");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^They look to be simple darkened %^RESET%^%^WHITE%^metal %^BOLD%^%^BLACK%^bracers at first, though the %^RESET%^%^WHITE%^metal %^BOLD%^%^BLACK%^seems odd. As you watch them a bit more, the color seems to shift about and the %^RESET%^%^WHITE%^metally %^BOLD%^%^BLACK%^look to them is all but gone. It'd be hard to tell what the bracers are actually made of leaving you only with the word: %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(2000);
	set_lore(
@AVATAR
The bracers forged of shadows. Worn only by agents of the Shadow Lord, slaves to his will, never to be free, but always willing. Made by the clergy of the Lord of Shadows for agents of their lord for multiple reasons. First is to keep them safe and protected by the Lord himself. Second is to conceal the wearer in an attempt to aid them in their mission. Third is so the clergy and their Lord can watch the agent and control it to whatever end.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to flow in and wrap around %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^forearms.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^wrap around your forearms.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As the %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seep into %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^arms, %^RESET%^%^BLUE%^"+ETOQCN+" %^BOLD%^%^BLACK%^shudders.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^slowly seep into your arm chilling your bones.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
