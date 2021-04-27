#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^S%^RESET%^p%^BOLD%^ik%^RESET%^e%^BOLD%^%^BLACK%^d gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_id(({ "greaves", "spiked greaves" }));
	set_short("%^BOLD%^%^BLACK%^Greaves of a %^RESET%^%^RED%^to%^BOLD%^rm%^RESET%^%^RED%^e%^BOLD%^%^RED%^nt%^RESET%^%^RED%^ed %^BOLD%^%^BLACK%^soul%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^S%^RESET%^p%^BOLD%^ik%^RESET%^e%^BOLD%^%^BLACK%^d gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made to protect the shins and knees, these greaves are crafted from leather dyed jet black. Small but sharp %^BOLD%^%^BLACK%^si%^RESET%^lv%^BOLD%^er sp%^RESET%^ik%^BOLD%^%^BLACK%^es%^BOLD%^%^BLACK%^ protrude from the surface. The %^RESET%^%^RED%^t%^BOLD%^%^BLACK%^ip%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ of the shining spikes have been dyed a deep shade of %^RESET%^%^RED%^crim%^BOLD%^s%^RESET%^%^RED%^on%^BOLD%^%^BLACK%^, as if they have been %^RESET%^eternally%^BOLD%^%^BLACK%^ tainted with %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^. The flexibility of the leather would not hinder movement while offering protection to the wearer.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^The greaves of a tormented soul are highly prized by those of Loviatar's faith because it is rumored that they have been blessed in the blood of a sacrifice to the Maiden of Pain. Some even insist that they can still hear the screams of the hapless victim to this very day.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" smiles darkly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^A %^BOLD%^%^BLACK%^dark chorus%^RESET%^%^RED%^ of %^BOLD%^%^RED%^tortured screams%^RESET%^%^RED%^ fills your mind as you fasten the greaves.%^RESET%^");
	ETO->do_damage("torso",random(5));
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks momentarily distressed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remorsefully remove the "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The %^RESET%^silver spikes%^BOLD%^%^RED%^ of "+ETOQCN+"'s%^BOLD%^%^RED%^ "+query_short()+"%^BOLD%^%^RED%^ tears into "+who->QCN+"%^BOLD%^%^RED%^'s flesh, splattering %^RESET%^%^RED%^blood%^BOLD%^%^RED%^ everywhere!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^You bash your knee into "+who->QCN+"%^RESET%^%^BOLD%^%^RED%^, ripping into the flesh.%^RESET%^");
	tell_object(who,"%^BOLD%^%^RED%^You feel your flesh ripped asunder as "+ETOQCN+"%^BOLD%^%^RED%^ bashes you with "+query_short()+"%^BOLD%^%^RED%^.%^RESET%^");
		who->do_damage("torso",random(7));
return damage;	}
}