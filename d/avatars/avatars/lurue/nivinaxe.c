#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("battle axe");
	set_id(({ "axe", "axe of nivin", "nivin's axe", "nivins axe", "leather hilted axe", "stone axe" }));
	set_short("%^BOLD%^%^BLACK%^N%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n's St%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ne A%^RESET%^%^ORANGE%^x%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a stone axe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This stone axe is a bit heavier then a normal axe, but it seems balanced well enough.  Crafted completely out of a large piece of granite, the hilt has been wrapped in thick bands of dark leather that give it a solid grip.  The edge of the weapon is sharp although a few small nicks can be seen along the edge giving the weapon a less then smooth cut.  A crude weapon perhaps, but seemingly dangerous in the right hands.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(500);
	set_lore(
@AVATAR
Nivin was a great orcish warrior with a taste for using whatever came to hand at the moment.  Never one to carry anything more then the treasure he was seeking, Nivin would use stones, tree branches or the severed legs of his enemy to kill those who stood in his way.  At the Battle of the Three Crossed Roads, however, Nivin changed tactics.  It is said he stayed up all night before the great battle, fashioning this axe from a stone that held some sort of special meaning to him.  Whatever that meaning was is unknown, but Nivin's victory over the human army at the battle suggests that Nivin knew what he was doing, even if he cast the weapon aside the next day.

AVATAR
	);
	set_property("lore difficulty",14);
	set_type("slashing");
	set_prof_type("axe");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^With a grunt, "+ETOQCN+" hefts the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^With a grunt, you heft the "+query_short()+"%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" grunts like an orc as they put the "+query_short()+" %^BOLD%^%^BLUE%^aside%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grunt like an orc as you put the "+query_short()+" %^BOLD%^%^BLUE%^aside%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" screams bloody murder as they tear into "+targ->QCN+" with the "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^You scream bloody murder as you tear into "+targ->QCN+" with the "+query_short()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" screams bloody murder as they tear into you with their "+query_short()+"!%^RESET%^");
		return roll_dice(2,3)+0;	}
}