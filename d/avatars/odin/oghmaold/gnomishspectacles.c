#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gnomish spectacles");
	set_id(({ "spectacles", "gnomish spectacles" }));
	set_short("%^BOLD%^%^BLUE%^Gn%^MAGENTA%^o%^BLUE%^mish Spect%^MAGENTA%^a%^BLUE%^cles%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A set of %^MAGENTA%^odd %^BLUE%^spectacles%^RESET%^");
	set_long(
@AVATAR
This is a set of small, %^BOLD%^%^MAGENTA%^oddly shaped %^RESET%^spectacles desgined to be worn about the head.  They are similar to traditional eyeglasses in that they have two lenses surrounded by a metal frame that tucks behind the wearer's ears, but there the similarity ends.  Numerous auxilary lenses and other aparati stem from the main set of the glasses and look as if they would be used to provide more %^BOLD%^%^WHITE%^magnification %^RESET%^or to filter the %^BOLD%^%^BLACK%^light%^RESET%^.  The bridge has been made unusually wide as if it wouldn't sit properly on anything but a large, bulbous nose.  

AVATAR
	);
	set_weight(2);
	set_value(5000);
	set_lore(
@AVATAR
This is a set of masterwork gnomish spectacles.  They are created by the finest gnomish craftsmen in order to aid their bretheren in persuing whatever academic work they may be working on.  This set in particular has been made by Biggyvonstepasto of Svlistenglist who is reputed to be one of the finest craftsmen around today.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" puts on the odd spectacles and looks a bit silly.",ETO);
	tell_object(ETO,"You put on the odd spectacles and peer through their glass lenses.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" takes off the odd spectacles and looks less silly.",ETO);
	tell_object(ETO,"You take off the odd spectacles and blink your eyes a few times.");
	return 1;
}
