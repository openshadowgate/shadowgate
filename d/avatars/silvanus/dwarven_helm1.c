#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven Helm");
	set_id(({ "helm", "helmet", "dwarven helm", "dwarven helmet" }));
	set_short("%^BOLD%^%^BLACK%^Horned Dwarven Helmet%^RESET%^");
	set_obvious_short("horned helmet");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This helm is made from a fine mithril and has been forged perfectly to fit a dwarf. Two spiked horns protrude from the top of it and a %^RED%^symbol%^BOLD%^%^BLACK%^ of two %^RED%^crossing hammers%^BOLD%^%^BLACK%^ is engraved into its' front.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(100);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" pulls the "+query_short()+" on!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^Preparing for battle you wear the "+query_short()+"!%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" rips the "+query_short()+" off!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^You remove the "+query_short()+" and calm yourself!%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
