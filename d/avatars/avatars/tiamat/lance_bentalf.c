#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("iron lance");
	set_id(({ "lance" }));
	set_short("%^BOLD%^%^BLACK%^Lance of the %^BOLD%^%^CYAN%^C%^BLACK%^o%^CYAN%^l%^WHITE%^d %^CYAN%^Ty%^WHITE%^r%^BLACK%^a%^CYAN%^n%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^cold iron lance%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a horseman's lance, surrounded in an aura of violence.  The main shaft has been masterfully forged from heavy, dark %^RESET%^iron%^BOLD%^%^BLACK%^.  The small piercing point, shaped like an arrowhead, appears to be nothing less than pure %^WHITE%^di%^CYAN%^a%^WHITE%^mon%^CYAN%^d%^BLACK%^.  The protective guard has been highly decorated with a flight of dueling %^WHITE%^frost wyverns%^BLACK%^.  Their dangerous tails curl around the guard and surround the grip.  The handle has been wrapped in a chain of tiny links, providing excellent stability in the grip of a gauntlet.  As you inspect the lance, you can feel a dense, %^CYAN%^cold aura%^BLACK%^ surrounding it.%^RESET%^

AVATAR
	);
	set_weight(16);
	set_value(7000);
	set_lore(
@AVATAR
The Lance of the Cold Tyrant is an exquisite weapon of extraordinary evil.  It was cold forged in more primitive times from metal rumored to have fallen from the sky to the top of Mount Krakus.  It was allegedly crafted at the behest of a dark lord of the Kinnesaruda and a dozen master smiths were executred before the perfect specimen was created.  The lance was used by the dark lord to battle the red and gold dragons standing in the way of the expanding empire.  Eventually lost to a draconic victor, it reemerged from a dragon's hoard during the resettlement of the Dagger region.  The lance then came into possession of the deathknight Balgus, who ordered the diamond edge in order the pierce the hearts and souls of even the most steadfast forces of good.  When Balgus was destroyed, the lance was taken by one of his squires, who was subsequently buried with the magic weapon.  It was recently recovered by the dark knight Bentalf Hearson.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);
	set_size(3);
	set_wc(1,12);
	set_large_wc(1,21);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" shudders as the lance is wielded.",ETO);
	tell_object(ETO,"%^CYAN%^You feel a surge of cold rush up the lance into your arm.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" flushes briefly as though suddenly warming.",ETO);
	tell_object(ETO,"%^CYAN%^You feel the bitter cold ease as you unwield the lance.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^CYAN%^"+ETOQCN+" drives the diamond-tipped lance into "+targ->QCN+", freezing them from the inside!",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^You drive the diamond tip of the lance into "+targ->QCN+", freezing them from the inside!");
	tell_object(targ,"%^CYAN%^As "+ETOQCN+" drives the diamond tip of the lance into you, your body freezes from the inside!");
		return roll_dice(3,3)+0;	}

}
