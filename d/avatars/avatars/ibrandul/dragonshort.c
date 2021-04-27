#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^BLACK%^ec%^RESET%^%^WHITE%^h%^RESET%^%^BOLD%^%^BLACK%^o of g%^RESET%^%^RED%^l%^RESET%^%^BOLD%^%^BLACK%^ory%^RESET%^%^WHITE%^");
	set_id(({ "sword", "short sword", "fang sword" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^ec%^RESET%^%^WHITE%^h%^RESET%^%^BOLD%^%^BLACK%^o of g%^RESET%^%^RED%^l%^RESET%^%^BOLD%^%^BLACK%^ory%^RESET%^%^WHITE%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^d%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^%^BOLD%^%^BLACK%^ag%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^n f%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ng short sword%^RESET%^%^WHITE%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^You are on the eastern side of a city square. To the west to see the rui%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^BLACK%^s of a f%^RESET%^%^WHITE%^ou%^RESET%^%^BOLD%^%^BLACK%^nt%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^in. The street was obviously the scene of a %^RESET%^%^RED%^bloody battle%^RESET%^%^BOLD%^%^BLACK%^, as the ground is pockmarked with small craters and the fine cobblestones have been mostly ruined%^RESET%^%^WHITE%^
%^RESET%^%^BOLD%^%^WHITE%^This short sword has been crafted out of the fang of a %^RESET%^%^BOLD%^%^BLACK%^dragon%^RESET%^%^BOLD%^%^WHITE%^. It's blade has been carved to a double edge and broadens slightly before coming together to a razor sharp point. A %^RESET%^%^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^v%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^BOLD%^%^WHITE%^ runs down the middle of the blade, allowing %^RESET%^%^RED%^blo%^RESET%^%^BOLD%^%^RED%^o%^RESET%^%^RED%^d %^RESET%^%^BOLD%^%^WHITE%^to flow off and away from the point. Two %^RESET%^%^ORANGE%^dragon heads %^RESET%^%^BOLD%^%^WHITE%^with %^RESET%^%^RED%^ru%^RESET%^%^BOLD%^%^RED%^b%^RESET%^%^RED%^y %^RESET%^%^BOLD%^%^WHITE%^eyes form a sturdy cross piece, and the hilt has been carefully shaped to allow a firm grip for a small hand. A %^RESET%^%^YELLOW%^fi%^RESET%^%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^RESET%^%^BOLD%^%^WHITE%^ %^RESET%^%^RED%^o%^RESET%^%^ORANGE%^p%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^YELLOW%^l%^RESET%^%^BOLD%^%^WHITE%^ is set into the pommel, giving the sword an aura of flame%^RESET%^%^WHITE%^

AVATAR
	);
	set_weight(4);
	set_value(10000);
	set_lore(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^crafted by a weaponsmith known in the realms by a hundred names, this blade was formed out of the fang of a black dragon ripped out after it was killed.  

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("short blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,4);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^"+ETOQCN+"%^RESET%^%^BOLD%^%^BLACK%^ grasps the sword and close thier eyes suddenly%^RESET%^%^WHITE%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^you grasp the sword in your hands, your mind fills with c%^RESET%^%^WHITE%^h%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^BOLD%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^tic images you just cant understand%^RESET%^%^WHITE%^");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^"+ETOQCN+"%^RESET%^%^BOLD%^%^BLACK%^ releases the sword and opens thier eyes%^RESET%^%^WHITE%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^you release the sword, your mind clears swiftly of the images%^RESET%^%^WHITE%^");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^RESET%^%^WHITE%^"+ETOQCN+"%^RESET%^%^BOLD%^%^BLACK%^ thrusts the %^RESET%^%^WHITE%^"+query_short()+" %^RESET%^%^BOLD%^%^BLACK%^into %^RESET%^%^WHITE%^"+targ->QCN+"%^RESET%^%^BOLD%^%^BLACK%^ and it flares with a sudden %^RESET%^%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^l%^RESET%^%^BOLD%^%^RED%^dr%^RESET%^%^YELLOW%^i%^RESET%^%^BOLD%^%^RED%^tch fi%^RESET%^%^ORANGE%^r%^RESET%^%^BOLD%^%^RED%^e%^RESET%^%^BOLD%^%^BLACK%^.. %^RESET%^%^WHITE%^"+targ->QCN+"%^RESET%^%^BOLD%^%^BLACK%^ screams%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^As you thrust the sword into %^RESET%^%^WHITE%^"+targ->QCN+"%^RESET%^%^BOLD%^%^BLACK%^, your eyes close and you see a hundred black dragons wheeling in combat against an army of %^RESET%^%^YELLOW%^go%^RESET%^%^ORANGE%^l%^RESET%^%^YELLOW%^ds %^RESET%^%^BOLD%^%^BLACK%^and %^RESET%^%^BOLD%^%^WHITE%^si%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^%^WHITE%^ve%^RESET%^%^WHITE%^r%^RESET%^%^BOLD%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^");
	tell_object(targ,"%^RESET%^%^WHITE%^"+ETOQCN+"%^RESET%^%^BOLD%^%^BLACK%^ thrusts the %^RESET%^%^WHITE%^"+query_short()+" %^RESET%^%^BOLD%^%^BLACK%^deep into you. Your vision swims and you feel a horrible %^RESET%^%^BOLD%^%^RED%^b%^RESET%^%^ORANGE%^u%^RESET%^%^BOLD%^%^RED%^rni%^RESET%^%^YELLOW%^n%^RESET%^%^BOLD%^%^RED%^g %^RESET%^%^BOLD%^%^BLACK%^and the screams of a hundred dragons%^RESET%^");
		return roll_dice(4,4)+-1;	}
}