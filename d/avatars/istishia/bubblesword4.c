#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Bubbleblade");
	set_id(({ "blade", "bubbleblade", "sword", "bubbles" }));
	set_short(" %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^RESET%^");
	set_obvious_short("%^CYAN%^A strange looking ringed blade%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This eerie blade appears appears to have been made with a childs toy in mind. Its bluish tinted length is inscribed with wavey images and curves into several rings at its end. Each ring is highly bejeweled and inscribed with images of seashells and sea creatures at play, and within each ring can be seen a %^RED%^r%^YELLOW%^a%^MAGENTA%^in%^BLUE%^b%^RED%^o%^MAGENTA%^w%^BLUE%^ tinted lens of water.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(12000);
	set_lore(
@AVATAR
*

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1000,10);
	set_large_wc(1000,10);
	set_property("enchantment",30);
	set_ac(5000);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" %^MAGENTA%^giggles%^WHITE%^ childishly as she takes the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^WHITE%^ in hand.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^you %^MAGENTA%^giggle%^WHITE%^ childishly as you take the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^WHITE%^ in hand");
	ETO->add_attack_bonus(10000);
	ETO->add_damage_bonus(100000);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" sighs wistfully as the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^WHITE%^ leaves her grasp%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You sigh wistfully as the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^WHITE%^ leaves your grasp%^RESET%^");
	ETO->add_attack_bonus(-10000);
	ETO->add_damage_bonus(-100000);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^A stream of Bubbles trail in the wake of the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^BLUE%^ as it cleaves through "+targ->QCN+"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^A stream of Bubbles trail in the wake of the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^BLUE%^ as it cleaves through "+targ->QCN+"");
	tell_object(targ,"%^BOLD%^%^BLUE%^A stream of Bubbles trail in the wake of the %^BOLD%^%^BLUE%^B%^CYAN%^u%^BLUE%^bb%^WHITE%^l%^CYAN%^e %^BLUE%^B%^WHITE%^l%^CYAN%^a%^BLUE%^d%^WHITE%^e%^BLUE%^ as it cleaves through you, leaving you unable to see your opponent!");
		targ->set_paralyzed(roll_dice(5,4)+-1);
return 0;	}
}