#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Tierenantinial's touch");
	set_id(({ "scimitar" }));
	set_short("%^BOLD%^%^YELLOW%^Ti%^BOLD%^%^WHITE%^ere%^BOLD%^%^YELLOW%^nan%^BOLD%^%^WHITE%^tinia%^BOLD%^%^YELLOW%^l's %^BOLD%^%^GREEN%^touch%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A shimmering silver scimitar%^RESET%^");
	set_long(
@AVATAR
This beautifully crafted %^BOLD%^%^WHITE%^silver%^RESET%^ scimitar has an %^BOLD%^%^BLACK%^ebony %^RESET%^handle and a %^BOLD%^%^WHITE%^mithril %^RESET%^crossguard that is connected by %^BOLD%^%^GREEN%^leaf-like %^RESET%^junctures in the metal. The blade looks extremely %^BOLD%^%^RED%^keen %^RESET%^and seems to change in color from a crystalline white to a dull silver. 

AVATAR
	);
	set_weight(8);
	set_value(20000);
	set_lore(
@AVATAR
This blade was crafted by the elven smith, Sarandrial Tllevonian as a gift for the silver dragon Tierenantinial for aiding their village from an attack of orcs nearly two hundred years ago. A prized item of the silver dragon, this blade supposedly never left its side and was kept by the dragon even in its travels. 

AVATAR
	);
	set_property("lore difficulty",29);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",6);
	set_ac(-2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You wield the scimitar and you feel a tingling sensation enter your body.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" jumps into the air and you hear a large humming sound as "+ETOQCN+" cuts %^BOLD%^%^RED%^deeply %^BOLD%^%^WHITE%^into "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You jump in the air and spin as the scimitar hums. It's blade cuts %^BOLD%^%^RED%^deeply %^BOLD%^%^WHITE%^into "+targ->QCN+".");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" jumps into the air and you hear a large humming sound as "+ETOQCN+" cuts %^BOLD%^%^RED%^deeply %^BOLD%^%^WHITE%^into you!");
		return roll_dice(5,6)+0;	}
}