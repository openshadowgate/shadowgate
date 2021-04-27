#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ebon handaxe");
	set_id(({ "axe", "ebony axe", "ebon axe", "ebony handaxe", "ebon handaxe" }));
	set_short("%^BOLD%^%^BLACK%^Ebony Handaxe%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^ebony handaxe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This small axe has been crafted from an ebony metal, its design is flawless.  Engraved into the head of the axe is a %^RED%^reddish-orange%^BOLD%^%^BLACK%^ sun, adding to the darkness of the axe an awkward hint of light.  There is an inscription beneath the sun.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^May light forever shine outward, exposing the hidden things.%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(6);
	set_value(100);
	set_type("slashing");
	set_prof_type("small axe");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" grabs the handle of the "+query_short()+"%^BOLD%^%^WHITE%^ and the engraving on its blade begins %^YELLOW%^glowing!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^As you grab the handle of the "+query_short()+"%^BOLD%^%^WHITE%^, the sun engraved into its blade begins %^YELLOW%^glowing!%^BOLD%^%^WHITE%^");
	TP->add_attack_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^The blade of "+TP->query_cap_name()+"'s%^BOLD%^%^WHITE%^ "+query_short()+"%^BOLD%^%^WHITE%^ stops %^YELLOW%^glowing!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^As you release the "+query_short()+"%^BOLD%^%^WHITE%^ its blade stops %^YELLOW%^glowing!%^RESET%^");
	TP->add_attack_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The head of the "+query_short()+"%^BOLD%^%^WHITE%^ wielded by "+ETO->query_cap_name()+"%^BOLD%^%^WHITE%^ %^RED%^glows%^BOLD%^%^WHITE%^ as it strikes "+targ->query_cap_name()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The head of your "+query_short()+"%^BOLD%^%^WHITE%^ %^RED%^glows%^BOLD%^%^WHITE%^ as it strikes "+targ->query_cap_name()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^The head of "+ETO->query_cap_name()+"'s%^BOLD%^%^WHITE%^ "+query_short()+"%^BOLD%^%^WHITE%^ %^RED%^glows%^BOLD%^%^WHITE%^ as it strikes you, draining your energy!%^RESET%^");
		return roll_dice(1,6)+0;	}
}