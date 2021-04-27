#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("yellow ioun stone");
	set_id(({ "stone", "pebble", "ioun stone", "ioun", "stone", "yellow pebble", "yellow stone", "yellow ioun stone", "ioun", "small stone", "small yellow stone" }));
	set_short("%^YELLOW%^Ioun Stone%^RESET%^");
	set_obvious_short("small stone");
	set_long(
@AVATAR
This is a small stone of dull yellow color, about the size of a marble.  It is perfectly smooth and round, and has no markings of any kind.  

AVATAR
	);
	set("read",
@AVATAR
There's nothing on it to read.

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(100);
	set_lore(
@AVATAR
This appears to be an Ioun Stone of some kind of magical properties.  It is said that ioun stones have magical effects on their users while active.  To activate a stone, one must simply release it, and it will take off of its own accord and begin to orbit around it's user's head in no particular pattern (wear stone).

AVATAR
	);
	set_property("lore difficulty",12);
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
	tell_room(environment(ETO),"%^RESET%^A %^YELLOW%^small stone%^RESET%^ begins floating in circles about "+ETOQCN+"'s head!",ETO);
	tell_object(ETO,"You release the "+query_short()+" and it begins circling about your head.");
	ETO->add_stat_bonus("constitution",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^RESET%^plucks a small floating stone out of mid-air.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^You grab the "+query_short()+" out of mid-air.%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"The "+query_short()+" orbits about "+ETOQCN+"'s head at a dizzying pace!",({ETO,who}));
	tell_object(ETO,"The "+query_short()+" whirls about your head in a frenzy!");
	tell_object(who,"");
	}
}