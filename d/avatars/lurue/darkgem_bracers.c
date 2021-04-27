#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create(){
	::create();
	set_name("black bracers");
	set_id(({ "bracers", "black bracers", "jeweled bracers", "bracers of the kel'reththyl", "bracers of the kelreththyl", "drow bracers" }));
	set_short("%^BOLD%^%^GREEN%^B%^BLACK%^ra%^RESET%^%^GREEN%^c%^BOLD%^e%^BLACK%^r%^GREEN%^s %^BLACK%^of the %^GREEN%^K%^BOLD%^%^BLACK%^el'%^GREEN%^re%^RESET%^%^GREEN%^t%^BOLD%^ht%^BLACK%^hy%^GREEN%^l%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^GREEN%^j%^BLACK%^e%^GREEN%^w%^RESET%^%^GREEN%^e%^BOLD%^l%^BLACK%^e%^GREEN%^d %^BLACK%^set of %^GREEN%^l%^BLACK%^e%^GREEN%^a%^RESET%^%^GREEN%^t%^BOLD%^h%^BLACK%^e%^GREEN%^r b%^BLACK%^r%^GREEN%^a%^RESET%^%^GREEN%^c%^BOLD%^e%^BLACK%^r%^GREEN%^s%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These bracers are fashioned from thick black leather panels that wrap the lower arm in a protective shroud which extends from wrist to elbow.  Synched via leather lacing along the arm's underside, the bracers are pliable enough to fit on almost any arm.  Set with %^RESET%^%^CYAN%^iron studs %^BOLD%^%^BLACK%^along the exterior of the bracers are six %^RESET%^%^GREEN%^dark green emeralds%^BOLD%^%^BLACK%^.  Square cut, they run along the spine of the bracer catching and %^GREEN%^a%^BOLD%^%^BLACK%^b%^GREEN%^so%^RESET%^%^GREEN%^r%^BOLD%^bi%^BLACK%^n%^RESET%^%^GREEN%^g %^BOLD%^%^BLACK%^the light around them instead of reflecting it with the usual sparkling luster of such gemstones.%^RESET%^

AVATAR
	);
//	set_weight(10);
	set_value(3000);
	set_lore(
@AVATAR
Made by House Kel'reththyl, one of the many drow houses of the underdark, these bracers are designed to do one thing, protect their wearer from their surface, light using enemies.  Though many versions exist, they all bare a striking resemblance to each other with the simple, dramatic design and the light absorbing jewels.  Jewels said to be enchanted to draw light from any nearby source and transform it into dangerously dark magic. 

AVATAR
	);
	set_property("lore difficulty",22);
/*
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
*/
	set_property("enchantment",2);
//	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^As you lace the set of %^BOLD%^%^BLACK%^black bracers %^RESET%^%^GREEN%^up your arm you can feel the reserve of %^BOLD%^power %^RESET%^%^GREEN%^just waiting to consume your enemy.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^The thrum of power fades as you unlace the %^RESET%^"+query_short()+" %^RESET%^%^GREEN%^from your arm.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^RESET%^%^GREEN%^Crying out, "+ETOQCN+" brings their arms together at the wrists, and the%^BOLD%^ dark emeralds %^RESET%^%^GREEN%^of the %^RESET%^"+query_short()+" %^RESET%^%^GREEN%^ignite with a burning intensity that tears into "+who->QCN+"!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel subtle whisper of %^BOLD%^%^BLACK%^dark magic %^RESET%^%^GREEN%^coursing along your skin as it gathers within the gemstones of the "+query_short()+".  %^RESET%^%^GREEN%^Suddenly the emeralds %^BOLD%^ignite %^RESET%^%^GREEN%^with a burning dark light that tears into "+who->QCN+"!%^RESET%^");
	tell_object(who,"%^RESET%^%^GREEN%^You watch, unable to defend yourself as the power spills from the %^BOLD%^dark emeralds %^RESET%^%^GREEN%^upon "+ETOQCN+"'s %^RESET%^"+query_short()+" %^RESET%^%^GREEN%^and tears into your very being!%^RESET%^");
		who->do_damage("torso",random(16));
return damage;	}
}