#include <std.h>
inherit "/d/common/obj/weapon/giant_battle_axe";

void create(){
	::create();
	set_name("Bruteaxe");
	set_id(({ "axe", "giant axe" }));
	set_short("%^BOLD%^%^BLACK%^A large %^RESET%^%^RED%^m%^ORANGE%^a%^RESET%^%^RED%^l%^ORANGE%^i%^RESET%^%^RED%^c%^ORANGE%^i%^RESET%^%^RED%^o%^ORANGE%^u%^RESET%^%^RED%^s %^BOLD%^%^RED%^waraxe%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Waraxe of the %^RESET%^%^ORANGE%^B%^RESET%^%^RED%^r%^ORANGE%^u%^RESET%^%^RED%^t%^ORANGE%^e%^RESET%^");
	set_long("%^RED%^This is a large waraxe. It has a wooden handle that is wrapped around by strips of leather hide. It is a double bladed axe of the sharpest steel, and has ared tinge to it. On the  bottom of han"
	"dle an emblem of a savage wolf has been engraved%^RESET%^
"	);
	set_value(2000);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" wields "+query_short()+" and he gets a look of bloodlust in his eyes",ETO);
	tell_object(ETO,"%^RED%^You wield the axe and feel an urge to kill");
	return 1;
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RED%^"+ETOQCN+" screams at the top of his lungs and lands a massive blow on "+targ->QCN+"",({ETO,targ}));
	tell_object(ETO,"%^RED%^You scream at the top of you lungs and land a massive blow to "+targ->QCN+"");
	tell_object(targ,"%^RED%^"+ETOQCN+" screams at the top of his lungs and lands a massive blow on you");
		return roll_dice(2,8)+10;	}

}
