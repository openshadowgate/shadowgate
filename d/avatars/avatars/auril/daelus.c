#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("daelus");
	set_id(({ "sword", "bastard sword", "weapon" }));
	set_short("%^BOLD%^%^GREEN%^Daelus's %^BOLD%^%^CYAN%^hope%^RESET%^");
	set_obvious_short("A %^BOLD%^%^WHITE%^silver %^RESET%^bladed bastard sword with a %^RESET%^%^GREEN%^jade %^RESET%^handle%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^The hilt of this blade is made out of carved %^BOLD%^%^GREEN%^jade%^RESET%^%^GREEN%^. The blade of the bastard sword is made out of %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ and polished to pefection. Along the blade is a set of %^BOLD%^%^YELLOW%^runes %^RESET%^%^GREEN%^that are inscribed with a soft %^BOLD%^%^CYAN%^glow%^RESET%^%^GREEN%^. The pommel of this sword is shaped into a %^BOLD%^%^YELLOW%^f%^BOLD%^%^RED%^l%^BOLD%^%^YELLOW%^ow%^BOLD%^%^RED%^er%^RESET%^%^GREEN%^.

AVATAR
	);
	set_weight(12);
	set_value(3000);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(1,8);
	set_property("enchantment",3);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You grip the sword tightly.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You sadly unwield the sword.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^The sword blade hums.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The sword blade hums.");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+"'s sword hums and you feel a jolt!");
		return roll_dice(1,6)+2;	}
}