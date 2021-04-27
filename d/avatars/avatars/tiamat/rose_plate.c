#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^RED%^rose plate%^RESET%^");
	set_id(({ "plate", "rose plate", "armor" }));
	set_short("%^BOLD%^%^RED%^Body Armor of Firehair%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^rose breastplate%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a suit of plate armor that immediately stands out because of its rose colored finish, the nature of the craftsmanship is unknown.  The suit consists primarily of the breastplate, but other vital areas are also protected by the strange red metal.  Where flexibility is required, red leather provides comfort.  The pieces interlock expertly, distributing the little excess weight.  When the armor is fitted close to the body, it feels like it has its own gentle heartbeat which syncs with the wearer.%^RESET%^

AVATAR
	);
	set_weight(60);
	set_value(6000);
	set("chabonus",1);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^RED%^The plates of armor fit "+ETOQCN+" %^BOLD%^%^RED%^perfectly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The plates of "+query_short()+" smoothly conform to fit your body.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^RED%^seems reluctant to remove the armor.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel departed from a loved one as you remove "+query_short()+"%^RESET%^");
	return 1;
}
