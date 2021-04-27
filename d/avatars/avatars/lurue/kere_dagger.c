#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("finely made dagger");
	set_id(({ "dagger", "kereteli dagger", "finely made dagger", "kereteli dagger" }));
	set_short("%^BOLD%^%^GREEN%^K%^BLACK%^ereteli %^GREEN%^C%^BLACK%^urved %^GREEN%^D%^BLACK%^agger%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^f%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLACK%^e%^BLUE%^l%^BLACK%^y m%^BLUE%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^curved dagger%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^CYAN%^This highly decorated weapon is forged with a titanium core steal which gives the blade an impressive soundness, even under the most grievous of pressures.  A dark %^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^r%^BOLD%^a%^BLACK%^y-b%^RESET%^%^BLUE%^l%^BOLD%^u%^BLACK%^e %^RESET%^%^CYAN%^in color, the dagger has a crescent shaped curve lined with several hooked teeth along its back edge, the better to rip wounds open with.  The dagger is acid etched with intricate swirls and ridges that follow the length of the weapon and only taper away when they reach the %^RED%^razor edge%^CYAN%^.  The hilt of this spectacular weapon is gilded in %^ORANGE%^gold%^CYAN%^, %^BOLD%^%^WHITE%^platinum %^RESET%^%^CYAN%^and %^GREEN%^%^BOLD%^emeralds%^RESET%^%^CYAN%^, including the large diamond cut gem that forms the pommel of the blade. A designer's piece to be sure, it would fetch a high price or cut a man's throat equally well.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1800);
	set_lore(
@AVATAR

%^BOLD%^%^GREEN%^K%^BLACK%^ereteli of %^GREEN%^A%^BLACK%^lsa'telanere is well known throughout the southern lands of the %^GREEN%^T%^BLACK%^svarian %^GREEN%^E%^BLACK%^mpire.  Their master smiths and weapons crafters as said to know no compare for their skill with the raw metals that are pulled from the %^GREEN%^K%^BLACK%^ereteli mines.  Elven owned, the %^GREEN%^K%^BLACK%^ereteli-%^GREEN%^B%^BLACK%^lades are highly prized both for their exceptional craftsmanship as well as their enduring quality.  The fact that they are often considered collectors pieces and can fetch exorbitant prices between men of high station does not stop them from being coveted by most who admire fine weapons.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+targ->QCN+" cries out in pure agony as the hooks of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^GREEN%^catch and rend their flesh!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^"+targ->QCN+" cries out in pure agony as the hooks of the "+query_short()+" %^BOLD%^%^GREEN%^catch and rend their flesh!");
	tell_object(targ,"%^BOLD%^%^GREEN%^You cry out in pure agony as the hooks of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^GREEN%^catch and rend your flesh!");
		return roll_dice(3,4)+1;	}
}