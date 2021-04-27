#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("blue stone");
	set_id(({ "stone", "blue stone", "blue ioun stone", "blue ioun", "ioun", "ioun stone" }));
	set_short("%^RESET%^%^BLUE%^Blue Ioun Stone%^RESET%^");
	set_obvious_short("blue stone");
	set_long(
@AVATAR
This is a small stone, about the size of a marble.  It is a deep blue color, and is completely smooth, without any markings at all.

AVATAR
	);
	set_weight(0);
	set_value(100);
	set_lore(
@AVATAR
This is an ioun stone.  It has no weight and its wearer gains a small benefit from using it.  It's said that each color grants a different benefit, and that they may have other powers, as well.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" releases a "+query_short()+", which begins orbiting "+ETOQCN+"'s head in a haphazard way!",ETO);
	tell_object(ETO,"You release the "+query_short()+", and it floats up into a haphazard orbit about your head.");
	ETO->set_property("magic resistance",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" plucks an orbiting "+query_short()+" out of mid-air.",ETO);
	tell_object(ETO,"You snatch the "+query_short()+" out of mid-air.");
	ETO->set_property("magic resistance",-2);
	return 1;
}
