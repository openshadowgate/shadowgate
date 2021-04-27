#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Hard Leather Boots");
	set_id(({ "boots" }));
	set_short("%^ORANGE%^Hard leather boots");
	set_obvious_short("Leather boots");
	set_long(
@AVATAR
%^ORANGE%^This pair of rugged leather boots climb up half the calves of the bearer. On the outside of each boot %^RED%^blood red%^ORANGE%^ painted steel buttons hold the boots together. The thick leather only presents itself around the foot, higher up it thins out, not to make a fullplate uncomfortable. %^BOLD%^%^BLACK%^The black souls%^RESET%^%^ORANGE%^ of the boots are deeply treaded, giving the wearer impressive traction, probably on ice. The toes are protected by a steel tip, forming to a short spike.

AVATAR
	);
	set_weight(5);
	set_value(4000);
	set_type("armor");
	set_limbs(({ "right leg", "left leg" }));
	set_size(1);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" grunts as he wears the "+query_short()+".",ETO);
	tell_object(ETO,"%^ORANGE%^The hard leather scrapes against your feet as you wear the "+query_short()+", but feel much more comfortable as you wear them.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" grunts as he removes the boots.",ETO);
	tell_object(ETO,"%^ORANGE%^Again the "+query_short()+" scrape against your feet, but their protection and feeling are missed.");
	return 1;
}
