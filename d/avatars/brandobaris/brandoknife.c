#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create(){
	::create();
	set_name("knife");
	set_id(({ "switchblade", "knife", "stiletto" }));
	set_short("%^BOLD%^%^BLACK%^M%^RESET%^o%^BOLD%^b%^RESET%^s%^BOLD%^%^BLACK%^t%^WHITE%^e%^BLACK%^r%^RESET%^'%^BOLD%^%^BLACK%^s S%^RESET%^w%^BOLD%^i%^RESET%^t%^BOLD%^c%^RESET%^h%^BOLD%^b%^RESET%^l%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a g%^RESET%^%^RED%^i%^BOLD%^l%^WHITE%^d%^BLACK%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^il%^RED%^e%^WHITE%^t%^RESET%^t%^BOLD%^%^BLACK%^o s%^RESET%^w%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^No longer than a human hand, this expensive-looking %^WHITE%^switchblade %^BLACK%^bears a elaborate handle, carved from %^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk m%^"
	"BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^g%^WHITE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^y %^BOLD%^%^BLACK%^and engraved with %^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^"
	"ch c%^BOLD%^r%^RESET%^%^RED%^im%^BOLD%^s%^RESET%^%^RED%^on s%^ORANGE%^c%^RED%^r%^ORANGE%^o%^RED%^l%^ORANGE%^l%^RED%^w%^ORANGE%^or%^RED%^k%^BOLD%^%^BLACK%^. A small %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOL"
	"D%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n %^BLACK%^button on the side of the handle may be pressed, releasing a %^WHITE%^g%^RESET%^l%^BOLD%^%^CYAN%^e%^WHITE%^a%^CYAN%^m%^RESET%^i%^BOLD%^ng s%^RESET%^i%^BOLD%"
	"^lv%^RESET%^e%^BOLD%^r b%^RESET%^l%^BOLD%^ade %^BLACK%^with a loud %^ORANGE%^-%^WHITE%^SNAP%^ORANGE%^-%^BLACK%^.%^RESET%^
"	);
	set_value(50000);
	set_item_bonus("dexterity",4);
	set_item_bonus("stealth",5);
	set_property("enchantment",9);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" flips the switchblade open with a loud %^ORANGE%^-%^WHITE%^SNAP%^ORANGE%^-%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You flip the switchblade open with a loud %^ORANGE%^-%^WHITE%^SNAP%^ORANGE%^-%^BLACK%^.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" closes the switchblade with a %^ORANGE%^-%^WHITE%^CLACK%^ORANGE%^-%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You close the switchblade with a %^ORANGE%^-%^WHITE%^CLACK%^ORANGE%^-%^BLACK%^.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" whistles a tune from '%^RESET%^West Side Story%^BOLD%^%^BLACK%^' as you cheerfully slash at "+targ->QCN+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You whistle a tune from '%^RESET%^West Side Story%^BOLD%^%^BLACK%^' as you cheerfully slash at "+targ->QCN+".%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" whistles a tune from '%^RESET%^West Side Story%^BOLD%^%^BLACK%^', cheerfully slashing at you.%^RESET%^");
		return roll_dice(0,0)+0;	}

}
