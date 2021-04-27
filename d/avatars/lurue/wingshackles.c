#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wing shackles");
	set_id(({ "shackles", "armor", "wingshackles", "wing shackles", "corset" }));
	set_short("%^BOLD%^%^BLACK%^wing shackles%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^wing shackles%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made to resemble a corset that wraps the chest of the wearer, this garment is made of iron bands that lock together along the back with the use of a cleverly made latching device that involves rings and an iron rod.  Covered in arcane %^RESET%^%^CYAN%^runes%^BOLD%^%^BLACK%^ the bands would seem ominous enough but for the strange metal shackles that are affixed to the back side.  These wide metal bands are too high on the back to hold a set of arms comfortably and far too generous in size to brace the arms of all but the heaviest of people.  In fact, they look to be designed to hold something that comes from the back itself, an extra set of appendages or %^WHITE%^wings%^BOLD%^%^BLACK%^!%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(3000);
	set_lore(
@AVATAR
Originally designed to be used in the capture and removal of harpies, these devices have found their way into use by more nefarious sorts over the years. Bound with magic the clasps and locking devices on the back cannot be removed without the trigger word which is uttered when the device is locked around the captive.  Rumor holds that there is another way to break the enchantments, but how exactly is not known. 

AVATAR
	);
	set_property("lore difficulty",14);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^With an ominous click the "+query_short()+" %^BOLD%^%^BLACK%^secures snuggly around "+ETOQCN+"'s body%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With a ominous click the "+query_short()+" secures snuggly around your body, trapping you in its iron embrace!%^RESET%^");
	ETO->set_property("magic resistance",50);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^With the spoken %^RESET%^word of power%^BOLD%^%^BLACK%^ the "+query_short()+" release their hold on "+ETOQCN+"!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With the spoken %^RESET%^word of power%^BOLD%^%^BLACK%^ "+query_short()+" releases its hold on you!%^RESET%^");
	ETO->set_property("magic resistance",-50);
	return 1;
}
