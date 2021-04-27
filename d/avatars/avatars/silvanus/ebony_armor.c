#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ebon armor");
	set_id(({ "armor", "fullplate", "ebon armor", "ebon fullplate", "ebony armor", "ebony fullplate" }));
	set_short("%^BOLD%^%^BLACK%^Ebony Fullplate%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^ebony fullplate%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This fullplate armor is made from a %^YELLOW%^shining%^BOLD%^%^BLACK%^ ebon metal.  It has been crafted to utter perfection, there are no blimishes on it's surface, nor any visible from its creation.  It even lacks any signs of normal wear and tear, forcing you to believe that there is some magical mystery behind it.%^RESET%^

AVATAR
	);
	set_weight(70);
	set_value(10000);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(6);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"%^BOLD%^%^BLACK%^ struggles with the "+query_short()+"%^BOLD%^%^BLACK%^ and finally manages to put it on.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^With a struggle you finally manage to get into your "+query_short()+"!%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^With a struggle "+ETO->query_cap_name()+"%^BOLD%^%^BOLD%^ finally manages to remove the "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You struggle with the "+query_short()+"%^BOLD%^%^BLACK%^ and finally manage to remove it.%^RESET%^");
	ETO->add_stat_bonus("constitution",1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The "+query_short()+"%^BOLD%^%^BLACK%^ worn by "+ETO->query_cap_name()+"%^BOLD%^%^BLACK%^ flashes a %^WHITE%^brilliant%^BOLD%^%^BLACK%^ white as "+who->query_cap_name()+"%^BOLD%^%^BLACK%^ strikes it!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your "+query_short()+"%^BOLD%^%^BLACK%^ flashes a %^WHITE%^brilliant%^BOLD%^%^BLACK%^ white as "+who->query_cap_name()+"%^BOLD%^%^BLACK%^ strikes it!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^As your strike "+ETO->query_cap_name()+"'s%^BOLD%^%^BLACK%^ "+query_short()+"%^BOLD%^%^BLACK%^ it flashes a %^WHITE%^brilliant%^BOLD%^%^BLACK%^ white!%^RESET%^");
		return (damage*150)/100;
	}
}