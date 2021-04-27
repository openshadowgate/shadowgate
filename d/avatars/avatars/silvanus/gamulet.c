#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("glowing amulet");
	set_id(({ "amulet", " glowing amulet", " glowing medallion", " medallion", " necklace", " glowing necklace" }));
	set_short("%^YELLOW%^Glowing Amulet%^RESET%^");
	set_obvious_short("%^YELLOW%^Glowing Amulet%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This amulet is made of what appears to be a rounded piece of %^YELLOW%^glowing%^BOLD%^%^WHITE%^ petrified %^YELLOW%^sulfur%^BOLD%^%^WHITE%^ hanging from a dull silver chain.%^RESET%^ 

AVATAR
	);
	set_weight(2);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^RED%^"+ETO->query_cap_name()+"'s "+query_short()+" %^RESET%^%^RED%^flashes a dark red!%^RESET%^",TP);
	tell_object(TP,"%^RED%^The "+query_short()+"%^RESET%^%^RED%^ burns your flesh as you place it around your neck!%^RESET%^");
	ETO->add_attack_bonus(2);
	ETO->do_damage("torso",random(12));
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->add_attack_bonus(-2);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^YELLOW%^The "+query_short()+" worn by "+ETO->query_cap_name()+" flashes brilliantly when "+who->query_cap_name()+" strikes it!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Your "+query_short()+" flashes brilliantly when "+who->query_cap_name()+" strikes it!%^RESET%^");
	tell_object(who,"%^YELLOW%^The "+query_short()+" worn by "+ETO->query_cap_name()+" flashes brilliantly when you strike it!%^RESET%^");
		who->do_damage("torso",random(2));
return damage;	}
}