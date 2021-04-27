#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("crystal sabre");
	set_id(({ "sabre", "crystal sabre", "quicksilver", "sword", "weapon" }));
	set_short("%^BOLD%^%^WHITE%^Qui%^RESET%^ck%^BOLD%^%^WHITE%^sil%^RESET%^er");
	set_obvious_short("A %^BOLD%^%^CYAN%^cry%^RESET%^st%^BOLD%^%^CYAN%^al %^RESET%^sabre");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This beautiful crystal bladed weapon is truly exquisite. The sabre's blade is out of solid crystal which has been sharpened to a fine edge. The pommel of the sword looks to be connected to the blade, as if it was a large piece of crystal which has a crosspiece and handle fused around it. The pommel is in the image of a carved %^RESET%^%^ORANGE%^horse%^BOLD%^%^CYAN%^. The hilt of the blade is made out of a smooth %^BOLD%^%^WHITE%^mi%^RESET%^thr%^BOLD%^%^WHITE%^al %^BOLD%^%^CYAN%^metal. Light and balanced, the sabre's handle is also made from solid mithril with the pommel of the blade extendingn from the bottom. The handle is wrapped in a rough %^BOLD%^%^GREEN%^skin %^BOLD%^%^CYAN%^of some kind which allows for a stronger grip.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(11);
	set_value(10000);
	set_lore(
@AVATAR
The crystal sabre's origin is well known. The weapon was made for the leader of the Paladin Order of Tyr in southern Azha. Winning many battles, Sir Kristan of Poeral (later known as Lord Kirstan) claimed his lord Tyr and the sword combined with his courage helped win the day. When the Paladin died he passed it on to his bretheren.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",4);
	set_unwield((:TO,"unwield_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"The balance of the blade is lost as you unwield the weapon.");
	return 1;
}
