#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silver bell");
	set_id(({ "bell", "silver bell", "silverbell" }));
	set_short("%^BOLD%^%^BLACK%^A s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^%^BLACK%^ll%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^%^BLACK%^ll%^RESET%^");
	set_long(
@AVATAR
This%^BOLD%^%^BLACK%^ s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^%^BLACK%^ll%^RESET%^ is quite well made and chimes with a lovely ringing sound that is both pure and bright.  A small loop is set into the top of the bell so that it can be affixed to something with a tie.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
Said to be the Muse of Beshaba's calling card, these bells are often found after a great deal of misfortune has struck in a strange and unknown manner.  It is rumored that these bells are either tokens left to reward those who help, or tokens left to remind those who failed.  In any case, the bell rings very purely.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^The %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ chimes brightly as "+ETOQCN+" wears it.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^The %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ chimes brightly as you wear it.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^The %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ chimes brightly as "+ETOQCN+" removes it.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^The %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ chimes brightly as you remove it.%^RESET%^");
	return 1;
}
