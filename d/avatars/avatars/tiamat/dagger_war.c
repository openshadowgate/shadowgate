#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Dagger of War");
	set_id(({ "dagger", "knife" }));
	set_short("%^BOLD%^%^CYAN%^The Dagger of %^YELLOW%^W%^CYAN%^a%^YELLOW%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^The Dagger of %^YELLOW%^W%^CYAN%^a%^YELLOW%^r%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This is a modest looking dagger, forged of pure mithril silver.  Though it appears aged beyond history, its edges are sharp.  The blade is actually composed of four blades, forming a cross shape.  The handle, carved of old hardwood, is wrapped in leather and painted in %^RESET%^faded images%^CYAN%^.  Altogether, it is an old, but unusual weapon of war.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(50);
	set("strbonus",2);
	set_type("piercing");
	set_prof_type("war dagger");
	set_size(1);
	set_wc(2,6);
	set_large_wc(4,6);
	set_property("enchantment",5);
	set_ac(2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^Power courses through the body of "+ETOQCN+"",ETO);
	tell_object(ETO,"%^YELLOW%^You feel true power course through your body!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks weak without the dagger.",ETO);
	tell_object(ETO,"%^ORANGE%^You feel weak without the dagger.");
	return 1;
}
