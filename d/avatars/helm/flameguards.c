#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracers");
	set_id(({ "flame guards", "guards", "bracers" }));
	set_short("%^RESET%^%^RED%^%^BOLD%^Fl%^RESET%^%^RED%^ame Gua%^BOLD%^rds%^RESET%^");
	set_obvious_short("a pair of gently glowing bracers");
	set_long(
@AVATAR
%^RESET%^%^RED%^%^BOLD%^These bracers are made of an odd metal with a faint reddish tint. The hue changes with the light seemingly like the dancing of a flickering flame. Small fire %^RESET%^%^RED%^a%^BOLD%^g%^RESET%^%^YELLOW%^at%^RED%^e%^RESET%^%^RED%^s %^BOLD%^and %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^YELLOW%^bi%^RED%^%^BOLD%^e%^RESET%^%^RED%^s %^BOLD%^line the front ends of the bracers and they sparkle softly with a faint red glow. On top of each bracer there is an ornate circle with an intricate flame motif.%^RESET%^

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
	tell_room(ETP,"%^RED%^%^BOLD%^"+ETO->query_cap_name()+"%^RED%^%^BOLD%^ wears the glowing bracers. %^RESET%^",TP);
	tell_object(TP,"%^RED%^%^BOLD%^You slip the bracers over your hands and feel their hot embrace.%^RESET%^");
	ETO->add_damage_bonus(3);
	ETO->set_property("magic resistance",20);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RED%^%^BOLD%^"+ETO->query_cap_name()+"%^RED%^%^BOLD%^ reluctantly removes the bracers.%^RESET%^",TP);
	tell_object(TP,"%^RED%^%^BOLD%^You reluctantly remove the bracers and feel a bond lessen.%^RESET%^");
	ETO->add_damage_bonus(-3);
	ETO->set_property("magic resistance",-20);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^RED%^%^BOLD%^"+ETO->query_cap_name()+"%^RED%^%^BOLD%^ parries "+who->query_cap_name()+"%^RED%^%^BOLD%^'s wild thrust with the bracers.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RED%^%^BOLD%^You parry "+who->query_cap_name()+"%^RED%^%^BOLD%^'s wild thrust with your bracers.%^RESET%^");
	tell_object(who,"%^RED%^%^BOLD%^Your wild thrust is parried by "+ETO->query_cap_name()+"%^RESET%^");
		return (damage*50)/100;
	}
}