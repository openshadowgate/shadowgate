#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Robe of the Reaper");
	set_id(({ "armor", "robe" }));
	set_short("%^BOLD%^%^BLACK%^A flowing black robe%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A flowing black robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This simple cowled robe is all that adorns the reaper's frame.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^This simple cowled robe has belonged to the Grim Reaper as long as death has existed.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" don their robe yet again, and prepares for the eternal deliverance of lost souls.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You don your robe yet again, and prepare for the eternal deliverance of lost souls.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" takes a break from the eternal struggle of lost souls.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You take a break from the eternal struggle of lost souls.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The simple black robe encompasses "+who->QCN+"'s weapon and absorbs the blow.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The simple black robe encompasses "+who->QCN+"'s weapon and absorbs the blow.%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^The simple black robe encompasses your weapon and absorbs the blow.%^RESET%^");
		ETO->set_paralyzed(random(100/100));
return damage;	}
}