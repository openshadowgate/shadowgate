#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("stuff");
	set_id(({ "stuff" }));
	set_short("stuff");
	set_long(
@AVATAR
This is a thing.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(20);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,4);
	set_large_wc(3,4);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"**",ETO);
	tell_object(ETO,"**");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"**",ETO);
	tell_object(ETO,"**");
	return 1;
}
