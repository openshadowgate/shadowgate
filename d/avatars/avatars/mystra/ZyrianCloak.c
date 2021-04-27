#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "cloak" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^Cloak of the Zyrian Society%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^cloak lined in silver%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^WHITE%^Woven together with a mithril-like fiber, the Cloak of the Zyrian Society is made to be unbreakable.  It flows gently about the wearer from the neck to the calves with the elgance of the wind.  A glittering silver cloth is stiched flawlessly into the edges of the cloak all the way around.  Across the back of the cloak, the insignia of the Zyrian Society can be seen embroidered in.  It features three six-point stars in an offset rectangular patteren up and to the right of crescent moon opening up to them.  Traveling through the moon towards the stars is an ornate cross piercing into the center of the design.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(25000);
	set("chabonus",1);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" swells up with pride while wearing the "+query_short()+"",ETO);
	tell_object(ETO,"Pride and confidence fill your soul as you don the "+query_short()+"");
	ETO->add_attack_bonus(1);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks disappointed when removing "+query_short()+"",ETO);
	tell_object(ETO,"You feel much less confident as you remove your "+query_short()+"");
	ETO->add_attack_bonus(-1);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^As "+who->QCN+" hits the "+query_short()+" worn by "+ETOQCN+", the glow within the lining radiates profusely%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Your "+query_short()+" glows intently when struck by "+who->QCN+"%^RESET%^");
	tell_object(who,"%^BOLD%^%^YELLOW%^You are blinded by a glow eminating from within the lining of "+ETOQCN+" "+query_short()+"%^RESET%^");
		who->set_paralyzed(roll_dice(2,6));
return damage;	}

}
