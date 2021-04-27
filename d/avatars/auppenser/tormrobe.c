#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Torm Official's Robe");
	set_id(({ "robe", "robes" }));
	set_short("%^BLUE%^Torm Official's Robe%^RESET%^");
	set_obvious_short("%^BLUE%^Blue silk robe with a %^YELLOW%^gold motif%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^This is a long delicate robe made from dark, royal blue %^RESET%^%^BOLD%^silk%^BLUE%^.  It has a wide rounded neck with %^YELLOW%^gold trim%^RESET%^%^BLUE%^.  The sleeves are long and loosely flowly also with %^YELLOW%^gold trim%^RESET%^%^BLUE%^.  The robe fits snugly to the waist and flares out from the bodice to just about the floor.  The robe is secured around the waist by a %^YELLOW%^gold satin sash%^RESET%^%^BLUE%^ which looks more ornamental than it is a necessity.  %^YELLOW%^Gold satin embroidery%^RESET%^%^BLUE%^ depicts a %^GREEN%^vine and leaf motif%^BLUE%^ around the %^YELLOW%^hem%^RESET%^%^BLUE%^, with some %^YELLOW%^tendrils%^RESET%^%^BLUE%^ reaching up almost to the waist.  The robe looks very expensive and seems like something an %^BOLD%^%^RED%^official%^RESET%^%^BLUE%^ might wear.

AVATAR
	);
	set_weight(5);
	set_value(100000);
	set_max_internal_encumbrance(30);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^"+ETOQCN+" looks more important as the %^RESET%^%^BLUE%^robe%^RESET%^%^BOLD%^ is worn.",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^You feel more important as you wear your %^BLUE%^robe.%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	ETO->add_stat_bonus("wisdom",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^"+ETOQCN+" looks a little less important as the %^RESET%^%^BLUE%^robe%^RESET%^%^BOLD%^ is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^You feel less important as you remove your %^RESET%^%^BLUE%^robe.%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	ETO->add_stat_bonus("wisdom",-1);
	return 1;
}
