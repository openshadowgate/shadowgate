#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Red Bodice");
	set_id(({ "bodice", "red bodice" }));
	set_short("%^RESET%^%^RED%^A figure-hugging bodice%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This is tight fitting bodice made from a high quality red cotton.  The bodice has boning to help it keep its shape and offer any necessary support.  It is fastened at the front with a %^BOLD%^%^BLACK%^long black lace%^RESET%^%^RED%^.  The scooped neckline is edged with a %^BOLD%^%^RED%^bright red ribbon.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(50);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^You have to breathe in as you tighten the lace%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^You can finally breathe easily again%^RESET%^");
	return 1;
}
