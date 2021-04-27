#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dragonhorn claw");
	set_id(({ "claw", "dragonhorn claw" }));
	set_short("%^BOLD%^%^BLACK%^Dr%^GREEN%^a%^BLACK%^gonh%^GREEN%^o%^BLACK%^rn Cl%^GREEN%^a%^BLACK%^w%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^w%^GREEN%^i%^BLACK%^cked%^GREEN%^l%^BLACK%^y c%^GREEN%^u%^BLACK%^rv%^GREEN%^e%^BLACK%^d cl%^GREEN%^a%^BLACK%^w%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Despite their names, these claws appear to be made out of metal rather then actual %^ORANGE%^dragon horns %^CYAN%^or %^GREEN%^dragon claws%^CYAN%^.  Still, they bare a distinct likeness to their namesake with the %^GREEN%^curved %^CYAN%^prongs extending out well past the knuckles to coil forward into %^BOLD%^%^BLACK%^deadly spikes%^RESET%^%^CYAN%^.  Thick %^ORANGE%^leather gloves%^CYAN%^, reinforced with belt weight straps across the palm, cover and protect the hand, while the long %^GREEN%^metal claws %^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^inky black metal %^RESET%^%^CYAN%^extend almost twice the length of the wearer's hand.  Dragon claws indeed!%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(2000);
	set_lore(
@AVATAR
Legend hold that these claws were first fashioned out of true dragon talons when Orolof Towerstone, dwarven slayer of all things large, simply cut off the paws of Isterbicken the green dragon.  After hollowing and cleaning them out, the tales say that Orolof simply wore them over his own gloved hands, using a strip of dried rawhide to seal them on.  Over time the flesh rotted away and Orolof was forced to find something else as a substitution.  The eventual outcome ended up much as claws appear today.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("knuckles");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips on the %^RESET%^"+query_short()+"%^RESET%^%^BOLD%^%^BLACK%^ and starts looking about for something to scratch.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slide the %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^ on and feel the urge to reach out and scratch something... %^GREEN%^hard%^BLACK%^!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" gives a tug on %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^ and they slide right off.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With regret, you draw the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^from your hand.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^With a mighty cry of success, %^BLACK%^"+ETOQCN+"%^BOLD%^%^GREEN%^ reaches out and scratches %^BOLD%^%^BLACK%^"+targ->QCN+" %^BOLD%^%^GREEN%^with their%^RESET%^ "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^With a mighty cry of success, you reach out and scratch %^BOLD%^%^BLACK%^"+targ->QCN+" %^BOLD%^%^GREEN%^ with your "+query_short()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^With a mighty cry of success, %^BLACK%^"+ETOQCN+"%^BOLD%^%^GREEN%^ reaches out and scratches you hard with their%^RESET%^ "+query_short()+"!%^RESET%^");
		return roll_dice(2,4)+0;	}
}