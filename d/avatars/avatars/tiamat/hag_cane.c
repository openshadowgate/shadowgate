#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("twisted cane");
	set_id(({ "club", "cane" }));
	set_short("%^RESET%^%^ORANGE%^H%^RED%^a%^ORANGE%^gg%^RED%^a%^ORANGE%^rd C%^RED%^a%^ORANGE%^ne%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a twisted cane%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a cane that appears to be little more than than a stripped hunk of treebranch, polished smooth and perhaps finished in wax.  It retains its natural twists and knots.  The part of the cane meant to be held is wrapped in aged, %^RED%^cracking leather%^ORANGE%^. A casual inspection reveals this to be a very old, if durable cane.  Taken in as a whole, however, it has a touch of style.  Some lettering appears to have been %^BOLD%^%^BLACK%^burned%^RESET%^%^ORANGE%^ near the bottom.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
For my new Grandpa

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(200);
	set_lore(
@AVATAR
A Haggard Cane is usually the result of some dark ritual.  They are traded between hags as a sign of goodwill when one of their own kind is ready to depart the world.  All the hags in the coven contribute their blood and spittle before presenting the cane to the aging hag.  The process that makes it magical is as yet unknown and probably very disgusting.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,7);
	set_large_wc(1,6);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^stoops down and wields a twisted cane.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You stoop down to wield the cane.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^stops crouching over the cane.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You rise from your crouch as you unwield the cane.%^RESET%^");
	return 1;
}
