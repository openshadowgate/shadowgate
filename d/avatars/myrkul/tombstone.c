#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create(){
	::create();
	set_name("%^BOLD%^%BLACK%^Tombstone of Assbeating%^RESET%^");
	set_id(({ "tombstone" }));
	set_short("%^BOLD%^%^BLACK%^Tombstone of Assbeating%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Tombstone of Assbeating%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is Myrkul's Tombstone for OOCly beating the crap out of things.%^RESET%^
");
	set_value(0);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^Tombstoned!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Tombstoned!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^Tombstoned!%^RESET%^");
		return roll_dice(1,1)+1000;	}

}
