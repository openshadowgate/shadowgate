#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Auril Surcoat");
	set_id(({ "surcoat" }));
	set_short("%^BOLD%^%^WHITE%^Snow-whi%^CYAN%^t%^WHITE%^e Surcoat%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Surcoat%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a traditional surcoat  It is made from a snow-white cotton of the finest quality.  The Ailette on each shoulder bears a small embroidered %^CYAN%^sn%^WHITE%^o%^CYAN%^wflake%^WHITE%^ stitched in exquisite detail, a larger %^CYAN%^sno%^WHITE%^w%^CYAN%^fla%^WHITE%^k%^CYAN%^e%^WHITE%^ has been emroidered as the central image on the front of the surcoat.  The lower part of the surcoat is split in the centre suggesting this is intended to be worn by those mounted on horse-back.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(5500);
	set_lore(
@AVATAR
This is a traditional knight's surcoat.  It is split in the centre so that it can be worn on horseback without causing any difficulty, whereas those worn by footmen would be split at each side.  This particular surcoat bears the repeated image of a snowflake making it apparant that it was commissioned by one of Auril's faithful.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The snowflakes feel icy to the touch!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The surcoat still looks as clean and white as when you put it on!%^RESET%^");
	return 1;
}
