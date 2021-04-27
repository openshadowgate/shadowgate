#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("black stone");
	set_id(({ "stone", " black stone", " black ioun", " ioun", " ioun stone", " black ioun stone", " small stone", " small black stone" }));
	set_short("%^BLACK%^%^BOLD%^Black Ioun Stone%^RESET%^");
	set_obvious_short("small stone");
	set_long(
@AVATAR
This is a small dark stone, nearly black, about the size of a marble.  It is perfectly round and smooth, with no markings whatsoever.

AVATAR
	);
	set_weight(0);
	set_value(100);
	set_lore(
@AVATAR
This is an ioun stone.  Ioun stones are magical items which, when used (wear stone) will grant their users magical effects.  The type of effect is determined by the color of the stone.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" releases a "+query_short()+", and it beings floating about in mid-air!",ETO);
	tell_object(ETO,"You release the "+query_short()+" and it floats up, commencing a haphazard orbit about your head.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" plucks a "+query_short()+" out of mid-orbit!",ETO);
	tell_object(ETO,"You grab the "+query_short()+" out of mid-air.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^RED%^%^BOLD%^The "+query_short()+" %^RED%^%^BOLD%^orbiting "+ETOQCN+"%^RED%^%^BOLD%^'s head fires a dart of magical energy at "+who->QCN+"%^RED%^%^BOLD%^!",({ETO,who}));
	tell_object(ETO,"%^RED%^%^BOLD%^A dart of energy shoots from your "+query_short()+" %^RED%^%^BOLD%^and zaps "+who->QCN+"!");
	tell_object(who,"%^RED%^%^BOLD%^The "+query_short()+" %^RED%^%^BOLD%^ orbiting "+ETOQCN+"%^RED%^%^BOLD%^'s head fires a magical dart of energy at you, zapping you!");
		who->do_damage("torso",random(5));
return damage;	}
}