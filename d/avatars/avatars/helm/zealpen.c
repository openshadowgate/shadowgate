#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("moonstone pendant");
	set_id(({ "pendant", "jewelry", "moonstone pendant", "necklace" }));
	set_short("%^RESET%^%^CYAN%^a small %^RESET%^%^BOLD%^silver%^RESET%^%^CYAN%^ pendant%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a small %^RESET%^%^BOLD%^silver%^RESET%^%^CYAN%^ pendant%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This pendant is oval-shaped, a little less than two inches across. It has been formed from %^RESET%^%^BOLD%^bright silver metal%^RESET%^%^CYAN%^, with %^RESET%^sw%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^i%^RESET%^ng %^CYAN%^patterns across it in a markedly-elven style. Upon the upper surface a pattern has been created with several etchings, of two feminine eyes surrounded by seven stars. The eyes and each star have been set with small pieces of %^RESET%^moo%^BOLD%^n%^RESET%^stone %^CYAN%^that sparkle when caught by %^YELLOW%^light%^RESET%^%^CYAN%^. On the underside something has been etched in a flowing elven script. A simple %^RESET%^%^ORANGE%^leather cord%^RESET%^%^CYAN%^ has been threaded to hold it around the wearer's neck.

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^GREEN%^'May the light of the moon always shine down upon you ranger. From your friend and priestess, Shrydelhi'%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(143);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^Your resolve is strengthened as you don the pendant.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^Your remain strong in faith as you remove the pendant.%^RESET%^");
	return 1;
}
