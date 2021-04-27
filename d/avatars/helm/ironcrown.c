#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("crown");
	set_id(({ "crown", "ironcrown", "iron crown" }));
	set_short("%^RESET%^%^BLUE%^a heavy iron crown%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^a heavy iron crown%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This is a heavy crown elaborately wrought of iron that has been twisted and bent into large thorns and sharp spires. The metal is cold to the touch and carries a dark hue tinted with blue.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(32);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("wisdom",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("wisdom",-1);
	return 1;
}
