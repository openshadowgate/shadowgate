#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("red stone");
	set_id(({ "stone", "pebble", "red stone", "red pebble", "ioun", "ioun stone", "red ioun stone", "small stone", "red ioun" }));
	set_short("%^RESET%^%^RED%^Red Ioun Stone%^RESET%^");
	set_obvious_short("small stone");
	set_long(
@AVATAR
This is a small stone, about the size of a marble.  It is a deep red color, and is completely smooth, without any markings at all.

AVATAR
	);
	set_weight(0);
	set_value(100);
	set_lore(
@AVATAR
This is a magical ioun stone.  It is said that while being utilized (wear stone) they will grant the wearer some kind of magical effect.  Each stone is different, as defined by its color.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" releases a "+query_short()+", which begins orbiting "+ETOQCN+"'s head in a haphazard way!",ETO);
	tell_object(ETO,"You release the "+query_short()+", and it floats up into a haphazard orbit about your head.");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" plucks an orbiting "+query_short()+" out of mid-air.",ETO);
	tell_object(ETO,"You snatch the "+query_short()+" out of mid-air.");
	ETO->add_attack_bonus(-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 0){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"");
	}
}