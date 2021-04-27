#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("vine whip");
	set_id(({ "whip", "vine whip", "vine" }));
	set_short("%^RESET%^%^GREEN%^sl%^RESET%^%^GREEN%^it%^BOLD%^he%^RESET%^%^GREEN%^ri%^BOLD%^ng v%^RESET%^%^GREEN%^in%^BOLD%^e w%^RESET%^%^GREEN%^hi%^BOLD%^p%^RESET%^");
	set_obvious_short("%^RESET%^a green vine%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This green vine looks like what you might cut off of a plant.  About ten feet long, one end is quite wide while the other is narrow and thin.  Bands of dark and light green cover the length, giving it a woven look, and small leaf buds are hear and there, making for a nubbly texture along the length. The tip however ends in a jagged thorn, the only one along the whole length.  Ivory in color it almost looks like a fingernail, making you wonder just where this came from.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
Harvested from the remains of Yolia the corrupted maidservant, this whip once served as her arm. Made monstrous after being experimented upon by an evil wizard, the transformation left her mindless with only the goal of killing whatever was around her and using it for food.  Half plant and half human, what remained of her was barely recognizable. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("lash");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^The whip in "+ETOQCN+"'s hand comes to life and wraps itself around "+targ->QCN+"'s neck, choking the life out of "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^The whip comes to life in your hands suddenly!  It lashes out and wraps around "+targ->QCN+"'s neck, choking the life out of them!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^The whip in "+ETOQCN+"'s hand comes to life and wraps around your neck!  You feel the life being choked out of you!%^RESET%^");
		targ->set_paralyzed(roll_dice(6,0)+0);
return 0;	}

}
