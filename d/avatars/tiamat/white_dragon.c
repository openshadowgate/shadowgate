#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("dragon hide");
	set_id(({ "scales", "scale", "hide" }));
	set_short("%^RESET%^dragon scales%^RESET%^");
	set_obvious_short("%^RESET%^dragon scales%^RESET%^");
	set_long(
@AVATAR
This item is for Immortal use only.  If you find it in your possession, please return to an Immortal or offer.  Thanks.

<Tiamat>

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_heart_beat(1);
	set_max_internal_encumbrance(300);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",4);
	set_ac(18);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 600){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETOQCN+" returns the attack from "+who->QCN+" with a mighty tail slap!!!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You return the attack from "+who->QCN+" with a mighty tail slap!!!%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^"+ETOQCN+" returns your attack with a mighty tail slap!!!%^RESET%^");
		who->do_damage("torso",roll_dice(4,12));
return damage;	}

}

void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(random(500) > 495) 
	 {
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^WHITE%^You flap your wings furiously!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^"+ETOQCN+" %^WHITE%^flaps their wings furiously, creating a cold wind!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^WHITE%^You emit a deafening roar!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^The dragon emits a deafening roar!%^RESET%^", ({ETO}));
				break;
		}
	}
}