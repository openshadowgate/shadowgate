#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("hammer of souls");
	set_id(({ "hammer", " medium hammer", " soul hammer", " hammer of souls" }));
	set_short("%^BOLD%^%^BLACK%^Hammer of Souls%^RESET%^");
	set_obvious_short("medium hammer");
	set_long(
@AVATAR
%^RED%^This hammer is made from a metal that has been %^BOLD%^%^BLACK%^charred%^RESET%^%^RED%^ by an intense, unknown %^BOLD%^%^RED%^flame%^RESET%^RED%^.  Along the shaft of the hammer run several mysterious %^BLUE%^runes%^RED%^, in the center of the %^BLUE%^runes%^RED%^ is an %^BLUE%^insignia%^RED%^ of some sort, which depicts a human kneeling before an %^BOLD%^%^BLACK%^obscurred%^RESET%^%^RED%^ figure, with a very small inscription in the upper corner.  The head of the hammer is in the shape of an arched rectangle and has a %^YELLOW%^glowing%^RESET%^%^RED %^BOLD%^%^GREEN%^gem%^RESET%^%^RED%^ inset into it's side.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Aliare DoomRiden, Demon Lord of The Abyss%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(200);
	set_lore(
@AVATAR
%^RED%^This hammer has been known throughout it's existence for it's power to trap souls within it's gem.  It is rumored that it was forged by an angry God eons ago, in an attempt to overthrow his arch-rival.  It disappeared from known existence roughly four centuries ago.%^RESET%^

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(2,5);
	set_large_wc(2,5);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" grasps the handle of the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^RED%^With determination you grasp the handle of your "+query_short()+".%^RESET%^");
	TP->add_stat_bonus("intelligence",1);
	TP->add_attack_bonus(2);
	TP->do_damage("torso",random(6));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" seems unsure but finally decides to release the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^RED%^With hesistance you decide to release your grasp on the "+query_short()+"%^RESET%^");
	TP->add_stat_bonus("intelligence",-1);
	TP->add_attack_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 125){
	tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+" slams the "+query_short()+" into "+targ->query_cap_name()+" with great force!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^You slam your "+query_short()+" into "+targ->query_cap_name()+"!%^RESET%^");
	tell_object(targ,"%^RED%^"+ETO->query_cap_name()+" slams the "+query_short()+" into you with great force!%^RESET%^");
		return roll_dice(1,10)+2;	}
}