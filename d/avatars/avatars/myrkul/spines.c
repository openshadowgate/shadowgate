#include <std.h>
inherit "/d/common/obj/armour/breastplate";

void create(){
	::create();
	set_name("spines");
	set_id(({ "spines" }));
	set_short("%^BOLD%^%^RED%^V%^RESET%^%^RED%^i%^BOLD%^ci%^RESET%^%^RED%^o%^BOLD%^us S%^RESET%^%^RED%^p%^BOLD%^ines%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^V%^RESET%^%^RED%^i%^BOLD%^ci%^RESET%^%^RED%^o%^BOLD%^us S%^RESET%^%^RED%^p%^BOLD%^ines%^RESET%^");
	set_long("These are vicious spines that form like a porcupine quilt and will shred any attacker.
");
	set_value(1000);
	set_size(2);
	set_property("enchantment",1);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^RESET%^"+ETOQCN+" %^RESET%^shreds "+who->QCN+" with his "+query_short()+"!!!%^RESET%^",({ETO,who}));
	tell_object(ETO,"You shred your attacker with your spines!");
	tell_object(who,"You get shredded by "+ETOQCN+"'s "+query_short()+"!!!!");
		who->do_damage("torso",roll_dice(3,10));
return damage;	}

}
