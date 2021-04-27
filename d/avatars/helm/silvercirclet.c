#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet", "silver circlet" }));
	set_short("%^RESET%^%^BOLD%^si%^RESET%^lver circ%^BOLD%^let%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^si%^RESET%^lver circ%^BOLD%^let%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This is a beautiful well-crafted piece of jewelry where several thin strands of purest silver have been braided to form a circlet that you can wear over your hair. Moonstones and small sapphires have been carefully fitted into the braids around the circlet and when it is worn it appears to glow with a soft blue light.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^RESET%^%^CYAN%^%^BOLD%^A gentle blue glow surrounds "+ETO->query_cap_name()+"%^CYAN%^%^BOLD%^.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^A gentle blue glow surrounds you.%^RESET%^");
	ETO->add_stat_bonus("wisdom",1);
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RESET%^%^CYAN%^%^BOLD%^The gentle blue glow surrounding "+ETO->query_cap_name()+"%^CYAN%^%^BOLD%^ fades.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^The gentle blue glow fades.%^RESET%^");
	ETO->add_stat_bonus("wisdom",-1);
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
