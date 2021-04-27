#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("smokey boots");
	set_id(({ "boots", "boot", "shoe", "shoes", "smoke boots" }));
	set_short("%^RESET%^S%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^k%^RESET%^e B%^BOLD%^%^BLACK%^o%^RESET%^o%^BOLD%^%^BLACK%^t%^RESET%^s%^RESET%^");
	set_obvious_short("%^RESET%^smoke colored boots%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a pair of boots of a very unusual nature.  You suspect that the
boots are mostly comprised of leather, but the outer layer is covered with
felt the color of thick smoke.  They seem rather light for their size and
halfway up the calf, tied with thick black leather laces.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1200);
	set_lore(
@AVATAR
Smoke Boots are popular among assassins working in Azha.  They are
lightweight and keep the feet dry on the hottest summer days.  A rare few
pair have been enchanted by the masters to harness the power of the
sandstorm, smoke, and chaos.  The wise killer uses these powers to their
tactical advantage.

AVATAR
	);
	set_property("lore difficulty",14);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^As "+ETOQCN+"%^RESET%^ slips on their boots, they give off a puff of %^BOLD%^%^BLACK%^dark smoke%^RESET%^.",ETO);
	tell_object(ETO,"%^RESET%^When you slip on the boots, they release a puff of %^BOLD%^%^BLACK%^dark smoke%^RESET%^.");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),""+ETOQCN+" %^RESET%^%^BOLD%^%^BLACK%^vanishes in a puff of smoke, then emerges for a quick strike on "+who->QCN+"%^RESET%^%^BOLD%^%^BLACK%^.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You vanish in a puff of smoke and use your concealment to land a quick blow on "+who->QCN+"%^RESET%^%^BOLD%^%^BLACK%^!%^RESET%^");
	tell_object(who,""+ETOQCN+" %^RESET%^%^BOLD%^%^BLACK%^vanishes in a puff of smoke, then lands a quick blow from behind you!%^RESET%^");
		who->do_damage("torso",random(6));
return damage;	}
}