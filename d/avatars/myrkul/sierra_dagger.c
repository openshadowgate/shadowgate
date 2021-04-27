#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger" }));
	set_short("%^BOLD%^%^BLACK%^C%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^ru%^BOLD%^%^BLACK%^p%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^d %^GREEN%^e%^BOLD%^l%^RESET%^%^GREEN%^ven%^MAGENTA%^ d%^BOLD%^a%^RESET%^%^MAGENTA%^gger%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^C%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^ru%^BOLD%^%^BLACK%^p%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^d %^GREEN%^e%^BOLD%^l%^RESET%^%^GREEN%^ven%^MAGENTA%^ d%^BOLD%^a%^RESET%^%^MAGENTA%^gger%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^The dagger has %^WHITE%^skull%^BLACK%^ for a pommel, the hilt bound in %^RESET%^%^ORANGE%^wire%^BOLD%^%^BLACK%^, and a long, %^RESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^%^MAGENTA%^cked %^B"
	"OLD%^%^BLACK%^double sided blade. Well-balanced, and impeccably sharp, the once-curved %^GREEN%^l%^RESET%^%^GREEN%^e%^BOLD%^af s%^RESET%^%^GREEN%^h%^BOLD%^ape%^BLACK%^ has been straightened. The dagge"
	"r emanates an %^CYAN%^unearthly chill%^BLACK%^, full of %^RED%^hate%^BLACK%^, %^BLUE%^m%^RESET%^%^BLUE%^a%^BOLD%^dn%^RESET%^%^BLUE%^e%^BOLD%^ss%^BLACK%^, and %^WHITE%^unlife.%^RESET%^  
"	);
	set_value(10000);
	set_lore("%^YELLOW%^There once was an %^RESET%^%^MAGENTA%^evil cleric%^YELLOW%^ named %^BLUE%^Sierra%^YELLOW%^, a legendary follower of %^BLACK%^Cyric%^YELLOW%^. It is told that she once battled an %^GREEN%^elv"
	"en ranger%^YELLOW%^ sent to slay her on behalf of the good folk of the realm. Defeating the %^BLACK%^vigilante warriors%^YELLOW%^, %^Sierra%^YELLOW%^ sacrificed her %^RED%^enemy%^YELLOW%^ to the dark "
	"entity known as %^BLACK%^Vhiirtaahk%^YELLOW%^. In a %^MAGENTA%^mockery%^YELLOW%^ of her fallen enemy and a %^RED%^warning%^YELLOW%^ to others that may think to defy her, %^BLUE%^Sierra %^WHITE%^corrup"
	"ted%^YELLOW%^ this blade in the name of %^BLACK%^Cyric.%^RESET%^
"	);
	set_property("lore difficulty",15);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" %^MAGENTA%^stabs%^RED%^ "+targ->QCN+" %^BOLD%^%^RED%^in the heart with %^RESET%^"+query_short()+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You %^MAGENTA%^stab%^RED%^ "+targ->QCN+" %^BOLD%^%^RED%^in the heart with %^RESET%^"+query_short()+"%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" %^MAGENTA%^stabs%^RED%^ you %^BOLD%^%^RED%^in the heart with %^RESET%^"+query_short()+"%^RESET%^");
		return roll_dice(10,3)+0;	}

}
