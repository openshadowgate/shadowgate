#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("fan");
	set_id(({ "fan", "ironwood fan", "carved fan" }));
	set_short("%^BOLD%^%^BLACK%^C%^RESET%^%^CYAN%^a%^WHITE%^r%^BOLD%^%^BLACK%^ved F%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^RESET%^a %^CYAN%^I%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^now%^RESET%^o%^CYAN%^d%^RESET%^ fan");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made from ironwood, this delicate fan is carved with delightful images of frolicking %^RESET%^%^CYAN%^birds %^BOLD%^%^BLACK%^amongst a %^RESET%^%^MAGENTA%^floral %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^vine %^BOLD%^%^BLACK%^setting on one side, and with a %^RESET%^%^ORANGE%^wild hunt %^BOLD%^%^BLACK%^setting on the other.  Despite it's fanciful designs, the wood is as sturdy as the metal it is named after, and the fan's edges have been shaved down into nearly %^RESET%^razor sharp %^BOLD%^%^BLACK%^edges, making this fan both weapon and decoration.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(100);
	set_lore(
@AVATAR
The carved fans of Yorsbe are prized for their delicate craftsmanship and intricate designs.  Fashioned to represent two phases of life, each fan is unique and tells a story for those who are familiar with the Yorsbe rituals.  In this case, one can only wonder what the exact story is, though the peaceful setting on one side broken by the wild dash of the hunt on the other eludes to a time of broken peace and changing temperament.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("fan");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,4);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" unfurls their "+query_short()+" %^BOLD%^%^CYAN%^and weaves it about in a quick succession of deadly movements!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You unfurl your "+query_short()+" %^BOLD%^%^CYAN%^and weave it about in a swirl of quick movements to defend and cut your enemy!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^You feel the cut and sting of the sharp edges of "+ETOQCN+"'s "+query_short()+"!%^RESET%^");
		return roll_dice(1,4)+0;	}
}