#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("daedinblade");
	set_id(({ "sword", "longsword", "long sword", "family sword" }));
	set_short("%^BOLD%^%^YELLOW%^Broenil's %^BOLD%^%^YELLOW%^Protector%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A silver bladed longsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This long sword has a beautiful silver blade. E%^BOLD%^%^YELLOW%^tc%^BOLD%^%^WHITE%^hed in the blade is the name %^RESET%^%^MAGENTA%^Broenil %^BOLD%^%^WHITE%^in flowing script. The blade has a groove down the length which ends at the hilt which is made out of a tarnished silver. The pommel is simply made, a circle with a '%^RESET%^%^MAGENTA%^B%^BOLD%^%^WHITE%^' in it.

AVATAR
	);
	set_weight(10);
	set_value(5000);
	set_lore(
@AVATAR
This sword has been past down the Baenil family line for nearly two hunded years. Said to be created for Lethrod Baenil as a reward for his service to his local king. It is an honored keepsake and used as a sign of loyalty and honor to the family line.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_ac(1);
	set_wield((:TO,"wield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel proud as you wield this weapon.");
	return 1;
}

