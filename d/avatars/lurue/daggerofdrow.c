#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger of glass");
	set_id(({ "dagger", "talon", "curved talon", "dagger of glass" }));
	set_short("%^BOLD%^%^BLACK%^C%^RED%^u%^BLACK%^rved T%^RED%^a%^BLACK%^lon%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a curved dagger made of glass%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This curved dagger looks incredibly sharp and dangerous.  Made from some form of %^BOLD%^%^BLACK%^black glass%^RESET%^ it has been wrapped in %^RED%^red leather%^RESET%^.  The gleam it holds in the light is pale, as though it draws the light in rather then catching and reflecting it.  Despite being made of glass, the weapons retains its sharp edge without breaking or fracturing, making it a wicked weapon indeed.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(400);
	set_lore(
@AVATAR
Some drow favor naturally made weapons, claiming that they are part of the underdark and so hold the power of their home.  Making the weapon truly superior.  Some even go so far as to have these weapons enchanted.  Those that find them on the surface claim that they are fine weapons indeed.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The razor sharp edge of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^cuts deep into "+targ->QCN+"'s body!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The razor sharp edge of the "+query_short()+" %^BOLD%^%^BLACK%^cuts deep into "+targ->QCN+"'s body!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^The razor sharp edge of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^cuts deep into your body!%^RESET%^");
		return roll_dice(1,4)+2;	}

}
