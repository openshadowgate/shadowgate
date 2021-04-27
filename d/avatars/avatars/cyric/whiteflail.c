#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("white flail");
	set_id(({ "flail", " weapon", " white flail", " mithril flail", " electric flail", " talos flail" }));
	set_short("%^RESET%^%^BOLD%^Mithril Flail%^RESET%^");
	set_obvious_short("flail");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a high quality flail with a single spiked ball and chain made of mithril.  The grip is wrapped in brown leather, but is probably also mithril.  The metal itself is a whitish-grey with light veins of blue or turquoise running through it.  A single circular rune is inscribed on the ball and wraps itself around the last link of the chain where it connects to the ball.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(700);
	set_lore(
@AVATAR
Darmai, the mage who created this flail, was a devout follower of Talos.  In homage to the stormlord, he tried to create a weapon with which Talos' followers could use to strike their enemies with lightning.  Darmai, however, was not an archmage and the lightning he hoped to imbue the flail with never manifested.  Instead of lightning turning multiple enemies to cinders, only occasionally would a small bolt of electricity zap a single opponent.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^The "+query_short()+" wielded by "+ETOQCN+" starts crackling with energy.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^A few tendrils of electricity dance around the ball of "+query_short()+"%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+"'s "+query_short()+" appears mundane again.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^The tendrils of electricity sputter and die out.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^CYAN%^%^BOLD%^An arc of electricity leaps from "+query_short()+" to "+targ->QCN+"!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^%^BOLD%^An arc of electricity zaps "+targ->QCN+"!!%^RESET%^");
	tell_object(targ,"%^CYAN%^%^BOLD%^The "+query_short()+" wielded by "+ETOQCN+" zaps you with electricity!!%^RESET%^");
		return roll_dice(2,3)+1;	}
}