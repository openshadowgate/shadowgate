#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("revkla's call");
	set_id(({ "axe", "medium axe", "revkla's call", "weapon" }));
	set_short("%^BOLD%^%^RED%^Re%^BOLD%^%^BLACK%^vkl%^RESET%^%^ORANGE%^a's %^BOLD%^%^BLACK%^Ca%^BOLD%^%^RED%^ll%^RESET%^");
	set_obvious_short("Battle axe");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This medium axe is finely crafted, it's head made out of pure %^BOLD%^%^WHITE%^adamantite%^BOLD%^%^RED%^. The edges have been sharpened to a %^BOLD%^%^YELLOW%^keen %^BOLD%^%^RED%^edge and lines of what look like trails of %^RESET%^%^RED%^blood %^BOLD%^%^RED%^trails off onto the axe. The handle is made out of %^RESET%^%^ORANGE%^oak %^BOLD%^%^RED%^that has been hardened and covered with %^BOLD%^%^YELLOW%^runes%^BOLD%^%^RED%^. On the end of the handle sits half of a dragons %^BOLD%^%^CYAN%^eye %^BOLD%^%^RED%^that watches everything that moves warily. And inscription flows up the side.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Chaos in heart, chaos forever.

AVATAR
	);
     set("langage","str");	set_weight(10);
	set_value(15000);
	set_type("slashing");
	set_prof_type("medium axe");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" wields the axe and smiles slightly.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^A voice in your head says: %^BOLD%^%^CYAN%^Come, we have things to do.");
	ETO->add_stat_bonus("strength",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" unwields the axe and frowns slightly.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^A voice in your head says: %^BOLD%^%^CYAN%^What? Are we finished? No, we have things yet to do!");
	ETO->add_stat_bonus("strength",-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^The axe wails and strikes "+targ->query_cap_name()+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The axe wails and strikes your target!");
	tell_object(targ,"%^BOLD%^%^YELLOW%^The axe wails and strikes you!");
		return roll_dice(2,6)+0;	}
}