#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Mask of Death");
	set_id(({ "mask", "mask of death" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_long(
@AVATAR
This mask is made of stainless titanium. The mask is in the shape of an expressionless face. Their are no openings in the mask. Where the eyes on the mask are, two obsidian gems sit.  On the inside of the mask there is some small writing. You do not understand how the wearer of the mask is supposed to see through the it, much less put it on.

AVATAR
	);
	set_weight(5);
	set_value(2000);
	set_type("clothing");
	set_limbs(({ }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" stiffens momentarily as they put on the "+query_short()+".",ETO);
	tell_object(ETO,"Your eyes feel like they will explode as you slide the "+query_short()+" on, but then the feeling subsides.");
	ETO->add_stat_bonus("wisdom",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" sighs deeply, wobbles unsteadily and then shakes their head after removing the "+query_short()+".",ETO);
	tell_object(ETO,"Your head feels sore as you remove the "+query_short()+".");
	ETO->add_stat_bonus("wisdom",2);
	return 1;
}
