#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Batwing Cloak");
	set_id(({ "cloak", "batwing cloak", "cape" }));
	set_short("%^ORANGE%^%^BOLD%^%^BLACK%^Batwing %^RESET%^%^ORANGE%^Cloak%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A cloak made of batwing skin%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This strange cloak or cape appears to be fashioned from the wing skin of a giant bat.  The skin is stretched between thin and pliable bones still covered in dense %^BOLD%^%^BLACK%^bat fur%^RESET%^%^ORANGE%^.  The bones connect to a thick %^BOLD%^%^BLACK%^black leather collar%^RESET%^%^ORANGE%^ studded in semi-precious %^RED%^s%^GREEN%^t%^YELLOW%^o%^WHITE%^n%^GREEN%^e%^RED%^%^ORANGE%^s%^RESET%^%^ORANGE%^.  By wearing the collar, the skin cloak can then be worn over the shoulders like two "wings".  There is a morbid beauty about the item.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1100);
	set_lore(
@AVATAR
This rare cloak last belonged to a paranoid and maniacal werebat known only as The Baron.  As the Baron grew insane with age, he began to create lesser werebats to serve him and punish the community of Kildare Glen.  The manufacturer of the cloak is unknown, but the Baron claimed that he enchanted it with a flight spell.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" wears the cloak, the bat wings stretch outward from them!",ETO);
	tell_object(ETO,"%^ORANGE%^As you clasp the collar of the cloak, the wings stretch out taut and menacing outward from you!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" removes their cloak, their bat wings fall limp at their sides.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^As you loosen the collar, the wings fall limp to your sides.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^ORANGE%^A bat wing from "+ETOQCN+"'s cloak rises to block the attack from "+who->QCN+"!",({ETO,who}));
	tell_object(ETO,"%^ORANGE%^One wing of the cloak rises up to protect you from "+who->QCN+"'s attack!");
	tell_object(who,"%^ORANGE%^Your attack is blocked by a bat wing from "+ETOQCN+"'s cloak!");
return (damage*10)/100;	}
}