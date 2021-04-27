#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("wrist clasp");
	set_id(({ "clasp", "wrist clasp", "black clasp" }));
	set_short("%^BOLD%^%^BLACK%^S%^BLUE%^h%^BLACK%^a%^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^%^BLACK%^lo%^BLUE%^r%^BLACK%^d's C%^BLUE%^l%^BLACK%^a%^RESET%^s%^BOLD%^%^BLACK%^p%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a t%^RESET%^h%^BOLD%^i%^BLACK%^n w%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^t c%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^p of p%^RESET%^u%^BOLD%^%^BLACK%^re%^RESET%^s%^BOLD%^%^BLACK%^t b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This simple %^RESET%^w%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^s%^WHITE%^t c%^CYAN%^l%^BOLD%^a%^RESET%^%^CYAN%^s%^WHITE%^p %^BOLD%^%^BLACK%^would look like any other, two thin sheets of stu"
	"dded metal designed to hold the cuff of a tunic in place. A few oddities do draw the eye, however, most notably its o%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^r%^RESET%^w%"
	"^BOLD%^%^BLACK%^or%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^d%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^y b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k h%^RESET%^u%^BOLD%^%^BLACK%^e, which seems to %^BLU"
	"E%^darken %^BLACK%^anything it comes into contact with. Despite its thinness, the strange metal seems surprisingly durable, and is cool to the touch at all times.%^RESET%^
"	);
	set_value(5000);
	set_lore("%^BOLD%^%^BLACK%^The metal making up this wrist clasp is a rare, nigh-indestructible alloy called 'd%^RESET%^a%^BOLD%^%^BLACK%^rk p%^RESET%^l%^BOLD%^%^BLACK%^at%^RESET%^i%^BOLD%^%^BLACK%^n%^WHITE%^u%^"
	"BLACK%^m', generally found only in trace quantities across the planes - indeed, even the small amount of material making up this trinket makes it an undeniable rarity on the Prime. The trinket's mater"
	"ial actually seems to be its least interesting feature, however, for it appears to have been attuned by divine magic to the %^RESET%^%^CYAN%^Plane of Shadows%^BOLD%^%^BLACK%^, allowing anyone who wear"
	"s it to subconsciously draw upon the transient plane's energies.%^RESET%^
"	);
	set_property("lore difficulty",25);
	set_item_bonus("dexterity",2);
	set_item_bonus("sight bonus",2);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^RESET%^s%^CYAN%^t c%^WHITE%^l%^BOLD%^%^CYAN%^a%^RESET%^s%^CYAN%^p %^BOLD%^%^BLACK%^s%^RESET%^p%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^kl%^RESET%^e%^BOLD%^%^BLACK%^s darkly as "+ETOQCN+" affixes it to a sleeve.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^RESET%^s%^CYAN%^t c%^WHITE%^l%^BOLD%^%^CYAN%^a%^RESET%^s%^CYAN%^p %^BOLD%^%^BLACK%^s%^RESET%^p%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^kl%^RESET%^e%^BOLD%^%^BLACK%^s darkly as you affix it to your sleeve.%^RESET%^");
	return 1;
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s skin %^WHITE%^p%^RESET%^u%^BOLD%^%^BLACK%^l%^WHITE%^s%^BLACK%^e%^WHITE%^s %^BLACK%^black with s%^RESET%^h%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^ow e%^RESET%^n%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^g%^BOLD%^%^BLACK%^y as "+who->QCN+" strikes, and the blow is turned aside!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You suddenly find your skin protected by a thin layer of s%^RESET%^h%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^ow e%^RESET%^n%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^g%^BOLD%^%^BLACK%^y, turning the blow aside!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^Your strike is suddenly turned aside, as "+ETOQCN+"'s skin briefly turns black with s%^RESET%^h%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^ow e%^RESET%^n%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^g%^BOLD%^%^BLACK%^y!%^RESET%^");
return (damage*-100)/100;	}

}
