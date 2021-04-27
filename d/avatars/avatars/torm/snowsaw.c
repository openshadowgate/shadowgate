#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Snow Saw");
	set_id(({ "saw", "snow saw" }));
	set_short("%^BOLD%^%^WHITE%^Sno%^CYAN%^w%^WHITE%^ Saw%^RESET%^");
	set_obvious_short("a snow saw");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a steel saw with a %^RESET%^%^ORANGE%^cloth bou%^RED%^n%^ORANGE%^d wooden handle%^BOLD%^%^CYAN%^.  The blade has been indented in a pattern suitable for cutting through snow and ice, with %^WHITE%^rou%^CYAN%^n%^WHITE%^ded %^CYAN%^i%^WHITE%^nde%^CYAN%^n%^WHITE%^tat%^CYAN%^i%^WHITE%^ons%^CYAN%^ a%^WHITE%^nd s%^CYAN%^h%^WHITE%^arp%^CYAN%^,%^WHITE%^ fla%^CYAN%^t%^WHITE%^ tee%^CYAN%^t%^WHITE%^h.%^CYAN%^  A useful tool for anyone who travels through cold, snowy landscapes.  %^RED%^The steel blade looks very sharp.

AVATAR
	);
	set_weight(4);
	set_value(2700);
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
	tell_object(ETO,"%^BOLD%^WHITE%^You take care not to touch the icy blade%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+targ->QCN+" is cut by a saw%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The saw scrapes along "+targ->QCN+"'s skin%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s icy blade sends a shiver down your spine!%^RESET%^");
		return roll_dice(1,4)+0;	}
}