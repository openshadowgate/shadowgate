#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "sword", "longsword", "long sword", "blade", "faerzress blade" }));
	set_short("%^RESET%^%^MAGENTA%^Fae%^BOLD%^%^BLACK%^rzr%^RESET%^%^MAGENTA%^ess %^RED%^Blade%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A darkly %^RESET%^%^MAGENTA%^glowing%^RED%^ sword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A finely crafted sword made from the ore %^RESET%^%^MAGENTA%^Faerzress%^BOLD%^%^BLACK%^.  It is about four feet in length with an ornate X shaped hilt, and a leering %^RED%^demons%^BLACK%^ face for the pommel. The blade is leaf shaped at the top, but tapers inward and forms a long striking surface. A blood groove runs down the middle of the blade within it are wicked looking %^RESET%^%^GREEN%^runes%^BOLD%^%^BLACK%^. The handle of the sword is forged from darksteel with a well worn leather wrapping the grip. The entire blade %^MAGENTA%^glows%^BLACK%^ with a soft purple light that also seems to absorb the light around it keeping the blade warm to the touch at all times.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
The runes in the blood groove spell out Foe Cleaver

AVATAR
	);
     set("langage","orcish");	set_weight(10);
	set_value(1000);
	set_lore(
@AVATAR
These blades are awarded to the Highest in command of the Grull-Thrak Orc tribe. Noted not only for thier use of swords advanced tactis and a sembalance of honor amongst thier tribe.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("medium blade");
	set_size(medium);
	set_wc(1,10);
	set_large_wc(2,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The blade flashes with %^MAGENTA%^light%^BLACK%^ as "+ETOQCN+" grips it%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The blade flashes with %^MAGENTA%^light%^BLACK%^ as you grip it%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^The light of the blade %^RESET%^%^MAGENTA%^dims%^BOLD%^%^BLACK%^ as "+ETOQCN+" releases it%^RESET%^",ETO);
	tell_object(ETO,"%^The light of the blade %^RESET%^%^MAGENTA%^dims%^BOLD%^%^BLACK%^ as you release it%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The sword in "+ETOQCN+"'s hand %^MAGENTA%^glows%^BLACK%^ a bit brighter as it strikes "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you strike a blow with the sword it grows %^RESET%^%^RED%^warmer%^BOLD%^%^BLACK%^ in your hand for a moment%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" strikes you with the blade and it %^RED%^BURNS%^BLACK%^!!!");
		return roll_dice(1,8)+0;	}

}
