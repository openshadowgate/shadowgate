#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracers");
	set_id(({ "wave guards", "bracers", "guards" }));
	set_short("%^RESET%^%^CYAN%^%^BOLD%^Wa%^RESET%^%^CYAN%^ve Gua%^BOLD%^rds%^RESET%^");
	set_obvious_short("a pair of gently glowing bracers");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^These bracers are made of an odd metal with a slightly bluish tint. The hue changes with the light seemingly like shadows over the ocean floor when the sun shines through the water. Small %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^a%^BOLD%^t%^RESET%^e%^BOLD%^r o%^RESET%^p%^CYAN%^%^BOLD%^a%^RESET%^%^CYAN%^l%^BLUE%^%^BOLD%^s %^CYAN%^and %^BLUE%^a%^RESET%^%^CYAN%^q%^BOLD%^u%^RESET%^a%^BOLD%^m%^RESET%^a%^BOLD%^r%^RESET%^i%^CYAN%^%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^s %^CYAN%^line the front ends of the bracers and they sparkle softly with a faint blue glow. On top of each bracer there is an ornate circle with an intricate cresting wave motif.

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^CYAN%^%^BOLD%^"+ETO->query_cap_name()+"%^CYAN%^%^BOLD%^ wears the glowing bracers. %^RESET%^",TP);
	tell_object(TP,"%^CYAN%^%^BOLD%^You slip the bracers over your hands and feel their gentle clasp.%^RESET%^");
	ETO->add_damage_bonus(3);
	ETO->set_property("magic resistance",20);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^CYAN%^%^BOLD%^"+ETO->query_cap_name()+"%^CYAN%^%^BOLD%^ reluctantly removes the bracers.%^RESET%^",TP);
	tell_object(TP,"%^CYAN%^%^BOLD%^You reluctantly remove the bracers and feel a bond lessen.%^RESET%^");
	ETO->add_damage_bonus(-3);
	ETO->set_property("magic resistance",-20);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^CYAN%^%^BOLD%^"+ETO->query_cap_name()+"%^CYAN%^%^BOLD%^ parries "+who->query_cap_name()+"%^CYAN%^%^BOLD%^'s wild thrust with the bracers.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^CYAN%^%^BOLD%^You parry "+who->query_cap_name()+"%^CYAN%^%^BOLD%^'s wild thrust with your bracers.%^RESET%^");
	tell_object(who,"%^CYAN%^%^BOLD%^Your wild thrust is parried by "+ETO->query_cap_name()+"%^RESET%^");
		return (damage*50)/100;
	}
}