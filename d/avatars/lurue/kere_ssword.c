#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("finely made short sword");
	set_id(({ "sword", "shortsword", "short sword", "kereteli short sword", "finely made shortsword", "kereteli shortsword" }));
	set_short("%^BOLD%^%^CYAN%^K%^BLACK%^ereteli %^CYAN%^S%^BLACK%^hort %^CYAN%^S%^BLACK%^word%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^f%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLACK%^e%^BLUE%^l%^BLACK%^y m%^BLUE%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^short sword%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^CYAN%^This highly decorated weapon is forged with a titanium core steal which gives the blade an impressive soundness, even under the most grievous of pressures.  A dark %^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^r%^BOLD%^a%^BLACK%^y-b%^RESET%^%^BLUE%^l%^BOLD%^u%^BLACK%^e %^RESET%^%^CYAN%^in color, the short, straight blade is acid etched with intricate swirls and ridges that follow the length of the weapon and only taper away when they reach the %^RED%^razor edge%^CYAN%^.  The hilt of this spectacular weapon is gilded in %^ORANGE%^gold%^CYAN%^, %^BOLD%^%^WHITE%^platinum %^RESET%^%^CYAN%^and %^BOLD%^%^CYAN%^sapphires%^RESET%^%^CYAN%^, including the large princess cut gem that forms the pommel of the blade. A designer's piece to be sure, it would fetch a high price or cut a man's throat equally well.%^RESET%^


AVATAR
	);
	set_weight(4);
	set_value(2000);
	set_lore(
@AVATAR

%^BOLD%^%^CYAN%^K%^BLACK%^ereteli of %^CYAN%^A%^BLACK%^lsa'telanere is well known throughout the southern lands of the %^CYAN%^T%^BLACK%^svarian %^CYAN%^E%^BLACK%^mpire.  Their master smiths and weapons crafters as said to know no compare for their skill with the raw metals that are pulled from the %^CYAN%^K%^BLACK%^ereteli mines.  Elven owned, the %^CYAN%^K%^BLACK%^ereteli-%^CYAN%^B%^BLACK%^lades are highly prized both for their exceptional craftsmanship as well as their enduring quality.  The fact that they are often considered collectors pieces and can fetch exorbitant prices between men of high station does not stop them from being coveted by most who admire fine weapons.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("short blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,4);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+targ->QCN+" screams in pain as the perfect edge of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^RED%^cuts deep! %^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^"+targ->QCN+" screams in pain as the perfect edge of the "+query_short()+" %^BOLD%^%^RED%^cuts deep! %^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^You scream in pain as the perfect edge of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^RED%^cuts deep!%^RESET%^");
		return roll_dice(4,4)+1;	}
}