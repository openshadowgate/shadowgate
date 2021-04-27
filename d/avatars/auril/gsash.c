#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("guild sash");
	set_id(({ "sash" }));
	set_short("%^RESET%^%^MAGENTA%^A %^BOLD%^%^BLACK%^s%^BOLD%^%^BLUE%^il%^BOLD%^%^BLACK%^k %^BOLD%^%^BLUE%^sa%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A %^BOLD%^%^BLACK%^s%^BOLD%^%^BLUE%^il%^BOLD%^%^BLACK%^k %^BOLD%^%^BLUE%^sa%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This silk sash is made out of fine quality purple. The sash wraps around the waist of the wearer comfortably and where the sash overlaps an emblem is set. Upon the emblem is a shadowy blue dragon that is vaguely distinguishable as such. The wifts of the creature spreads across the emblem making it eerily in appearance. The sash ends hang down about a half foot down the leg.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(2);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" slips on the sash.",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You slip on the pleasant feeling sash.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" slips off the sash.",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You slip off the pleasant feeling sash.");
	return 1;
}
