#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^mi%^RESET%^t%^BOLD%^h%^RESET%^ri%^BOLD%^%^BLACK%^l gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_id(({ "greaves", "greave" }));
	set_short("%^BOLD%^%^BLACK%^Mi%^RESET%^t%^BOLD%^h%^RESET%^r%^BOLD%^%^BLACK%^il %^RESET%^%^RED%^Battle %^BOLD%^%^BLACK%^Gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^mi%^RESET%^t%^BOLD%^h%^RESET%^ri%^BOLD%^%^BLACK%^l gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^Tempered and impressive, the %^BOLD%^%^BLACK%^mi%^RESET%^t%^BOLD%^h%^RESET%^r%^BOLD%^%^BLACK%^il%^RESET%^%^RED%^ used to construct these small greaves looks absolutely indestructible. Shaped to fit the entire thick, small legs of a dwarf, adjustable %^ORANGE%^leather buckles%^RED%^ line the front of the hard metal. The firm metal has been polished to a glossy finish. The knee plates add flexibility to the otherwise unyielding greaves, and each plate has been adorned with a %^BOLD%^%^RED%^ga%^RESET%^%^RED%^r%^BOLD%^%^RED%^net shield%^RESET%^%^RED%^ bearing a %^BOLD%^%^WHITE%^s%^RESET%^h%^BOLD%^ini%^RESET%^n%^BOLD%^g si%^RESET%^lv%^BOLD%^er s%^RESET%^w%^BOLD%^o%^RESET%^r%^BOLD%^d%^RESET%^%^RED%^.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(3500);
	set_lore(
@AVATAR
Long ago, an ancient battle was fought in the desert east of the city now known as Shadow. Leading a small army of Tempus, the battle-priest Galfi rushed headlong into battle, destroying many enemies in his wake. Unfortunately, this was the last anyone saw of the brave dwarf who was struck down in the midst of battle. Sand and time nicked away at his prized mithril battle greaves, but they eventually resurfaced and were found by a small group of explorers who were scouting the area for goblin camps. The greaves were rightfully returned to the local temple of Tempus where they were restored to their original glory.

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("armor");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You effortlessly strap on the sturdy greaves.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-5);
	return 1;
}
