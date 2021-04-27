#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("glove");
	set_id(({ "glove", "glove of the feline" ,"claws"}));
	set_short("%^BOLD%^%^BLACK%^Glove of the Feline%^RESET%^");
	set_obvious_short("black leather glove");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A single black leather glove has been carelessly left here.  The glove features eyelets along the outter edge, so one might adjust it to a perfect fit.  After sliding your hand into the glove, a small lever feels out of place.  Pressing your palm against the lever five sharp %^WHITE%^claws%^%^BLACK%^ spring out of the tip of the glove.

AVATAR
	);
	set_weight(2);
	set_value(3000);
	set_lore(
@AVATAR
The Gloves of the Feline where crafted by the Amazons in thanks to one of their totem animals, the cat.  The cult of the cat has been growing in number among the Amazon's, and some sages ponder if it might spread across the realms one day.

AVATAR
	);
	set_type("slashing");
	set_prof_type("feline glove");
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
void init(){
    ::init();
    add_action("wear_em","wear");
    add_action("remove_em","remove");
}
int query_size(){
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" "+
		"slides on the glove and flashes a grin as claws that "+
		"glisten and extend.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slide on the glove and marvel in delight "+
		"at the claws that spring from the "+query_short()+".");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" removes the "+
		"glove and the claws retract back into the "+query_short()+".",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the glove causing the claws "+
		"to retract into the "+query_short()+"");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
		tell_room(ETO,"%^BOLD%^%^BLACK%^"+
			""+ETO->query_cap_name()+" wildly rakes their claws "+
			"against "+targ->query_cap_name()+"!",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^BLACK%^You savagely rake your "+
			"claws against "+targ->query_cap_name()+"!");
		tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" "+
			"wildly rakes their claws into your flesh!");
		return (roll_dice(2,4));
	}
}
int wear_em(string str){
	if(!str){
		tell_object(ETO,"%^BOLD%^What are you wanting to wear?\n");
		return 1;
	}
	if(str == "glove" || str == "glove 2" || str == "glove 3" ||
		str == "glove 4" || str == "glove 5" || str == "glove 6"){
		ETO->force_me("wield "+str);
		return 1;
	}
}
int remove_em(string str){
	if(!str){
		tell_object(ETO,"%^BOLD%^What are you wanting to wear?\n");
		return 1;
	}
	if(str == "glove" || str == "glove 2" || str == "glove 3" ||
		str == "glove 4" || str == "glove 5" || str == "glove 6"){
		ETO->force_me("unwield "+str);
		return 1;
	}
}
