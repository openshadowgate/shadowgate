#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("dragon scales");
	set_id(({ "scales", "scale" }));
	set_short("%^BOLD%^%^WHITE%^dragon scales%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^dragon scales%^RESET%^");
	set_long(
@AVATAR
This is for immortal use only.  Please offer the item or ask an immortal for assistance.  ty

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",0);
	set_ac(16);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^YELLOW%^The dragon roars loudly, and gives "+who->QCN+" a powerful tail slap!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You lash out at "+who->QCN+" with a mighty tail slap!");
	tell_object(who,"%^BOLD%^%^YELLOW%^The dragon roars loudly, and gives you a powerful tail slap!");
		who->do_damage("torso",roll_dice(6,8));
return damage;	}

}
