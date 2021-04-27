#include <std.h>
inherit "/d/common/obj/weapon/scythe";

void create(){
	::create();
	set_name("No-dachi");
	set_id(({ "no-dachi", "sword" }));
	set_short("%^BOLD%^%^CYAN%^T%^BLUE%^i%^CYAN%^ta%^BLUE%^n%^CYAN%^nic N%^BLUE%^o%^CYAN%^-D%^BLUE%^a%^CYAN%^chi%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^T%^BLUE%^i%^CYAN%^ta%^BLUE%^n%^CYAN%^nic N%^BLUE%^o%^CYAN%^-D%^BLUE%^a%^CYAN%^chi%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^This sword is %^RED%^massive%^CYAN%^, extending a full four feet in length with a foot-long hilt. Forged in %^BLUE%^cold steel%^CYAN%^, the sword has but one curving blade. The source "
	"of the curve is from the two types of steel used to make the weapon: a %^RED%^hardened steel%^CYAN%^ for sharpness and a %^GREEN%^soft steel%^CYAN%^ to absorb the impact on the back of the blade. Used"
	" against %^BLACK%^cavalry%^CYAN%^, the No-Dachi evened the battlefield for the warrior on foot. This weapon is a %^YELLOW%^masterpiece%^CYAN%^ that its like might only be forged by one of a few artist"
	"s.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^BOLD%^%^RED%^This No-Dachi is a masterwork of an %^YELLOW%^ogre-magi%^RED%^ smith. His name has been lost to time, but it is an heirloom of the %^YELLOW%^Yellow Tooth%^RED%^ tribe.%^RESET%^
");
    set_property("lore difficulty",15);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^With a %^CYAN%^rasp%^RED%^, "+ETOQCN+" draws the keen edged "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^This blade feels wonderfully balanced in your hands%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	ETO->add_skill_bonus("endurance",2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^With a %^BLUE%^rasp%^CYAN%^, "+ETOQCN+" sheaths the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^With a %^BLUE%^rasp%^CYAN%^, you sheath your "+query_short()+".%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	ETO->add_skill_bonus("endurance",-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" lands a mighty blow against "+targ->QCN+" with the "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You land a mighty blow against "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" lands a massive blow into your flesh with the "+query_short()+"%^RESET%^");
		return roll_dice(2,20)+10;	}

}
