#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create(){
	::create();
	set_name("carrot");
	set_id(({ "sharp carrot", "carrot" }));
	set_short("%^ORANGE%^a sh%^BOLD%^a%^RESET%^%^ORANGE%^rp carrot%^RESET%^");
	set_obvious_short("%^ORANGE%^a sh%^BOLD%^a%^RESET%^%^ORANGE%^rp carrot%^RESET%^");
	set_long("%^ORANGE%^A non edible carrot with a very sharp point. It looks as if it were pulled right off a toy, a very big toy. Careful how it is held, might hurt someone.%^RESET%^
");
	set_value(200);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" seems to be loving a little much on "+query_short()+" as it is held tight%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^"+query_short()+" makes you feel complete somehow.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks lost as "+query_short()+" %^ORANGE%^is unwielded%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You miss "+query_short()+" already.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 40){
	tell_room(environment(query_wielded()),"%^ORANGE%^"+ETOQCN+" laughs strangely when "+query_short()+" %^ORANGE%^releases an odd smell as it enters %^BOLD%^"+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^"+query_short()+" %^ORANGE%^releases a strange smell as it enters %^BOLD%^"+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^ORANGE%^"+ETOQCN+" sticks you with the smelly "+query_short()+" %^RESET%^");
		return roll_dice(0,0)+0;	}

}
