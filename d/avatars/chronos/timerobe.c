#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("timerobe");
	set_id(({ "robe" }));
	set_short("%^BOLD%^%^BLUE%^R%^RESET%^%^BLUE%^o%^BOLD%^b%^RESET%^%^BLUE%^e%^RESET%^ of %^BOLD%^%^WHITE%^T%^BLACK%^i%^WHITE%^m%^BLACK%^e%^WHITE%^l%^BLACK%^e%^WHITE%^ssn%^BLACK%^e%^WHITE%^ss%^RESET%^");
	set_obvious_short("%^BLUE%^a %^BOLD%^%^BLACK%^wrin%^BLUE%^k%^BLACK%^led%^RESET%^ old%^BOLD%^%^BLUE%^ robe%^RESET%^");
	set_long(
@AVATAR
y%^BOLD%^%^BLUE%^This dark blue robe is made of a strange material. The soft robe is cut in such a fashion that the sleeves and body drag low across the ground giving ample room to move about in the robe. The deep %^BLACK%^wrinkles%^BLUE%^ and %^CYAN%^folds%^BLUE%^ that cover the robe give it a somewhat unkempt appearance. Upon inspecting the folds and creases you notice that many %^WHITE%^twink%^YELLOW%^l%^WHITE%^ing li%^YELLOW%^g%^WHITE%^hts%^BLUE%^ from within is actually a multitude of %^RESET%^%^BLUE%^st%^WHITE%^a%^BLUE%^rs%^BOLD%^ and %^WHITE%^li%^YELLOW%^gh%^WHITE%^ts%^BLUE%^, seemingly bending time and space to form the robe around the wearer.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(2000);
	set_lore(
@AVATAR
Amazingly similar to the odd fabric that makes up the well of worlds. An unknown must have attempted to weave togther the properties of the mutiverse to clothe themselves in. Whatever happened to the original wearer however... is only a mystery.

AVATAR
	);
	set_property("lore difficulty",10);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" settles deep into the robe%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You pull on the robe and sink into it's deep %^BLACK%^folds%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" hesitates a moment before slipping out of the robe%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You lose your touch with the %^BLUE%^Cosmos%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+ETOQCN+" escapes attack by diving into a %^BLACK%^wrinkle%^BLUE%^ and reappearing elsewhere%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You dive into the %^BOLD%^%^BLACK%^folds%^BLUE%^ of the robe for protection%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLUE%^"+ETOQCN+" dives into the %^BLACK%^folds%^BLUE%^ of the robe!!%^RESET%^");
return (damage*50)/100;	}
}