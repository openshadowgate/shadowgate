#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create(){
	::create();
	set_name("walking stick");
	set_id(({ "stick", "cane", "walking stick", "gentleman's cane", "blackthorn" }));
	set_short("%^BOLD%^%^BLACK%^G%^RESET%^%^ORANGE%^e%^RED%^n%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^l%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n's C%^RESET%^%^RED%^a%^ORANGE%^n%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a d%^RESET%^a%^BOLD%^%^BLACK%^rk b%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^kt%^RESET%^%^RED%^h%^ORANGE%^o%^BOLD%^%^BLACK%^rn walking stick%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This stylish %^RESET%^%^ORANGE%^walking stick %^BOLD%^%^BLACK%^looks to be about three and a half feet in length, and has a casually r%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^s%^RESET%^t%"
	"^RED%^i%^BOLD%^%^BLACK%^c appearance, created from a single b%^RESET%^%^RED%^l%^ORANGE%^a%^BOLD%^%^BLACK%^c%^RESET%^%^RED%^k%^ORANGE%^t%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^o%^ORANGE%^r%^BOLD%^%^BLACK%^n "
	"branch with much of its bark still left intact. Several touches do lend the piece of touch of %^ORANGE%^class %^BLACK%^and %^CYAN%^sophistication%^BLACK%^, however, like a band of polished %^RESET%^s%"
	"^BOLD%^ilve%^RESET%^r %^BOLD%^%^BLACK%^set around its tip, and an ornate o%^RESET%^n%^BOLD%^y%^BLACK%^x handle carved into the shape of a curled-up, sleeping %^WHITE%^cat%^BLACK%^.%^RESET%^
"	);
	set_value(15000);
	set_lore("%^BOLD%^%^BLACK%^The innocuously named 'Gentleman's Cane' would not look out of place in most parts of society, bearing a design and purpose almost identical to any other walking stick in the realm. Y"
	"et these sticks are in fact holy artifacts touched by Mask himself, so that his priests might make use of the Shadowlord's blessings even when discretion and subtlety is called for.%^RESET%^
"	);
	set_property("lore difficulty",25);
	set_item_bonus("caster level",2);
	set_item_bonus("thievery",2);
	set_item_bonus("influence",2);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" grasps the wooden walking stick.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a subtle sense of %^RESET%^%^CYAN%^slyness %^BOLD%^%^BLACK%^overcome you as you grasp the %^RESET%^%^ORANGE%^wooden walking stick%^BOLD%^%^BLACK%^.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" lets go of the wooden walking stick.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your heightened sense for %^RESET%^%^CYAN%^subterfuge %^BOLD%^%^BLACK%^seems to dull slightly as the %^RESET%^%^ORANGE%^walking stick %^BOLD%^%^BLACK%^escapes your grasp.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^As "+ETOQCN+" swings the walking stick down upon "+targ->QCN+", the wood briefly transforms into a thin blade of %^WHITE%^r%^RESET%^a%^BOLD%^%^CYAN%^z%^WHITE%^or s%^RESET%^h%^BOLD%^%^BLACK%^a%^WHITE%^rp m%^BLACK%^e%^WHITE%^t%^CYAN%^a%^WHITE%^l%^BLACK%^, delivering a %^RESET%^%^RED%^d%^BOLD%^e%^WHITE%^a%^RED%^dl%^RESET%^%^RED%^y %^BOLD%^%^WHITE%^slice%^BLACK%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you swing the walking stick down upon "+targ->QCN+", the wood briefly transforms into a thin blade of %^WHITE%^r%^RESET%^a%^BOLD%^%^CYAN%^z%^WHITE%^or s%^RESET%^h%^BOLD%^%^BLACK%^a%^WHITE%^rp m%^BLACK%^e%^WHITE%^t%^CYAN%^a%^WHITE%^l%^BLACK%^, delivering a %^RESET%^%^RED%^d%^BOLD%^e%^WHITE%^a%^RED%^dl%^RESET%^%^RED%^y %^BOLD%^%^WHITE%^slice%^BLACK%^!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^As "+ETOQCN+" swings the walking stick down upon you, the wood briefly transforms into a thin blade of %^WHITE%^r%^RESET%^a%^BOLD%^%^CYAN%^z%^WHITE%^or s%^RESET%^h%^BOLD%^%^BLACK%^a%^WHITE%^rp m%^BLACK%^e%^WHITE%^t%^CYAN%^a%^WHITE%^l%^BLACK%^, cutting into you with a %^RESET%^%^RED%^d%^BOLD%^e%^WHITE%^a%^RED%^dl%^RESET%^%^RED%^y %^BOLD%^%^WHITE%^slice%^BLACK%^!%^RESET%^");
		return roll_dice(10,5)+0;	}

}
