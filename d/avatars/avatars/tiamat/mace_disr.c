#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("mace of disruption");
	set_id(({ "mace" }));
	set_short("%^BOLD%^%^WHITE%^Mace of %^RESET%^%^BLUE%^Di%^BOLD%^sr%^CYAN%^up%^RESET%^%^CYAN%^tion%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^Highly polished mace%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a mace forged out of almost solid adamantium.  The shaft is thick and dense, and highly decorated in a cherub motif.  The grip is wound tightly in thick %^ORANGE%^leather%^WHITE%^, causing a slip of the weapon in hand a rare occurrence.  The striking head of the mace is large, about half again the size of a large grapefruit.  It is dense and solid, feeling heavy in hand.  It is polished perfectly smooth and round, such that you can make out your reflection vaguely on the surface.  The whole head hums quietly.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(2200);
	set_lore(
@AVATAR
A Mace of Disruption was a common weapon in the battle against the undead.  Few remain today.  The maces were most commonly crafted by priests of lawful faiths, and they are said to be blessed against the living dead.  Its name comes from the aura surrounding the striking head, which has a vibrating aura used to shatter nonliving material.  The shaft of each mace was usually personalized for its former owner or church.

AVATAR
	);
	set_property("lore difficulty",11);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The mace wielded by "+ETOQCN+" begins to %^CYAN%^hum%^WHITE%^ and vibrate.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The striking head of the mace begins to %^CYAN%^hum%^WHITE%^ loudly, vibrating your arm!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^The mace held by "+ETOQCN+" %^RESET%^stops humming so loudly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^The mace quiets to a gentle hum.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The mace wielded by "+ETOQCN+" smashes into "+targ->QCN+" with a wave of vibrating %^RESET%^%^BLUE%^di%^BOLD%^sr%^CYAN%^up%^RESET%^%^CYAN%^tion%^RESET%^!!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your mace smashes into "+targ->QCN+" with a wave of vibrating %^RESET%^%^BLUE%^di%^BOLD%^sr%^CYAN%^up%^RESET%^%^CYAN%^tion%^RESET%^!!");
	tell_object(targ,"%^RESET%^%^CYAN%^Your body is smashed with a wave of disruption from the mace wielded by "+ETOQCN+"%^RESET%^!!");
		return roll_dice(1,8)+-1;	}
}