#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak of the night");
	set_id(({ "cloak", "silk cloak", "black cloak", "black silk cloak", "cloak of the night" }));
	set_short("%^BOLD%^%^BLACK%^Cloak of the N%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A flowing black silk cloak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This cloak is made of silk so %^BOLD%^%^BLACK%^black %^BLUE%^it is almost unnatural.  Light seems to be literally absorbed by it, cloaking its wearer in a dark array of unnatural shadows.  It is billowing and looks as if it would reach just to the ankles of a wearer of average height.  A voluminous hood sewn into it appears as if it would conceal the identify of its wearer well enough.  An ornate %^BLACK%^dark steel %^BLUE%^clasp inset with an %^BOLD%^%^BLACK%^obsidian disk %^BOLD%^%^BLUE%^holds the cloak in place around the neck.

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^The %^YELLOW%^light %^RESET%^around "+ETOQCN+" seems literally consumed as they slip on the cloak.",ETO);
	tell_object(ETO,"%^RESET%^You slip on the cloak and a soft aura of %^BOLD%^%^BLACK%^darkness %^RESET%^surrounds you.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips off the cloak and the light around them seems to brighten.",ETO);
	tell_object(ETO,"%^RESET%^You slip off the cloak and the %^BOLD%^%^BLACK%^darkness %^RESET%^arround your body dissipates.");
	return 1;
}
