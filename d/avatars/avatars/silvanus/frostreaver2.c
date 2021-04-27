#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("FrostReaver");
	set_id(({ "axe", "frostreaver", "frost reaver", "FrostReaver", "Frost Reaver" }));
	set_short("%^BOLD%^%^WHITE%^F%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^s%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^R%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^medium axe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^The head of this massive axe is made from a frost white %^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^y%^RESET%^%^WHITE%^s%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^l that has been chiseled on both ends to form serrated edges.  It connects seamlessly to an %^BOLD%^%^RED%^adamantite%^BOLD%^%^WHITE%^ handle.  The handle has been laced with the scaly hide of some great reptilian beast in order to reinforce the %^BOLD%^%^RED%^adamantite%^BOLD%^%^WHITE%^ and offer the wielder a superb grip.%^RESET%^

AVATAR
	);
	set_weight(14);
	set_value(2000);
	set_type("slashing");
	set_prof_type("medium axe");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" readies the "+query_short()+"%^BOLD%^%^WHITE%^ and suddenly shivers!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^A cold chill runs through your body as you ready the "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^");
	TP->do_damage("torso",random(4));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" releases the "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^The warmth returns to your body as you release the "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The "+query_short()+"%^BOLD%^%^WHITE%^ wielded by "+ETO->query_cap_name()+" %^YELLOW%^glows%^BOLD%^%^WHITE%^ an icy %^CYAN%^blue%^BOLD%^%^WHITE%^ as it sinks into "+targ->query_cap_name()+"'s flesh, causing "+targ->query_cap_name()+" to shiver!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your "+query_short()+"%^BOLD%^%^WHITE%^ glows an icy %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^ as it sinks into "+targ->query_cap_name()+"'s flesh, causing "+targ->query_cap_name()+" to shiver!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+"'s "+query_short()+"%^BOLD%^%^WHITE%^ %^YELLOW%^glows%^BOLD%^%^WHITE%^ an icy %^CYAN%^blue%^BOLD%^%^WHITE%^ as it sinks into your flesh, causing a deathly cold chill to run through your body!%^RESET%^");
		return roll_dice(1,12)+1;	}
}