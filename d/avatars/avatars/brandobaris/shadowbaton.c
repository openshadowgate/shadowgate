#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create(){
	::create();
	set_name("shadowflame baton");
	set_id(({ "baton", "shadowflame baton", "blackened baton" }));
	set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^MAGENTA%^h%^BOLD%^a%^RESET%^%^MAGENTA%^d%^BOLD%^o%^BLACK%^w%^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^a%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^e B%^RESET%^%^MAGENTA%^a%^BOLD%^t%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d b%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^n bearing %^RESET%^%^MAGENTA%^o%^BOLD%^r%^RESET%^%^MAGENTA%^na%^BOLD%^t%^RESET%^%^MAGENTA%^e c%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^vi%^RESET%^%^MAGENTA%^n%^BOLD%^g%^RESET%^%^MAGENTA%^s%^WHITE%^");
	set_long("%^BOLD%^%^BLACK%^This simple baton looks to be just over a foot long, and is perhaps a single inch thick. Carved from s%^WHITE%^l%^RESET%^ee%^BOLD%^%^BLACK%^k, b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%"
	"^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^wood%^BOLD%^%^BLACK%^, a %^RESET%^%^MAGENTA%^s%^BOLD%^p%^RESET%^%^MAGENTA%^he%^BOLD%^r%^RESET%^%^MAGENTA%^e"
	"-c%^BOLD%^u%^RESET%^%^MAGENTA%^t %^BOLD%^gem %^BLACK%^of %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rp%^WHITE%^l%^MAGENTA%^e j%^BOLD%^a%^RESET%^%^MAGENTA%^de %^BOLD%^%^BLACK%^is set into its ti"
	"p, catching the eye in an almost %^RESET%^%^GREEN%^h%^BOLD%^%^WHITE%^y%^RESET%^%^GREEN%^p%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^t%^RESET%^i%^GREEN%^c %^BOLD%^%^BLACK%^trance as it arcs "
	"through the air. The bottom half of the baton is marked by simple %^RESET%^%^ORANGE%^ridges%^BOLD%^%^BLACK%^, allowing one a firm grip, but the rest of the wood bears %^RESET%^o%^BOLD%^r%^MAGENTA%^n%^"
	"WHITE%^at%^RESET%^e %^BOLD%^%^BLACK%^carvings of %^RESET%^%^RED%^m%^ORANGE%^o%^RED%^n%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^RED%^s%^BOLD%^%^BLACK%^, coiling around "
	"the wooden shaft in an almost %^RESET%^%^RED%^p%^WHITE%^o%^RED%^s%^WHITE%^s%^RED%^e%^WHITE%^s%^RED%^s%^WHITE%^i%^RED%^ve %^BOLD%^%^BLACK%^fashion.%^RESET%^
"	);
	set_value(25000);
	set_lore("%^BOLD%^%^BLACK%^While details of this baton's creation are scarce, it is clear that this particular piece has been remarkably well preserved. There is some evidence to suggest that batons similar to "
	"this were infrequently found in the possession of some of the ancient Zin'Charu, however. Reportedly infused with powerful %^MAGENTA%^c%^GREEN%^h%^MAGENTA%^arm %^BLACK%^magics, and the blessings of %^"
	"RESET%^%^MAGENTA%^Shar %^BOLD%^%^BLACK%^herself, these were often gifted to the leaders of Her various organizations - %^RESET%^%^MAGENTA%^church%^BOLD%^%^BLACK%^, %^RESET%^military%^BOLD%^%^BLACK%^, "
	"and %^MAGENTA%^magi %^BLACK%^- in order to better ensure the loyalty and compliance of their inferiors.%^RESET%^
"	);
	set_property("lore difficulty",35);
	set_item_bonus("attack bonus",2);
	set_item_bonus("influence",2);
	set_item_bonus("caster level",1);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Taking the thin, blackened baton in hand, "+ETOQCN+"'s presence seems to grow as the %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^begins to seep with thin tendrils of s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^e-l%^RESET%^i%^BOLD%^%^BLACK%^ke s%^RESET%^h%^BOLD%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the baton respond as you take it in hand, and the %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^begins to seep with thin t%^RESET%^e%^BOLD%^%^BLACK%^nd%^RESET%^r%^BOLD%^i%^RESET%^l%^BOLD%^%^BLACK%^s of s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^e-l%^RESET%^i%^BOLD%^%^BLACK%^ke s%^RESET%^h%^BOLD%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" sets the baton aside, and the area seems to %^RESET%^brighten%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You set the baton aside for now, and the shadows about you %^RESET%^dissipate%^BOLD%^%^BLACK%^.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^A long tendril of s%^RESET%^h%^BOLD%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w lashes out from "+ETOQCN+"'s baton, c%^RESET%^o%^BOLD%^i%^BLACK%^l%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g tightly around "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^A long tendril of s%^RESET%^h%^BOLD%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w lashes out from your baton, c%^RESET%^o%^BOLD%^i%^BLACK%^l%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g itself around "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^A long tendril of s%^RESET%^h%^BOLD%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w lashes out from "+ETOQCN+"'s baton, c%^RESET%^o%^BOLD%^i%^BLACK%^l%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g tightly around you!%^RESET%^");
		targ->set_paralyzed(roll_dice(6,4)+0);
return 0;	}

}
