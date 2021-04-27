#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hood");
	set_id(({ "hood" }));
	set_short("%^BOLD%^%^BLACK%^Lu%^RESET%^%^RED%^min%^BOLD%^%^BLACK%^ou%^RESET%^%^RED%^s H%^BOLD%^%^BLACK%^ood%^RESET%^");
	set_obvious_short("an oversized hood");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This hood is very dark looking in appearance.  It is made extra large to come over the wearers head and across his face to hiding his eyes and enveloping the rest in shadow.  The hood itself is made of wool that has been dyed a deep yet dark grey, almost turning black.  It has been hand stitched, but not so well to hide the seams.  The hood ties about the wearers neck with a small strip of twine attached at the corners of the seem.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^Not much is known about this hood or it's origin.  There used to be many copies of it in existance but they have long since faded from history.  It is believe they were worn as a guild symbol by a group of magi in the 3rd century SG for the hood had extraordinary properties that assited the magi in their studies.  Since, many copies were made trying to recreate the special effects this hood had for the magi, but none have been successful.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",30);
	set("intbonus",2);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" looks to be in pain after wearing "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^A sharp pain hits your mind when you wear your "+query_short()+"%^RESET%^");
	ETO->add_damage_bonus(1);
	ETO->do_damage("torso",random(30));
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" breathes a sigh of relief after removing "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^The pain in your head subsides as you remove your "+query_short()+"%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}

