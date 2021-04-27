#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bat of dmf beating");
	set_id(({ "bat" }));
	set_short("%^RESET%^%^GREEN%^Bat of DMF %^RESET%^%^RED%^Beating%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^Bat of DMF %^RESET%^%^RED%^Beating%^RESET%^");
	set_long(
@AVATAR
This is the %^RESET%^%^GREEN%^Bat of DMF %^RESET%^%^RED%^Beating%^RESET%^.  It's
used by wizzes to beat DMF's.  Don't become one ;)
.

AVATAR
	);
	set("read",
@AVATAR
Youuuuuuuuu're outta there!!!!

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("medium club");
	set_size(2);
	set_wc(10,10);
	set_large_wc(10,10);
	set_property("enchantment",30);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" wields the bat and glances around the room for someone to %^RESET%^%^RED%^punish%^RESET%^.",ETO);
	tell_object(ETO,"You grasp the bat and look around for someone to %^RESET%^%^RED%^punish%^RESET%^.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" unwields the bat and the %^RESET%^%^RED%^anger %^RESET%^fades from their face.",ETO);
	tell_object(ETO,"You unwield the bat and let your %^RESET%^%^RED%^anger %^RESET%^subside.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+ETOQCN+" howls in %^RESET%^%^RED%^rage %^RESET%^and smacks the living hell out of "+targ->QCN+" with their bat.",({ETO,targ}));
	tell_object(ETO,"You howl in %^RESET%^%^RED%^rage %^RESET%^and smack the living hell out of "+targ->QCN+" with your bat.");
	tell_object(targ,""+ETOQCN+" howls in %^RESET%^%^RED%^rage %^RESET%^and smacks the living hell out of you with their bat.");
		targ->set_paralyzed(roll_dice(2,10)+0);
return 0;	}
}