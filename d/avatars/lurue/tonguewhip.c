#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip", "tongue whip", "red whip", "tongue" }));
	set_short("%^BOLD%^%^RED%^a long sinuous tongue%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^a long sinuous tongue%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This long cord of leathery material appears to be the tongue of some sort of creature.  Over twelve feet long it trails from very narrow to wide at the base and has an odd tacky feeling that causes it to attach to things.  Rended from the body of whatever creature it came from, the wider end is frayed and uneven, but one could still grasp the base a little further up and use the tongue as a sort of whip.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(150);
	set_lore(
@AVATAR
Cut from the body of a great slime creature, this tongue was its main defense against predators and served as its only means to draw food into its mouth.  Prehensile, it could wrap around a victim and swiftly pull them into the waiting maw with little more then a single scream getting tearing from its victim's lips.  The tongue, gathered from the body, is known for its ability to secrete a type of tacky liquid that acts like a temporary glue, immobilizing the victim temporarily and is often sought by those wishing to subdue their victim rather then kill them.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("lash");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" looks a little noxious as the tacky substance of the "+query_short()+" %^BOLD%^%^GREEN%^sticks to their hand.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The tacky substance of the whip like tongue adheres to your skin as you take firm hold.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" wipes the tacky remains of the "+query_short()+" %^BOLD%^%^GREEN%^residue on their clothing.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You wipe the remains of the "+query_short()+" %^BOLD%^%^GREEN%^tacky residue from your hand onto your clothing.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^RED%^ lashes out and wraps around "+targ->QCN+", immobilizing them with the tacky substance that covers the "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The "+query_short()+"%^BOLD%^%^RED%^ lashes out and wraps around "+targ->QCN+", immobilizing them with the tacky substance that covers the "+query_short()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^RED%^ lashes out and wraps around you, immobilizing you with the tacky substance that covers the "+query_short()+"!%^RESET%^");
		targ->set_paralyzed(roll_dice(10,0)+0);
return 0;	}
}