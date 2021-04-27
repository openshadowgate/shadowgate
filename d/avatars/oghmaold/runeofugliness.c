#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("rune of putrid horror");
	set_id(({ "rune", "rune of putrid horror", "horrible green rune", "green rune" }));
	set_short("%^BOLD%^%^BLUE%^Rune %^RESET%^of %^GREEN%^Putrid %^BOLD%^%^MAGENTA%^Horror%^RESET%^");
	set_obvious_short("%^RESET%^A %^MAGENTA%^horrible %^GREEN%^green %^BOLD%^%^BLUE%^rune%^RESET%^");
	set_long(
@AVATAR
This is a small %^GREEN%^green rune %^RESET%^fixed to the bearer's left hand.  An almost tangible aura of %^RESET%^%^MAGENTA%^horror %^RESET%^and %^BOLD%^%^BLACK%^uncleanliness %^RESET%^emanates from this foul thing.  It gives off a horrid, almost inhuman %^BOLD%^%^GREEN%^stench %^RESET%^that simply will not abate.  A small inscription is written along the edges.  

AVATAR
	);
	set("read",
@AVATAR
Let's see your pretty smirk now.

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",-5);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"The rune adheres to "+ETOQCN+"'s left hand easily.",ETO);
	tell_object(ETO,"The rune adheres itself to your left hand painlessly.");
	ETO->add_stat_bonus("charisma",-14);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" smiles happily as they remove the rune from their hand.",ETO);
	tell_object(ETO,"You manage to get the accursed rune off your hand.");
	ETO->add_stat_bonus("charisma",14);
	return 1;
}
