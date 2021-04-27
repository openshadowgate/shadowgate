#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("adamantine kama");
	set_id(({ "kama", "final harvest", "harvest" }));
	set_short("%^BOLD%^%^BLACK%^Final Harvest%^RESET%^%^WHITE%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Adamantine Kama%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This wicked looking kama is a horrible looking weapon.  Unlike a farmer's kama, this blade is obviously designed to kill.  A polished ebony handle is carved meticulously with a strange set of %^RESET%^%^RED%^gl%^BOLD%^%^RED%^o%^RESET%^%^RED%^wing ru%^BOLD%^%^RED%^ne%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^.  It's blade is curved slightly, and angled sharply from the handle, but it bears a strange blood groove, and a faint %^BOLD%^%^CYAN%^bl%^BOLD%^%^BLUE%^u%^BOLD%^%^CYAN%^e fog %^BOLD%^%^BLACK%^rolls off the blade constantly, dissipating after traveling no more than a few inches.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_type("slashing");
	set_prof_type("kama");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^Wisps of fog trace after "+ETOQCN+"'s kama, freezing "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The wound left by your "+query_short()+" trails a hint of fog as it slices into "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^Your flesh cracks from the cold left by "+ETOQCN+"'s kama!%^RESET%^");
		return roll_dice(0,0)+0;	}
}