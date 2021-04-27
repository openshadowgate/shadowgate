#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("slicing whip");
	set_id(({ "whip", "slicing whip", "barbed whip" }));
	set_short("%^BOLD%^%^BLACK%^Sl%^RED%^i%^YELLOW%^c%^RED%^i%^BLACK%^ng W%^RED%^h%^YELLOW%^i%^BLACK%^p %^RED%^o%^BLACK%^f P%^RED%^a%^YELLOW%^i%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a b%^RED%^a%^YELLOW%^r%^BLACK%^b%^RED%^e%^BLACK%^d whip%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This whip is of fairly simple design but looks like it would be dangerous, if not deadly, in the right hands.  The braided strips of leather are tightly bound, creaking as they move and coil.  Their alternating shades of %^YELLOW%^yellow%^BLACK%^, black and %^RED%^red%^BLACK%^, making them mesmerizing to watch.  Reminding you of a snake as it coils ready to strike.  Worked into the braid are dozens of sharp %^WHITE%^metal barbs%^BLACK%^, designed to tear and bite into the flesh.  The grip of this whip is fashioned of %^RESET%^%^CYAN%^steal %^BOLD%^%^BLACK%^and tapers to a long sharp point, making you wonder if this weapon doesn't have other uses as well.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(300);
	set_lore(
@AVATAR
This whip and several others like it were fashioned by a rather intelligent bugbear named Theylis Clawedsnout who, after being nearly torn apart by a pack of human adventurers, decided to make a dangerous ranged weapon. Theylis made several versions of his whips, each with a different purpose.  Though it is said that his barbed one was the most dangerous of them all.

AVATAR
	);
	set_property("lore difficulty",17);
	set_type("lash");
	set_prof_type("whip");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" uncoils the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ and gets ready to strike!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You uncoil the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ and get ready to strike!%^RESET%^");
	ETO->add_damage_bonus(4);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" curls the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ up, carefully avoiding the sharp barbs.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You curl the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ up, carefully avoiding the sharp barbs.%^RESET%^");
	ETO->add_damage_bonus(-4);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" wraps the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ around "+targ->QCN+"'s neck and yanks them off balance.  Reversing their grip, "+ETOQCN+" %^RED%^slams %^BLUE%^the %^WHITE%^sharp spike %^BLUE%^on the end of the %^RESET%^"+query_short()+"'s%^BOLD%^%^BLUE%^ grip deep into "+targ->QCN+"'s chest!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You wrap the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ around "+targ->QCN+"'s neck and yank them to you.  Reversing your grip, you %^RED%^slam %^BLUE%^the %^WHITE%^sharp spike %^BLUE%^on the end of the grip deep into "+targ->QCN+"'s chest!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" wraps the %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ around your neck! As you struggle to get away, they reverse their grip and %^RED%^slam %^BLUE%^the %^RESET%^"+query_short()+"'s %^WHITE%^sharpened spike %^BLUE%^ deep into your chest!%^RESET%^");
		return roll_dice(2,4)+2;	}
}