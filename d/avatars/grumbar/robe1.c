#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("skeletal robe");
	set_id(({ "skeletal robe" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^Skeletal Robe%^RESET%^");
	set_obvious_short("paper thin robe");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This robe is paper thin, made from an unknown material.  It offers no protection to the body of the wearer.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(150000);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" wears the "+query_short()+" and a muffled scream eminates from it",ETO);
	tell_object(ETO,"wears the "+query_short()+"");
	ETO->add_stat_bonus("strength",1);
	ETO->set_property("magic resistance",25);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"muffled screams end in silence as "+ETOQCN+" removes the "+query_short()+"",ETO);
	tell_object(ETO,"removes the "+query_short()+"");
	ETO->add_stat_bonus("strength",-1);
	ETO->set_property("magic resistance",-25);
	return 1;
}
