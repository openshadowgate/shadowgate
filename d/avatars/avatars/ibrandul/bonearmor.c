#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^BLACK%^the m%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ntle of the lo%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^");
	set_id(({ "armor", "bone armor", "mantle", "leather", "mantle of lost souls" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^the m%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ntle of the lo%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^e%^RESET%^%^BOLD%^%^BLACK%^avy leat%^RESET%^%^ORANGE%^h%^RESET%^%^BOLD%^%^BLACK%^er draped in %^RESET%^%^WHITE%^bo%^RESET%^%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This armor, formed from %^RESET%^%^ORANGE%^heavy leather%^RESET%^%^BOLD%^%^BLACK%^, is covered with %^RESET%^%^WHITE%^small metal cords %^RESET%^%^BOLD%^%^BLACK%^that attach %^RESET%^%^BOLD%^%^WHITE%^bones%^RESET%^%^BOLD%^%^BLACK%^. As you look over the armor you realize that many different creatures are evident. The %^RESET%^%^BOLD%^%^WHITE%^skull %^RESET%^%^BOLD%^%^BLACK%^of an elf, the %^RESET%^%^BOLD%^%^WHITE%^legbone %^RESET%^%^BOLD%^%^BLACK%^of a human, %^RESET%^%^YELLOW%^claws %^RES

AVATAR
	);
	set_weight(35);
	set_value(10000);
	set_lore(
@AVATAR
%^RED%^The cult of Gartok Nor, a very violent offshoot of the church of Bane, is usually kept in reserve. Although thier allegience is to Bane and Bane only, they do not follow orders well, and an order to kill usually ends only when the Gartok Nor have no one left to kill. The armor of the Gartok Nor is a very personalized thing. Every important kill adds to the armor, and it is started with the skulls of thier father, mother, and lover. As they add to the armor, its power grows%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
        set_size(1);
	set_property("enchantment",4);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^The bones rattle as "+ETOQCN+"%^RESET%^%^BOLD%^ wears the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^The bones rattle as you wear the "+query_short()+"%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^The bones rattle as "+ETOQCN+"%^RESET%^%^BOLD%^ removes the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^The bones rattle as you remove the "+query_short()+"%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BLACK%^%^BOLD%^A %^RED%^scream%^BLACK%^%^BOLD%^ fills the air as "+who->QCN+"%^BLACK%^%^BOLD%^ strikes "+ETOQCN+"%^BLACK%^%^BOLD%^'s ",({ETO,who}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^A %^RED%^scream%^BLACK%^%^BOLD%^ fills the air as "+who->QCN+"%^BLACK%^%^BOLD%^ strikes the "+query_short()+"%^RESET%^");
	tell_object(who,"%^BLACK%^%^BOLD%^A %^RED%^scream%^BLACK%^%^BOLD%^ fills the air as you strike "+ETOQCN+"%^BLACK%^%^BOLD%^'s "+query_short()+"%^RESET%^");
		who->set_paralyzed(random(2));
return damage;	}
}
