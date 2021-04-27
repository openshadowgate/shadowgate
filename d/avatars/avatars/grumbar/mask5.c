#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Mask of Death");
	set_id(({ "mask", "mask of death", "death mask" }));
	set_short("%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^sk of De%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^th%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This mask is made of stainless %^BOLD%^%^CYAN%^titanium%^RESET%^%^MAGENTA%^. The mask is in the shape of an expressionless face. Their are no openings in the mask but where the eyes on the mask are, two obsidian %^BOLD%^%^BLACK%^gems %^RESET%^%^MAGENTA%^sit. You do not understand how the wearer of the mask is supposed to see through the it, much less put it on.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(2000);
	set_lore(
@AVATAR
%^RESET%^%^MAGENTA%^This mask has no markings on it yet it is very, very old.  It was created by the not-so-wise wizard Humbolt. He was attempting to find a way to cheat death and created this mask to assist him in becoming wiser.  It obviously did not work as he is dead and you have this mask.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",40);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^CYAN%^"+ETOQCN+" %^RESET%^%^MAGENTA%^chokes and gags as %^BOLD%^%^CYAN%^"+query_short()+" %^RESET%^%^MAGENTA%^is being put on, then the fit subsides as it falls into place.%^RESET%^ ",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^Your head feels like it is in a vice as you struggle to put the %^BOLD%^%^CYAN%^"+query_short()+" %^RESET%^%^MAGENTA%^on, then the pain subsides.%^RESET%^");
	ETO->add_stat_bonus("wisdom",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^CYAN%^"+ETOQCN+" %^RESET%^%^MAGENTA%^sighs deeply and struggles to gather in fresh air while removing the %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^, then chuckles sarcastically when it is completely off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^Your head explodes as you remove the %^BOLD%^%^CYAN%^"+query_short()+" %^RESET%^%^MAGENTA%^but then you realize it isn't real once it is off.%^RESET%^");
	ETO->add_stat_bonus("wisdom",-2);
	return 1;
}
