#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Dwarf Slicer");
	set_id(({ "sword", "longsword", "long sword", "dwarf slicer" }));
	set_short("Dwarf Slicer");
	set_obvious_short("longsword");
	set_long(
@AVATAR
This ancient elven blade has a tapered and double-edged blade. It's hilt is wrapped in soft leather and the strong guard angles up in such a way as to aid in particular against hammer and axe type weapons. The pommel holds a gorgeous single large star sapphire.

AVATAR
	);
	set_weight(15);
	set_value(2000);
	set_lore(
@AVATAR
One of the elven blades made to help defeat the dwarves from one of the race wars from long ago.

AVATAR
	);
	set_type("slashing");
	set_prof_type("blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,5);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" momentarily gets a faraway look in his eyes as he wields "+query_short()+".",ETO);
	tell_object(ETO,"Your mind floods with memories of battles, your fallen cousins, and the dwarves that killed them as you wield "+query_short()+".");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" seems to hesitate as they unwield "+query_short()+".",ETO);
	tell_object(ETO,"You hesitate slightly as you grieve for your cousins and try to push back your hatred for the dwarves that killed them.");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),""+query_short()+" cuts "+targ->query_cap_name()+" easily with each slash from "+ETO->query_cap_name()+".",({ETO,targ}));
	tell_object(ETO,""+query_short()+" cuts "+targ->query_cap_name()+" easily.");
	tell_object(targ,""+query_short()+" cuts you easily as "+ETO->query_cap_name()+" slashes at you.");
		return roll_dice(1,6)+0;	}
}