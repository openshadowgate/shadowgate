#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("green tinted sword ");
	set_id(({ "sword", "green tinted sword", "longsword", "long sword", "forests edge", "forest's edge" }));
	set_short("%^RESET%^%^GREEN%^F%^ORANGE%^o%^WHITE%^r%^ORANGE%^e%^GREEN%^st%^ORANGE%^'%^GREEN%^s E%^ORANGE%^d%^WHITE%^g%^GREEN%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^GREEN%^green-tinted%^ORANGE%^ longsword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This long sword has been carefully crafted in the tradition of the fabled and renowned %^ORANGE%^elven rangers%^GREEN%^.  The double edges on the blade have an unusual, nearly imperceptible %^BOLD%^green sheen %^RESET%^%^GREEN%^and the weapon, though long, seems light for it's size when wielded, hinting at an %^WHITE%^unusual power%^GREEN%^.  The pommel is tightly wrapped in a %^ORANGE%^supple leather %^GREEN%^insuring a secure grip on this extraordinarily %^WHITE%^sharp %^GREEN%^weapon. Near the end of the hilt is a tiny mark resembling %^BLUE%^rippling water %^GREEN%^in the center of a %^BOLD%^leaf%^RESET%^%^GREEN%^.%^RESET%^

AVATAR
	);
	set_weight(7);
	set_value(500);
	set_lore(
@AVATAR
Designed by a follower of Istishia, this weapon was made to aid in the cause of the elven rangers patrolling the northern lands of Dagger.  It is said that the elves sought his help to create these blades as a challenge to the human's skill.  The magic imbued within them, however, is all elven, laid into the very metal by the efforts of elven mages whose skills with the weave have taken centuries to master.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" looks a bit surprised as they take firm hold of the %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ feels surprisingly light in your hand.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" looks a bit disappointed as they set %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ aside.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You feel a sense of connection slip away as you set the %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^ aside.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+"'s %^RESET%^"+query_short()+"%^RESET%^%^ORANGE%^ glows %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^ as it strikes "+targ->QCN+" solidly!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^The %^RESET%^"+query_short()+"%^RESET%^%^ORANGE%^ glows %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^ as it strikes "+targ->QCN+" solidly!%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+"'s %^RESET%^"+query_short()+"%^RESET%^%^ORANGE%^ glows %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^ as it strikes you solidly!%^RESET%^");
		return roll_dice(2,4)+1;	}
}