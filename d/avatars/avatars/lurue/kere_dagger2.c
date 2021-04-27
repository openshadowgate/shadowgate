#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("finely made dagger");
	set_id(({ "dagger", "kereteli dagger", "finely made dagger", "kereteli dagger" }));
	set_short("%^BOLD%^%^YELLOW%^K%^BLACK%^ereteli %^YELLOW%^C%^BLACK%^urved %^YELLOW%^D%^BLACK%^agger%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^f%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLACK%^e%^BLUE%^l%^BLACK%^y m%^BLUE%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^straight dagger%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^CYAN%^This highly decorated weapon is forged with a titanium core steal which gives the blade an impressive soundness, even under the most grievous of pressures.  A dark %^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^r%^BOLD%^a%^BLACK%^y-b%^RESET%^%^BLUE%^l%^BOLD%^u%^BLACK%^e %^RESET%^%^CYAN%^in color, the dagger is lined with several hooked teeth along its back edge, the better to rip wounds open with.  The dagger is acid etched with intricate swirls and ridges that follow the length of the weapon and only taper away when they reach the %^RED%^razor edge%^CYAN%^.  The hilt of this spectacular weapon is gilded in %^ORANGE%^gold%^CYAN%^, %^BOLD%^%^WHITE%^platinum %^RESET%^%^CYAN%^and %^YELLOW%^topaz%^RESET%^%^CYAN%^, including the large diamond cut gem that forms the pommel of the blade. A designer's piece to be sure, it would fetch a high price or cut a man's throat equally well.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1400);
	set_lore(
@AVATAR

%^YELLOW%^K%^BLACK%^ereteli of %^YELLOW%^A%^BLACK%^lsa'telanere is well known throughout the southern lands of the %^YELLOW%^T%^BLACK%^svarian %^YELLOW%^E%^BLACK%^mpire.  Their master smiths and weapons crafters as said to know no compare for their skill with the raw metals that are pulled from the %^YELLOW%^K%^BLACK%^ereteli mines.  Elven owned, the %^YELLOW%^K%^BLACK%^ereteli-%^YELLOW%^B%^BLACK%^lades are highly prized both for their exceptional craftsmanship as well as their enduring quality.  The fact that they are often considered collectors pieces and can fetch exorbitant prices between men of high station does not stop them from being coveted by most who admire fine weapons.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+"'s "+query_short()+"%^YELLOW%^ rips and tears "+targ->QCN+"'s flesh as it cuts deep!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^Your blade rips and tears "+targ->QCN+"'s flesh as it cuts deep!%^RESET%^");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+"'s "+query_short()+"%^YELLOW%^ rips and tears your flesh as it cuts deep!%^RESET%^");
		return roll_dice(2,4)+1;	}
}