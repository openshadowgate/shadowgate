#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RED%^Hammer of Might%^RESET%^");
	set_id(({ "hammer", " medium hammer" }));
	set_short("%^RED%^Hammer of %^YELLOW%^Might%^RESET%^");
	set_obvious_short("A medium sized hammer");
	set_long(
@AVATAR
%^RED%^This hammer is very heavy, and has a long oak handle, the head is made out of pure %^WHITE%^admantium%^RED%^ and in the other end of it, leather straps are attached. it looks like a sturdy and strong weapon that could deliver a immense punch to anyone
.

AVATAR
	);
	set_weight(25);
	set_value(5000);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(4,3);
	set_large_wc(4,4);
	set_property("enchantment",4);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BLUE%^"+TP->query_cap_name()+" wields the heavy hammer, and squeezes tightly around the handle",TP);
	tell_object(TP,"%^BLUE%^You wield the heavy hammer, and squeezes tightly around the handle");
	TP->add_attack_bonus(5);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" unwields the hammer, and relaxes",TP);
	tell_object(TP,"%^GREEN%^You release your tense grip around the handle, at feel your muscles relax");
	TP->add_attack_bonus(-5);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 125){
	tell_room(environment(query_wielded()),"%^CYAN%^The heavy hammer smashes into "+targ->query_cap_name()+"",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^The heavy hammer smashes into "+targ->query_cap_name()+"");
	tell_object(targ,"%^CYAN%^The heavy hammer smashes into you");
		targ->set_paralyzed(roll_dice(1,0)+0);
return 0;	}
}