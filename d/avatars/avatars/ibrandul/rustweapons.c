#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^grafted scythes%^RESET%^");
	set_id(({ "blades" }));
	set_short("%^RESET%^%^BOLD%^grafted scythes%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^grafted scythes%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^grafted scythes%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("grafted");
	set_size(1);
	set_wc(2,4);
	set_large_wc(2,4);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^the "+query_short()+" slash into "+targ->QCN+"'s skin, spraying %^BOLD%^blood%^RESET%^ and leaving a trail of %^ORANGE%^sand%^RESET%^%^RED%^ and rust!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^you slash "+query_short()+"");
	tell_object(targ,"%^RESET%^%^RED%^as the "+query_short()+" slash into your skin, %^BOLD%^blood%^RESET%^ sprays and your skin %^BLACK%^%^BOLD%^boils!%^RESET%^");
		return roll_dice(3,4)+-1;	}
}

int drop(){ return 1; }
