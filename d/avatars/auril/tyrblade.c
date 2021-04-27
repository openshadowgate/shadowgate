#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tyr's blade");
	set_id(({ "sword", " longsword", " long sword" }));
	set_short("%^BOLD%^%^YELLOW%^Jus%^BOLD%^%^GREEN%^tice's %^BOLD%^%^RED%^F%^BOLD%^%^BLACK%^u%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^y%^RESET%^");
	set_obvious_short("A long sword");
	set_long("Made from strong %^RESET%^%^BLUE%^steel%^RESET%^, this weapon is exceptionately "+
		"made. The hilt of the blade is two small %^BOLD%^%^YELLOW%^scales%^RESET%^, that come in "+
		"together to form a symbol of %^BOLD%^%^RED%^Tyr%^RESET%^. The handle is wrapped in "+
		"intricate links of %^BOLD%^%^WHITE%^silver chain%^RESET%^. The pommel is a "+
		"heavy %^BOLD%^%^RED%^je%^BOLD%^%^BLUE%^we%^BOLD%^%^RED%^l%^RESET%^ which shimmers "+
		"slightly. The blade has sharpened to a %^BOLD%^%^CYAN%^keen %^RESET%^edge, making its "+
 	"cut incredibly precise.");
	set_weight(7);
	set_value(5000);
	set_lore("This sword is given to devote followers of Tyr by their high priest. It is an "+
		"incredible honor.");
 set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield("%^BOLD%^%^WHITE%^With remorse you unwield the weapon, losing the feelings."+
		"%^RESET%^");
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The sword is easily held, a strange strength "+
		"flows through you%^RESET%^");
	return 1;
}


int hit_func(object targ){
	if(random(1000) < 220){
	tell_room(environment(ETO),ETO->query_cap_name()+"%^BOLD%^%^RED%^ cries out: "+
		"%^BOLD%^%^YELLOW%^%^BOLD%^%^GREEN%^For the Glory of %^BOLD%^%^YELLOW%^"+
		"Tyr%^BOLD%^%^GREEN%^!%^BOLD%^%^YELLOW%^, %^BOLD%^%^RED%^as they cut into "+
		targ->query_cap_name()+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^With a burst of power, you cut into your opponent!"+
		"%^RESET%^");
	tell_object(targ,ETO->query_cap_name()+"%^BOLD%^%^RED%^ cries out: %^BOLD%^%^YELLOW%^"+
		"%^BOLD%^%^GREEN%^For the Glory of %^BOLD%^%^YELLOW%^Tyr%^BOLD%^%^GREEN%^!%^BOLD%^"+
		"%^YELLOW%^, %^BOLD%^%^RED%^as they cut into you!");
		return roll_dice(3,4)+-1;	}
}