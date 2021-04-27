#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Jet black gr%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_id(({ "greaves" }));
	set_short("%^BOLD%^%^BLACK%^Jet black gr%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Jet black gr%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Finely crafted from leather, the jet black greaves are made to protect the lower legs and knees. Although they are mostly unadorned, a %^RESET%^%^RED%^red st%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^ip%^BOLD%^%^BLACK%^ of %^RESET%^%^RED%^g%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^n%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ lines the top of the greaves. Upon closer inspection, the bottom corner of the greaves has been embossed with the symbol of a coiled %^RESET%^%^GREEN%^sc%^BOLD%^%^BLACK%^our%^RESET%^%^GREEN%^ge%^BOLD%^%^BLACK%^. The flexibility of the leather would not hinder mobility while providing some protection and creating a sle%^RESET%^e%^BOLD%^%^BLACK%^k appearance.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Crafted especially for those of the faith, these greaves are a prized possesion of Loviatar's faithful.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" smiles darkly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^A searing pain ripples through your body.%^RESET%^");
	return 1;
}

