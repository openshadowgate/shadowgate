#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dragon scales");
	set_id(({ "scales" }));
	set_short("%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^gon sc%^RESET%^a%^BOLD%^%^WHITE%^les%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^gon sc%^RESET%^a%^BOLD%^%^WHITE%^les%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a large swath of dragon scales from a great white wrym.  The scales appear to be from the torso, neck and tail with a few scraps that might have gone down the legs.  Heavy and bulky, they are still %^RED%^raw %^WHITE%^with skin, blood and fat on the inside,  as they have not yet been tanned properly.%^RESET%^

AVATAR
	);
	set_weight(100);
	set_value(10000);
	set_lore(
@AVATAR
The scales of a dragon are strong indeed and many are the armor smiths who crave such pelts to work on.  Though only the most skilled can work on them with any success, there is still great competition due to the lack of raw materials.  Even a white dragon's hide, the least of all the chromatic dragons, is said to fetch a fine price in the right markets.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("clothing");
	set_limbs(({ "right wing", "left wing" }));
	set_size(3);
	set_property("enchantment",5);
	set_ac(13);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The dragon rears up, buffeting "+who->QCN+" with her wings!  A roar of rage issues from her mouth as she tears into "+who->QCN+" with mad abandon!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The dragon rears up, buffeting "+who->QCN+" with her wings!  A roar of rage issues from her mouth as she tears into "+who->QCN+" with mad abandon!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^The dragon rears up, buffeting you with her wings!  A roar of rage issues from her mouth as she tears into you with mad abandon!%^RESET%^");
		who->do_damage("torso",random(50));
return damage;	}
}