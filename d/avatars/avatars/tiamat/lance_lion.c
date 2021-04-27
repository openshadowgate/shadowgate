#include <std.h>
inherit "/d/common/obj/weapon/lance.c";

void create(){
	::create();
	set_name("gilded mithril lance");
	set_id(({ "lance", "mithril lance" }));
	set_short("%^BOLD%^%^WHITE%^La%^CYAN%^n%^WHITE%^ce of the %^YELLOW%^L%^RED%^i%^YELLOW%^o%^RED%^n%^YELLOW%^'s Pr%^RESET%^%^ORANGE%^i%^YELLOW%^d%^RESET%^%^ORANGE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^g%^YELLOW%^i%^ORANGE%^ld%^YELLOW%^ed %^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l lance%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a heavy lance of noble, almost divine design.  It has been forged almost entirely of %^BOLD%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l%^RESET%^, the length of the shaft having a bright %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y%^RESET%^ glow that occasionally shines with a %^CYAN%^warm blue%^RESET%^ tint.  Almost a dozen feet in length from grip to flawless point, it could only be used efficiently from a mount.  The hand guard is stylized to look like the head of a 

AVATAR
	);
	set_weight(14);
	set_value(4000);
	set_lore(
@AVATAR
%^BOLD%^%^RED%^The Lance of the Lion's Pride is an old symbol of knightly prestige.  In ages past, they were created and enchanted for holy knights belonging to the Order of Saint Justin.  The Order existed across several good churches and was charged with protecting the weak from tyranny and plague, both home and abroad.  They were renown for their vigilance as guardians.  Although the Order has ceased to exist, the lances are sometimes gifted to worthy warriors as a symbol of the never ending knightly ch

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);
	set_size(2);
	set_wc(1,12);
	set_large_wc(1,21);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" swells with pride as they wield the lance.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You swell with pride as you wield the lance.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks diminished somehow as they unwield the lance.",ETO);
	tell_object(ETO,"%^ORANGE%^You feel diminished as you unwield the lance.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^YELLOW%^A deafening lion R%^RESET%^%^ORANGE%^O%^YELLOW%^A%^RESET%^%^ORANGE%^R%^YELLOW%^ courses down the lance, disorienting "+targ->QCN+" !",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^A deafening lion R%^RESET%^%^ORANGE%^O%^YELLOW%^A%^RESET%^%^ORANGE%^R%^YELLOW%^ courses down the lance, disorienting your foe!%^RESET%^");
	tell_object(targ,"%^YELLOW%^A deafening lion R%^RESET%^%^ORANGE%^O%^YELLOW%^A%^RESET%^%^ORANGE%^R%^YELLOW%^ courses down the lance, disorienting your senses!!!");
		targ->set_paralyzed(roll_dice(15,0)+0);
return 0;	}

}
