#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^CYAN%^Ak%^RESET%^a%^BOLD%^%^CYAN%^di's Mace%^RESET%^");
	set_id(({ "mace" }));
	set_short("%^BOLD%^%^CYAN%^Ak%^RESET%^a%^BOLD%^%^CYAN%^di's Mace%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^simple iv%^RESET%^o%^BOLD%^%^WHITE%^ry mace%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Made of polished ivory, this mace appears mostly harmless. A small %^RESET%^white %^BOLD%^%^WHITE%^sphere hangs from the end of a delicate white chain. The handle is embedded with cut %^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^ap%^BOLD%^%^BLUE%^p%^RESET%^%^BLUE%^h%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^re%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^, formed into the image of birds which %^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^p%^RESET%^ir%^BLUE%^a%^BOLD%^%^BLUE%^l %^BOLD%^%^WHITE%^along its length. It is very pretty, even if it doesn't look especially effective.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(100);
	set_lore(
@AVATAR
%^CYAN%^Property of the Queen of the Air.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size();
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",5);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^The small sphere begins to %^BOLD%^%^WHITE%^glow%^RESET%^%^CYAN%^ brightly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The small sphere begins to %^BOLD%^%^WHITE%^glow%^RESET%^%^CYAN%^ brightly.%^RESET%^");
	ETO->add_damage_bonus(3);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The small sphere %^RESET%^dims%^BOLD%^%^BLUE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The small sphere %^RESET%^dims%^BOLD%^%^BLUE%^.%^RESET%^");
	ETO->add_damage_bonus(3);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The small sphere of "+ETOQCN+"'s mace begins to spin rapidly, forming a %^RESET%^%^CYAN%^whirlwind%^BOLD%^%^WHITE%^. %^YELLOW%^Lightning%^BOLD%^%^WHITE%^ streaks out, striking "+targ->QCN+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The small sphere begins to spin, causing a %^RESET%^%^CYAN%^whirlwind%^BOLD%^%^WHITE%^. %^YELLOW%^Lightning%^BOLD%^%^WHITE%^ streaks out from the concentrated air, striking your opponent.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^YELLOW%^Jagged streaks of %^BOLD%^%^WHITE%^lightning%^YELLOW%^ from "+ETOQCN+"'s mace strike into you, inflicting some damage.%^RESET%^");
	}
}