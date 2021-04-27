#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^W%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h of the F%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^RESET%^");
	set_id(({ "armor", " dragon scale", " wrath of the father" }));
	set_short("%^BOLD%^%^BLACK%^W%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h of the F%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^dragon scale armor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This armor is made of black scales, the armor covers the wearer's body tightly, large scales have been used on the shoulders as shoulder plates. The edges of the scales have been lined with %^RESET%^%^RED%^fever iron%^BOLD%^%^BLACK%^, giving them the look of large dark %^RED%^b%^BOLD%^%^BLACK%^l%^RED%^oo%^BOLD%^%^BLACK%^d drops. The inside of the armor has been lined with %^RESET%^%^RED%^crimson%^BOLD%^%^BLACK%^ silk. The image of %^RESET%^%^WHITE%^a %^BOLD%^b%^RESET%^l%^BOLD%^a%^RESET%^z%^BOLD%^i%^RESET%^n%^BOLD%^g silver sword over a %^RESET%^%^BOLD%^%^BLACK%^b%^RESET%^%^RED%^l%^BOLD%^oo%^BOLD%^%^BLACK%^d %^RESET%^%^RED%^red%^RESET%^%^BOLD%^%^BLACK%^ shield has been engraved into the back of the armor. The armor seams to be sturdy, but very light and easy to move in.%^RESET%^

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
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ clasps on the "+query_short()+"%^BLACK%^%^BOLD%^, adjusting it and stretching%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You clasp the "+query_short()+"%^BLACK%^%^BOLD%^ on slowly, adjusting it carefully to fit%^RESET%^");
	ETO->add_damage_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ removes the "+query_short()+"%^BLACK%^%^BOLD%^, they frown slightly%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the "+query_short()+"%^BLACK%^%^BOLD%^ slowly, seeming naked and weaker without it%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BLACK%^%^BOLD%^"+who->QCN+"%^BLACK%^%^BOLD%^'s blow seems to deflect off of "+ETOQCN+"%^BLACK%^%^BOLD%^'s "+query_short()+"%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^"+who->QCN+"%^BLACK%^%^BOLD%^'s blow seems to deflect off of your "+query_short()+"%^RESET%^");
	tell_object(who,"%^BLACK%^%^BOLD%^Your blow seems to deflect off of "+ETOQCN+"%^BLACK%^%^BOLD%^'s "+query_short()+"%^RESET%^");
return (damage*50)/100;	}
}