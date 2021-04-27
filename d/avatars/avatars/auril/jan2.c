#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("janblade");
	set_id(({ "sword", "longsword", "long sword", "family sword" }));
	set_short("%^BOLD%^%^WHITE%^A silver bladed longsword%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^Broenil's %^BOLD%^%^YELLOW%^Protector%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This long sword has a beautiful silver blade. E%^BOLD%^%^YELLOW%^tc%^BOLD%^%^WHITE%^hed in the blade is the name %^RESET%^%^MAGENTA%^Broenil %^BOLD%^%^WHITE%^in flowing script. The blade has a groove down the length which ends at the hilt which is made out of a tarnished silver. The pommel is simply made, a circle with a '%^RESET%^%^MAGENTA%^B%^BOLD%^%^WHITE%^' in it.

AVATAR
	);
	set_weight(10);
	set_value(10000);
	set_lore(
@AVATAR
This sword has been past down the Baenil family line for nearly two hunded years. Said to be created for Lethrod Baenil as a reward for his service to his local king. It is an honored keepsake and used as a sign of loyalty and honor to the family line.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(get meteor swarm f);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You wield the sword and feel an inner strength.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You unwield the sword and feel it's protection waver.");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" 's weapon cuts you deep!");
		return roll_dice(1,4)+0;	}
}