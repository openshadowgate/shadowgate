#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Shadow Robe");
	set_id(({ "robe", "shadow robe", "robe of shadow" }));
	set_short("%^BOLD%^%^BLACK%^Shadow-Stained Robe%^RESET%^");
	set_obvious_short("robe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This robe is made from cloth that appears to be stained by the very shadows.  It gives off darkness and flickers when it comes in contact with even the smallest amount of light.  A moving patern is woven into the front and back of it, giving you the feeling that perhaps this robe is not inanimate.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" quickly slips on the "+query_short()+"!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You quickly wrap the "+query_short()+" around your body!%^RESET%^");
	ETO->add_stat_bonus("dexterity",1);
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" steps out of the shadows provided by his "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You step from the "+query_short()+"!%^RESET%^");
	ETO->add_stat_bonus("dexterity",-1);
	ETO->set_property("magic resistance",-10);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^As "+who->query_cap_name()+" strikes the "+query_short()+" worn by "+ETO->query_cap_name()+", "+ETO->query_cap_name()+" cackles evilly!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^"+who->query_cap_name()+" strikes your "+query_short()+" and you cackle %^RED%^insanely!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^As you strike the "+query_short()+" worn by "+ETO->query_cap_name()+", "+ETO->query_cap_name()+" cackles evilly and you feel something strike at your very lifesource!%^RESET%^");
		who->do_damage("torso",random(20));
return damage;	}
}