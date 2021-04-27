#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Jade claws");
	set_id(({ "gauntlet", "mithril gauntlet" }));
	set_short("%^WHITE%^Mithril gauntlet with %^GREEN%^Jade claws%^RESET%^");
	set_obvious_short("A gauntlet");
	set_long(
@AVATAR
%^WHITE%^This mithril gauntlet is actually a fine weapon, made out of several leather strings connected to two mithril plates on the palm and face of the hand. The plates are connected with some thicker leather cords to be fastend around the wrist.  At the end of the gauntlet are 5 small Mithril pouches the fingers are placed in, each with a very sharp %^GREEN%^Jade claw.

AVATAR
	);
	set_weight(10);
	set_value(400);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,5);
	set_large_wc(2,4);
	set_property("enchantment",2);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,""+TP->query_cap_name()+" wears the gauntlet and examines the claws.",TP);
	tell_object(TP,"You buckle up the gauntlet, and look at the fine %^GREEN%^jade claws.");
	TP->add_attack_bonus(0);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"You carefully unbuckle the gauntlet and check it for damage");
	TP->add_attack_bonus(0);
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 600){
	tell_room(environment(query_wielded()),"%^GREEN%^"+ETO->query_cap_name()+
	  " rips through "+targ->query_cap_name()+" with the gauntlet's jade "
     "claws.",({ETO,targ}));
	tell_object(ETO,"%^GREEN%^The gauntlet's jade claws rip through the flesh of "+targ->query_cap_name()+".");
	tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+" rips through you with the gauntlet's jade claws.");
      set_property("magic",1);
      targ->do_damage("torso",random(6)+20);
		remove_property("magic");
		targ->set_paralyzed(roll_dice(1,0)+0);
return 0;	
   }
}