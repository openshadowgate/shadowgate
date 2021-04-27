#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Sword of Glory");
	set_id(({ "sword", " two handed", " two-handed sword", " two-handed" }));
	set_short("%^WHITE%^Sword of Glory%^RESET%^");
	set_obvious_short("a two-handed sword");
	set_long(
@AVATAR
%^WHITE%^This masterpiece of a weapon, is made out of a unknown metal, the blade itself is Ivory White, and down the middle of the blade, a %^BOLD%^%^BLACK%^black line %^RESET%^%^WHITE%^runs, where the blood can run off. On the hilt there are several %^YELLOW%^golden ornaments%^WHITE%^, and delicate carvings, with ancient runes, and strong leather bands, provide exellent grip on the long blade. In the end, a huge %^RED%^red ruby %^WHITE%^is embedded.

AVATAR
	);
	set_weight(20);
	set_value(6000);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(2,6);
	set_large_wc(3,5);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^WHITE%^"+TP->query_cap_name()+" wields the gorgeous blade, and you notice the %^RED%^ruby %^WHITE%^glow softly.",TP);
	tell_object(TP,"%^WHITE%^You wield the gorgeous blade, and notice the %^RED%^ruby %^WHITE%^glow softly.");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^WHITE%^As "+TP->query_cap_name()+" unwields the blade, the %^RED%^ruby %^WHITE%^stops glowing.",TP);
	tell_object(TP,"%^WHITE%^As you unwield the blade, the %^RED%^ruby %^WHITE%^stops glowing.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^RED%^The blade flows through the air, and cuts deeply into "+targ->query_cap_name()+"",({ETO,targ}));
	tell_object(ETO,"%^RED%^The blade flows through the air, and cuts deeply into your foe");
	tell_object(targ,"%^RED%^The blade flows through the air, and cuts you deeply");
		targ->set_paralyzed(roll_dice(1,0)+0);
return 0;	}
}