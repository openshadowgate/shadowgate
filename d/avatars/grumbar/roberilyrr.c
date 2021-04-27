#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("mass of shadows");
	set_id(({ "robe" }));
	set_short("a swirling mass of shadows");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This swirling mass of shadows is strange, to say the least.  Every now and then, amidst the shadows, you see pockets of darkness.  The shadows cover the main portion of the wearers torso but otherwise doesn't appear to offer much protection.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^Screams rage from seemingly everywhere then die down suddenly%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^You flinch as "+query_short()+" covers your body%^RESET%^");
	ETO->add_stat_bonus("intelligence",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^The silence is suddenly ominous but then the feeling subsides%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^Your vision is obscured briefly as "+query_short()+" lifts from your body%^RESET%^");
	ETO->add_stat_bonus("intelligence",-1);
	return 1;
}
