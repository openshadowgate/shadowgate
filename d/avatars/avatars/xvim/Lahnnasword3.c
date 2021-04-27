#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Fighters sword of glory");
	set_id(({ "sword", " two handed sword", " two handed" }));
	set_short("%^WHITE%^Sword of Glory%^RESET%^");
	set_obvious_short("a two-handed sword");
	set_long(
@AVATAR
%^WHITE%^This masterpiece of a weapon, is made out of a unknown metal, the blade itself is Ivory White, and down the middle of the blade, a %^BOLD%^BLACK%^Black%^RESET%^%^WHITE%^ line runs, where the blood can run off. On the hilt there are several golden ornaments, and delicate carvings, with ancient runes, and strong leather bands, provide exellent grip on the long blade. In the end, a huge %^RED%^red ruby%^RESET%^%^WHITE%^ is embedded.

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
	tell_room(ETP,"%^WHITE%^"+TP->query_cap_name()+" wields the gorgeous blade, and you notice the %^RED%^ruby %^WHITE%^glow softly%^RESET%^.",TP);
	tell_object(TP,"%^WHITE%^You wield the gorgeous blade, and notice the %^RED%^ruby %^WHITE%^glow softly%^RESET%^.");
	TP->add_stat_bonus("dexterity",1);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^WHITE%^As "+TP->query_cap_name()+" unwields the blade, the %^RED%^ruby%^WHITE%^ stops glowing.%^RESET%^",TP);
	tell_object(TP,"%^WHITE%^As you unwield the blade, the %^RED%^ruby%^WHITE%^ stops glowing.%^RESET%^");
	TP->add_stat_bonus("dexterity",1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^RED%^The blade flows through the air, and cuts deeply into your foe");
	tell_object(targ,"");
		targ->set_paralyzed(roll_dice(1,0)+0);
return 0;	}
}