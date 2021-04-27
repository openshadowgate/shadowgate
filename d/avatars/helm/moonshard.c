#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "moonshard", "shard", "dagger", "weapon", "blade", "longdagger", "long dagger" }));
	set_short("%^RESET%^%^BOLD%^Moonshard%^RESET%^");
	set_obvious_short("a pale longdagger");
	set_long(
@AVATAR
This is a longdagger wrought of what appears to be mithril. The metal is cold to the touch and somewhat dull in color, as if in need of oils and polish. The blade is about a foot long and marked with runes tinted with black, the hilt is skillfully wound with black leather.

AVATAR
	);
	set_weight(2);
	set_value(1533);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,5);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ grabs the hilt of the longdagger.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^You grab the cold hilt of the longdagger.%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ unwields the longdagger.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^You ease your grip on the still cold hilt of the longdagger.%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^The dagger grows less dull as you strike at "+targ->query_cap_name()+"%^RESET%^%^BOLD%^ and hits.%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ hits you with a pale white dagger.%^RESET%^");
		return roll_dice(1,4)+0;	}
}