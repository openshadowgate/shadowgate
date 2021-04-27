#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lance of Fortune");
	set_id(({ "lance" }));
	set_short("%^RESET%^a %^BOLD%^%^BLACK%^jet %^RESET%^and %^BOLD%^%^WHITE%^pearl %^RESET%^laced lance");
	set_long(
@AVATAR
%^RESET%^This lance is simply beautiful yet brutal in its appearance.  Its core is made from the most stout wood available and is covered with a mixture of jet and pearl.  The jet and pearl are wound around it so well that one would have to examine the weapon for such a long time and with proper tools to see the seams.  It is longer than most lances, probably a good foot or so.  A single line of runes line the lance from tip to hilt.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^Only the most %^YELLOW%^noble %^BLUE%^may feel my power!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(3000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(mediuam);
	set_wc(2,100);
	set_large_wc(3,100);
	set_property("enchantment",5);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" wields "+query_short()+"",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^A warm feeling moves slowly up your arm as you wield "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("cha",1);
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" releases "+query_short()+" with a soft sigh",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^Your body feels colder somehow as you release the grip of "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("cha",-1);
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"A small shockwave reverberates around the room as "+ETOQCN+" hits "+targ->QCN+" with "+query_short()+"",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^A shockwave from the blow hitting "+targ->QCN+" strikes you as odd as it hits you in the face%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^RED%^"+ETOQCN+" strikes you with their lance and you are in shock for a moment%^RESET%^");
		targ->set_paralyzed(roll_dice(3,4)+-1);
return 0;	}
}