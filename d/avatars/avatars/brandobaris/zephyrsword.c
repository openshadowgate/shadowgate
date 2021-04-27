#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("Longsword of the Zephyr");
	set_id(({ "sword", "longsword", "silver longsword", "silver sword", "zephyr sword" }));
	set_short("%^BOLD%^%^CYAN%^L%^WHITE%^o%^RESET%^n%^BOLD%^%^CYAN%^g%^WHITE%^s%^RESET%^w%^BOLD%^%^CYAN%^o%^WHITE%^r%^CYAN%^d of the Z%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^p%^CYAN%^h%^RESET%^y%^BOLD%^%^CYAN%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^a g%^RESET%^l%^BOLD%^%^CYAN%^i%^WHITE%^t%^CYAN%^t%^RESET%^e%^BOLD%^%^CYAN%^r%^WHITE%^i%^RESET%^n%^BOLD%^%^CYAN%^g %^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^RESET%^e%^BOLD%^r %^CYAN%^l%^WHITE%^o%^CYAN%^n%^WHITE%^g%^CYAN%^s%^WHITE%^w%^CYAN%^o%^WHITE%^r%^CYAN%^d%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^This e%^WHITE%^l%^CYAN%^e%^WHITE%^g%^CYAN%^a%^WHITE%^n%^CYAN%^t, %^WHITE%^silver longsword %^CYAN%^is about three and a half feet in length, and its muted blade %^RESET%^s%^BOLD%^h%^RE"
	"SET%^i%^BOLD%^m%^RESET%^m%^BOLD%^er%^RESET%^s %^BOLD%^%^CYAN%^softly, like a %^WHITE%^m%^RESET%^i%^BOLD%^s%^RESET%^t%^BOLD%^y m%^RESET%^or%^BOLD%^n%^RESET%^in%^BOLD%^g s%^RESET%^k%^BOLD%^y%^CYAN%^. %^"
	"WHITE%^M%^RESET%^i%^BOLD%^l%^RESET%^k%^BOLD%^y o%^RESET%^p%^BOLD%^%^BLACK%^a%^WHITE%^ls %^CYAN%^are set into the sword's tapered, sweeping cross-guard, and the hilt is wrapped tightly in a layer of %^"
	"RESET%^%^ORANGE%^leather %^BOLD%^%^CYAN%^dyed %^BLUE%^cobalt blue%^CYAN%^, while a large and faceted %^WHITE%^di%^CYAN%^a%^RESET%^m%^BOLD%^o%^CYAN%^n%^WHITE%^d %^CYAN%^has been set as a simple, yet se"
	"rviceable pommel.%^RESET%^
"	);
	set_value(20000);
	set_lore("%^CYAN%^Ancient Tsarven legends speak of great %^BOLD%^%^WHITE%^silver scimitars %^RESET%^%^CYAN%^wielded by the old Djinn warriors of Air, said to be capable of inspiring a devastating %^BOLD%^%^WHIT"
	"E%^w%^CYAN%^i%^WHITE%^n%^RESET%^d%^BOLD%^s%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^m %^RESET%^%^CYAN%^with but a flourish, or cutting a great %^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^o%^BOLD%^%"
	"^BLACK%^r%^RESET%^n%^BOLD%^%^BLACK%^a%^WHITE%^d%^BLACK%^o %^RESET%^%^CYAN%^clean in two with a single mighty stroke. Whatever the truth to these accounts, the Akadians have kept the legend alive with "
	"this longsword variant. Imbued with the divine blessings of the Queen of Air herself, these blades have oft been known to be carried by the Akadian rangers of the %^YELLOW%^Tsarven Empire%^RESET%^%^CY"
	"AN%^, some of the few individuals brave enough to dare walk the treacherous expanse of %^BOLD%^%^RED%^Talzashaar's Teeth%^RESET%^%^CYAN%^.%^WHITE%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("damage bonus",2);
	set_item_bonus("attack bonus",2);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^A gust of %^CYAN%^wind %^WHITE%^picks up about "+ETOQCN+", as they grasp the longsword's hilt.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^A gust of %^CYAN%^wind %^WHITE%^picks up about you as you grasp the longsword's hilt.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" sets aside the longsword.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You set aside the longsword, and hear the faint %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^s%^RESET%^p%^BOLD%^e%^RESET%^r%^BOLD%^in%^RESET%^g %^BOLD%^of a departing %^CYAN%^b%^RESET%^%^CYAN%^r%^WHITE%^e%^BOLD%^e%^RESET%^z%^BOLD%^%^CYAN%^e%^WHITE%^.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^A r%^RESET%^a%^BOLD%^z%^BLACK%^o%^CYAN%^r-s%^RESET%^h%^BOLD%^a%^BLACK%^r%^CYAN%^p c%^WHITE%^u%^CYAN%^r%^WHITE%^r%^CYAN%^e%^WHITE%^n%^CYAN%^t of %^WHITE%^air %^CYAN%^rushes forth from "+ETOQCN+"'s blade, %^WHITE%^cutting %^CYAN%^"+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A r%^RESET%^a%^BOLD%^z%^BLACK%^o%^CYAN%^r-s%^RESET%^h%^BOLD%^a%^BLACK%^r%^CYAN%^p c%^WHITE%^u%^CYAN%^r%^WHITE%^r%^CYAN%^e%^WHITE%^n%^CYAN%^t of %^WHITE%^air %^CYAN%^rushes forth from your blade, %^WHITE%^cutting %^CYAN%^"+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^A r%^RESET%^a%^BOLD%^z%^BLACK%^o%^CYAN%^r-s%^RESET%^h%^BOLD%^a%^BLACK%^r%^CYAN%^p c%^WHITE%^u%^CYAN%^r%^WHITE%^r%^CYAN%^e%^WHITE%^n%^CYAN%^t of %^WHITE%^air %^CYAN%^rushes forth from "+ETOQCN+"'s blade, %^WHITE%^cutting %^CYAN%^into you!%^RESET%^");
		return roll_dice(5,4)+0;	}

}
