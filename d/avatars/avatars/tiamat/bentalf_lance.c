#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("iron lance");
	set_id(({ "lance", "iron lance", "lance of the cold tyrant" }));
	set_short("%^BOLD%^%^BLACK%^Lance of the %^BOLD%^%^CYAN%^C%^BLACK%^o%^CYAN%^l%^WHITE%^d %^CYAN%^Ty%^WHITE%^r%^BLACK%^a%^CYAN%^n%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black, cold iron lance%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a horseman's lance, surrounded in an aura of violence.  The main shaft has been masterfully forged from heavy, dark %^RESET%^iron%^BOLD%^%^BLACK%^.  The small piercing point, shaped like an arrowhead, appears to be nothing less than pure %^WHITE%^di%^CYAN%^a%^WHITE%^mon%^CYAN%^d%^BLACK%^.  The protective guard has been highly decorated with a flight of dueling %^WHITE%^frost wyverns%^BLACK%^.  Their dangerous tails curl around the guard and surround the grip.  The handle has been wrapped in a chain of tiny links, providing excellent stability in the grip of a gauntlet.  As you inspect the lance, you can feel a dense, %^CYAN%^cold aura%^BLACK%^ surrounding it.%^RESET%^

AVATAR
	);
	set_weight(14);
	set_value(7000);
	set_lore(
@AVATAR
The Lance of the Cold Tyrant is an exquisite weapon of extraordinary evil.  It was cold forged in more primitive times from metal rumored to have fallen from the sky to the top of Mount Krakus.  It was allegedly crafted at the behest of a dark lord of the Kinnesaruda and a dozen master smiths were executred before the perfect specimen was created.  The lance was used by the dark lord to battle the red and gold dragons standing in the way of the expanding empire.  Eventually lost to a draconic victor, it reemerged from a dragon's hoard during the resettlement of the Dagger region.  The lance then came into possession of the deathknight Balgus, who ordered the diamond edge in order the pierce the hearts and souls of even the most steadfast forces of good.  When Balgus was destroyed, the lance was taken by one of his squires, who was subsequently buried with the magic weapon.  It was recently recovered by the dark knight Bentalf Hearson.

AVATAR
	);
	set_property("lore difficulty",25);
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
	tell_room(environment(ETO),"%^CYAN%^As "+ETOQCN+" wields the lance, you hear fearful whispers emanate from the weapon.",ETO);
	tell_object(ETO,"%^CYAN%^Chilling cries of despair fill your ears briefly as you wield the lance.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^CYAN%^You hear fearful cries being muffled as "+ETOQCN+" unwields the lance.",ETO);
	tell_object(ETO,"%^CYAN%^You hear fearful cries muffled as you unwield the lance.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 80){
	tell_room(environment(query_wielded()),"%^CYAN%^As "+ETOQCN+"'s lance strikes true, you hear painful screams sent down the lance into "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^Cries of pain scream down the lance and into "+targ->QCN+"!");
	tell_object(targ,"%^CYAN%^As you are struck by the lance, otherworldly screams travel down its shaft and into you, causing great despair!");
		targ->set_paralyzed(roll_dice(3,6)+0);
return 0;	}

}
