#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("hunters robe");
	set_id(({ "robe" }));
	set_short("%^RESET%^%^GREEN%^The %^BOLD%^%^GREEN%^Hu%^RESET%^%^GREEN%^nt%^BOLD%^%^GREEN%^er's %^RESET%^%^GREEN%^Robe%^RESET%^");
	set_obvious_short("%^RESET%^a %^GREEN%^green %^RESET%^and %^ORANGE%^brown %^RESET%^leafy robe");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This robe is long, appearing to drag on the ground at times.  It's made from a variety of leaves ranging from small to large, soft to hard and ranging in color from green to brown and all the reds in between.  There is a hood for the wearer to use to shield himself from the elements.  When wearing the hood and putting their hands in the pockets, this robe effectively hides the wearer if in the right environment.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(2000);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(6);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The scent of the %^GREEN%^outdoors %^ORANGE%^fills the air for a moment...%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^Bloodlust %^GREEN%^fills you when you wear the "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The odor of %^GREEN%^sweat %^ORANGE%^mixed with %^RED%^blood %^ORANGE%^fills your senses momentarily...%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You are disturbed for a brief moment when you remove your "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
