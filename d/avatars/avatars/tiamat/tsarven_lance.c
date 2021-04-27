#include <std.h>
//inherit WEAPON;
//Changed to inherit the basic lance ~Circe~ 3/16/13
//It wasn't doing any damage because it didn't have a damage type.
inherit "/d/common/obj/weapon/lance.c";


void create(){
	::create();
	set_name("tsarven lance");
	set_id(({ "lance" }));
	set_short("%^RESET%^%^YELLOW%^L%^RED%^a%^YELLOW%^nc%^RED%^e%^YELLOW%^ of Might%^RESET%^");
	set_obvious_short("%^RESET%^%^YELLOW%^Tsarven lance%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is a heavy horse lance, forged from steel and painted in vivid %^YELLOW%^yellow %^RESET%^%^ORANGE%^and %^RED%^red %^ORANGE%^stripes.  The hand guard is highly decorated into the face of a lion with %^BOLD%^%^WHITE%^pure platinum%^RESET%^%^ORANGE%^ hair and %^BOLD%^%^RED%^ruby%^RESET%^%^ORANGE%^ eyes.  It is designed in such a way that the lance itself sprouts from the lion's roaring mouth.  It is a noble looking weapon and is slow to chip and wear.%^RESET%^%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1350);
	set_lore(
@AVATAR
The Lances of Might are no longer in manufacture or use.  They were often issued to Tsarven horsemen and knights known as the Lions of His Holiness.  The Lions were charged with protecting the roads and guarding pilgrims traveling to the holy sites around what is now called Shadow, formerly of the Empire.  The order quickly lost wealth and prestige when the Empire lost these lands.

AVATAR
	);
	set_property("lore difficulty",5);
/*	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(2);
	set_wc(1,12);
	set_large_wc(1,21);
*/
	set_property("enchantment",1);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^As "+ETOQCN+" wields the lance, they exude a sense of pride.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel the protection from the spirit of the mighty lion%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks more subdued without the lance in hand.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You no longer feel the lion in your heart.%^RESET%^");
	return 1;
}
