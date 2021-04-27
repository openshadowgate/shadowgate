#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Greaves of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_id(({ "greaves", "Greaves", "shadow greaves", "Shadow greaves", "Shadow Greaves" }));
	set_short("%^BOLD%^%^BLACK%^Greaves of %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("Dark greaves");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These are a pair of dark greaves, round in shape with no special curves or the like. Though for rather simple greaves they have a very interesting and unique quality. No part of them is a physical material. They seem to be created completely of living %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^, moving about freely in the form of greaves.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
The greaves forged of shadows. Worn only by agents of the Shadow Lord, slaves to his will, never to be free, but always willing. Made by the clergy of the Lord of Shadows for agents of their lord for multiple reasons. First is to keep them safe and protected by the Lord himself. Second is to conceal the wearer in an attempt to aid them in their mission. Third is so the clergy and their Lord can watch the agent and control it to whatever end. 

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^seem to flow in and wrap around %^RESET%^%^BLUE%^"+ETOQCN+"'s %^BOLD%^%^BLACK%^lower legs.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^wrap around your lower legs.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^escape from %^RESET%^%^BLUE%^%N's %^BOLD%^%^BLACK%^lower legs and disappear.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^slowly escape from around your lower legs and disappear.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
