#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lance of Lawgiving");
	set_id(({ "lance" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^a sleek and slender lance%^RESET%^");
	set_obvious_short("a heavy lance");
	set_long(
@AVATAR
%^RESET%^This lance is very sleek and very slender.  It is made from the wood of an %^ORANGE%^ash tree %^RESET%^and has been coated with finely crushed %^BOLD%^%^BLUE%^sapphires%^RESET%^.  It is very light-weight and easy to wield.  A long inscription is etched along the length of the weapon.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^BOLD%^%^BLUE%^With each strike of this lance...
%^RESET%^%^BOLD%^%^BLUE%^     ...Justice serves our Lord!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(3000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(2);
	set_wc(1,6);
	set_large_wc(1,12);
	set_property("enchantment",1);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^BOLD%^%^BLUE%^is visibly calmed as he wields "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^Calm overwhelms you as you wield "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("constitution",1);
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^BOLD%^%^BLUE%^is visibly confused for a moment as he unwields "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^Reality floods back to you as you remove your grip from "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^CYAN%^Spa%^BLUE%^r%^CYAN%^ks %^BLUE%^fly as "+ETOQCN+" %^RESET%^%^BOLD%^%^BLUE%^pounds "+targ->QCN+" %^RESET%^%^BOLD%^%^BLUE%^with the tip of "+query_short()+" %^RESET%^%^BOLD%^%^BLUE%^smartly in the chest%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^CYAN%^Spa%^BLUE%^r%^CYAN%^ks %^BLUE%^fly as you pound "+targ->QCN+" %^RESET%^%^BOLD%^%^BLUE%^with the tip of "+query_short()+"%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^BLUE%^Visions of calm and order flood your mind momentarily as you are struck squarely in the chest by "+query_short()+"%^RESET%^");
		targ->set_paralyzed(roll_dice(1,4)+0);
return 0;	}
}