#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("metal contraption");
	set_id(({ "contraption", "metal contraption", "odd contraption" }));
	set_short("%^BOLD%^%^GREEN%^An odd looking %^WHITE%^metal %^GREEN%^contraption%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^An odd looking %^WHITE%^metal %^GREEN%^contraption%^RESET%^");
	set_long(
@AVATAR
This is an odd looking contraption indeed!  It appears to be some type of hand replacement apparatus, though its precise manufacture is still an enigma to you.  It consists of a smooth, %^BOLD%^%^BLACK%^adamantium %^RESET%^handguard that is attached to a metal, clamplike thingamabob that looks as if made to go around the hilt of the weapon.  You would surmise that below the handguard a set of buckles or somesuch has been inset as to allow this whatchamacallit to be attached to a stump of an arm.

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" straps the odd contraption to the stump of their arm.",ETO);
	tell_object(ETO,"You strap the odd contraption to the stump of your arm and think it might be come in handy.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes the odd contraption from their stump.",ETO);
	tell_object(ETO,"You remove the odd contraption from your stump and feel a little less useful.");
	return 1;
}
