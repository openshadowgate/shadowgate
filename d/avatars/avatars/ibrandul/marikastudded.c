#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^W%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h of the M%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^RESET%^");
	set_id(({ "armor", "dragon scale", "wrath of the mother" }));
	set_short("%^BOLD%^%^BLACK%^W%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h of the M%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^dragon scale armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This armor is made of %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^ scales, the scales have been worked together to a well fitted armor, showing every curve of the wearer, the armor is made more like a shirt, fitted together in the front by one %^BOLD%^%^WHITE%^ivory%^RESET%^%^GREEN%^ clasp made to the form of a %^BOLD%^%^GREEN%^leaf%^RESET%^%^GREEN%^ it is engraved with a %^BOLD%^%^WHITE%^u%^RESET%^n%^BOLD%^i%^RESET%^c%^BOLD%^o%^RESET%^r%^BOLD%^n %^RESET%^%^GREEN%^head. Large scales used as shoulder plates of the armor bear the image of a %^BOLD%^%^WHITE%^w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e %^RESET%^wolf%^GREEN%^. The scales have been worked together expertly, with %^BOLD%^%^GREEN%^green%^RESET%^%^GREEN%^ material, giving it an appearance of dark %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^BOLD%^a%^RESET%^GREEN%^v%^BOLD%^e%^RESET%^GREEN%^s hanging from %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s.%^RESET%^%^GREEN%^ The armor shows of much of the wearer's body, with its deep cut neckline, and leaving the wearers abs uncovered. Yet its material seams to be able to deflect about any blow hitting it.%^RESET%^

AVATAR
	);
	set_weight(20);
	set_value(10000);
	set_lore(
@AVATAR
crafted by the master smith Darum of Tempus, this armor has been created from the scales of a mighty Black Dragon felled by his hands.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+"%^RESET%^%^GREEN%^ clasp on the "+query_short()+"%^RESET%^%^GREEN%^, looking around warily%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You clasp the "+query_short()+"%^RESET%^%^GREEN%^. You feel an urge to protect%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+"%^RESET%^%^GREEN%^ removes the "+query_short()+"%^RESET%^%^GREEN%^, they relax visibly%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You remove the "+query_short()+"%^RESET%^%^GREEN%^, feeling at ease again%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^ strikes "+ETOQCN+"%^RESET%^%^GREEN%^, "+ETOQCN+"%^RESET%^%^GREEN%^ grabs for them%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^GREEN%^As "+who->QCN+"%^RESET%^%^GREEN%^'s blow is about to strike you, you turn and grab for them%^RESET%^");
	tell_object(who,"%^RESET%^%^GREEN%^As you strike "+ETOQCN+"%^RESET%^%^GREEN%^ they grab at you, holding you against them%^RESET%^");
		who->set_paralyzed(random(2));
return damage;	}
}