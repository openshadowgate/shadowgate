#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("vanguard's armwraps");
	set_id(({ "wraps", "armwraps", "vanguard's arm wraps", "arm wraps" }));
	set_short("%^YELLOW%^V%^RED%^a%^RESET%^%^ORANGE%^n%^BOLD%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^r%^BOLD%^d's A%^RED%^r%^ORANGE%^m W%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^p%^BOLD%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d and %^ORANGE%^g%^RESET%^%^ORANGE%^o%^WHITE%^l%^YELLOW%^d %^RED%^leather arm wraps%^RESET%^");
	set_long("%^BOLD%^%^RED%^These heavy %^RESET%^%^ORANGE%^l%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^t%^RESET%^%^ORANGE%^h%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^r %^BOLD%^%^RED%^arm wraps are quite long, and"
	" may be coiled around the wearer's arms in a s%^RESET%^%^ORANGE%^p%^BOLD%^%^WHITE%^i%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^l that nearly reaches the elbows of most. Dyed a vi%^RESET%^%^RED%^b%^BOL"
	"D%^rant blo%^RESET%^%^RED%^o%^BOLD%^d r%^RESET%^%^RED%^e%^BOLD%^d and with a %^RESET%^white %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^n %^RED%^from its protective coating, it loo"
	"ks like these wraps would go a ways toward protecting the wearer's forearms from all but the heaviest blows. The edges of the leather are %^WHITE%^embellished %^RED%^with o%^WHITE%^r%^BLACK%^n%^RED%^a"
	"%^RESET%^%^ORANGE%^t%^BOLD%^%^RED%^e and a%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^g%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^r %^ORANGE%^e%^RESET%^n%^YELLOW%^g%^RESET%^r%^YELLO"
	"W%^a%^RESET%^v%^YELLOW%^i%^WHITE%^n%^RESET%^g%^YELLOW%^s%^RED%^, inlaid with %^ORANGE%^gold%^RED%^.%^RESET%^
"	);
	set_value(5000);
	set_lore("%^BOLD%^%^RED%^Little can be said for sure about these arm wraps, save that they have the uncanny tendency to find their way into the possession of a certain breed of warrior. Often doubted and downtr"
	"odden, yet with an unbreakable spirit and drive for self-improvement, these souls find themselves aided by the wrap's magical abilities more than anyone.%^RESET%^
"	);
	set_property("lore difficulty",15);
	set_item_bonus("attack bonus",2);
	set_item_bonus("damage bonus",2);
	set_item_bonus("fortitude",1);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" winds the %^RESET%^%^ORANGE%^leather wraps %^BOLD%^%^RED%^around their forearms, looking somewhat more %^ORANGE%^c%^WHITE%^o%^ORANGE%^n%^WHITE%^f%^ORANGE%^i%^WHITE%^d%^ORANGE%^e%^WHITE%^n%^ORANGE%^t%^RED%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You wind the %^RESET%^%^ORANGE%^leather wraps %^BOLD%^%^RED%^around your forearms and secure it, feeling markedly %^ORANGE%^s%^WHITE%^e%^ORANGE%^lf-a%^WHITE%^s%^ORANGE%^s%^WHITE%^u%^ORANGE%^r%^WHITE%^e%^ORANGE%^d%^RED%^.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^The leather wraps %^BLACK%^u%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^co%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^l %^RED%^and fall away from "+ETOQCN+"'s arms.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The leather wraps %^BLACK%^u%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^co%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^l %^RED%^and fall away from your arms.%^RESET%^");
	return 1;
}

