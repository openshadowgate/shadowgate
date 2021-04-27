#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("crimson coif");
	set_id(({ "Coif", "coif", "crimson coif", "Crimson Coif" }));
	set_short("%^BOLD%^%^RED%^Cri%^YELLOW%^m%^RED%^son %^YELLOW%^Coif%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Cri%^YELLOW%^m%^RED%^son %^YELLOW%^Coif%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This coif is made from a large, rough piece of leather that has been dyed a deep cri%^YELLOW%^m%^RED%^son.  At first glance you would almost assume it was dyed in blood.  When worn it would cover the entire head of the wearer, with the ends coming down to slightly below the neck.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(1000);
	set_lore(
@AVATAR
%^RED%^Legend has it that this item was created by a powerful rogue mage named Blackthorn.  He magically bound the leather together and then dyed it, with the aide of more magic in the blood of his fallen enemy, Ragnarran, a priest of Tyr.%^RED%^

AVATAR
	);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(3);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
  if (ETO->query_lowest_level() < 19) {
    tell_object(ETO,"%^RED%^The blood red coif keeps slipping off your head.%^RESET%^");
     return 0;
  }
	tell_room(ETP,"%^RED%^"+ETO->query_cap_name()+"%^RED%^ wears the "+query_short()+"%^RED%^ with a slight grimace.%^RESET%^",TP);
	tell_object(TP,"%^RED%^You slip on the "+query_short()+" with a slight grimace.%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RED%^"+ETO->query_cap_name()+"%^RED%^ removes the "+query_short()+"%^RED%^ and looks relieved.%^RESET%^",TP);
	tell_object(TP,"%^RED%^You finally remove the "+query_short()+"%^RED%^ and feel relieved.%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^RED%^The surface of the "+query_short()+"%^RED%^ worn by "+ETO->query_cap_name()+"%^RED%^ seems to shift as "+who->query_cap_name()+"%^RED%^ strikes it!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RED%^The surface of your "+query_short()+"%^RED%^ seems to shift, absorbing most of the blow, as "+who->query_cap_name()+"%^RED%^ strikes it.%^RESET%^");
	tell_object(who,"%^RED%^The surface of the "+query_short()+"%^RED%^ worn by "+ETO->query_cap_name()+"%^RED%^ seems to shift as you strike it, weakening your blow!%^RESET%^");
		return (damage*25)/100;
	}
}
