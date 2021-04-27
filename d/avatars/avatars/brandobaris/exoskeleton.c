#include <std.h>
inherit "/d/common/obj/armour/shield";

void create(){
	::create();
	set_name("twisted exoskeleton");
	set_id(({ "exoskeleton", "twisted exoskeleton" }));
	set_short("%^BOLD%^%^BLACK%^a b%^RESET%^a%^BOLD%^r%^RESET%^b%^BOLD%^%^BLACK%^ed and t%^RESET%^%^GREEN%^w%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d e%^RESET%^x%^BOLD%^%^BLACK%^o%^RESET%^s%^BOLD%^%^BLACK%^k%^RESET%^%^GREEN%^e%^WHITE%^l%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^BLACK%^on%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a b%^RESET%^a%^BOLD%^r%^RESET%^b%^BOLD%^%^BLACK%^ed and t%^RESET%^%^GREEN%^w%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d e%^RESET%^x%^BOLD%^%^BLACK%^o%^RESET%^s%^BOLD%^%^BLACK%^k%^RESET%^%^GREEN%^e%^WHITE%^l%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^BLACK%^on%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^a b%^RESET%^a%^BOLD%^r%^RESET%^b%^BOLD%^%^BLACK%^ed and t%^RESET%^%^GREEN%^w%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d e%^RESET%^x%^BOLD%^%^BL"
	"ACK%^o%^RESET%^s%^BOLD%^%^BLACK%^k%^RESET%^%^GREEN%^e%^WHITE%^l%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^BLACK%^on%^RESET%^
"	);
	set_value(0);
	set_item_bonus("damage resistance",2);
	set_item_bonus("spell damage resistance",4);
	set_size(1);
	set_property("enchantment",0);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 950){
	tell_room(environment(query_worn()),""+who->QCN+" %^BOLD%^%^BLACK%^tries to %^WHITE%^stomp %^BLACK%^on %^RESET%^"+ETOQCN+"%^BOLD%^%^BLACK%^, but gets %^ORANGE%^j%^WHITE%^a%^RED%^b%^WHITE%^b%^ORANGE%^ed %^BLACK%^by its ba%^RESET%^r%^BOLD%^b%^RESET%^e%^BOLD%^%^BLACK%^d exoskeleton!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RED%^"+who->QCN+" tried to stomp on you!");
	tell_object(who,"%^BOLD%^%^BLACK%^You %^WHITE%^stomp %^BLACK%^down hard on %^RESET%^"+ETOQCN+"%^BOLD%^%^BLACK%^! %^ORANGE%^...%^RED%^OW! %^BLACK%^The r%^WHITE%^a%^RESET%^zo%^BOLD%^%^BLACK%^r-s%^WHITE%^h%^RESET%^a%^BOLD%^%^BLACK%^rp b%^RED%^a%^WHITE%^r%^RESET%^b%^BOLD%^%^BLACK%^s of its exoskeleton %^RED%^dig %^BLACK%^into your foot!%^RESET%^");
		who->do_damage("torso",roll_dice(5,3));
return damage;	}

}
