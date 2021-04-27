#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Bow Saw");
	set_id(({ "saw", "bow saw", "woodland saw" }));
	set_short("%^GREEN%^A %^RESET%^%^RED%^B%^RESET%^%^ORANGE%^o%^GREEN%^w%^RED%^ S%^GREEN%^a%^BOLD%^%^GREEN%^w%^RESET%^");
	set_obvious_short("a woodland saw");
	set_long(
@AVATAR
%^CYAN%^The bow that supports the blade of this saw is fashioned from a %^ORANGE%^bent green wo%^GREEN%^o%^ORANGE%^d branch%^CYAN%^.  The blade has been indented in a pattern suitable for cutting dead wood, with straight %^BOLD%^%^WHITE%^p%^RESET%^oi%^BOLD%^%^WHITE%^nt%^RESET%^e%^BOLD%^%^WHITE%^d t%^RESET%^e%^BOLD%^%^WHITE%^et%^RESET%^h%^CYAN%^.  A useful tool for any outdoor camp.  %^RED%^The steel blade looks vicious.

AVATAR
	);
	set_weight(5);
	set_value(2570);
	set_type("slashing");
	set_prof_type("tool");
	set_size(2);
	set_wc(2,5);
	set_large_wc(2,4);
	set_property("enchantment",2);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^You feel closer to nature as you hold the saw%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^%^"+targ->QCN+" is cut by a saw%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^The saw scrapes along "+targ->QCN+"'s skin%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^%^"+ETOQCN+"'s blade saws through your skin!%^RESET%^");
		return roll_dice(1,4)+0;	}
}