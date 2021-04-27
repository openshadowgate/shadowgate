#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("snuggie");
	set_id(({ "snuggie", "robe" }));
	set_short("%^RESET%^%^CYAN%^The Official %^YELLOW%^Snuggie%^RESET%^%^CYAN%^!%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^The Official %^YELLOW%^Snuggie%^RESET%^%^CYAN%^!%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Blankets are OK but they can slip and slide, plus your hands are trapped inside.  The %^YELLOW%^Snuggie%^RESET%^%^CYAN%^ keeps you totally warm and gives you the freedom to use your hands!  Work the remote, use your laptop or do some reading in total warmth and comfort!  %^YELLOW%^Snuggie%^RESET%^%^CYAN%^ is made with super soft, thick, luxurious fleece with roomy, oversized sleeves that let you do what you want while still being totally wrapped in warmth.  Now available in %^RED%^burgundy%^CYAN%^, %^BLUE%^royal blue%^CYAN%^, and %^GREEN%^sage green%^CYAN%^.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_max_internal_encumbrance(500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" is, like, totally wrapped in warmth.",ETO);
	tell_object(ETO,"%^CYAN%^You are, like, totally wrapped in warmth.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BLUE%^"+query_short()+" seems lost without the Snuggie.",ETO);
	tell_object(ETO,"%^BLUE%^How will you go on without it?");
	return 1;
}

