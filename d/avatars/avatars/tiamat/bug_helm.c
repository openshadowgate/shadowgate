#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("insect headpiece");
	set_id(({ "bug", "helmet", "insect", "headpiece" }));
	set_short("%^MAGENTA%^A pa%^BOLD%^ra%^RESET%^%^MAGENTA%^si%^BOLD%^ti%^RESET%^%^MAGENTA%^c headpiece%^RESET%^");
	set_obvious_short("%^RESET%^An %^MAGENTA%^insect%^RESET%^ worn as %^BOLD%^%^MAGENTA%^headpiece%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^What you hold before you is actually a large insect.  It looks like a large potato bug, with a hard %^BOLD%^purple shell%^RESET%^%^MAGENTA%^.  The head of the bug has a set of large mandibles that look they are eager to attach to something.  One only needs to try to wear it...%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(25);
	set("wisbonus",1);
	set("chabonus",-1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" screams as the bug works its way into his ear!",ETO);
	tell_object(ETO,"%^MAGENTA%^The bug works its way painfully into your ear!!");
	ETO->do_damage("torso",random(25));
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" seems relieved as the bug crawls out of their ear.",ETO);
	tell_object(ETO,"%^MAGENTA%^You finally feel some relief as the bug is removed from your ear.");
	return 1;
}
