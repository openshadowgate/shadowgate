#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^black leather trench coat%^RESET%^");
	set_id(({ "trench", "coat", "trench coat", "trenchcoat" }));
	set_short("%^BOLD%^%^BLACK%^Coat of %^RESET%^%^MAGENTA%^D%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black leather trench coat%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^As black as midnight, this long coat could easily conceal someone in dark places and when exposed to light it captures it entirely, reflecting only darkness to its surroundings. It is crafted from flawless leather and is sized to just barely touch the ground. The neckline is cut high and is complete with a heavy hood that can be pulled low over the face. Seven round obs%^RESET%^id%^BOLD%^%^BLACK%^ian buttons line the front to keep the coat securely closed. Deep pockets have been sewn into the sides. The coat feels remarkably %^RESET%^cool%^BOLD%^%^BLACK%^ to the touch.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(3500);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Much of the history of this dark coat remains a mystery. Shady figures throughout time have been known to take an interest in the garment, its appeal widespread to those that enjoy the sort of activities that take place in dark, secluded places.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",16);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The coat feels cold against your skin as you slip it on.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The room seems brighter as you remove the coat.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
