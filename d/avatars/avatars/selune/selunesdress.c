#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("mydress");
	set_id(({ "dress", "selune's dress", "goddess dress" }));
	set_short("%^BLUE%^Selune's Dress%^RESET%^");
	set_obvious_short("%^BLUE%^Selune's Dress%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^This is a dress befitting a %^RESET%^%^MAGENTA%^goddess%^RESET%^%^BOLD%^.  It is a soft shade of %^RESET%^%^BLUE%^blue%^RESET%^%^BOLD%^ with %^RESET%^diamond beads%^BOLD%^ that %^RESET%^%^CYAN%^sparkle%^RESET%^%^BOLD%^ in the light.  The fabric is sheer silk leaving nothing to the imagination.  The sleeves are long and flowing past the writes.  The neckline is cut extremely low to reveal the wearer's cleavage.  The skirt is in an a-frame and is long, falling to below the wearer's ankles.  This is truly a %^RESET%^%^CYAN%^bea%^MAGENTA%^uti%^CYAN%^ful%^RESET%^%^BOLD%^ dress.

AVATAR
	);
	set_weight(5);
	set_value(35000);
	set_lore(
@AVATAR
This dress was fashioned from the moon itself. Crafted of only the best of silk and diamonds. This dress was made by Selune herself.

AVATAR
	);
	set_property("lore difficulty",15);
	set_max_internal_encumbrance(200);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(240);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" slips the revealing dress on with a sigh%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^Slips the revealing dress on with a sigh%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" slips the dress off with reluctance%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^You slip the dress off with reluctance%^RESET%^");
	return 1;
}
