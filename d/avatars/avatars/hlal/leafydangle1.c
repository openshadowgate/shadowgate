#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("a pair of leafy earrings");
	set_id(({ "earring", "earrings", "leafy earring", "leafy earrings", "leafy", "dangling leaves" }));
	set_short("%^RESET%^%^GREEN%^a pair of %^BOLD%^d%^RESET%^%^GREEN%^a%^CYAN%^ng%^GREEN%^li%^CYAN%^n%^BOLD%^%^GREEN%^g %^RESET%^%^GREEN%^leafy %^BOLD%^earrings%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^a pair of %^BOLD%^d%^RESET%^%^GREEN%^a%^CYAN%^ng%^GREEN%^li%^CYAN%^n%^BOLD%^%^GREEN%^g %^RESET%^%^GREEN%^leafy %^BOLD%^earrings%^RESET%^");
	set_long("%^RESET%^%^GREEN%^This pair of earrings have been well made. Tiny green leaves dangle from a vine-like strips that fall from a single emerald stud in each ear. They shimmer in the light and look quite"
	" beautiful on their own, a wonderful asset to any jewelry collection.%^RESET%^
"	);
	set_value(3000);
	set_item_bonus("charisma",2);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+" looks stunning as they wear "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel absolutely stunning as you wear "+query_short()+"%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+"'s ears look naked without "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^Your ears feel naked without "+query_short()+"%^RESET%^");
	return 1;
}

