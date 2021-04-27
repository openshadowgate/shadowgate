#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("lucky charm");
	set_id(({ "charm", "lucky charm", "lucky", "bracelet" }));
	set_short("a %^BOLD%^%^WHITE%^silver%^RESET%^ charm bracelet");
	set_obvious_short("a %^BOLD%^%^WHITE%^silver%^RESET%^ charm bracelet");
	set_long(
@AVATAR
This bracelet looks fairly ordinary.  A series of links connecting one another to form a sturdy chain.  Hanging from these links are several charms.  There's a %^GREEN%^green shamrock%^RESET%^, a %^BLUE%^blue diamond%^RESET%^, a %^MAGENTA%^purple heart%^RESET%^, a %^YELLOW%^yellow sun%^RESET%^, and a %^BOLD%^%^WHITE%^silver moon%^RESET%^.  As the bracelet is moved it tinkles softly as the charms clink against one another.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(200);
	set_lore(
@AVATAR
Given to a young woman named Molara by a traveling sailor who'd had a bit of misfortune in the city of Shadow after playing a game of cards and taking the wrong person's gold.  Her aid in getting him out of the city resulted in him giving her his lucky charm.  Hoping to give her a bit of luck in repayment for her kindness.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->set_property("magic resistance",-5);
	return 1;
}
