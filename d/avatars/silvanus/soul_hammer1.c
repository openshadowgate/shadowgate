#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Hammer of Souls");
	set_id(({ "hammer", "soul hammer", "hammer of souls", "medium hammer" }));
	set_short("%^BOLD%^%^BLACK%^Hammer of Souls%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^blackened hammer%^RESET%^");
	set_long(
@AVATAR
%^RED%^This hammer is made from a metal that has been %^BOLD%^%^BLACK%^charred%^RESET%^%^RED%^ by an intense %^YELLOW%^h%^RED%^e%^YELLOW%^a%^RED%^t.%^RESET%^%^RED%^  Along the shaft of the hammer run several mysterious %^BLUE%^runes%^RED%^.  In the center of the %^BLUE%^runes%^RED%^ is an %^BLUE%^insignia%^RED%^ which depicts a human kneeling before an %^BOLD%^%^BLACK%^obscurred%^RESET%^%^RED%^ figure.  There is a very small %^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ in the upper corner of the %^BLUE%^insignia%^RESET%^%^RED%^.  The head of the hammer is in the shape of an arched rectangle and has a %^YELLOW%^glowing %^GREEN%^gem%^RESET%^%^RED%^ inset into it's side.%^RESET%^  

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Aliare DoomRiden, Demon Lord of The Abyss%^RESET%^

%^BOLD%^%^BLACK%^You struggle to make out something written below the name....%^RESET%^

%^BOLD%^%^GREEN%^The power of the gem is immense... it can enslave so..... 

%^BOLD%^%^BLACK%^The rest of the writing on the hammer has been smeared, obviously it was melted whenever the hammer was charred%^RESET%^

AVATAR
	);
	set_weight(14);
	set_value(1000);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(2,5);
	set_large_wc(1,10);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" grasps the hilt of the "+query_short()+"%^RED%^!%^RESET%^",TP);
	tell_object(TP,"%^RED%^With determination you grasp the "+query_short()+"%^RED%^!%^RESET%^");
	TP->do_damage("torso",random(12));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" timidly release the "+query_short()+"%^RED%^!%^RESET%^",TP);
	tell_object(TP,"%^RED%^You timidly release the "+query_short()+"%^RED%^!%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+" furiously strikes "+targ->query_cap_name()+" with the "+query_short()+"%^RED%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^You furiously strike "+targ->query_cap_name()+" with your "+query_short()+"%^RED%^!%^RESET%^");
	tell_object(targ,"%^RED%^"+ETO->query_cap_name()+" furiously strikes you with the "+query_short()+"%^RED%^!%^RESET%^");
		return roll_dice(2,6)+1;	}
}