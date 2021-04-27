#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^B%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^d %^BOLD%^%^BLACK%^short sword%^RESET%^");
	set_id(({ "sword", "Sword", "short sword", "Short sword", "Short Sword", "barbed sword", "Barbed sword", "Barbed Sword", "barbed short sword", "Barbed short sword" }));
	set_short("%^BOLD%^%^BLACK%^B%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^d %^BOLD%^%^BLACK%^short sword%^RESET%^");
	set_obvious_short("short sword");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is one nasty looking short sword. The blade is roughly two feet long with another six inches for the handle, there is no crossguard between the blade and handle. The handle is made up of some smaller %^BOLD%^%^WHITE%^bones %^BOLD%^%^BLACK%^that were tied tightly together, the grip is some rough %^RESET%^%^ORANGE%^leather %^BOLD%^%^BLACK%^wrapped around the bones. The blade is a %^RESET%^%^BLUE%^dark black color %^BOLD%^%^BLACK%^with little b%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rbs covering it in some random design. No matter which direction the blade was swung the b%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rbs would tear and rip the skin and muscle from the victim.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(100);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",1);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETOQCN+"'s light up while gripping the blade tightly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BLUE%^Your eyes light up as you grasp the blade tightly in your hand!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETOQCN+" gets a look of sadness while letting go of the blade.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BLUE%^You feel like you've lost a part of yourself as you release the blade.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^RESET%^%^BLUE%^The barbs on "+ETOQCN+"'s sword %^RESET%^%^RED%^rip %^RESET%^%^BLUE%^the flesh from %^BOLD%^%^BLUE%^"+targ->QCN+"%^RESET%^%^BLUE%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BLUE%^As you slice into %^BOLD%^%^BLUE%^"+targ->QCN+" %^RESET%^%^BLUE%^the barbs %^RESET%^%^RED%^rip %^RESET%^%^BLUE%^their flesh apart!%^RESET%^");
	tell_object(targ,"%^RESET%^%^BLUE%^As "+ETOQCN+" slashes you, the barbs on the blade %^RESET%^%^RED%^rip %^RESET%^%^BLUE%^your flesh away!%^RESET%^");
		return roll_dice(1,4)+1;	}
}