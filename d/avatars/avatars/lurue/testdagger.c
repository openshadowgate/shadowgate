#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger", "sharp dagger", "ruby dagger" }));
	set_short("%^RED%^Ruby %^BLUE%^Dagger%^RESET%^");
	set_obvious_short("a sharp dagger");
	set_long(
@AVATAR
%^RED%^This long sharp dagger is made of pure %^BOLD%^ruby%^RESET%^%^RED%^ and %^WHITE%^sparkles%^RED%^ brightly in the faintest of light like %^BOLD%^blood%^RESET%^%^RED%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


      O---O
      |   |
      O---O

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(100);
	set_lore(
@AVATAR
This dagger was made in the fire pits of the Derro as an eating tool for young firegiants.  As such, the edge is a little dulled, but it could probably still cut some meat up with a little sawing. 

AVATAR
	);
	set_property("lore difficulty",10);
	set("conbonus",1);
	set("chabonus",-1);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" just wielded their "+query_short()+" - %^RED%^RUN .. Run now!%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^You firmly grip the hilt of your %^RESET%^"+query_short()+"%^RESET%^%^BLUE%^ and grin %^RED%^devilishly%^RESET%^");
	ETO->do_damage("torso",random(5));
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" sighs and unwields their "+query_short()+"",ETO);
	tell_object(ETO,"You sigh as you unwield "+query_short()+"");
	ETO->do_damage("torso",random(10));
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+" attacks "+targ->QCN+" with their "+query_short()+"",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^You strike "+targ->QCN+" with your "+query_short()+"");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+" attacks you with their "+query_short()+"");
		targ->set_paralyzed(roll_dice(2,4)+2);
return 0;	}

}
