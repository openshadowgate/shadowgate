#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("twisted blade");
	set_id(({ "sword", "blade", "weapon", "short sword" }));
	set_short("%^BOLD%^%^RED%^Rez%^BOLD%^%^BLACK%^ral'a%^BOLD%^%^RED%^zk%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A %^RESET%^%^RED%^t%^BOLD%^%^RED%^wi%^RESET%^%^BLUE%^st%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^RED%^short sword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This short, twisted weapon is exquisitely crafted. The blade of the weapon is made out of wrought %^RESET%^%^BLUE%^iron %^BOLD%^%^BLACK%^steel and has been twisted in order to add a more brutal slash. A thin %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^runs down the length of the blade. The handle is oddly long for this size of weapon and the handle has a small, %^BOLD%^%^WHITE%^ivory %^BOLD%^%^BLACK%^button on it, near the hilt. The handle has been wrapped almost entirely by a rough %^BOLD%^%^GREEN%^skin %^BOLD%^%^BLACK%^to enhance grip.

AVATAR
	);
	set_weight(7);
	set_value(5000);
	set_lore(
@AVATAR
This sword was crafted sixty years ago in the Underdark. The recipient was a male drow of some report named Rezalron. Rezalron used the blade to supposedly take 1000 lives and then lost it. The blade, reknown for its cruelty has passed on from person to person for years.

AVATAR
	);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,10);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You grip the handle.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You unwield the twisted blade.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" presses a %^BOLD%^%^RED%^button %^BOLD%^%^BLACK%^on the handle of the twisted blade and another blade shoots out from the pommel. "+ETOQCN+" slashes "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You press the %^BOLD%^%^RED%^button %^BOLD%^%^BLACK%^on the handle and a blade shoots out from the pommel. You slash your opponent!");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" presses a %^BOLD%^%^RED%^button %^BOLD%^%^BLACK%^on the handle of the twisted blade and another blade shoots out from the pommel. "+ETOQCN+" slashes you!");
		return roll_dice(1,6)+-1;	}
}