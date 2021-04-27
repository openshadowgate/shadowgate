#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bruiserknuckles");
	set_id(({ "knuckle", "Knuckle", "Knuckles", "knuckles" }));
	set_short("%^WHITE%^chain%^RESET%^ %^CYAN%^wrapped%^RESET%^ %^YELLOW%^leather gloves%^RESET%^");
	set_obvious_short("Bruisers gloves");
	set_long(
@AVATAR
%^CYAN%^These inelegant%^RESET%^ %^YELLOW%^leather gloves%^RESET%^ %^CYAN%^are either worn by the very sadistic or the very unimaginative. The design is simple, but very effective. The%^RESET%^ %^YELLOW%^thick leather%^RESET%^ %^CYAN%^provides padding for the wielders hands, whilst the thick%^RESET%^ %^WHITE%^chain%^RESET%^ %^CYAN%^wrapped around it is bound to crack bone or break skin. Nothing special to look at, just nasty.%^RESET%^

AVATAR
	);
	set_weight(10 pounds);
	set_value(500);
	set_type("piercing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(2,6);
	set_large_wc(2,8);
	set_property("enchantment",3);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RED%^"+ETOQCN+" brutally flogs "+targ->QCN+" with their "+query_short()+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^You lay the fist in, brutally flogging "+targ->QCN+" with your "+query_short()+"%^RESET%^");
	tell_object(targ,"%^RED%^"+ETOQCN+" brutally flogs you with his "+query_short()+"%^RESET%^");
		return roll_dice(0,0)+0;	}
}