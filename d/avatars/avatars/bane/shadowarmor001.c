#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Armor of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_id(({ "leather", "Leather", "armor", "Armor", "shadow armor", "Shadow armor", "Shadow Armor" }));
	set_short("%^BOLD%^%^BLACK%^Armor of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("dark armor");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A strange looking suit of armor, seemingly composed completely out of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^. The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^twist and weave themselves around the wearer in the form of perhaps a %^RESET%^%^ORANGE%^leather %^BOLD%^%^BLACK%^type of armor. Since this armor has no material part to it you would think it wouldnt hinder your movement or make any noise what so ever. Despite its capabilities though, it is truly a magnificant sight.%^RESET%^

AVATAR
	);
	set_weight(20);
	set_value(500);
	set_lore(
@AVATAR
The armor forged of shadows. Worn only by agents of the Shadow Lord, slaves to his will, never to be free, but always willing. Made by the clergy of the Lord of Shadows for agents of their lord for multiple reasons. First is to keep them safe and protected by the Lord himself. Second is to conceal the wearer in an attempt to aid them in their mission. Third is so the clergy and their Lord can watch the agent and control it to whatever end.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to flow in around %^RESET%^%^BLUE%^"+ETOQCN+" %^BOLD%^%^BLACK%^and wrap themselves into a protective armor.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^wrap themselves around you.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^drain off of "+ETOQCN+" slowly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^drain off you.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
