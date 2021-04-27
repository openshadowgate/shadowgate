#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracers");
	set_id(({ "wind guards", "bracers", "guards" }));
	set_short("%^RESET%^%^BOLD%^Wi%^RESET%^nd Gua%^RESET%^%^BOLD%^rds%^RESET%^");
	set_obvious_short("a pair of gently glowing bracers");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^These bracers are made of an odd metal with a soft white tint. The hue changes with the light seemingly like clouds that roll past a scenery. Small aventurines and turquoises line the front ends of the bracers and they sparkle softly with a faint white glow. On top of each bracer there is an intricate etching of a cloud.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_type("bracer");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ wears the glowing bracers. %^RESET%^",TP);
	tell_object(TP,"%^RESET%^%^BOLD%^You slip the bracers over your hands and feel their gentle clasp.%^RESET%^");
	ETO->add_damage_bonus(3);
	ETO->set_property("magic resistance",20);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ reluctantly removes the bracers.%^RESET%^",TP);
	tell_object(TP,"%^RESET%^%^BOLD%^You reluctantly remove the bracers and feel a bond lessen.%^RESET%^");
	ETO->add_damage_bonus(-3);
	ETO->set_property("magic resistance",-20);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^"+ETO->query_cap_name()+"%^RESET%^%^BOLD%^ parries "+who->query_cap_name()+"%^RESET%^%^BOLD%^'s wild thrust with the bracers.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BOLD%^You parry "+who->query_cap_name()+"%^RESET%^%^BOLD%^'s wild thrust with your bracers.%^RESET%^");
	tell_object(who,"%^RESET%^%^BOLD%^Your wild thrust is parried by "+ETO->query_cap_name()+"%^RESET%^");
		return (damage*50)/100;
	}
}