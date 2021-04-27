#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("Ninja-to");
	set_id(({ "sword", "ninjato", "ninja-to" }));
	set_short("%^BOLD%^%^BLACK%^Ninja-to of Death%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A slightly curved ninja-to%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This blade is the shorter version of the katana. It is made of the same steel and have been beaten and layered hundreds of times making it ultra sharp and deadly. It is said each ninj"
	"a-to is used on a prisoner and if the blade can't cut through the man in one strike, the smith have failed and will be executed. The blade is slightly curved for a better strike and the handle have be"
	"en wrapped in dark linen for a better grip.%^RESET%^
"	);
	set_value(0);
	set_property("enchantment",5);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" suddenly tumbles behind "+targ->QCN+", and within a %^RESET%^%^WHITE%^blink%^BOLD%^%^BLACK%^ of an %^RESET%^%^WHITE%^eye%^BOLD%^%^BLACK%^, he have closed the %^YELLOW%^distance%^BOLD%^%^BLACK%^ and places his "+query_short()+" between %^WHITE%^two ribs%^BOLD%^%^BLACK%^ and p%^CYAN%^i%^BOLD%^%^BLACK%^e%^CYAN%^r%^BOLD%^%^BLACK%^c%^CYAN%^e%^BOLD%^%^BLACK%^s "+targ->QCN+"'s %^RED%^lungs.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^In the fray of combat, you tumble behind your opponent, quickly studying "+targ->QCN+", before dashing in and delivers a near %^RED%^fatal %^WHITE%^stab %^BLACK%^that pierces "+targ->QCN+" %^RED%^lungs.");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" suddenly tumbles behind you, and within a %^RESET%^%^WHITE%^blink%^BOLD%^%^BLACK%^ of an %^RESET%^%^WHITE%^eye%^BOLD%^%^BLACK%^, he have closed the %^YELLOW%^distance%^BOLD%^%^BLACK%^ and places his "+query_short()+" between %^WHITE%^two ribs%^BOLD%^%^BLACK%^ and p%^CYAN%^i%^BOLD%^%^BLACK%^e%^CYAN%^r%^BOLD%^%^BLACK%^c%^CYAN%^e%^BOLD%^%^BLACK%^s your %^RED%^lungs.%^RESET%^");
		return roll_dice(200,0)+0;	}

}
