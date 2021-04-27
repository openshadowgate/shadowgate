#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Puzzle Ring");
	set_id(({ "ring", "puzzle ring", "ring of faith" }));
	set_short("%^BOLD%^%^YELLOW%^Ring of Faith%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^Puzzle Ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This is a puzzle ring.  Four separate gold rings are linked together in such a way to form a single gold ring.  As you look at the ring you can see it would be very easy for the bands to be separated, but you can't begin to imagine how they could be fitted back together again.

AVATAR
	);
	set_weight(2);
	set_value(7250);
	set_lore(
@AVATAR
%^RESET%^%^CYAN%^This is a puzzle ring.  The history of such rings being associated with people of strong faith is long and not very well documented.  Some people maintain that linking the four bands into one ring is itself a test of faith and only those who are truly dedicated to the gods can accomplish it.  Another widely held belief is that contemplating the interwoven bands is an aid to meditation and prayer.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BLUE%^You slide the puzzle ring onto your finger%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You take great care not to separate the four sections of the ring as you remove it%^RESET%^");
	return 1;
}
